#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
#define FILENAME "file.txt"
#include<fstream>
//ͷ�ļ�д����������

class workManger
{
public:
	workManger();
	void showMenu();  //չʾ�˵�
	void exitSystem();  //�˳�ϵͳ����
	void addPerson();  //����ְ������������Ҫ����ļ�����
	void save();       //���ְ��֮�󣬱��浽�ļ���
	int getNum();  //����ļ���ְ���ĸ���
	void init_tP();  //��ʼ������ָ��
	void showAll();   //��ʾ����Ա����Ϣ
	void delPe();     //ɾ��Ա������
	void modiPe();    //�޸�ְ������
	void findPe();    //����ְ�����������ֻ���
	void idSort();    //����������߽�������
	void upSort();    //��������
	void lowSort();		//��������
	void cleanFile();   //����ļ�����
	int IsExist(int id);   // �ж�ְ���Ƿ���ڣ����ڷ����±꣬�����ھͷ���-1
	~workManger();    //ֱ���������ɣ�������Դ�ļ���д��ʵ��

	int num;     //��¼�ļ����˵ĸ���
	worker **tP; //Ա�������ָ��
	bool Exist;  //��־�ļ��Ƿ����
	
};