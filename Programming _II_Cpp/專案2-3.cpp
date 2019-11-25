#include <iostream>

using namespace std;

class RecyclingVector
{
	private:
		char name;
		int n;
		int *m;
	public:
		char getname()
		{
			return this->name; 
		}
		int getnum()
		{
			return this->n;
		}
		void set(const char);//assignment
		
		void set_no_cin(const char);
		
		void change(const int,const int);//while 'I'
		
		void print();//for test
		
		RecyclingVector():n(0),m(NULL)
		{
		}
		RecyclingVector(int n, double m[])
		{
		  this->n = n;
		  this->m = new int[n];
		  for(int i = 0; i < n; i++)
		    this->m[i] = m[i];
		}
		RecyclingVector(const RecyclingVector& v)
		{
		  this->n = v.n;
		  this->m = new int[n];
		  for(int i = 0; i < n; i++)
		    this->m[i] = v.m[i];	
		}
		RecyclingVector(int n, const RecyclingVector& v)
		{
			this->n = n;
			this->m = new int[n];
			for(int i = 1; i < v.n + 1;i++)
			{
				this->m[i] = v.m[i%(v.n)];
			}
		}
		~RecyclingVector()
		{ 
		  delete [] m;
		}
	
  		int& operator[](const int index);
		bool operator==(const RecyclingVector);
		bool operator> (const RecyclingVector);
		bool operator< (const RecyclingVector);
		void operator= (const RecyclingVector);
		const RecyclingVector operator+(const RecyclingVector);
		const RecyclingVector operator-(const RecyclingVector);
};
// end of class definition of RecyclingVector


// RecyclingVector's instance functions
void RecyclingVector::change(const int site,const int change_to)
{
	this->m[site] = change_to;
}
void RecyclingVector::set(const char a)
{
	this -> name = a;
	cin >> this -> n;
	this -> m = new int[this -> n];
	for(int i = 0;i < n;i++)
		cin >> this -> m[i];
}
void RecyclingVector::set_no_cin(const char a)
{
	this->name = a;
	this->n = 0;
	this->m = NULL;
} 
void RecyclingVector::print()
{
	cout << "\n" << this->name << " " << this->n << " ";
	for(int k = 0;k < this->n ;k++)
	{
		cout << this->m[k] << " ";
	}
}

// end of REcyclingVector's instance functions

// RecyclingVector's overloaded operators

int& RecyclingVector::operator[](const int index)
{
    return this->m[index - 1];
}

bool RecyclingVector::operator==(const RecyclingVector right)
{
	int dim = this->n;
	if(right.n > this->n)
		dim = right.n;
	for(int i = 0;i < dim;i++)
		if(this->m[i % this->n] != right.m[i % right.n])//recycle the number to the longer dimension
			return false;
	return true;
}
bool RecyclingVector::operator> (const RecyclingVector right)
{
	int dim = this->n;
	if(right.n > this->n)
		dim = right.n;
	for(int i = 0;i < dim;i++)
		if(this->m[i % this->n] <= right.m[i % right.n])
			return false;
	return true;
}
bool RecyclingVector::operator< (const RecyclingVector right)
{
	int dim = this->n;
	if(right.n > this->n)
		dim = right.n;
	for(int i = 0;i < dim;i++)
		if(this->m[i % this->n] >= right.m[i % right.n])
			return false;
	return true;
}
void RecyclingVector::operator= (const RecyclingVector right)
{
	if(this->n != right.n)
		delete [] this->m;
	this->n = right.n;
	this->m = new  int[this->n];
	for(int i = 0;i < n;i++)
		this->m[i] = right.m[i];
}


const RecyclingVector RecyclingVector::operator+(const RecyclingVector right)
{
    RecyclingVector answer;
    answer.n = this->n;
    if(right.n > answer.n)
    	answer.n = right.n;
    answer.m = new int[answer.n];
    for(int i = 0; i < answer.n; i++)
    {
        answer.m[i] = this->m[i % this->n] + right.m[i % right.n];
    }
    return answer;
}
const RecyclingVector RecyclingVector::operator-(const RecyclingVector right)
{
    RecyclingVector answer;
    answer.n = this->n;
    if(right.n > answer.n)
    	answer.n = right.n;
    answer.m = new int[answer.n];
    for(int i = 0; i < answer.n; i++)
    {
        answer.m[i] = this->m[i % this->n] - right.m[i % right.n];
    }
    return answer;
}

