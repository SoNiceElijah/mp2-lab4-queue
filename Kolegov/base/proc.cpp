#include "proc.h"


Statistics TProc::Run(double q1, double q2, int runTime)
{
	Statistics stat;

	stat.taskNum = 0;
	stat.taskRejected = 0;
	stat.taskSleep = 0;

	int coreState = corsNum;
	srand(time(NULL));

	for (int tact = 0; tact < runTime; tact++) 
	{

		//Generate task
		double chance = ((double)rand() / (RAND_MAX));
		if (chance < q1)
		{
			try {
				Task t;
				t.cors = rand() % corsNum;
				queue.Push(t);
			}
			catch (char* ex)
			{
				if (ex == "Queue full")
					stat.taskRejected++;
			}
		}

		//Free cores
		for (int i = 0; i < corsNum - coreState; i++)
		{
			chance = ((double)rand() / (RAND_MAX));
			if (chance < q2)
				coreState++;
		}

		//FetchTasks
		try
		{
			while (coreState - queue.Check().cors >= 0)
			{
				coreState -= queue.Shift().cors;
				stat.taskNum++;
			}
		}
		catch (char* ex)
		{
			if (ex == "Queue empty")
				stat.taskSleep++;
		}

	}

	return stat;
}