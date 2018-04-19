#pragma once
#include"event.h"
#include<iostream>
#include<vector>
#include<queue>
#include<functional>


using namespace std;



class scheduler {
public:
	bool Tick();
	bool InsertJob();
	bool RunJob();
	Job FindShortest();
	bool CheckAvailability();
	Job DeleteShortest();
	bool decrementTimer();
	bool ReleaseProcs();
	


private:
	vector<Job> runningJobs;
	priority_queue<Job, vector<int>, greater<int>> WaitQueue;
};