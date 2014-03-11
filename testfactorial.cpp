#include <iostream>
#include <cmath>
#include <time.h>
using namespace  std;
int main(){
	double factorial(double n);
	double fib(double n);
	double dgfactorial(double n);
	double botupfib(double n);
	double* nrfib(int n);
	double s;
	double* fuckinga;
	cout<<"请输入一个正整数：\n"<<"下面来计算其阶乘\n";
	cin>>s;
	cout <<s<<"的阶乘为："<<dgfactorial(s)<<endl;
	//cout<<"第"<<s<<"项为"<<fib(s)<<endl; 
	cout<<"新方法计算的结果为\n"<<botupfib(s)<<endl;
	fuckinga=nrfib(s);
	cout<<"使用矩阵方法计算的结果为\n"<<fuckinga[2]<<endl;
	delete[] fuckinga;//need test
	return 0;
}
double factorial(double n)
{ 
	double product=1;
	while (n>0)
	{
		product=n*product;
		n=n-1;
	}
	return product;
}
double fib(double n)//递归方法，幂级，非常慢
{
	double sumfb=1;
	if(n>2)
	{
        sumfb=fib(n-1)+fib(n-2);
	}
	return sumfb;

}
double dgfactorial(double n)
{
	double product=1;
	if(n>1)
	{
		product=n*dgfactorial(n-1);
	}
	return product;
}
double botupfib(double n)//bottom up algorithm 自底向上
{
   double a0=1;//存储偶数
   double a1=1;//存储奇数
   double an=1;//存储最新信息
   for (int i=3;i<=n;i++){
        an=a0+a1;
        if (i%2==0) a1=an;
        else
        	a0=an;
   }
   return an;
}
double* nrfib(int n)//divide&conque  矩阵方法
{   double* originmat=new double [4];//使用数组模拟2阶矩阵
	originmat[0]=1;
	originmat[1]=1;
	originmat[2]=1;
	originmat[3]=0;
	double* tmpa;
	double* tmpb;
    if (n<3){
    	if (n<2)
        return originmat;
        else{
        		originmat[0]=2;
				originmat[1]=1;
				originmat[2]=1;
				originmat[3]=1;
        		return originmat;
    	}
    }
    else{
    	if (n%2==0){
    		tmpa=nrfib(n/2);
    		originmat[0]=tmpa[0]*tmpa[0]+tmpa[1]*tmpa[2];
    		originmat[1]=tmpa[0]*tmpa[1]+tmpa[1]*tmpa[3];
    		originmat[2]=tmpa[0]*tmpa[2]+tmpa[2]*tmpa[3];
    		originmat[3]=tmpa[2]*tmpa[1]+tmpa[3]*tmpa[3];
    		return originmat;
    		}

    	else{
    		tmpa=nrfib((n-1)/2);
    		tmpb=nrfib((n+1)/2);
    		originmat[0]=tmpa[0]*tmpb[0]+tmpa[1]*tmpb[2];
    		originmat[1]=tmpa[0]*tmpb[1]+tmpa[1]*tmpb[3];
    		originmat[2]=tmpa[2]*tmpb[0]+tmpa[3]*tmpb[2];
    		originmat[3]=tmpa[2]*tmpb[1]+tmpa[3]*tmpb[3];
    		return originmat;
    		}
    	}
}
