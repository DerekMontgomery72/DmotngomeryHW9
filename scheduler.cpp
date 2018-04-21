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
	
	int choice = 0, Ticks, procs, ;
	string typed, jobID;

	do {
		cout << "How would you like to enter a new Job into the system:\n";
		cout << " Manual or Through the input file\n";
		cout << "Enter manual, or file" << endl;
		cin >> typed;
		if (typed == "manaul") {
			//get job through user input
			// also allow for the user to enter exit command to exit the program
		}
		else if (typed == "file") {
			//get job from the input file

		}


	}
}
/*
Used to insert a new job into the waitQueue

To do:
1. Run checks to be sure the job is valid
2. Enter the job into the waitqueu
*/
bool scheduler::InsertJob(Job &newJob)
{
	WaitQueue.push(newJob);
	return true;
}
/*
Function to move a job into the running jobs map
Once a job is in the map its ticks will begin to be decremented until it is finished and needs removed

To do:
1. Create checks to be sure the job is valid to be entered into the map
2. Enter the job into the map
*/
bool scheduler::RunJob(Job &newJob)
{
	int id = newJob.getId();
	runningJobs.insert(std::pair<int, Job>(id, newJob));
}
/*
Function to find the next shortest job in the waitQueue Will use peek, so the Job is not removed from the queue
It will then return a copy of the next shortest job, so any comparisons that need to be made can be
To do:
1. Peek into the waitQueue
2. Assign a copy using this, and then return it for comparison/may call checkAvailabilty() in here so that the comparison can made in case the job needs to be inserted

*/
Job scheduler::FindShortest()
{
	return WaitQueue.top();
}
/*
Function to check the availabilty of the processors, If there is enough processors to run the job that is passed in then
the function will return true, otherwise will return false.
To do:
1. Pass in a job
2. Check if the number of available processors is less than the processors needed to run this process
3. Return a value
*/
bool scheduler::CheckAvailability(const Job &curJob)
{
	if (curJob.getProc() > this->availableProc) {
		return false;
	}
	else {
		return true;
	}
}

void scheduler::DeleteShortest()
{
	WaitQueue.pop();
}

bool scheduler::decrementTimer()
{
	for (std::map<int, Job>::iterator it = runningJobs.begin(); it != runningJobs.end; it++) {
		it->second.setTicks(it->second.getTicks() - 1);
	}
}

bool scheduler::ReleaseProcs()
{
	for (std::map<int, Job>::iterator it = runningJobs.begin(); it != runningJobs.end(); it++) {
		if (it->second.getTicks() == 0) {
			availableProc = availableProc + it->second.getProc();
			cout << "The process " << it->second.getDescript() << "has finished running." << endl;
			runningJobs.erase(it);
		}
		
	}
}
