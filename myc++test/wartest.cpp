#include <iostream>
#include <string>
#include <vector>
using namespace std;
class warrior
{
private:
	string type;
	int No,HP,ATK;
public:
	 warrior(string ntype,int nNo,int nHP,int nATK);
	 warrior(){}
	 void set_warrior(string ntype,int nNo,int nHP,int nATK)
	{type=ntype;No=nNo;HP=nHP;ATK=nATK;}
	string get_Type();
	int get_No(){return No;};
    int get_HP();
    int get_ATK();
    void set_HP(int newHp);
    void set_ATK(int newATK);
};
warrior::warrior(string ntype,int nNo,int nHP,int nATK)
{
	type=ntype;No=nNo;HP=nHP;ATK=nATK;
}
string warrior::get_Type()
{
	return type;
}
int warrior::get_HP()
{
	return HP;
}
int warrior::get_ATK()
{
	return ATK;
}
class Command
{
private:
	string Color;
	int lifeNo;
	int warriorNo[5];//dragon,ninja,iceman,lion,wolf
	string typeorder[5];
	int lifeneed[5];
	vector<warrior> army;
	int state;//记录是否还能继续造兵
	int order;//记录已经造的次序 0 1 2 3 4
	bool hasprinted;//记录是否打印最后停止制造的标志
	
public:
	static int Time;
	Command(string nColor,int nlifeNo,string ct[5],int lf[5]);
	string get_Color();
	int get_lifeNo();
	int get_typeNo(string s);
	int get_sum();
	bool creat_warrior(warrior newman);
	int get_state(){return state;}
	warrior get_lastone(){return army.back();};//返回最后一个武士
	void printinfo();
	bool creat_warrior();
	bool get_hasprinted(){return hasprinted;};
};
Command::Command(string nColor,int nlifeNo,string ct[],int lf[])
{
	Color=nColor;lifeNo=nlifeNo;
	//warriorNo={0,0,0,0,0};
	for(int i=0;i<5;i++)
	{
		warriorNo[i]=0;
		typeorder[i]=ct[i];
		lifeneed[i]=lf[i];
	}

	vector<warrior> army;
	state=1;
	order=0;
	hasprinted=false;
}
string Command::get_Color()
{
	return Color;
}
int Command::get_lifeNo()
{
	return lifeNo;
}
int Command::get_typeNo(string s)
{
	if(s=="dragon")
			return warriorNo[0];
		else if (s=="ninja")
		    return warriorNo[1];
		else if (s=="iceman")
		    return warriorNo[2];
		else if (s=="lion")
		    return warriorNo[3];
		else
			return warriorNo[4];
}
int Command::get_sum()
{
	if (army.empty())
		return 0;
	else
	return army.size();
}
bool Command::creat_warrior(warrior newman)//制造一个士兵，返回T OR F
{
    order=(order+1)%5;
	if (newman.get_HP()<(lifeNo+1))
	{
		army.push_back(newman);//生产一个武士
		if(newman.get_Type()=="dragon")
			warriorNo[0]+=1;
		else if (newman.get_Type()=="ninja")
		    warriorNo[1]+=1;
		else if (newman.get_Type()=="iceman")
		    warriorNo[2]+=1;
		else if (newman.get_Type()=="lion")
		    warriorNo[3]+=1;
		else
			warriorNo[4]+=1;
		lifeNo=lifeNo-newman.get_HP();//更新生命值
	    return true;
	}
	else 

	    return false;
}
bool Command::creat_warrior()//无参数形式的制造士兵，T表示成功，失败表示不可能再造了
{
	int k=order;bool tmp;
	warrior newman;
	while (1)
	{
		newman.set_warrior(typeorder[order],get_sum()+1,lifeneed[order],0);
		tmp=creat_warrior(newman);
		if (tmp)
		{ state=1;return true;}

	    else if (k==order)
	    {
	    	state=0;
	    	return false;
	    }
	  //  cout<<"test"<<k<<"fuck"<<order<<endl;
	}
}
void Command::printinfo( )
{
	if (hasprinted)
		;
	else
    {if (state==0)
      	{
      		cout.width(3);cout.fill('0');
      	     cout<<Time;
      	     cout<<" "<<Color<<" headquarter stops making warriors"<<endl;
      	     hasprinted=true;
      	}
      	else
      	{
      		cout.width(3);cout.fill('0');
      	     cout<<Time;
      		warrior Rone=get_lastone();//取最后一个武士
      		cout<<" "<<Color<<" "<<Rone.get_Type()<<" "<<
      		get_sum()<<" born with strength "
      		<<Rone.get_HP()<<","<<get_typeNo(Rone.get_Type())
      		<<" "<<Rone.get_Type()<<" in "<<Color<<" headquarter"<<endl;
      	}
      }
}

int Command::Time=0;
int main()
{
	int originhp[5];
	string types[5]={"dragon","ninja","iceman","lion","wolf"};
	string typesR[5]={"iceman","lion","wolf","ninja","dragon"};
	string typesB[5]={"lion","dragon","ninja","iceman","wolf"};
	int originlife;
	int caseno;//测试的case个数
	cin>>caseno; 
	int (*inhps)[5]=new int[caseno][5];
	int *inlife=new int[caseno];
	for(int i=0;i<caseno;i++)//读入输入
	{
		cin>>inlife[i];
		for(int j=0;j<5;j++){cin>>inhps[i][j];}
	}
    for (int k=0;k<caseno;k++)
    {
    	Command::Time=0;//初始化时间
    	for(int i=0;i<5;i++){originhp[i]=inhps[k][i];}//初始化武士生命值
    	originlife=inlife[k];//初始化总生命值
    int originhpR[5]={originhp[2],originhp[3],originhp[4],originhp[1],originhp[0]};
    int originhpB[5]={originhp[3],originhp[0],originhp[1],originhp[2],originhp[4]};
	Command R("red",originlife,typesR,originhpR);
	Command B("blue",originlife,typesB,originhpB);
    cout<<"Case:"<<k+1<<endl;
    bool sa=R.creat_warrior();
    bool sb=B.creat_warrior();
    while (1)
      {
      	if (R.get_hasprinted()&&B.get_hasprinted())
      		break;
      	if (R.get_state()||~R.get_hasprinted())
      	{
      		R.printinfo();
            sa=R.creat_warrior();
        }
        if (B.get_state()||~B.get_hasprinted())
      	{
      		B.printinfo();
      		sb=B.creat_warrior();
      	}
      	Command::Time+=1;   
///////////////////////////////
      }
  }
  delete []inhps;
  delete []inlife;
    return 0;
}