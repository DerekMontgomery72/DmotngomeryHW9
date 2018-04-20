#pragma once
#include"event.h"
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<map>


using namespace std;



class scheduler {
public:
	bool Tick();
	bool InsertJob(Job &newJob);
	bool RunJob(Job &newJob);
	Job FindShortest();
	bool CheckAvailability( const Job &curJob);
	void DeleteShortest();
	bool decrementTimer();
	bool ReleaseProcs();
	


private:
	map<int, Job> runningJobs; // A map of all running Jobs, with the int ID as the key for finding specific maps although it is not needed
	priority_queue<Job, vector<Job>, myComparator> WaitQueue;
	int tickNum;
	int availableProc;
	int maxProc;
	int Mode; // An integer value to distinguish between running from a file, or through user input to insert each file.

};