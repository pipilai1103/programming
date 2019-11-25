#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float n = 0;
	float k = 0;
	float x [100] = {0};
	float sum = 0;
	float avr = 0;
	int sigmaa = 0;
	float var = 0;
	int ans [100] = {0};
	
	cin >> n >> k;
	for(int i = 0;i < n;i++)
	{
		cin >> x [i];
		sum += x[i];
	}
	avr = sum / n;
	sum = 0;
	for(int i = 0;i < n;i++)
	{
		sum += (pow(x[i] - avr,2));
	}
	var = sum / n;
	sigmaa = (pow(var,0.5)) * k;
	

	int cnt = 0;
	for(int i = 0;i < n;i++)
	{
		if(x [i] > avr + sigmaa || x [i] < avr - sigmaa)
		{
			ans[cnt] = x [i];
			cnt++;
		}
	}

	if(cnt == 0)
	{
		cout << "-1";
		return 0;
	}
	
	for(int i = 0;i < cnt - 1;i++)
		for(int j = 0;j < cnt - i - 1;j++)
			if (ans[j] > ans[j + 1])
			{
				int temp;
				temp = ans[j];
                ans[j] = ans[j + 1];
                ans[j + 1] = temp;
			}
	for(int i = 0;i < cnt - 1;i++)
		cout << ans [i] << " ";
	cout << ans [cnt - 1];
	
	return 0;
}
