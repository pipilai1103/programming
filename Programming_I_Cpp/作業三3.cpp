#include <iostream>

using namespace std;

int main()
{
	int S = 0,s = 0,co = 0,cu = 0,I = 0,n = 0,x = 0,q = 0;
	int o = 0, u = 0,a = 0;//o為存貨成本，u為缺貨成本 ，a為缺貨日數 
	cin >> S >> s >> co >> cu >> I >> n;
	for(;n > 0;--n)
	{
		cin >> x;
		I = I - x + q;
		if(I > s)
		{
			o = o + I * co;
			q = 0;
		}
		else
		{
			q = S - I;
			if(I < 0)
			{
				u = u - I * cu;
				a++;
			}
			if(I > 0)
				o = o + I * co;

		}
	}
	cout << a << " " << o + u;
	return 0;
}
