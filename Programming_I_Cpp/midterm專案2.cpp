#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	int s[10][2] = {0};//存放分數區間 
	char g[10][1] = {0};//存放等第 
	int x = 0;
	int score = 0;
	char G = 0;
	cin >> n;
	for(int i = 0;i <n;i++)
	{
		for(int j = 0;j <3;j++)
			if(j != 2)
				cin >> s[i][j];
			else
				cin >> g[i][0];
	}
	cin >> x;
	if(x == 0)
	{
		cin >> score;
		for(int i = 0;i <n;i++)
		{
			if(score >= s[i][0] && score <= s[i][1])
			{
				cout << g[i][0];
				return 0;
			}	
		}
	}
	else
	{
		cin >> G;
		for(int i = 0;i <n;i++)
		{
			if(G == g[i][0])
			{
				cout << (s[i][0] + s[i][1] + 1)/2;
				return 0;
			}
		}
	}
}
