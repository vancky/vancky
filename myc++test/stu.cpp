#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class student
{
private:
	string name;
	int age;
	string stuID;
	int fstyscore,sndyscore,thdyscore,fthyscore;
public:
	void set_onestu(string newname,int newage,string newstuID,int new1core,int new2core,\
		int new3score,int new4score);
	void dispinfo();
};
void student::set_onestu(string newname,int newage,string newstuID,int new1core,int new2core,\
		int new3score,int new4score)
{
     name=newname;
     age=newage;
     stuID=newstuID;
     fstyscore=new1core;
     sndyscore=new2core;
     thdyscore=new3score;
     fthyscore=new4score;
}
void student::dispinfo()
{
	cout<<name<<','<<age<<','<<stuID<<','
	<<(fstyscore+sndyscore+thdyscore+fthyscore)/4<<endl;
}
int main()
{
	string Tname,tmps;
	int Tage;
	string TstuID;
	student aTom;
	int T1s,T2s,T3s,T4s;
	getline(cin,Tname,',');
	getline(cin,tmps,',');
	Tage=atoi(tmps.c_str());
	getline(cin,TstuID,',');
	getline(cin,tmps,',');
	T1s=atoi(tmps.c_str());
	getline(cin,tmps,',');
	T2s=atoi(tmps.c_str());
	getline(cin,tmps,',');
	T3s=atoi(tmps.c_str());
	cin>>T4s;
	aTom.set_onestu(Tname,Tage,TstuID,T1s,T2s,T3s,T4s);
	aTom.dispinfo();
}


