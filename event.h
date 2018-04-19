#pragma once
#include<iostream>
#include<string>

using namespace std;

class Job {
public:
	Job(int jobId, string descript, int nticks, int nproc);
	Job( const Job &copy);
	~Job();

	friend bool operator>(const Job&j1, const Job&j2);
	friend bool operator<(const Job&j1, const Job&j2);
	friend bool operator==(const Job&j1, const Job&j2);

	int getId() const;
	string getDescript() const;
	int getTicks() const;
	int getProc() const;

	void setId(int newId);
	void setDescript(string newDescript);
	void setTicks(int newTick);
	void setProc(int newProc);



private:
	int jobId;
	string jobDescript;
	int ticks;
	int proc;
};


