#include"worker.h"

normalPe::normalPe(int id,string name,int depaId)
{
	this->name=name;
	this->id=id;
	this->depaId=depaId;
}
void normalPe::showInfo()
{
	cout<<"ְ�����:"<<id
		<<"\tְ������:"<<name
		<<"\t��λ:"<<this->getDepaId()
		<<"\t��λְ��:��ɾ�����������"<<endl;
}
string normalPe::getDepaId()
{
	return ("��ͨԱ��");
}

manger::manger(int id,string name,int depaId)
{
	this->name=name;
	this->id=id;
	this->depaId=depaId;
}
void manger::showInfo()
{
	cout<<"ְ�����:"<<id<<"\tְ������:"<<name<<"\t��λ:"<<this->getDepaId()<<"\t��λְ��:����ϰ彻���������·������Ա��"<<endl;
}
string manger::getDepaId()
{
	return "����";
}

boss::boss(int id,string name,int depaId)
{
	this->name=name;
	this->id=id;
	this->depaId=depaId;
}
void boss::showInfo()
{
	cout<<"ְ�����:"<<id<<"\tְ������:"<<name<<"\t��λ:"<<this->getDepaId()<<"\t��λְ��:����ȫ��˾"<<endl;
}
string boss::getDepaId()
{
	return "�ϰ�";
}