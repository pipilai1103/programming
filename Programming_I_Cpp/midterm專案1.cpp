#include <iostream>

using namespace std;

int main()
{
	int n = 0,y = 0,z = 0;
	cin >> n >> y >> z;
	int x[100] = {0};
	int b = 0,c = 0;
	for(int a = 0;a < n;a++)
	{
		cin >> x[a];
		if(x[a] >  y && x[a] < z)
			b++;
	}
	if(b == 0)
	{
		cout <<	0;
		return 0;
	}
	for(int a = 0;a < n;a++)
	{
		if(x[a] >  y && x[a] < z)
		{
			cout << x[a];
			c++;
			if(c < b)
				cout << " ";
		}
	}
	return 0;
}
