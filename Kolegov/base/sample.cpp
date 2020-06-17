#include "proc.h"
#include <string>

using namespace std;

int main()
{
	string time;
	string queue = "";
	string q1 = "";
	string q2 = "";
	string cores = "";

	//setlocale(LC_ALL, "Russian");


	cout << "Tacts count: ";
	cin >> time;
	cout << "Queue size: ";
	cin >> queue;
	cout << "Task intensity: ";
	cin >> q1;
	cout << "Proc power: ";
	cin >> q2;
	cout << "Cores count: ";
	cin >> cores;

	TProc p(stoi(queue),stoi(cores));
	auto s = p.Run(stod(q1.c_str()), stod(q2.c_str()), stoi(time));

	cout << "\n";
	cout << "Task count " << s.taskNum << endl;
	cout << "Task rejected " << s.taskRejected << " or " << s.taskRejectedProc() << "% " << endl;
	cout << "Sleep time " << s.taskSleep << " or " << s.taskSleepProc() << "% " << endl;

	system("pause");

	return 0;
}
