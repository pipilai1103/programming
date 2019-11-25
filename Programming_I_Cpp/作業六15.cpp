#include <iostream>

using namespace std;

int main()
{
	int ssCnt = 0,eleCnt = 0;
	cin >> ssCnt >> eleCnt;
	int sum[25] = {0};
	int num[25][100] = {0};
	char name[25] = {0};
	float cost[25] = {0};
	for(int i = 0;i < ssCnt;i++)
	{
		cin >> sum[i];
		for(int j = 0;j < sum[i];j++)
			cin >> num[i][j];
	}
	for(int i = 0;i < ssCnt;i++)
		cin >> name[i];
	for(int i = 0;i < ssCnt;i++)
		cin >> cost[i];
	bool cover[25][100] = {0};
	for(int i = 0;i < ssCnt;i++)
		for(int j = 0;j < sum[i];j++)
			for(int k = 0;k < eleCnt;k++)
				if(num[i][j] == k + 1)
					cover[i][k] = 1;
	
	float score[25] = {0};
	
	while(true)
	{
		for(int i = 0;i < ssCnt;i++)
		{
			if(sum[i] != 0)
				score[i] = cost[i] / sum[i];
		}
		float choose = 0;
		for(int i = 0;i < ssCnt;i++)
		{
			
			if(score[i]!= 0)
			{
				choose = score[i];
				break;
			}
		}
		for(int i = 0;i < ssCnt;i++)
		{
			if(score[i] != 0 && score[i] < choose)
				choose = score[i];
		}
		
		for(int i = 0;i < ssCnt;i++)
			if(choose == score[i])
			{
				for(int l = 0;l < ssCnt;l++)
					if(score[l] == choose && name[l] < name[i])
					{
						name[i] = name[l];
						break;
					}
				cout << name[i];
				score[i] = 0;
				for(int j = 0;j < eleCnt;j++)
					if(cover[i][j] != 0)
						for(int k = 0;k < ssCnt;k++)
							cover[k][j] = 0;
				break;
			}
		int a = 0;
		for(int i = 0;i < ssCnt;i++)
			for(int j = 0;j < eleCnt;j++)
			{
				if(cover[i][j] != 0)
					a++;
			}	
		if(a == 0)
			return 0;
		else
			cout << " ";
		for(int i = 0;i < ssCnt;i++)
		{
			sum[i] = 0;
			for(int j = 0;j < eleCnt;j++)
				sum[i] += cover[i][j];
			if(sum[i] == 0)
				score[i] = 0;
		}
		
	}
	return 0;
}
