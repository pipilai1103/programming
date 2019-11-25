#include <iostream>
using namespace std;

int main()
{
	int n = 0,m = 0,B = 0;
	int num[100] = {0};
	int c[100] = {0};
	int s[100] = {0};
	int con [5000][2] = {0}; 
	cin >> n >> m >> B;
	for(int i = 0;i < n;i++)
		cin >> c [i];
	for(int i = 0;i < n;i++)
		cin >> s [i];
	for(int i = 0;i < m;i++)
		cin >> con[i][0] >> con[i][1];
	for(int i = 0;i < n;i++)
		num[i] = i + 1;
	
	int cho = c[0];
		int a = 0;
		for(int i = 0;i < n;i++)
		{
			if(c[i] > cho)
			{
				cho = c[i];
				a = i;
			}
		}
		if(B < s[a])
		{
			c[a] = 0;
		}
		else
		{
			cout << num[a];
			B -= s[a];
			c[a] = 0;
		}
	for(int i = 0;i < m;i++)
	{
	
			if(num [a]== con[i][0])
			{
				c[con[i][1]] = 0;
			}
			if(num [a]== con[i][1])
			{
				c[con[i][0]] = 0;
			}
	}
	int cnt = 0;
	while(true)
	{
		int cho = c[0];
		int a = 0;
		if(cnt == n)
			return 0;
		for(int i = 0;i < n;i++)
		{
			if(c[i] > cho)
			{
				cho = c[i];
				a = i;
			}
		}
		if(B < s[a])
		{
			c[a] = 0;
			cnt++;
		}
			
		else
		{
			cout << " " << num[a];
			B -= s[a];
			c[a] = 0;
			cnt++;
		}
			for(int i = 0;i < m;i++)
	{
	
			if(num [a]== con[i][0])
			{
				c[con[i][1]] = 0;
			}
			if(num [a]== con[i][1])
			{
				c[con[i][0]] = 0;
			}
	}
		
	}
	return 0;
}
