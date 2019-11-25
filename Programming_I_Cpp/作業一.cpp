#include <iostream >
using namespace std;
int main()
{
	int num1 = 0, num2 = 0;
	while(true)
	{
		cout << "Please enter two numbers , "
		<< "separated by a white space: ";
		
		cin >> num1 >> num2;
		
		if(num1 > num2)
		cout << "The larger one is " << num1;
		
		if(num1 < num2)
		cout << "The larger one is " << num2;
		
		if(num1 == num2)
		{
			cout << "The two are equal";
			return 0;
		}
	}	
}
