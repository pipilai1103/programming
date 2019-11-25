#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	int d[100] = {0};//截止時間 
	int p[100] = {0};//處理時間 
	int w[100] = {0};//工作順序 
	int c[100] = {0};//完成時間 
	int s1 = 0,s2 = 0; 
	int delay = 0;
	int t = 0;
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> d[i];
	for(int i = 0;i < n;i++)
		cin >> p[i];
	for(int i = 0;i < n;i++)
		cin >> w[i];
	cin >> s1 >> s2;

		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				if(w[i] == j + 1)
				{
					if(i == 0)
						c[i] = p[j];
					else
						c[i] = p[j] + c[i - 1];
				}
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				if(w[i] == j + 1)
					if(c[i] > d[j])
						delay++;
		cout << delay;
		
	
}
