#include <iostream>
#include <string>
using namespace  std;
void swap_values(int &value1,int &value2);
int main()
{
	/*printf("what the fuck");*/
	cout<<"fuckyou\n";
	//char letter;
	//cout<<"请输入一个字母\n";
	//cin>>letter;
	cout<<"Testing 1,2,3\n";
	int a=3,b=4;
	int *x=&a,*y=&b;
	double rate(0.93),cost;
	cout << a << "\n"
	<<rate << "\nwhat the fuck"<<endl;
	cout<<"输入每人消费额度:$";
	cin>>cost;
	string day;
	day="monday";
	cout<<day<<endl;
	cout<<a<<"\n"<<b<<"\n";
	swap_values(a,b);
    cout<<"交换后\n"<<a<<"\n"<<b<<"\n";
    swap_values(a,b);
    cout<<"交换前\n"<<*x<<"\n"<<*y<<"\n";
    swap_values(*x,*y);
    cout<<"交换后\n"<<*x<<"\n"<<*y<<"\n";
    cout<<4%2;
	return 0;
}
void swap_values(int& value1,int& value2)
{
	int temp;
	temp=value1;
	value1=value2;
	value2=temp;
}