#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

class car
{
	private:
		string plate;//車牌  
		char type;
		int tagnum;//屬性總數
		string* cartag;//屬性 
		int status;//狀態 
		int x,y;//位置 
		string direction;//方向 
		int gradecnt;//總被評分次數 
		int grade;//總得分 
		int hr,mn;//時間 
	public:
		car()//:plate(0),tagnum(0),status(0),gradecnt(0),grade(0),hr(0),mn(0)
		{
			status = 0;
			cartag = new string[30];
			gradecnt = 9;
			grade = 0;
			hr = 0;
			mn = 0;
			x = 0;
			y = 0;
		}
		~car()
		{
		}
		string getplate()
		{
			return plate;
		}
		int getstatus()
		{
			return status;
		}
		char gettype()
		{
			return type;
		}
		int getx()
		{
			return x;
		}
		int gety()
		{
			return y;
		}
		void setplate(string &temp)
		{
			this->plate = temp;
		}
		void empty()
		{
			this->status = 1;
		}
		void NC(string,char);
		void OC(string,string);
		bool operator==(const string);
		int distance(int,int);
		
};

int car::distance(int x,int y)
{
	int d = abs(this->x - x) + abs(this->y - y);
	return d;
}
void car::NC(string temp,char type)
{
	this->type = type;
	//cout << this->type << '\n';//
	if(temp == "()")
	{
		this->tagnum = 0;
		exit(1);
	}
	int tagcnt = 1;
	int i = 0;
	while(temp[i]!=')')
	{
		if(temp[i] ==',')
			tagcnt += 1;
		i++;
	}
	this->tagnum = tagcnt;
	temp.erase(0,1);//(
	if(tagcnt == 1)
	{
		temp.erase(temp.size()-1,1);
		this->cartag[0] = temp;
	}
	else if(tagcnt > 1)
	{
		for(int k = 0;k < tagcnt - 1;k++)
		{
			int index = 0;
			index = temp.find(',',0);
			this->cartag[k] = temp.substr(0,index);
			temp.erase(0,index + 1);//erase ...,
		}
		temp.erase(temp.size()-1,1);//)
		this->cartag[tagcnt-1] = temp;
	}
	/*for(int k = 0;k < tagcnt;k++)
		cout << cartag[k] << " ";*/
}
void car::OC(string direc,string site)
{
	this->status = 1;
	this->direction = direc;
	int index;
	index = site.find(',',0);
	
	string xx = site.substr(1,index - 1);
	site.erase(0,index+1);
	string yy = site.substr(0,site.size() - 1);
	//cout << xx <<" " << yy;
	char temp[index-1];
	for(int k = 0;k < index-1;k++)
		temp[k] = xx[k];
	this->x = atoi(temp);
	//delete []temp;
	temp[site.size()-1];
	for(int k = 0;k < site.size()-1;k++)
		temp[k] = yy[k];
	this->y = atoi(temp);
	//delete []temp;
	//cout << this->plate << " status:" << this->status << " direction:"<< this->direction << " x:" << x << " y:" << y;//
}
bool car::operator==(const string temp)
{
	for(int i = 0;i < 6;i++)
		if(this->plate[i] != temp[i])
			return false;
	return true;
}

/*void car::moving(move,hr,mn)
{
	if(move == 'N')
		
}*/

class passenger
{
	private:
		string number;//手機號碼 
		int tagnum;//屬性數量 
		int status;//狀態 
		string*passtag;//屬性 
		bool cartype;//指派車種 
		int x,y;//位置 
		int hr,mn;//時間 
	public:
		passenger()//:number(0),tagnum(0)
		{
			passtag = new string[30];
			tagnum = 0;
			status = 0;
			hr = 0;
			mn = 0;
		}
		~passenger()
		{
		}
		int matchcar;
		string getnum()
		{
			return number;
		}
		int getstatus()
		{
			return status;
		}
		int getx()
		{
			return x;
		}
		int gety()
		{
			return y;
		}
		void setnum(string &temp)
		{
			this->number = temp;
		}
		void outline()
		{
			this->status = 0;
		}
		void NP(string);
		void OP(string);
		bool operator==(const string);
		
};


