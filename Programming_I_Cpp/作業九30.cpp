#include <iostream>
using namespace std;
int main ()
{
	int  N = 0,m = 0,K = 0;//�����A�}�񨮡A������� 
		cin >> N >> m >> K;
	int* n = new int[N];//���[
	int* y = new int[m];//���ɻP�_
	int* z = new int[m];//���ݨ���
	int* u = new int[K];//���s
	int* t = new int[K];//������A
	int* sum = new int[N];//�����C�Ө��������� 
	

	
	for(int i = 0;i < N;i++)
		sum[i] = 0;
	
	for(int i = 0;i < N;i++)
		cin >> n[i];
		
	for(int i = 0;i < m;i++)
		cin >> y[i];
		
	for(int i = 0;i < m;i++)
		cin >> z[i];
		
	for(int i = 0;i < K;i++)
	{
		cin >> u[i] >> t[i];//t=0��ܭɨ��A���M�N�O���b�Y����
		if(t[i] == 0)
			y[u[i] - 1] = 1;
		else
		{
			y[u[i] - 1] = 0;
			z[u[i] - 1] = t[i];
		}
	}
	for(int i = 0;i < m;i++)
	{
		if(y[i] == 0)
		{
			sum[z[i] - 1]++;
		}
	}	
	for(int i = 0;i < N;i++)
	{
		cout << sum[i] << ":";
		if(sum[i] == 0)
		{
			cout << "\n";
		}
		else
		{
			for(int j = 0;j < m;j++)
			{
				if(y[j] == 0 && z[j] == i + 1)
				{
					cout << j + 1;
					sum[i]--;
					if(sum[i] == 0)
					{
						cout << "\n";
						break;
					}
					else
					cout << " ";
				}
			}
		}
	}

	return 0;
}
