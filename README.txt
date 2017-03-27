Winnie Wan Yee Chan
84522010

CPSC 221 Programming Project 1:  Queues, Simulation of an Airport Runway

Makefile
- for compiling program

README.txt
- give instructions and comments

LQueue.h
- header file

LQueue.C
- contain queue functions
- basic and added extra functions: (move_to_front, merge_two_queues, length, back, middle)

LQueue_driver.c
- Starts by asking user to test Part 1 (enter "1") or Part 2 (enter "2")
* Part 1 Test cases for move_to_front and merge_two_queues
* Part 2:  Simulating Airport Runway
- there are two runways: runway 1 and runway 2;
- there are two landing queues: landing queue 1 and landing queue 2;
- there are two takeoff: takeOff queue 1 and takeOff queue 2;
- plans in landing queue 1 and takeOff queue 1 will only use runway 1;
- planes in landing queue 2 and takeOff queue 2 will only use runway 2;
- When emergency state occurs, runway 2 is out of service.  Therefore merge landing queues 1 and 2, merge takeOff queues 1 and 2, use ONLY runway 2;
- Emergency state only occurs midway through simulation;
- using counters to keep track of data;  (Request time, Completion time, Plane Number, Number of Planes)
- ends simulation when reached total simulation time ended all both landing/take off queues are empty;
- generates statistics

Output_Part1.txt
- includes testing of Part one:
- move_to_front: tested moving front, middle and back element to front;
- merge_two_queues: tested when length of q1<q2 and when length of q2<q1;

Output_Part2.txt
User Input Entered:
   Time for a plane to land (in minutes): 3
   Time for a plane to takeOff (in minutes): 2
   Landing rate (planes per hour): 13
   Takeoff Rate (planes per hour): 12
   Emergency Rate (per hour): 11
   How long to run the simulation (in minutes): 50
