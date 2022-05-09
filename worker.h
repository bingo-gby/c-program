#pragma once
#include<iostream>
#include<string>
using namespace std;

class worker
{
public:
	
	//显示个人信息
	virtual void showInfo()=0;   //设置为纯虚函数，子类必须重写
	virtual string getDepaId()=0;  //获取岗位名称

	string name;
	int id;     //职工编号
	int depaId;   //职工所在名称编号
};
//创建普通员工、经理和老板类，继承抽象类
class normalPe:public worker
{
public:
	normalPe(int id,string name,int depaId);    //构造函数，初始化
	void showInfo();
	string getDepaId();
};
class manger:public worker
{
public:
	manger(int id,string name,int depaId);
	void showInfo();
	string getDepaId();
};
class boss:public worker
{
public:
	boss(int id,string name,int depaId);
	void showInfo();
	string getDepaId();
};