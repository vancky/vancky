#include <iostream>
using namespace std;
class CRectangle
{
public:
	int w,h;
	void Init(int w_,int h_)
	{
		w=w_;h=h_;
	}
	int Area()
	{
		return w*h;
	}
	int Perimeter(){
		return 2*(w+h);
	}
};
void printArea(CRectangle& r){
	r.w=9;//引用与直接调用的区别
	cout<<r.Area()<<endl;

}
class Complex{
public:
	double real,imag;
	Complex(){}
	Complex(const Complex & c){
		real=c.real;
		imag=c.imag;
		cout<<"复制构造函数调用\n";
	}
};
int main(){
	int w,h;
	CRectangle r;
	cin>>w>>h;
	r.Init(w,h);
	r.w=7;
	printArea(r);
	cout<<"fuck"<<r.Area()<<endl;
	Complex c1;
	c1.real=1;c1.imag=2;
	Complex c2(c1);
	cout<<c2.real<<endl;
	
	return 0;
}
