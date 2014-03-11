#include <iostream>
using namespace std;
class CSample{
	public:
	 int a;
	CSample();
	CSample(int b);

};
CSample::CSample(){
	cout<<"fukingA"<<endl;
}
CSample::CSample(int b){
	cout<<"fukingB"<<endl;
}
int main(){
	CSample array1[2];
	cout<<"step1"<<endl;
	CSample array2[2]={4,3};
	cout<<"step2"<<endl;
	CSample array3[2]={3};
	cout<<"step3"<<endl;
}