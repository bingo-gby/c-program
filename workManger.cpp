#include"workManger.h"
// ����������
//1 ���û��Ĺ�ͨ�˵�����
//2 ��ְ����ɾ�Ĳ�Ĳ���
//3 ���ļ��Ķ�д����
workManger::workManger()    // ���캯��ʵ��
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	//�ļ����������
	if(!ifs.is_open())
	{
		cout<<"�ļ�������"<<endl;
		this->num=0;
		this->tP=NULL;
		this->Exist=true;
		ifs.close();
		return;
	}
	//�ļ�Ϊ��
	char ch;
	ifs>>ch;
	if(ifs.eof())
	{
		cout<<"�ļ�Ϊ��"<<endl;
		this->num=0;
		this->tP=NULL;
		this->Exist=true;  //�ջ��߲����ھ��������Ϊtrue
		ifs.close();
		return;
	}
	//�ļ���������
	int num=this->getNum();
	cout<<"ְ������Ϊ"<<num<<"��"<<endl;
	this->num=num;  //��ʼ��������

	//��ʼ������
	this->tP=new worker*[this->num];   //�ȿ��ٿռ��ٳ�ʼ��
	this->init_tP();
	this->Exist=false;    //������Ϊfalse�����Խ�����ʾ

}  
workManger::~workManger()   //��������ʵ��
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
	cout<<"********��ӭʹ��ְ������ϵͳ********"<<endl;
	cout<<"********   0 �˳��������   ********"<<endl;
	cout<<"********   1.����ְ����Ϣ   ********"<<endl;
	cout<<"********   2.��ʾְ����Ϣ   ********"<<endl;
	cout<<"********   3.ɾ����ְԱ��   ********"<<endl;
	cout<<"********   4.�޸�ְ����Ϣ   ********"<<endl;
	cout<<"********   5.����ְ����Ϣ   ********"<<endl;
	cout<<"********   6.���ձ������   ********"<<endl;
	cout<<"********   7.��������ĵ�   ********"<<endl;
	cout<<"************************************"<<endl;
}
void workManger::exitSystem()
{
	cout<<"лл����ʹ��,��ӭ�´�����"<<endl;
	system("pause");
	exit(0);
}
//���ļ���д����
void workManger::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);
	for(int i=0;i<this->num;i++)
	{
		ofs<<this->tP[i]->id<<" "<<this->tP[i]->name<<" "<<this->tP[i]->depaId<<endl;
		// id ���� ���ű��
	}
	ofs.close();
}
//���ְ���ĺ���
void workManger::addPerson()
{
	cout<<"����������ְ������:"<<endl;
	int addnum=0;
	cin>>addnum;
	if (addnum>0)  //�������0�ſ�ʼ���
	{
		//�����¿ռ��С
		int newSize=this->num+addnum;
		//�����¿ռ�
		worker **newSpace=new worker*[newSize];

		//��ԭ�ռ������ݴ�����¿ռ���
		if(this->tP!=NULL) // ���ԭ���鲻Ϊ��
		{
			for(int i=0;i<num;i++)
			{
				newSpace[i]=this->tP[i];
			}
		}
		//����������
		for(int i=0;i<addnum;i++)
		{
			int id;
			string name;
			int dId;
			cout<<"�����"<<i+1<<"ְ�����:"<<endl;
			cin>>id;
			cout<<"�����"<<i+1<<"ְ������:"<<endl;
			cin>>name;
			cout<<"ѡ���ְ��ְλ"<<endl;
			cout<<"1. ��ͨԱ��"<<endl;
			cout<<"2. ����"<<endl;
			cout<<"3. �ϰ�"<<endl;
			cin>>dId;

			// Ȼ�����ѡ��Ķ������½�������
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
				
		//�ͷ�ԭ�пռ�
		delete[] this->tP;
		//�����¿ռ��ָ���Լ�����
		this->tP=newSpace;
		this->num=newSize;
		cout<<"���"<<addnum<<"��Ա���ɹ�"<<endl;
		this->Exist=false;   //���֮��Ѹò�����Ϊfalse
	}
	else
	{
		cout<<"������������"<<endl;
	}
	this->save();   //��ü�this
	//�����֮�󣬵�����Ȼ�󷵻���һ��
	system("pause");  //�����������
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
	while(ifs>>id&&ifs>>name&&ifs>>dId)   //һ���ж���������˳�whileѭ��
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
	int index=0;  //��������
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
		cout<<"�ļ������ڻ�Ϊ��"<<endl;
	}
	else
	{
		cout<<"ְ��������Ϊ"<<this->num<<endl;
		for(int i=0;i<this->num;i++)
		{
			this->tP[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
//����ְ������ж��Ƿ����
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
//ɾ��Ա�����������ݱ��
void workManger::delPe()
{
	if(this->Exist)
	{
		cout<<"�ļ������ڻ�Ϊ��"<<endl;
	}
	else
	{
		cout<<"��������Ҫɾ����Ա�����"<<endl;
		int del_num;
		cin>>del_num;
		int index=this->IsExist(del_num);
		if(index==-1)
		{
			cout<<"�޴�Ա��"<<endl;
		}
		else
		{
			for(int i=index;i<this->num-1;i++)
			{
				this->tP[i]=this->tP[i+1];
			}
			this->num--;  //����num����
			cout<<"ɾ���ɹ�"<<endl;
			this->save();
		}
	}
	system("pause");
	system("cls");
}
//�޸�ְ����Ϣ����
void workManger::modiPe()
{
	if(this->Exist)
	{
		cout<<"�ļ������ڻ�Ϊ��"<<endl;
	}
	else
	{
		int modi_num;
		cout<<"������Ҫ�޸ĵ�ְ�����"<<endl;
		cin>>modi_num;
		int index=this->IsExist(modi_num);
		if(index!=-1)  //˵������
		{
			int newid;
			string newname;
			int newdId;
			cout<<"�������µ�ְ�����:"<<endl;
			cin>>newid;
			cout<<"������������:"<<endl;
			cin>>newname;
			cout<<"ѡ���ְ��ְλ"<<endl;
			cout<<"1. ��ͨԱ��"<<endl;
			cout<<"2. ����"<<endl;
			cout<<"3. �ϰ�"<<endl;
			cin>>newdId;
			//�������ݣ�����������
			
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
			cout<<"�޸ĳɹ�"<<endl;
			this->save();
		}
		else
		{
			cout<<"�޸�ʧ��,���޴���"<<endl;
		}
	}
	system("pause");
	system("cls");
}
//���ݱ�Ż����ֲ�����Ϣ
void workManger::findPe()
{
	if(this->Exist)
	{
		cout<<"�ļ������ڻ�Ϊ��"<<endl;
	}
	else          //�ļ�����
	{
		int num;
		cout<<"��������ҵķ�ʽ"<<endl;
		cout<<"1. ����Ų���"<<endl;
		cout<<"2.����������"<<endl;
		cin>>num;
		if(num==1)
		{
			int tar;
			cout<<"������Ҫ���ҵı��"<<endl;
			cin>>tar;
			int index=this->IsExist(tar);
			if(index!=-1)  //˵������
			{
				cout<<"���ҳɹ�"<<endl;
				this->tP[index]->showInfo();
			}
			else
			{
				cout<<"δ���ҵ�"<<endl;

			}
		}
		else if(num==2)
		{
			string name;
			cout<<"������Ҫ���ҵ�ְ������"<<endl;
			cin>>name;
			bool flag=false;
			for(int i=0;i<this->num;i++)
			{
				if(this->tP[i]->name==name)
				{
					cout<<"���ҳɹ�"<<endl;
					flag=true;
					this->tP[i]->showInfo();
					//������ͬ���ģ���˲���break
				}
			}
			if(!flag)
			{
				cout<<"���޴���"<<endl;
			}
		}
		else
		{
			cout<<"������������������"<<endl;
		}
	}
	system("pause");
	system("cls");
}
void workManger::idSort()
{
	if(this->Exist)
	{
		cout<<"�ļ������ڻ�Ϊ��"<<endl;
	}
	else
	{
		cout<<"ѡ������ʽ"<<endl;
		cout<<"1. ����"<<endl;
		cout<<"2.����"<<endl;
		int num;
		cin>>num;
		if(num==1)
		{
			this->upSort(); //����ɹ������
		}
		else
		{
			this->lowSort();
		}
	}
	system("pause");
	system("cls");
}
//��������
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
	cout<<"��������ɹ�"<<endl;
	cout<<"�����ȫ����ϢΪ"<<endl;
	this->save();
	this->showAll();
}
//��������
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
	cout<<"��������ɹ�"<<endl;
	cout<<"�����ȫ����ϢΪ"<<endl;
	this->save();
	this->showAll();
}
//����ļ�����
void workManger::cleanFile()
{
	cout<<"ȷ�����������"<<endl;
	cout<<"1.ȷ��"<<endl;
	cout<<"2.������һ��"<<endl;
	int select;
	cin>>select;
	if(select==1)
	{
		//trunc ���Ƿ������ļ�����ɾ��Ȼ�����´���
		ofstream ofs(FILENAME,ios::trunc);
		ofs.close();
		//Ȼ��ʼ�ͷŶ����Ŀռ�
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
		cout<<"��ճɹ�"<<endl;
	}
	system("pause");
	system("cls");
}