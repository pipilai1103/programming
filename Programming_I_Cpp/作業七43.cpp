#include <iostream>
using namespace std;

void hanoi(char from, char via, 
           char to, int disc,int i,int &s)
{

	if(disc == 1)
	{
		s++;
		if(s == i)
	    {
	    	cout << "Disc 1 from " << from << " to " << to ;
	       	exit(0);
		}
	}
	else
	{
		hanoi(from, to, via, disc - 1,i,s);
	    s++;
	    if(s == i)
	    {
	    	cout << "Disc " << disc << " from " << from << " to " << to ;
	       	exit(0);
		}
	    hanoi(via, from, to, disc - 1,i,s);
	    
	}
}

int main()
{
  int disc = 0; // number of discs
  int i = 0;
	int s = 0;
  cin >> disc >> i;
  char a = 'A', b = 'B', c = 'C';
    
  hanoi(a, b, c, disc,i,s);
    
  return 0;
}
