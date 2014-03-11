#include <iostream>
#include <vector>
using namespace std;
class B{
private:	int v;
public:
	void func(){}
};
void futest(int a)
{
   cout<<a;
   cout<<"int futest"<<endl;
}
int main(){
	//class A {public:int v; A* p;};
	//class A {public: int v;};
	 //A a;a.p=&a;
	//A a;a.p=new A; delete a.p;
	//A a;a.v=3;
	//A* p=new A;
	//p->v=4;delete p;
	cout<<"mainend\n";
	cout<<int('1');
	int D[3]={1,3,4};
	int j=1;
	int s=D[j];
	cout<<"fuck"<<s<<endl;
	futest(s);
	int originhp[5]={2,3,4,5,6};
	vector<int> v;
	v.push_back(10);
	v.push_back(3);
	if (v.size())
    {futest(originhp[j]);}
    cout<<v.back()<<endl;

	return 0;
}

