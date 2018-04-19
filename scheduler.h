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
	bool InsertJob();
	bool RunJob();
	Job FindShortest();
	bool CheckAvailability( const Job &curJob);
	Job DeleteShortest();
	bool decrementTimer();
	bool ReleaseProcs();
	


private:
	map<int, Job> runningJobs; // A map of all running Jobs, with the int ID as the key for finding specific maps although it is not needed
	priority_queue<Job, vector<int>, greater<int>> WaitQueue;
	int tickNum;
	int availableProc;
	int maxProc;

};