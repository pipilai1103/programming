#include <iostream>

using namespace std;

int main()
{
	int m = 0,n = 0,k = 0,h = 0;
	cin >> m >> n >> k >> h;
	int B[100][100] = {0};
	int c[100] = {0};
	int L[2][100] = {0}; 
	int t0 = 0,t = 0;//º»¶s≈‹º∆ 
	
	for(int i = 0;i < m;i++)
		for(int j = 0;j < n;j++)
		{
			cin >> B[i][j];
			if(B[i][j] != 0)
				c[i]++;
		}
		
	for(int s = 0;s < h;s++)
	{
		cin >> L[0][s];
		for(int i = 0;i < m;i++)
			if(i + 1 == L[0][s])
			{
				for(int j = 0;j < n;j++)
					L[1][s] += B[i][j];
				L[1][s] =L[1][s]-k * c[i];
			}
	}
					
	for(int i = 1;i < h;i++)
		for(int j = 0;j < h - i;j++)
		{
			if(L[1][j + 1] > L[1][j])
			{
				t = L[1][j],t0 = L[0][j];
				L[1][j] = L[1][j + 1],L[0][j] = L[0][j + 1];
				L[1][j + 1] = t,L[0][j + 1] = t0;
			}
			else if(L[1][j + 1] == L[1][j] && L[0][j + 1] < L[0][j])
			{
				t0 = L[0][j];
				L[0][j] = L[0][j + 1];
				L[0][j + 1] = t0;
			}		
		}
		
	if(h >= 3)
	{
		cout << L[0][0] <<" " << L[0][1] << " " << L[0][2];
		return 0;
	}
	else if(h == 2)
	{
		cout << L[0][0] << " " << L[0][1];
		return 0;
	}
	else if(h == 1)
	{
		cout << L[0][0];
		return 0;
	}
}
