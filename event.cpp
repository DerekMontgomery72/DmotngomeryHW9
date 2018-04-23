#include "event.h"

Job::Job()
{
	this->jobId = -1;
	this->jobDescript = "null";
	this->ticks = 0;
	this->proc = 0;
}

Job::Job(int jobId, string descript, int nticks, int nproc)
{
	this->jobId = jobId;
	this->jobDescript = descript;
	this->ticks = nticks;
	this->proc = nproc;

}

Job::Job(const Job & copy)
{
	this->jobId = copy.getId();
	this->jobDescript = copy.getDescript();
	this->ticks = copy.getTicks();
	this->proc = copy.getProc();
}

Job::~Job()
{
	// Nothing Needed in here right now
}

void Job::operator=(const Job & j1)
{
	this->jobId = j1.getId();
	this->jobDescript = j1.getDescript();
	this->ticks = j1.getTicks();
	this->proc = j1.getProc();
}

int Job::getId() const
{
	return this->jobId;
}

string Job::getDescript() const
{
	return this->jobDescript;
}

int Job::getTicks() const
{
	return this->ticks;
}

int Job::getProc() const
{
	return this->proc;
}

void Job::setId(int newId)
{
	this->jobId = newId;
}

void Job::setDescript(string newDescript)
{
	this->jobDescript = newDescript;
}

void Job::setTicks(int newTick)
{
	this->ticks = newTick;
}

void Job::setProc(int newProc)
{
	this->proc = newProc;
}

bool operator>(const Job & j1, const Job & j2)
{
	return (j1.getTicks() > j2.getTicks());
}

bool operator<(const Job & j1, const Job & j2)
{
	return (j1.getTicks() < j2.getTicks());
}

bool operator==(const Job & j1, const Job & j2)
{
	return (j1.getTicks() == j2.getTicks());
}
