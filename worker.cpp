#include"worker.h"

normalPe::normalPe(int id,string name,int depaId)
{
	this->name=name;
	this->id=id;
	this->depaId=depaId;
}
void normalPe::showInfo()
{
	cout<<"职工编号:"<<id
		<<"\t职工姓名:"<<name
		<<"\t岗位:"<<this->getDepaId()
		<<"\t岗位职责:完成经理交给的任务"<<endl;
}
string normalPe::getDepaId()
{
	return ("普通员工");
}

manger::manger(int id,string name,int depaId)
{
	this->name=name;
	this->id=id;
	this->depaId=depaId;
}
void manger::showInfo()
{
	cout<<"职工编号:"<<id<<"\t职工姓名:"<<name<<"\t岗位:"<<this->getDepaId()<<"\t岗位职责:完成老板交给的任务并下放任务给员工"<<endl;
}
string manger::getDepaId()
{
	return "经理";
}

boss::boss(int id,string name,int depaId)
{
	this->name=name;
	this->id=id;
	this->depaId=depaId;
}
void boss::showInfo()
{
	cout<<"职工编号:"<<id<<"\t职工姓名:"<<name<<"\t岗位:"<<this->getDepaId()<<"\t岗位职责:管理全公司"<<endl;
}
string boss::getDepaId()
{
	return "老板";
}