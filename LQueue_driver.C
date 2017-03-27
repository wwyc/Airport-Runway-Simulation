/*---------------------------------------------------------------------
                  Driver program to test the Queue class.
  ----------------------------------------------------------------------*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LQueue.h"
using namespace std;

void print(Queue q)
{ q.display(cout); }

int part1();
void part2();

int main(void) {
while(true){
	int part = 0;
	cout << "\n Enter 1 for to test Part 1, or 2 to test Part 2:"   << endl;
	cin >> part;
	if (part == 1) {
		part1();
			break;
	}
	else if (part == 2) {
		part2();
			break;
	} else {
	cout << "Invalid Entry!  Please enter 1 or 2 only!"   << endl;
			break;
	}
}
    return 0;
}

// PART 1:  move_to_front & merge_two_queues
int part1() {

cout << "\n****Part 1 Testing*****" << endl;

//test move_to_front
cout << "\n***Testing move_to_front***\n";
cout << "How many elements to add to the queue: ";
int multi0 = rand() % 10;

   Queue q0;
   int numItems0;
   cin >> numItems0;
   for (int i = 1; i <= numItems0; i++){
   q0.enqueue(multi0*i);}

   cout <<'\t' <<  "\nContents of queue before move to front:  ";
   print(q0);
   cout << endl;

cout << "test1:  move head to front: " << endl;
       q0.move_to_front(q0.front());
       cout <<'\t' <<  "Contents of queue after move to front:  ";
       print(q0);
       cout << endl;

cout << "test2:  move middle to front: " << endl;
       q0.move_to_front(q0.middle());
       cout <<'\t' <<  "Contents of queue after move to front:  ";
       print(q0);
       cout << endl;

cout << "test3:  move back to front:" << endl;
       q0.move_to_front(q0.back());
       cout <<'\t' <<  "Contents of queue after move to front:  ";
       print(q0);
       cout << endl;

//test merge_two_queues
cout << "\n *** Testing merge_two_queues *** \n";

Queue q1;
cout << "How many elements to add to the queue #1? ";
          int numItems1;
          cin >> numItems1;
   for (int i = 1; i <= numItems1; i++)
      q1.enqueue(5*i);

Queue q2;
cout << "How many elements to add to the queue #2? ";
          int numItems2;
          cin >> numItems2;
         for (int i = 1; i <= numItems2; i++)
            q2.enqueue(6*i);

cout << "\n Before Merge: \n";
       cout <<'\t' <<  "Contents of queue q1 :  ";
       print(q1);
       cout << endl;
       cout <<'\t' <<  "Contents of queue q2 :  ";
       print(q2);
       cout << endl;
q1.merge_two_queues(q1, q2);
       cout << "\n After Merge:\n";
       cout <<'\t' <<  "Contents of queue q1 :  ";
       print(q1);
       cout << endl;
       cout <<'\t' <<  "Contents of queue q2 :  ";
       print(q2);
       cout << endl;

return 0;
}

// PART 2: SIMULATION
void part2() {

srand((int)time(NULL));

	cout << "\n****Part 2: Simulation*****\n" << endl;

//Data Entry from User:
	cout << "Bowen<221> runway" << endl;
	cout << "Enter:" << endl;

	int landingTime;
	cout << "   Time for a plane to land (in minutes): ";
	cin >> landingTime;
	int takeOffTime;
	cout << "   Time for a plane to takeOff (in minutes): ";
	cin >> takeOffTime;
	int landingRate;
	cout << "   Landing rate (planes per hour): ";
	cin >> landingRate;
	int takeoffRate;
	cout << "   Takeoff Rate (planes per hour): ";
	cin >> takeoffRate;
	int emergencyRate;
    cout << "   Emergency Rate (per hour): ";
    cin >> emergencyRate;
	int simTotalTime;
	cout << "   How long to run the simulation (in minutes): ";
	cin >> simTotalTime;

    Queue landingQueue;
    Queue takeoffQueue;
    bool landing = false;
    bool takingOff = false;
	int runwayFree = 0;
    Queue landingQueue2;
    Queue takeoffQueue2;
	bool landing2 = false;
    bool takingOff2 = false;
    int runwayFree2 = 0;

	int currentTime = 0;
	int planeNumber = 1000;

	int maxLandingQueueLength = 0;
	int maxTakeOffQueueLength = 0;
	int maxLandingQueueLength2 = 0;
    int maxTakeOffQueueLength2 = 0;

	int totalLandingRequestStartTime = 0;
	int totalLandingCompleteTime = 0;
	int totalTakeOffRequestStartTime = 0;
    int totalTakeOffCompleteTime = 0;
    int totalLandingPlanes = 0;
    int totalTakeOffPlanes = 0;

	bool endSim = false;
	bool emerg = false;

//run simulation
	while (true) {

//set random numbers
		int randomLand = rand()%60;
		int randomTakeoff = rand()%60;
		int randomLand2 = rand()%60;
		int randomTakeoff2 = rand()%60;
		int randomEmerg = rand()%60;

cout << "\nTime = " << currentTime << endl;

//check if currentTime is the input simulation total Time;
		if (currentTime == simTotalTime) {
			cout << '\t' << "No new takeoffs or landings will be generated" << endl;
			endSim = true;
		}

 //add plane to landing queue 1
 if ((endSim == false)&& (randomLand < landingRate)) {
				landingQueue.enqueue(planeNumber);
				cout << '\t' << "Plane " << planeNumber << " wants to land; added to landing queue 1  ;  " << landingQueue.length() << " in queue 1" << endl;
				planeNumber++;
				totalLandingRequestStartTime +=currentTime;
				//update maxlandingQueueLength
				if (landingQueue.length() > maxLandingQueueLength){
				maxLandingQueueLength = landingQueue.length();
				}
}

 //add plane to landing queue 2
 if ((emerg == false)&&(endSim == false)&& (randomLand2 < landingRate)) {
				landingQueue2.enqueue(planeNumber);
				cout << '\t' << "Plane " << planeNumber << " wants to land; added to landing queue 2  ;  " << landingQueue2.length() << " in queue 2" << endl;
				planeNumber++;
				totalLandingRequestStartTime +=currentTime;
				//update maxlandingQueueLength2
				if (landingQueue2.length() > maxLandingQueueLength2){
				maxLandingQueueLength2 = landingQueue2.length();
				}
}

//add plane to takeOff queue 1
 if ((endSim == false)&& (randomTakeoff < takeoffRate)) {
 				takeoffQueue.enqueue(planeNumber);
				cout << '\t' << "Plane " << planeNumber << " wants to takeoff; added to takeoff queue 1  ;  "<< takeoffQueue.length() << " in queue 1" << endl;
				planeNumber++;
				totalTakeOffRequestStartTime += currentTime;
				//update maxTakeOffQueueLength
                if (takeoffQueue.length() > maxTakeOffQueueLength){
                maxTakeOffQueueLength = takeoffQueue.length();
                }
			}

//add plane to takeOff queue 2
 if ((emerg == false)&&(endSim == false)&& (randomTakeoff2 < takeoffRate)) {
 				takeoffQueue2.enqueue(planeNumber);
				cout << '\t' << "Plane " << planeNumber << " wants to takeoff; added to takeoff queue 2  ;  "<< takeoffQueue2.length() << " in queue 2" << endl;
				planeNumber++;
				totalTakeOffRequestStartTime += currentTime;
				//update maxTakeOffQueueLength2
                if (takeoffQueue2.length() > maxTakeOffQueueLength2){
                maxTakeOffQueueLength2 = takeoffQueue2.length();
                }
			}

//Perform Landing for landing queue 1
			if ((!landingQueue.empty())&&(runwayFree==0)){
			 cout << '\t' << "Landing in runway 1: Plane " << landingQueue.front() << endl;
			landingQueue.dequeue();
			runwayFree =+ landingTime;
			landing = true;
			//use runway 1 to perform landing
			} else if (!(runwayFree == 0)){
			        if (landing == true)
                  		{runwayFree--;}
                  		if ((runwayFree == 0) && (landing == true)){
                  		cout << '\t' << "Landing complete in runway 1 ; " << landingQueue.length() << " in queue 1" << endl;
                  		totalLandingCompleteTime +=currentTime;
                  		totalLandingPlanes++;
                  		landing = false;
                  		}
                  		}

//Perform Landing for landing queue 2
			if ((emerg == false)&&(!landingQueue2.empty())&&(runwayFree2==0)){
			 cout << '\t' << "Landing in runway 2: Plane " << landingQueue2.front() << endl;
			landingQueue2.dequeue();
			runwayFree2 =+ landingTime;
			landing2 = true;
			//use runway 2 to perform landing
			} else if (!(runwayFree2 == 0)){
			        if (landing2 == true)
                  		{runwayFree2--;}
                  		if ((runwayFree2 == 0) && (landing2 == true)){
                  		cout << '\t' << "Landing complete in runway 2  ; " << landingQueue2.length() << " in queue 2" << endl;
                  		totalLandingCompleteTime +=currentTime;
                  		totalLandingPlanes++;
                  		landing2 = false;
                  		}
                  		}

//Perform TakeOff for take off queue 1
			if ((!takeoffQueue.empty())&&landingQueue.empty()&&(runwayFree==0)){
			 cout << '\t' << "Taking off in runway 1: Plane " << takeoffQueue.front() << endl;
			takeoffQueue.dequeue();
			takingOff = true;
			runwayFree =+ takeOffTime;
			//use runway 1 to perform takingoff
			} else if (!(runwayFree == 0)){
                  		if (takingOff == true)
                  		{runwayFree--;}
                  		if ((runwayFree == 0)&&(takingOff == true)){
                  		cout << '\t' << "Takeoff complete in runway 1; " << takeoffQueue.length() << " in queue 1" << endl;
                  		totalTakeOffCompleteTime += currentTime;
                  		totalTakeOffPlanes++;
                  		takingOff = false;
                  		}
                  		}

//Perform TakeOff for take off queue 2
			if ((emerg == false)&&(!takeoffQueue2.empty())&&landingQueue2.empty()&&(runwayFree2==0)){
			 cout << '\t' << "Taking off in runway 2: Plane " << takeoffQueue2.front() << endl;
			takeoffQueue2.dequeue();
			takingOff2 = true;
			runwayFree2 =+ takeOffTime;

			//use runway 2 to perform takingoff
			} else if (!(runwayFree2 == 0)){
                  		if (takingOff2 == true)
                  		{runwayFree2--;}
                  		if ((runwayFree2 == 0)&&(takingOff2 == true)){
                  		cout << '\t' << "Takeoff complete in runway 2; " << takeoffQueue2.length() << " in queue 2" << endl;
                  		totalTakeOffCompleteTime += currentTime;
                  		totalTakeOffPlanes++;
                  		takingOff2 = false;
                  		}
                  		}

// Emergency: Runway 2 is out of service; Merge landing Queue and takeoff Queues; use only runway 1;
		if ((currentTime>simTotalTime/2)&&(emerg == false)&&(endSim == false)&&(randomEmerg < emergencyRate)) {
        					cout << '\t' << "EMERGENCY: Runway 2 not in service; Merge landing and take off queues; Use runway 1 only!" << endl;
        					cout << '\t' << "Contents of landingQueue 1 before merge:  ";
                            print(landingQueue);
                            cout << endl;
        				    cout << '\t' << "Contents of landingQueue 2 before merge:  ";
                            print(landingQueue2);
                            cout << endl;
        	landingQueue.merge_two_queues(landingQueue, landingQueue2);
                            cout << '\t' << "Contents of landingQueue 1 after merge:  ";
                            print(landingQueue);
                            cout << endl;
        				    cout << '\t' << "Contents of landingQueue 2 after merge:  ";
                            print(landingQueue2);
                            cout << endl;

                            cout << '\t' << "Contents of takeoffQueue 1 before merge:  ";
                            print(takeoffQueue);
                            cout << endl;
                            cout << '\t' << "Contents of takeoffQueue 2 before merge:  ";
                            print(takeoffQueue2);
                            cout << endl;
        	takeoffQueue.merge_two_queues(takeoffQueue, takeoffQueue2);
                            cout << '\t' << "Contents of takeoffQueue 1 after merge:  ";
                            print(takeoffQueue);
                            cout << endl;
                            cout << '\t' << "Contents of takeoffQueue 2 after merge:  ";
                            print(takeoffQueue2);
                            cout << endl;
        					emerg = true;
        			}

//end simulation if passed total time entered and both landing and take off queues are empty
		if ((endSim == true) && landingQueue.empty() && takeoffQueue.empty()&&(runwayFree == 0) &&(runwayFree2 == 0)){
        cout << "\nEnd of program.\n" << endl;
        break;
        }
		currentTime++;
	}

//STATISTICS

    double AvgLanding = (totalLandingCompleteTime - totalLandingRequestStartTime)/ (double) totalLandingPlanes;
    double AvgTakeOff = (totalTakeOffCompleteTime - totalTakeOffRequestStartTime) / (double) totalTakeOffPlanes;

	cout << "\nSTATISTICS - QUEUE 1:" << endl;
	cout << "Maximum number of planes in landing queue 1 was: " << maxLandingQueueLength << endl;
	cout << "Maximum number of planes in takeoff queue 1 was: " << maxTakeOffQueueLength << endl;

	cout << "\nSTATISTICS - QUEUE 2:" << endl;
	cout << "Maximum number of planes in landing queue 2 was: " << maxLandingQueueLength2 << endl;
	cout << "Maximum number of planes in takeoff queue 2 was: " << maxTakeOffQueueLength2 << endl;

	cout << "\nSTATISTICS - TOTAL FOR QUEUE 1 & 2:" << endl;
	cout << "Average minutes spent waiting to land total: " << AvgLanding << endl;
    cout << "Average minutes spent waiting to takeoff total: " << AvgTakeOff << endl;

}
