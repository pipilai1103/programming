#include <iostream>
#include <algorithm> 

using namespace std;

struct Work 
{
	int num;
	int time;
	int benefit;
	int who; 
};
struct Worker
{
	int sumBen;
	int sumTime;	
}; 


int main()
{
	int job = 0,worker = 0,limit = 0;
	cin >> job >> worker >> limit;
	 
	Work*    mission = new Work      [job]; 
	Worker* employee = new Worker [worker]; 
	
	for(int i = 0;i < job;i++)
		mission [i]. num = i + 1;
	for(int i = 0;i < job;i++)
		cin >> mission [i]. time;
	for(int i = 0;i < job;i++)
		cin >> mission [i]. benefit;
	for(int i = 0;i < job;i++)
		mission [i]. who = 0;
	for(int i = 0;i < worker;i++)
	{
		employee [i]. sumBen  = 0;
		employee [i]. sumTime = 0;
	}
	
	//sorting
	for (int i = job - 1; i > 0; --i)
		for (int j = 0; j < i; ++j)
		{
        	if (mission [j].benefit < mission [j + 1]. benefit)
			{
				swap(mission [j].benefit,mission [j + 1]. benefit),
				swap(mission [j].num    ,mission [j + 1]. num    ),
				swap(mission [j].time   ,mission [j + 1]. time   );  
			}
			else if (mission [j].benefit == mission [j + 1]. benefit && 
					mission [j].time > mission [j + 1]. time)
			{
				swap(mission [j].num    ,mission [j + 1]. num    ),
				swap(mission [j].time   ,mission [j + 1]. time   );  
			}
		}
	
	
	for(int i = 0;i < job;i++)
	{

		int minBen  = 10000;
		int maxTime = 0;
		int rec     = -1;
		 
		for(int j = 0;j < worker;j++)
			if(employee [j].sumTime + mission [i].time <= limit)
			{
				if(employee [j].sumBen < minBen)
				{
					minBen  = employee [j].sumBen;
					maxTime = employee [j].sumTime;
					rec = j;
				}
				else if(employee [j]. sumBen == minBen && employee [j]. sumTime > maxTime)
				{
					minBen  = employee [j].  sumBen;
					maxTime = employee [j]. sumTime;
					rec = j;
				}
			}
				
		if(rec == -1)// 
			mission [i].who = 0; // 
		else
		{ 
			mission [i].who = rec + 1;
			employee [rec]. sumBen  += mission [i].benefit;
			employee [rec]. sumTime += mission [i].time;
		}
	}
	int minBen = employee[0]. sumBen;
	for(int i = 1;i < worker;i++)
		if(employee [i].sumBen < minBen)
			minBen = employee [i]. sumBen;
			
	//cout
	for(int i = 0;i < job - 1;i++)	
		cout << mission [i].num << " ";
	cout <<  mission [job - 1].num << "\n";
	
	for(int i = 0;i < job - 1;i++)	
		cout << mission [i].who << " ";
	cout <<  mission [job - 1].who << "\n";
	
	cout << minBen;
			
		
	return 0;
}