void passenger::NP(string temp)
{
	if(temp == "()")
	{
		this->tagnum = 0;
		exit(1);
	}
	int tagcnt = 1;
	int i = 0;
	while(temp[i]!=')')
	{
		if(temp[i] ==',')
			tagcnt += 1;
		i++;
	}
	this->tagnum = tagcnt;
	temp.erase(0,1);//(
	if(tagcnt == 1)
	{
		temp.erase(temp.size()-1,1);
		this->passtag[0] = temp;
	}
	else if(tagcnt > 1)
	{
		for(int k = 0;k < tagcnt - 1;k++)
		{
			int index = 0;
			index = temp.find(',',0);
			this->passtag[k] = temp.substr(0,index);
			temp.erase(0,index + 1);//erase ...,
		}
		temp.erase(temp.size()-1,1);//)
		this->passtag[tagcnt-1] = temp;
	}
	/*for(int k = 0;k < tagcnt;k++)
		cout << passtag[k] << " ";*/
}
void passenger::OP(string site)
{
	this->status = 1;
	
	int index;
	index = site.find(',',0);
	
	string xx = site.substr(1,index - 1);
	site.erase(0,index+1);
	string yy = site.substr(0,site.size() - 1);
	//cout << xx <<" " << yy;
	char temp[index-1];
	for(int k = 0;k < index-1;k++)
		temp[k] = xx[k];
	this->x = atoi(temp);
	//delete []temp;
	temp[site.size()-1];
	for(int k = 0;k < site.size()-1;k++)
		temp[k] = yy[k];
	this->y = atoi(temp);
	//delete []temp;
	//cout << "(" << this->x << "," << this->y << ")\n"; //
	//cout << this->plate << " status:" << this->status << " direction:"<< this->direction << " x:" << x << " y:" << y;//
}

bool passenger::operator==(const string temp)
{
	for(int i = 0;i < 10;i++)
		if(this->number[i] != temp[i])
			return false;
	return true;
}

