#ifndef __PROC_H__
#define __PORC_H__

#include "queue.h"
#include <time.h>
#include <iostream>

using namespace std;

struct Task 
{
	int cors;
};

struct Statistics 
{
	int taskNum;
	int taskRejected;
	double taskRejectedProc() { return ((double)taskRejected / (double)taskNum); }
	int taskSleep;
	double taskSleepProc() { return ((double)taskSleep / (double)taskNum); }
};


class TProc
{
  TQueue<Task> queue;
  int corsNum;
public:
  TProc(int queueSize, int coreNums) : queue(queueSize),corsNum(coreNums) {}
  Statistics Run(double q1, double q2, int time);
};

#endif
