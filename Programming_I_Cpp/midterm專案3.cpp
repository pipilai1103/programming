#include <iostream>

using namespace std;

int main()
{
	int n = 0,m = 0;
	cin >> n >> m;
	int know[2500][2] = {0};
	int p[50][3] = {0};//�Ĥ@��s�s���A�ĤG��s�Q�X�ӤH�{�ѡA�ĤT��s�{�ѴX�ӤH 
	int x = 0,y = 0;//x���Q�̦h�H�{�Ѫ��H�O�Q�h�֤H�{�ѡAy���{�ѳ̦h�H���H�{�Ѧh�֤H
	
	for(int i = 0;i < m;i++)
		for(int j = 0;j < 2;j++)
		cin >> know[i][j];
	for(int i = 0;i < n;i++)
		p[i][0] = i + 1;
	for(int i = 0;i < m;i++)
		for(int a = 0;a <n;a++)
		{
			if(know[i][1] == p[a][0])
				p[a][1]++;
			if(know[i][0] == p[a][0])
				p[a][2]++;
		}
		
	x = p[0][1];
	y = p[0][2];
	for(int a = 0;a <n;a++)
	{
		
		if(p[a][1] > x)
			x = p[a][1];
		if(p[a][2] > y)
			y = p[a][2];
	}
	cout << x << " " << y;
	return 0;
}