car drive[10000];
passenger human[10000];
int main()
{	
	int hh = 0;
	int mm = 0;
	string clock;
	string command;
	
	int passengercnt = 0;
	int carcnt = 0;
	int kilomax,regubase,reguprice,luxbase,luxprice,idealgrade,taggrade,kilograde,tagnum;
	string tagtemp;
	cin >> kilomax >> regubase >> reguprice >> luxbase >> luxprice >> idealgrade >> taggrade >> kilograde >> tagnum;
	//     K          aR          bR           aL         bL          k             h             p            n
	cin.ignore();
    //cout << kilomax <<" " << regubase <<" " << reguprice << " " << luxbase << " " << luxprice << " " << idealgrade <<" " << taggrade << " " << kilograde <<" " << tagnum;
    string* tag=new string[tagnum];
    if(tagnum!=0)
        getline(cin,tagtemp,'\n');
    else
        cin.ignore();
    for(int i=0; i<tagnum; i++)
    {   long index=0;
        if(i<tagnum-1)
        {   index=tagtemp.find(';',0);
            tag[i]=tagtemp.substr(0,index);
            tagtemp.erase(0,index+1);
        }
        else
            tag[i]=tagtemp;
    }
    //cout << tag[0] <<"@" << tag[1] << "@" << tag[2] << "@" << tag[3];
	while(1)
	{
		cin >> clock;//hh:mm
		char temptime[2] = {0};
		for(int i = 0;i < 2;i++)
			temptime[i] = clock[i];
		hh = atoi(temptime);
		for(int i = 0;i < 2;i++)
			temptime[i] = clock[i+3];
        mm = atoi(temptime);
        //cout << hh  << " " << mm << '\n';//
        
        string command,request;
        cin.ignore();
		getline(cin,request,'\n');
		command = request.substr(0,2);
		request.erase(0,3);//NP:
		//cout << "time:" << clock << " command:" << command;
		if(command == "NP")//乘客註冊 
		{
			string num;
			num = request.substr(0,10);//phonenumber
			request.erase(0,10);//(...)
			//cout << num << " " << request;
			bool exist = false;
			for(int i = 0;i < passengercnt;i++)
			{
				//cout << "a ";
				if(human[i]== num)
				{
					//cout << "b ";
					exist = true;
					break;
				}
			}
			if(exist == false)
			{
				human[passengercnt].setnum(num);
				//cout << human[passengercnt].getnum();
				human[passengercnt].NP(request);
				passengercnt++;
			}
		}
		else if(command == "NC")//車車註冊 
		{
			string num;
			num = request.substr(0,6);//platenumber
			request.erase(0,6);//(...)
			//cout << num << " " << request;
			bool exist = false;
			string type;
			type = request.substr(request.size() - 1,1);//L or R
			char temptype = type[0]; 
			request.erase(request.size() - 1,1);//L or R
			bool cartype;
			if(temptype == 'L')
				cartype = 1;
			else
				cartype = 0;
			//cout << cartype << " " << request << '\n';//
			for(int i = 0;i < carcnt;i++)
			{
				//cout << "a ";
				if(drive[i]== num)
				{
					//cout << "b ";
					exist = true;
					break;
				}
			}
			if(exist == false)
			{
					drive[carcnt].setplate(num);
					//cout << drive[carcnt].getplate();
					drive[carcnt].NC(request,temptype);
					carcnt++;
			}
		}
		else if(command == "OC")//車車上線 
		{
			string num;
			num = request.substr(0,6);//platenumber
			request.erase(0,6);//剩(x,y)N
			//cout << num << " " << request;
			
			for(int i = 0;i < carcnt;i++)
			{
				//cout << "a ";
				if(drive[i]== num)
				{
					if(drive[i].getstatus() == 0)
					{
						//cout << "b ";
						string direc;
						direc = request.substr(request.size() - 1,1);//N S E W H
						request.erase(request.size() - 1,1);//剩(x,y)
						//cout << direc<< " " << request << '\n';//
						drive[i].OC(direc,request);
					}
				}
			}
		}
		else if(command == "OP")//乘客上線 
		{
			string num;
			num = request.substr(0,10);//phonenumber
			request.erase(0,10);//剩(x,y)L 
			//cout << num << " " << request;//
			
			for(int i = 0;i < passengercnt;i++)
			{
				//cout << "a ";
				if(human[i] == num && human[i].getstatus() == 0)
				{
					//cout << "b ";
					string type;
					type = request.substr(request.size() - 1,1);//L R
					request.erase(request.size()- 1,1);//剩(x,y)
					char temptype = type[0];
					
					human[i].OP(request);
					int match = -1;
					int mindis = kilomax;
					if(temptype == 'L')
					{
						for(int k = 0;k < carcnt;k++)
						{
							if(drive[k].gettype() == 'L' && drive[k].distance(human[i].getx(),human[i].gety()) < mindis)
								{
									mindis = drive[k].distance(human[i].getx(),human[i].gety());
									match = k;
								}
						}
					}
					else if(temptype == 'R')
					{
						for(int k = 0;k < carcnt;k++)
						{
							if(drive[k].gettype() == 'R' && drive[k].distance(human[i].getx(),human[i].gety()) < mindis)
								{
									mindis = drive[k].distance(human[i].getx(),human[i].gety());
									match = k;
								}
						}
					}
					if(match == -1)
						human[i].outline();
					else
						drive[match].empty();
					//cout << cartype << " " << request << '\n';//	
				}
			}
		}
		else if(command == "EC")//車車轉向
		{
			string num = request.substr(0,6);
			request.erase(0,7);//剩N)
			request.erase(1,1);//剩N
			char move = request[1];
			/*for(int i = 0;i < carcnt;i++)
			{
				//cout << "a ";
				if(drive[i]== num)
				{
					if(drive[i].getstatus() == 1)
					{
						if(move != 'H')
							drive[i].moving(move);
					}
				}
			}*/
			 
		}	
	}
	return 0;
}
