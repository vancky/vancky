#include <iostream>
#include <stdlib.h>
using namespace  std;
const int mxdgs=9500;
int main(){
	int n;
	cout<<"请输入要计算阶乘的正整数:\n";
	cin>>n;
	int dgs[mxdgs];
	//最高位到第一个，次高位到第二个，逆序存储在数列中,5!为02100...
	dgs[0]=1;
	for (int i=1;i<mxdgs;i++) //???初始化？？
		dgs[i]=0;
	for (int k=2;k<=n;k++){//做阶乘运算用(k-1)!的第一个数字去乘k得到k!
		int cary=0;
		for (int j=0;j<mxdgs;j++){
			dgs[j]=k*dgs[j]+cary;
			cary=dgs[j]/10;
			dgs[j]=dgs[j]-10*cary;
		}
	}
	int count=mxdgs-1;//数阶乘共有多少位数
	while(!dgs[count])
		count--;
	int numdgofn=0;
	int m=n;      //数数字有多少位数
	while(m){
		m=m/10;
	    numdgofn++;
	}
	if(mxdgs-count<numdgofn+1){
		cout<<"超出位数限制\n";
		exit(1);
	}
	cout<<"一共有"<<count+1<<"位数字在"
	<<n<<"的阶乘中。他们是：\n";
	for(int i=count;i>=0;i--)
		cout<<dgs[i];
	cout<<'\n';
}
