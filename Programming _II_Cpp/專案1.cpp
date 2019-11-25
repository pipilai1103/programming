#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

void input_int();
void check_int();
//void reverse();

class BigInt
{
private:
	string name;
	string value;
	
public:
	BigInt();
	~BigInt();
	string get_name()
	{
		return name;
	}
	string get_value()
	{
		return value;
	}
	void operator=(const BigInt right)
	{
		this -> value = right.value;
	}
	string abs(const BigInt right)
	{
		string answer;
		answer = right.value;
		if(answer.at(0) == '-')
			answer.erase(0, 1);
		return answer;
	}
	string inverse(const BigInt right)
	{
		string answer;
		answer = right.value;
		if(right.value.at(0) == '-')
			answer.erase(0, 1);
		else
			answer = "-" + answer;
		return answer;
	}
	const BigInt operator+(const BigInt right)const
	{
		int str1[100] = {0};
		int str2[100] = {0};
		for(int i = 0;i < this -> value.size() ;i++)
		{
			str1[i] = this -> value[this -> value.size() - i - 1] - '0';
		}
		for(int i = 0;i < right.value.size() ;i++)
		{
			str2[i] = right.value[right.value.size() - i - 1] - '0';
		}
		int sho = 0;
		int lon = 0;
		int answer[101] = {0};
		if(this -> value.size() > right.value.size())
		{
			sho = right.value.size();
			lon = this -> value.size();
			for(int i = sho;i < lon;i++)
				str2[i] = 0;
		}
		else if(this -> value.size() < right.value.size())
		{
			sho = this ->value.size();
			lon = right.value.size();
			for(int i = sho;i < lon;i++)
				str1[i]= 0;
		}
		for(int i = 0;i < lon;i++)
		{
			answer[i] = str1[i] + str2[i];
			if(answer[i] > 9)
			{
				answer[i] += (-10);
				answer[i + 1] += 1;
			}
		}
		
	}
	
	//friend ostream& operator<<(ostream& os, const BigInt);
};

/*ostream& operator<<(ostream& os, const BigInt output)
{
	os << output.value << "\n";
	return os;
}*/

int main()
{
	int cnt = 0;
	string trash;
	BigInt* no = new BigInt [20];
	while(1)
	{
		string first;
		cin >> first;
		if(first == "cout")
			print_int();
		else if(first == "int")
			input_int();
		else
			check_int();
	}
/*	string input;
	while(getline(cin, input, '\n'))
	{
		if(input.find("int") != string::npos)
			input_int(imput);
	}
	char** name = new char[20];
	char** num  = new char[20];
	for(int i = 0;i < 20;i++)
	{
		name[i] = new char[10];
		num [i] = new char[100];
	}
	
	if(input == "int")
		input_int();*/
}
void print_int()
{
	string shit;
	getline(cin, shit, '\n');
	if(shit.find("abs") != string::npos)
	{
		for(int i = 0;i < cnt + 1;i++)
				if(no[i].name == shit(shit.find(">>")+2))
				{
					cout >> string abs(no[i]);
					break;
				}
	}
	if()
}
void input_int()
{
	cin >> no[cnt].get_name >> trash >> no[cnt].get_value;	
	no[cnt].value = no[cnt].value.substr(0,no[cnt].value.size() - 1);
/*	char inputchar[150];
	int cnt = 0;
	strcpy(inputchar[cnt], input.c_str());
	for(int i = 0;i < input.find("=") - 5;i++)
		name[cnt][i]= inputchar[i + 4];
	for(int i = input.find("=") + 2;i < input.find(";");i++)
		value[cnt][i] = */	
	cnt++;
}
void check_int()
{
	string buzz;
	getline(cin, buzz, '\n');
	if(buzz.find("= -") != string::npos)
	{
		for(int i = 0;i < cnt + 1;i++)
			for(int j = 0;j < cnt + 1;j++)
				if(no[i].name == buzz(buzz.find('=')+2) && no[j].name == first)
				{
					no[j].value = string inverse(no[i]);
					break;
				}
	}
	else if(buzz.find("abs") != string::npos)
	{
		for(int i = 0;i < cnt + 1;i++)
			for(int j = 0;j < cnt + 1;j++)
				if(no[i].name == buzz(buzz.find('=')+2) && no[j].name == first)
				{
					no[j].value = string abs(no[i]);
					break;
				}
	}
/*	if     (buzz.find('+') != string::npos)
		//pluss();
	else if(buzz.find('-') != string::npos && buzz.find("= -") == string::npos)
		//minuss();
	else if(buzz.find('*') != string::npos)
		//multii();
	else if(buzz.find('/') != string::npos)
		//divv();
	else if(buzz.find('%') != string::npos)
		//remainn();
	else if(buzz.find("square") != string::npos)
		//squaree();*/
	
}

