#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "IntersectionSimulationClass.h"
#include "random.h"

void IntersectionSimulationClass::readParametersFromFile(
     const string &paramFname
     )
{
  bool success = true;;
  ifstream paramF;

  paramF.open(paramFname.c_str());

  //Check that the file was able to be opened...
  if (paramF.fail())
  {
    success = false;
    cout << "ERROR: Unable to open parameter file: " << paramFname << endl;
  }
  else
  {
    //Now read in all the params, according to the specified format of
    //the text-based parameter file.
    if (success)
    {
      paramF >> randomSeedVal;
      if (paramF.fail() ||
          randomSeedVal < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set random generatsor seed" << endl;
      }
    }

    if (success)
    {
      paramF >> timeToStopSim;
      if (paramF.fail() ||
          timeToStopSim <= 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set simulation end time" << endl;
      }
    }

    if (success)
    {
      paramF >> eastWestGreenTime >> eastWestYellowTime;
      if (paramF.fail() ||
          eastWestGreenTime <= 0 ||
          eastWestYellowTime <= 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set east-west times" << endl;
      }
    }

    if (success)
    {
      paramF >> northSouthGreenTime >> northSouthYellowTime;
      if (paramF.fail() ||
          northSouthGreenTime <= 0 ||
          northSouthYellowTime <= 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set north-south times" << endl;
      }
    }

    if (success)
    {
      paramF >> eastArrivalMean >> eastArrivalStdDev;
      if (paramF.fail() ||
          eastArrivalMean <= 0 ||
          eastArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set east arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> westArrivalMean >> westArrivalStdDev;
      if (paramF.fail() ||
          westArrivalMean <= 0 ||
          westArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set west arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> northArrivalMean >> northArrivalStdDev;
      if (paramF.fail() ||
          northArrivalMean <= 0 ||
          northArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set north arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> southArrivalMean >> southArrivalStdDev;
      if (paramF.fail() ||
          southArrivalMean <= 0 ||
          southArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set south arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> percentCarsAdvanceOnYellow;
      if (paramF.fail() ||
          percentCarsAdvanceOnYellow < 0 ||
          percentCarsAdvanceOnYellow > 100)
      {
        success = false;
        cout << "ERROR: Unable to read/set percentage yellow advance" << endl;
      }

      //Use the specified seed to seed the random number generator
      setSeed(randomSeedVal);
    }

    paramF.close();
  }

  //Let the caller know whether things went well or not by printing the
  if (!success)
  {
    cout << "ERROR: Parameter file was NOT read in successfully, so the " <<
            "simulation is NOT setup properly!" << endl;
    isSetupProperly = false;
  }
  else
  {
    cout << "Parameters read in successfully - simulation is ready!" << endl;
    isSetupProperly = true;
  }
}

void IntersectionSimulationClass::printParameters() const
{
  cout << "===== Begin Simulation Parameters =====" << endl;
  if (!isSetupProperly)
  {
    cout << "  Simulation is not yet properly setup!" << endl;
  }
  else
  {
    cout << "  Random generator seed: " << randomSeedVal << endl;
    cout << "  Simulation end time: " << timeToStopSim << endl;

    cout << "  East-West Timing -" <<
            " Green: " << eastWestGreenTime <<
            " Yellow: " << eastWestYellowTime <<
            " Red: " << getEastWestRedTime() << endl;

    cout << "  North-South Timing -" <<
            " Green: " << northSouthGreenTime <<
            " Yellow: " << northSouthYellowTime <<
            " Red: " << getNorthSouthRedTime() << endl;

    cout << "  Arrival Distributions:" << endl;
    cout << "    East - Mean: " << eastArrivalMean <<
            " StdDev: " << eastArrivalStdDev << endl;
    cout << "    West - Mean: " << westArrivalMean <<
            " StdDev: " << westArrivalStdDev << endl;
    cout << "    North - Mean: " << northArrivalMean <<
            " StdDev: " << northArrivalStdDev << endl;
    cout << "    South - Mean: " << southArrivalMean <<
            " StdDev: " << southArrivalStdDev << endl;

    cout << "  Percentage cars advancing through yellow: " <<
            percentCarsAdvanceOnYellow << endl;
  }
  cout << "===== End Simulation Parameters =====" << endl;
}

void IntersectionSimulationClass::scheduleArrival(
     const string &travelDir
     )
{
  // Create new LightChange Event
  EventClass NextArrivalEvent;
  int arriveTime;

  if (travelDir == EAST_DIRECTION)
  {
    arriveTime = getPositiveNormal(eastArrivalMean, eastArrivalStdDev);
    NextArrivalEvent = EventClass(arriveTime + currentTime, EVENT_ARRIVE_EAST);
  }
  else if (travelDir == WEST_DIRECTION)
  {
    arriveTime = getPositiveNormal(westArrivalMean, westArrivalStdDev);
    NextArrivalEvent = EventClass(arriveTime + currentTime, EVENT_ARRIVE_WEST);
  }
  else if (travelDir == NORTH_DIRECTION)
  {
    arriveTime = getPositiveNormal(northArrivalMean, northArrivalStdDev);
    NextArrivalEvent = EventClass(arriveTime + currentTime, EVENT_ARRIVE_NORTH);
  }
  else if (travelDir == SOUTH_DIRECTION)
  {
    arriveTime = getPositiveNormal(southArrivalMean, southArrivalStdDev);
    NextArrivalEvent = EventClass(arriveTime + currentTime, EVENT_ARRIVE_SOUTH);
  }

  eventList.insertValue(NextArrivalEvent);
  cout << "Time: " << currentTime << " Scheduled " << NextArrivalEvent << endl;
}

void IntersectionSimulationClass::scheduleLightChange(
     )
{
  // Create new LightChange Event
  EventClass NextLightChange;

  if (currentLight == LIGHT_GREEN_EW)
  {
    NextLightChange = EventClass(
        eastWestGreenTime + currentTime,
        EVENT_CHANGE_YELLOW_EW);
  }
  else if (currentLight == LIGHT_YELLOW_EW)
  {
    NextLightChange = EventClass(
        eastWestYellowTime + currentTime,
        EVENT_CHANGE_GREEN_NS);
  }
  else if (currentLight == LIGHT_GREEN_NS)
  {
    NextLightChange = EventClass(
        northSouthGreenTime + currentTime,
        EVENT_CHANGE_YELLOW_NS);
  }
  else
  {
    NextLightChange = EventClass(
        northSouthYellowTime + currentTime,
        EVENT_CHANGE_GREEN_EW);
  }

  eventList.insertValue(NextLightChange);
  cout << "Time:" << currentTime << " Scheduled " << NextLightChange << endl;
}

bool IntersectionSimulationClass::handleNextEvent(
     )
{
  EventClass NextEvent;

  if (eventList.getNumElems() == 0)
  {
    // when no further event is scheduled.
    cout << endl << "No Event is scheduled." << endl;
    return false;
  }

  // Get next event
  eventList.removeFront(NextEvent);

  if (NextEvent.getTimeOccurs() > timeToStopSim)
  {
    // Timelimit of Simulation.
    cout << endl << "Next event occurs AFTER the simulation end time ("
    << NextEvent << ")!" << endl;
    return false;
  }

  currentTime = NextEvent.getTimeOccurs();

  cout << endl << "Handling " << NextEvent << endl;

  if (NextEvent.getType() == EVENT_ARRIVE_EAST)
  {
    // Add arriving car into Queue
    CarClass NewCar(EAST_DIRECTION, currentTime);
    eastQueue.enqueue(NewCar);
    cout << "Time: " << currentTime << " Car #" << NewCar.getId()
    << " arrives east-bound - queue length: "
    << eastQueue.getNumElems() <<endl;

    // Create new arriving Event
    scheduleArrival(EAST_DIRECTION);
  }
  else if (NextEvent.getType() == EVENT_ARRIVE_WEST)
  {
    // Add arriving car into Queue
    CarClass NewCar(WEST_DIRECTION, currentTime);
    westQueue.enqueue(NewCar);
    cout << "Time: " << currentTime << " Car #" << NewCar.getId()
    << " arrives west-bound - queue length: "
    << eastQueue.getNumElems() <<endl;

    // Create new arriving Event
    scheduleArrival(WEST_DIRECTION);
  }
  else if (NextEvent.getType() == EVENT_ARRIVE_NORTH)
  {
    // Add arriving car into Queue
    CarClass NewCar(NORTH_DIRECTION, currentTime);
    northQueue.enqueue(NewCar);
    cout << "Time: " << currentTime << " Car #" << NewCar.getId()
    << " arrives north-bound - queue length: "
    << eastQueue.getNumElems() <<endl;

    // Create new arriving Event
    scheduleArrival(NORTH_DIRECTION);
  }
  else if (NextEvent.getType() == EVENT_ARRIVE_SOUTH)
  {
    // Add arriving car into Queue
    CarClass NewCar(SOUTH_DIRECTION, currentTime);
    southQueue.enqueue(NewCar);
    cout << "Time: " << currentTime << " Car #" << NewCar.getId()
    << " arrives south-bound - queue length: "
    << eastQueue.getNumElems() <<endl;

    // Create new arriving Event
    scheduleArrival(SOUTH_DIRECTION);
  }
  else if (NextEvent.getType() == EVENT_CHANGE_GREEN_EW)
  {
    int countNorthCar = 0;
    int countSouthCar = 0;
    CarClass AdvancingCar;

    cout << "Advancing cars on north-south yellow" << endl;

    // Advancing cars on north bound
    if (northQueue.getNumElems() == 0)
    {
      cout << "  No north-bound cars waiting to advance on yellow" << endl;
    }
    else
    {
      bool doStopFirstCar = false;
      while (countNorthCar < northSouthYellowTime
          && northQueue.getNumElems() > 0
          && doStopFirstCar == false)
      {
        if (getUniform(0, 100) <= percentCarsAdvanceOnYellow)
        {
          northQueue.dequeue(AdvancingCar);
          cout << "  Car #" << AdvancingCar.getId()
               << " advances north-bound" << endl;
          countNorthCar++;
        }
        else{
          if (countNorthCar == 0)
          {
            cout << "  Next north-bound car will NOT advance on yellow" << endl;
          }
            doStopFirstCar = true;
        }
      }
    }

    // Advancing cars on south bound
    if (southQueue.getNumElems() == 0)
    {
      cout << "  No south-bound cars waiting to advance on yellow" << endl;
    }
    else
    {
      bool doStopFirstCar = false;
      while (countSouthCar < northSouthYellowTime
          && southQueue.getNumElems() > 0 && doStopFirstCar == false)
      {
        if (getUniform(0, 100) <= percentCarsAdvanceOnYellow)
        {
          southQueue.dequeue(AdvancingCar);
          cout << "  Car #" << AdvancingCar.getId()
               << " advances south-bound" << endl;
          countSouthCar++;
        }
        else
        {
          if (countSouthCar == 0)
          {
            cout << "  Next south-bound car will NOT advance on yellow" << endl;
          }
          doStopFirstCar = true;
        }
      }
    }

    cout << "North-bound cars advanced on yellow:" << countNorthCar
         << " Remaining queue: " << northQueue.getNumElems() << endl;

    cout << "South-bound cars advanced on yellow:" << countSouthCar
         << " Remaining queue: " << southQueue.getNumElems() << endl;

    // Switch light
    currentLight = LIGHT_GREEN_EW;
    // Create new LightChange Event
    scheduleLightChange();
  }
  else if (NextEvent.getType() == EVENT_CHANGE_YELLOW_EW)
  {
    int countEastCar = 0;
    int countWestCar = 0;
    CarClass AdvancingCar;

    cout << "Advancing cars on east-west green" << endl;

    // Advancing cars on east bound
    if (eastQueue.getNumElems() == 0)
    {
      cout << "  No east-bound cars waiting to advance on green" << endl;
    }
    else
    {
      while (countEastCar < eastWestGreenTime && eastQueue.getNumElems() > 0)
      {
        eastQueue.dequeue(AdvancingCar);
        cout << "  Car #" << AdvancingCar.getId()
             << " advances east-bound" << endl;
        countEastCar++;
      }
    }

    // Advancing cars on west bound
    if (westQueue.getNumElems() == 0)
    {
      cout << "  No west-bound cars waiting to advance on green" << endl;
    }
    else
    {
      while (countWestCar < eastWestGreenTime && westQueue.getNumElems() > 0)
      {
        westQueue.dequeue(AdvancingCar);
        cout << "  Car #" << AdvancingCar.getId()
             << " advances west-bound" << endl;
        countWestCar++;
      }
    }

    cout << "East-bound cars advanced on green:" << countEastCar
         << " Remaining queue: " << eastQueue.getNumElems() << endl;

    cout << "West-bound cars advanced on green:" << countWestCar
         << " Remaining queue: " << westQueue.getNumElems() << endl;

    // Switch light
    currentLight = LIGHT_YELLOW_EW;
    // Create new LightChange Event
    scheduleLightChange();
  }
  else if (NextEvent.getType() == EVENT_CHANGE_GREEN_NS)
  {
    int countEastCar = 0;
    int countWestCar = 0;
    CarClass AdvancingCar;

    cout << "Advancing cars on east-west yellow" << endl;

    // Advancing cars on east bound
    if (eastQueue.getNumElems() == 0)
    {
      cout << "  No east-bound cars waiting to advance on yellow" << endl;
    }
    else
    {
      bool doStopFirstCar = false;
      while (countEastCar < eastWestYellowTime && eastQueue.getNumElems() > 0 && doStopFirstCar == false)
      {
        if (getUniform(0, 100) <= percentCarsAdvanceOnYellow)
        {
          eastQueue.dequeue(AdvancingCar);
          cout << "  Car #" << AdvancingCar.getId()
               << " advances east-bound" << endl;
          countEastCar++;
        }
        else
        {
          if (countEastCar == 0)
          {
            cout << "  Next east-bound car will NOT advance on yellow" << endl;
          }
          doStopFirstCar = true;
        }
      }
    }

    // Advancing cars on west bound
    if (westQueue.getNumElems() == 0)
    {
      cout << "  No west-bound cars waiting to advance on yellow" << endl;
    }
    else
    {
      bool doStopFirstCar = false;
      while (countWestCar < eastWestYellowTime
          && westQueue.getNumElems() > 0 && doStopFirstCar == false)
      {
        if (getUniform(0, 100) <= percentCarsAdvanceOnYellow)
        {
          westQueue.dequeue(AdvancingCar);
          cout << "  Car #" << AdvancingCar.getId()
               << " advances west-bound" << endl;
          countWestCar++;
        }
        else
        {
          if (countWestCar == 0)
          {
            cout << "  Next west-bound car will NOT advance on yellow" << endl;
          }
          doStopFirstCar = true;
        }
      }
    }

    cout << "East-bound cars advanced on yellow:" << countEastCar
         << " Remaining queue: " << eastQueue.getNumElems() << endl;

    cout << "West-bound cars advanced on yellow:" << countWestCar
         << " Remaining queue: " << westQueue.getNumElems() << endl;

    // Switch light
    currentLight = LIGHT_GREEN_NS;
    // Create new LightChange Event
    scheduleLightChange();
  }
  else if (NextEvent.getType() == EVENT_CHANGE_YELLOW_NS)
  {
    int countNorthCar = 0;
    int countSouthCar = 0;
    CarClass AdvancingCar;

    cout << "Advancing cars on north-south green" << endl;

    // Advancing cars on north bound
    if (northQueue.getNumElems() == 0)
    {
      cout << "  No north-bound cars waiting to advance on green" << endl;
    }
    else
    {
      while (countNorthCar < northSouthGreenTime
          && northQueue.getNumElems() > 0)
      {
        northQueue.dequeue(AdvancingCar);
        cout << "  Car #" << AdvancingCar.getId()
             << " advances north-bound" << endl;
        countNorthCar++;
      }
    }

    // Advancing cars on south bound
    if (westQueue.getNumElems() == 0)
    {
      cout << "  No south-bound cars waiting to advance on green" << endl;
    }
    else
    {
      while (countSouthCar < northSouthGreenTime
          && southQueue.getNumElems() > 0)
      {
        southQueue.dequeue(AdvancingCar);
        cout << "  Car #" << AdvancingCar.getId()
             << " advances south-bound" << endl;
        countSouthCar++;
      }
    }

    cout << "North-bound cars advanced on green:" << countNorthCar
         << " Remaining queue: " << northQueue.getNumElems() << endl;

    cout << "South-bound cars advanced on green:" << countSouthCar
         << " Remaining queue: " << southQueue.getNumElems() << endl;

    // Switch light
    currentLight = LIGHT_YELLOW_NS;
    // Create new LightChange Event
    scheduleLightChange();
  }

  return true;
}

void IntersectionSimulationClass::printStatistics(
     ) const
{
  cout << "===== Begin Simulation Statistics =====" << endl;
  cout << "  Longest east-bound queue: " << maxEastQueueLength << endl;
  cout << "  Longest west-bound queue: " << maxWestQueueLength << endl;
  cout << "  Longest north-bound queue: " << maxNorthQueueLength << endl;
  cout << "  Longest south-bound queue: " << maxSouthQueueLength << endl;
  cout << "  Total cars advanced east-bound: " <<
          numTotalAdvancedEast << endl;
  cout << "  Total cars advanced west-bound: " <<
          numTotalAdvancedWest << endl;
  cout << "  Total cars advanced north-bound: " <<
          numTotalAdvancedNorth << endl;
  cout << "  Total cars advanced south-bound: " <<
          numTotalAdvancedSouth << endl;
  cout << "===== End Simulation Statistics =====" << endl;
}
