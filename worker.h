#pragma once
#include<iostream>
#include<string>
using namespace std;

class worker
{
public:
	
	//��ʾ������Ϣ
	virtual void showInfo()=0;   //����Ϊ���麯�������������д
	virtual string getDepaId()=0;  //��ȡ��λ����

	string name;
	int id;     //ְ�����
	int depaId;   //ְ���������Ʊ��
};
//������ͨԱ����������ϰ��࣬�̳г�����
class normalPe:public worker
{
public:
	normalPe(int id,string name,int depaId);    //���캯������ʼ��
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