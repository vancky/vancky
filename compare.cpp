#include<stdio.h>
#include<stdlib.h>
int MyCompare(const void *elem1,const void * elem2)
{
	unsigned int *p1,*p2;
	p1=(unsigned int*)elem1;//强制类型转换
	p2=(unsigned int*)elem2;
	return (*p1%10)-(*p2%10);//*取内容
}
#define NUM 5
int main()
{
	unsigned int an[NUM]={8,123,5,124,26};
	qsort(an,NUM,sizeof(unsigned int),MyCompare);//第三个参数是字节数
	for (int i=0;i<NUM;i++)
		printf("%d ",an[i]);

	printf("%d",sizeof(unsigned int));
	printf("%d\n",34&27);
	printf("%x\n",-12>>2 );
	printf("%d\n",26|14 );
	printf("%d\n",18^22 );
	int a=3,b=5;
	int&r=a;
	r=b;
	b=7;
	printf("%d\n",a);
		return 0;
}