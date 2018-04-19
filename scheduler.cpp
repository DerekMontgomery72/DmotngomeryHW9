#include "scheduler.h"

/*
Runs through 1 tick in the scheduler


To Do: 
1. Prompt user for submitting job: if user enters exit, kill program
								   if user does not enter anything enter NULL as the job name so it is not entered into the queue
2. Insert the job into the wait queue if needed
3. Decrement Timer for all running jobs in the map
4. Release all processors for completed jobs, if the job has ticks == 0, It will also need to be removed from the running jobs map as well
5. Find the next shortes job(<ji, pi, ti>) from the wait queue and check if a sufficient number of processors are available in the free pool
	Remove job Ji from the wait queue
	Insert job ji into running queue and assign pi processors (from free pool) to do that job; if after this first job allocation, there are still more jobs in the wait
	queue that have sufficient available processors to run on, then iteratively keep removing all the next shortes jobs until no more processors are available for the next
	shortest job, or the wait queue becomes empty
Return True if the tick runs successfully
If an invalid job is entered then print an appropriate error message



*/
bool scheduler::Tick()
{
	return false;
}
/*
Used to insert a new job into the waitQueue

To do:
1. Run checks to be sure the job is valid
2. Enter the job into the waitqueu
*/
bool scheduler::InsertJob(Job newJob)
{
	return false;
}
