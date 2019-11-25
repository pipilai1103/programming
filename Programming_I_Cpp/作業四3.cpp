#include <iostream>

using namespace std;

int main()
{
	int S = 0,co = 0,cu = 0,I = 0,n = 0,q = 0;
	int o = 0, u = 0,a = 0,min = 0;//o為存貨成本，u為缺貨成本
	cin >> S >> co >> cu >> I >> n;
	int x[1000] = {0};
	for(int m = 0;m < n;m++)
		cin >> x[m];
	for(int s = 0;s < S;s++)
	{
		int N = 0,i = 0,Q = 0;
		N = n;
		i = I;
		Q = q;
		for(int m = 0;m < N;m++)
		{
			i = i - x[m] +Q;
			if(i > s)
			{
				o = o + i * co;
				Q = 0;
			}
			else
			{
				Q = S - i;
				if(i < 0)
					u = u - i * cu;
				if(i > 0)
					o = o + i * co;
			}
		}
		if(s == 0)
			min = o + u;
		else if(o + u < min)
		{
			a = s;
			min = o + u;
		}
		o = 0;
		u = 0;
	}
	cout << a << " " << min;
	return 0;
}
