#include <iostream>

using namespace std;

int main()
{
	int a = 0,b = 0;
	cin >> a >> b;
	int x,y,c;
	x = a,y = b;
	while(x != 0 || y != 0)
	{
		if(x < y)
			y =  y - x;
		else
			x = x - y;
	}
		if(x == 0)
			a < b ? x = a : x = b;
		if(y == 0)
			a < b ? y = a : y = b;
	while(x != 0 && y != 0)
	{
		if(x < y)
			y =  y - x;
		else
			x = x - y;
	}
	if(x == 0||y == 0)
	{
		x == 0 ? c = y : c = x;
		if(c == 1)
		{ 
			cout << "0";
			return 0;
		}
		else
		{
			cout << "1";
			return 0;
		}
	}
}
