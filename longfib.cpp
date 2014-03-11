#include <iostream>
#include <stdlib.h>
using namespace  std;
const int mxdgs=9500;
int main(){
	int n;
	cout<<"请输入要计算的斐波那契数列的项数:\n";
	cin>>n;
	int dgsn1[mxdgs];//存储偶数项
	int dgsn2[mxdgs];//存储奇数项
	//最高位到第一个，次高位到第二个，逆序存储在数列中
	dgsn1[0]=1;dgsn2[0]=1;
	for (int i=1;i<mxdgs;i++) {//???初始化？？
		dgsn1[i]=0;
		dgsn2[i]=0;
	}
	for (int k=3;k<=n;k++){//针对每一位数做加法运算
		int cary=0;
		for (int j=0;j<mxdgs;j++){
			if (k%2==0){
			dgsn1[j]=dgsn2[j]+dgsn1[j]+cary;
			cary=dgsn1[j]/10;
			dgsn1[j]=dgsn1[j]-10*cary;
		}
		else {
			dgsn2[j]=dgsn2[j]+dgsn1[j]+cary;
			cary=dgsn2[j]/10;
			dgsn2[j]=dgsn2[j]-10*cary;
		}
		}
	}

	int count=mxdgs-1;//数结果共有多少位数
	while(!dgsn1[count])
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
	cout<<"一共有"<<count+1<<"位数字在斐波那契数列第"
	<<n<<"项中。他们是：\n";
	for(int i=count;i>=0;i--){
		if (n%2==0)
		cout<<dgsn1[i];
	    else 
		cout<<dgsn2[i];
	} 

	cout<<'\n';
}
