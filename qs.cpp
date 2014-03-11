#include <iostream>
#include <string>
typedef int* IntPtr;
using namespace std;
void quicksort(int A[],int p,int q);
int partition(int A[],int p,int q);
int main()
{

	int a[7]={2,4,1,8,9,3,5},k;

	cout<<"排序前数组"<<endl;
	for (k=0;k<7;k++)
		cout<<a[k]<<" ";
	cout<<partition(a,0,6);
     quicksort(a,0,6);
    cout<<"\n排序后数组"<<endl;
    for (k=0;k<7;k++)
    	cout<<a[k]<<" ";

}
void quicksort(int  A[],int p,int q)
{
	int r;
    if (p<q)
    {
    	r=partition(A,p,q);
    	quicksort(A,p,r-1);
    	quicksort(A,r+1,q);
    }
    
  
}
int partition(int A[],int p,int q)
{
	int x,i,j,tmp;
	x=A[p];
	i=p;
	for (j=p+1;j<=q;j++)
		{
			if (A[j]<=x)
			{  
				i=i+1;
				tmp=A[j];
				A[j]=A[i];
				A[i]=tmp;

		    }
         }
    A[p]=A[i];
    A[i]=x;
    return i;
}