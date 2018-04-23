#pragma once
#include<iostream>
#include<string>

using namespace std;

class Job {
public:
	Job();
	Job(int jobId, string descript, int nticks, int nproc);
	Job( const Job &copy);
	~Job();

	friend bool operator>(const Job&j1, const Job&j2);
	friend bool operator<(const Job&j1, const Job&j2);
	friend bool operator==(const Job&j1, const Job&j2);
	void operator=(const Job& j1);

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

class myComparator {
	int operator() (const Job &j1, const Job &j2) {
		return j1.getTicks() > j2.getTicks();
	}
};

