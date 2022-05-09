#include"workManger.h"
// 创建管理类
//1 与用户的沟通菜单界面
//2 对职工增删改查的操作
//3 对文件的读写交互
workManger::workManger()    // 构造函数实现
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	//文件不存在情况
	if(!ifs.is_open())
	{
		cout<<"文件不存在"<<endl;
		this->num=0;
		this->tP=NULL;
		this->Exist=true;
		ifs.close();
		return;
	}
	//文件为空
	char ch;
	ifs>>ch;
	if(ifs.eof())
	{
		cout<<"文件为空"<<endl;
		this->num=0;
		this->tP=NULL;
		this->Exist=true;  //空或者不存在就这个参数为true
		ifs.close();
		return;
	}
	//文件内有数据
	int num=this->getNum();
	cout<<"职工人数为"<<num<<"个"<<endl;
	this->num=num;  //初始化了人数

	//初始化数组
	this->tP=new worker*[this->num];   //先开辟空间再初始化
	this->init_tP();
	this->Exist=false;    //标记这个为false，可以进行显示

}  
workManger::~workManger()   //析构函数实现
{
	if(this->tP!=NULL)
	{
		for(int i=0;i<this->num;i++)
		{
			if(this->tP[i]!=NULL)
			{
				delete this->tP[i];
			}	
		}
		this->num=0;
		delete []this->tP;
		this->tP=NULL;
		this->Exist=true;
	}
}  
void workManger::showMenu()
{
	cout<<"************************************"<<endl;
	cout<<"********欢迎使用职工管理系统********"<<endl;
	cout<<"********   0 退出管理程序   ********"<<endl;
	cout<<"********   1.增加职工信息   ********"<<endl;
	cout<<"********   2.显示职工信息   ********"<<endl;
	cout<<"********   3.删除离职员工   ********"<<endl;
	cout<<"********   4.修改职工信息   ********"<<endl;
	cout<<"********   5.查找职工信息   ********"<<endl;
	cout<<"********   6.按照编号排序   ********"<<endl;
	cout<<"********   7.清空所有文档   ********"<<endl;
	cout<<"************************************"<<endl;
}
void workManger::exitSystem()
{
	cout<<"谢谢您的使用,欢迎下次再来"<<endl;
	system("pause");
	exit(0);
}
//往文件里写东西
void workManger::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);
	for(int i=0;i<this->num;i++)
	{
		ofs<<this->tP[i]->id<<" "<<this->tP[i]->name<<" "<<this->tP[i]->depaId<<endl;
		// id 姓名 部门编号
	}
	ofs.close();
}
//添加职工的函数
void workManger::addPerson()
{
	cout<<"请输入增加职工数量:"<<endl;
	int addnum=0;
	cin>>addnum;
	if (addnum>0)  //如果大于0才开始添加
	{
		//计算新空间大小
		int newSize=this->num+addnum;
		//开辟新空间
		worker **newSpace=new worker*[newSize];

		//将原空间下内容存放在新空间下
		if(this->tP!=NULL) // 如果原数组不为空
		{
			for(int i=0;i<num;i++)
			{
				newSpace[i]=this->tP[i];
			}
		}
		//输入新数据
		for(int i=0;i<addnum;i++)
		{
			int id;
			string name;
			int dId;
			cout<<"输入第"<<i+1<<"职工编号:"<<endl;
			cin>>id;
			cout<<"输入第"<<i+1<<"职工姓名:"<<endl;
			cin>>name;
			cout<<"选择该职工职位"<<endl;
			cout<<"1. 普通员工"<<endl;
			cout<<"2. 经理"<<endl;
			cout<<"3. 老板"<<endl;
			cin>>dId;

			// 然后根据选择的对象重新建立对象
			worker *p=NULL;
			switch(dId)
			{
			case 1:
				p=new normalPe(id,name,1);
				break;
			case 2:
				p=new manger(id,name,2);
				break;
			case 3:
				p=new boss(id,name,3);
				break;
			default:
				break;
			}
			newSpace[this->num+i]=p;
		}
				
		//释放原有空间
		delete[] this->tP;
		//更改新空间的指向以及人数
		this->tP=newSpace;
		this->num=newSize;
		cout<<"添加"<<addnum<<"名员工成功"<<endl;
		this->Exist=false;   //添加之后把该参数改为false
	}
	else
	{
		cout<<"输入数据有误"<<endl;
	}
	this->save();   //最好加this
	//添加完之后，得清屏然后返回上一级
	system("pause");  //按任意键继续
	system("cls");
}
int workManger::getNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	int id;
	string name;
	int dId;
	int num=0;
	while(ifs>>id&&ifs>>name&&ifs>>dId)   //一行行读，读完就退出while循环
	{
		num++;
	}
	return num;
}
void workManger::init_tP()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int dId;
	int index=0;  //数组的序号
	while(ifs>>id&&ifs>>name&&ifs>>dId)
	{
		worker *w=NULL;
		if(dId==1)
		{
			w=new normalPe(id,name,dId);
		}
		if(dId==2)
		{
			w=new manger(id,name,dId);
		}
		if(dId==3)
		{
			w=new boss(id,name,dId);
		}
		this->tP[index]=w;
		index++;
	}
	
}
void workManger::showAll()
{
	if (this->Exist)
	{
		cout<<"文件不存在或为空"<<endl;
	}
	else
	{
		cout<<"职工总人数为"<<this->num<<endl;
		for(int i=0;i<this->num;i++)
		{
			this->tP[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
//根据职工编号判断是否存在
int workManger::IsExist(int id)
{
	for(int i=0;i<this->num;i++)
	{
		if(this->tP[i]->id==id)
		{
			return i;
		}
	}
	return -1;
}
//删除员工操作，根据编号
void workManger::delPe()
{
	if(this->Exist)
	{
		cout<<"文件不存在或为空"<<endl;
	}
	else
	{
		cout<<"输入你想要删除的员工编号"<<endl;
		int del_num;
		cin>>del_num;
		int index=this->IsExist(del_num);
		if(index==-1)
		{
			cout<<"无此员工"<<endl;
		}
		else
		{
			for(int i=index;i<this->num-1;i++)
			{
				this->tP[i]=this->tP[i+1];
			}
			this->num--;  //更新num数量
			cout<<"删除成功"<<endl;
			this->save();
		}
	}
	system("pause");
	system("cls");
}
//修改职工信息操作
void workManger::modiPe()
{
	if(this->Exist)
	{
		cout<<"文件不存在或为空"<<endl;
	}
	else
	{
		int modi_num;
		cout<<"输入你要修改的职工编号"<<endl;
		cin>>modi_num;
		int index=this->IsExist(modi_num);
		if(index!=-1)  //说明存在
		{
			int newid;
			string newname;
			int newdId;
			cout<<"请输入新的职工编号:"<<endl;
			cin>>newid;
			cout<<"请输入新姓名:"<<endl;
			cin>>newname;
			cout<<"选择该职工职位"<<endl;
			cout<<"1. 普通员工"<<endl;
			cout<<"2. 经理"<<endl;
			cout<<"3. 老板"<<endl;
			cin>>newdId;
			//更新数据，放入数组中
			
			worker *p=NULL;
			switch(newdId)
			{
			case 1:
				p=new normalPe(newid,newname,1);
				break;
			case 2:
				p=new manger(newid,newname,1);
				break;
			case 3:
				p=new boss(newid,newname,1);
				break;
			default:
				break;
			}
			this->tP[index]=p;
			cout<<"修改成功"<<endl;
			this->save();
		}
		else
		{
			cout<<"修改失败,查无此人"<<endl;
		}
	}
	system("pause");
	system("cls");
}
//根据编号或名字查找信息
void workManger::findPe()
{
	if(this->Exist)
	{
		cout<<"文件不存在或为空"<<endl;
	}
	else          //文件存在
	{
		int num;
		cout<<"请输入查找的方式"<<endl;
		cout<<"1. 按编号查找"<<endl;
		cout<<"2.按姓名查找"<<endl;
		cin>>num;
		if(num==1)
		{
			int tar;
			cout<<"请输入要查找的编号"<<endl;
			cin>>tar;
			int index=this->IsExist(tar);
			if(index!=-1)  //说明存在
			{
				cout<<"查找成功"<<endl;
				this->tP[index]->showInfo();
			}
			else
			{
				cout<<"未查找到"<<endl;

			}
		}
		else if(num==2)
		{
			string name;
			cout<<"请输入要查找的职工姓名"<<endl;
			cin>>name;
			bool flag=false;
			for(int i=0;i<this->num;i++)
			{
				if(this->tP[i]->name==name)
				{
					cout<<"查找成功"<<endl;
					flag=true;
					this->tP[i]->showInfo();
					//可能有同名的，因此不能break
				}
			}
			if(!flag)
			{
				cout<<"查无此人"<<endl;
			}
		}
		else
		{
			cout<<"输入有误，请重新输入"<<endl;
		}
	}
	system("pause");
	system("cls");
}
void workManger::idSort()
{
	if(this->Exist)
	{
		cout<<"文件不存在或为空"<<endl;
	}
	else
	{
		cout<<"选择排序方式"<<endl;
		cout<<"1. 升序"<<endl;
		cout<<"2.降序"<<endl;
		int num;
		cin>>num;
		if(num==1)
		{
			this->upSort(); //排序成功并输出
		}
		else
		{
			this->lowSort();
		}
	}
	system("pause");
	system("cls");
}
//升序排列
void workManger::upSort()
{
	
	for(int i=0;i<this->num;i++)
	{
		int min=i;
		for(int j=i+1;j<this->num;j++)
		{
			if(this->tP[min]->id>this->tP[j]->id)
			{
				min=j;
			}

		}
		if(i!=min)
		{
			worker *temp=this->tP[i];
			this->tP[i]=this->tP[min];
			this->tP[min]=temp;
		}
	}
	cout<<"升序排序成功"<<endl;
	cout<<"排序后全部信息为"<<endl;
	this->save();
	this->showAll();
}
//降序排列
void workManger::lowSort()
{
	
	for(int i=0;i<this->num;i++)
	{
		int max=i;
		for(int j=i+1;j<this->num;j++)
		{
			if(this->tP[max]->id<this->tP[j]->id)
			{
				max=j;
			}

		}
		if(i!=max)
		{
			worker *temp=this->tP[i];
			this->tP[i]=this->tP[max];
			this->tP[max]=temp;
		}
	}
	cout<<"降序排序成功"<<endl;
	cout<<"排序后全部信息为"<<endl;
	this->save();
	this->showAll();
}
//清空文件函数
void workManger::cleanFile()
{
	cout<<"确认清空数据吗"<<endl;
	cout<<"1.确认"<<endl;
	cout<<"2.返回上一级"<<endl;
	int select;
	cin>>select;
	if(select==1)
	{
		//trunc 就是发现有文件，就删除然后重新创建
		ofstream ofs(FILENAME,ios::trunc);
		ofs.close();
		//然后开始释放堆区的空间
		if(this->tP!=NULL)
		{
			for(int i=0;i<this->num;i++)
			{
				if(this->tP[i]!=NULL)
				{
					delete this->tP[i];
				}	
			}
			this->num=0;
			delete []this->tP;
			this->tP=NULL;
			this->Exist=true;

		}
		cout<<"清空成功"<<endl;
	}
	system("pause");
	system("cls");
}