// end of MyVector's overloaded operators

RecyclingVector my[26];

int main()
{
	char command = 0;//the first char
	int count = 0;//my[count]
	while(cin >> command)
	{
		if(command == 'N')//new
		{
			char nn;
			cin >> nn;
			my[count].set(nn);
		//	my[count].print();//
			count++;
		}
		else if(command == 'A')//assignment
		{
			char nn;
			RecyclingVector temp;
			cin >> nn;
			temp.set(nn);
			for(int i = 0;i <count;i++)
				if(nn == my[i].getname())
				{
					my[i] = temp;
					//cout << i << " ";//
				//	my[i].print();//
					break;
				}
		}
	    else if(command == 'M' || command == 'S')
	    {
	    	int sum = 0;
			int site = 0;
            RecyclingVector temp;
            bool exist = false;
            char nn = 0;
            cin >> sum >> nn;
            char* tobe = new char[sum - 1];
            for(int i = 0; i < sum - 1; i++)
            {
                cin >> tobe[i];
               // cout << "names[" << i << "] == " << tobe[i] << "\n";//
            }
            //cout << count;//
            for(int i = 0;i < count;i++)
            {
            	
            	if(nn == my[i].getname())
            	{
            	//	cout << "aa";//
            		site = i;
            		exist = true;
            		break;
				}
			}
		//	cout << exist << "\n";//
			if(exist == false)
			{
			//	cout << "bb";//
				my[count].set_no_cin(nn);
			//	cout << my[count].getname();//
				site = count;
	            
			}
		//	cout << site <<" ";//
		//	my[site].print();//
			for(int j = 0;j < count;j++)
	                 {
	                 	if(my[j].getname() == tobe[0])
	                 	{
	                 	//	cout << "if";//
	                 	//	temp.print();//
	                 		temp = my[j];
	                 	//	temp.print();//
	                 		break;
						}
					 }
			 if(command == 'S')
			 {
			 	for(int i = 1; i < sum - 1; i++)
	                {
	                    for(int j = 0; j < count; j++)
	                    {
	                        if(my[j].getname() == tobe[i])
	                        {
	                          //  my[j].print();//
	                            temp = temp + my[j];
	                           // cout << "\n answer: ";//
	                          //  temp.print();//
	                        }
	                    }
	                }
			 }
			 else if(command == 'M')
			 {
			 	for(int i = 1; i < sum - 1; i++)
	                {
	                    for(int j = 0; j < count; j++)
	                    {
	                        if(my[j].getname() == tobe[i])
	                        {
	                         //   my[j].print();//
	                            temp = temp - my[j];
	                         //   cout << "\n answer: ";//
	                        //    temp.print();//
	                        }
	                    }
	                }
			 }
			if(exist == false)
	            count++;
			my[site] = temp;
	            //my[site].print();//
		}
		
		else if(command == 'I')
		{
			char nn;
			cin >> nn;
			int site = 0;
			int change_to = 0;
			cin >> site >> change_to;
			for(int i = 0;i < count;i++)
			{
				if(nn == my[i].getname())
				{
					my[i].change(site,change_to);
				//	my[i].print();//
					break;
				}				
			}
		}
		else if(command == 'C')
		{
			//cout << "compare ";//
			char command2;
			char compare,comparee;
			int comparenum[2]= {0};
			cin >> command2 >> compare >> comparee;
			for(int i = 0;i < count;i++)
				if(compare == my[i].getname())
				{
					comparenum[0] = i;
					for(int j = 0;j < count;j++)
						if(comparee == my[j].getname())
							comparenum[1] = j;
				}
			//my[comparenum[0]].print();//
			//my[comparenum[1]].print();//
			if(command2 == 'L')
			{
				cout << (my[comparenum[0]] < my[comparenum[1]]) << "\n";
			}
			else if(command2 == 'G')
			{
				cout << (my[comparenum[0]] > my[comparenum[1]]) << "\n";
			}
			else if(command2 == 'E')
			{
				cout << (my[comparenum[0]] == my[comparenum[1]]) << "\n";
			}
		}
	}
	return 0;
}
