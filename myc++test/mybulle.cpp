#include <iostream>
using namespace std;
int main()
{
	void bubble(int a[],int N);
	int N=7;
	//int a[]={9,2,3,4,8,13,20,2,34,41,1,24,39};
	int a[]={5,2,7,4,6,3,1};
	cout<<"排序前\n";
	for (int i=0;i<N;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	bubble(a,N);
	cout<<"排序后\n";
	for(int i=0;i<N;i++)
		cout<<a[i]<<" ";

	return 0;


}
void bubble(int a[],int N)
{
		int temp ;
	for(int j=0;j<N-1;j++)
	{
		int indicator=0;
	for(int i=0;i<N-1;i++)
	{
		if (a[i]>a[i+1])
		{
			temp=a[i+1];
			a[i+1]=a[i];
			a[i]=temp;
			indicator+=1;
		}

	}
	cout<<"第"<<j<<"次改变"<<indicator<<endl;
	for (int i=0;i<N;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	if (indicator==0) break;
    }
}
//void heapsort(int a[])