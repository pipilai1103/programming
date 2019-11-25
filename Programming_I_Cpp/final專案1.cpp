#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n = 0;
	int num [50] = {0};
	int ans [50] = {0};
	int cnt = 0;
	cin >> n;
	
	for(int i = 0;i < n;i++)
		cin >> num[i];
	if(n == 1 || n == 2)
		{
			cout <<"0";
			return 0;
		}
	for(int i = 0;i < n;i++)
	{
		for(int j = i + 1;j < n;j++)
			for(int k = i + 2;k < n;k++)
				if(pow(num[i],2) + pow(num[j],2) == pow(num[k],2))
				{
					ans[cnt*3] = num [i];
					ans[cnt*3 + 1] = num [j];
					ans[cnt*3 + 2] = num [k];
					cnt += 1;
				}
	}
	cout << cnt;
	if(cnt == 0)
		return 0;
	else
		cout << " " << ans[0];
	
	

	return 0;
}
