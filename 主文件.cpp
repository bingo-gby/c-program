#include<iostream>
using namespace std;
#include<string>
#include"workManger.h"  //�����Լ�����
#include"worker.h"

//class workManger;   ����Ҫ�ٴ�����
 int main()
{
	/*worker *w=NULL;      ���Դ���
	w=new boss(1,"gby",2);
	w->showInfo();
	w=new normalPe(1,"gby",2);
	w->showInfo();*/
	workManger w;
	int choice=0;
	while (true)
	{
		w.showMenu();  //չʾ���˵�������������ʵ�ֹ���
		cout<<"���������ѡ��:"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 0:           //�˳�����ϵͳ,ʵ���˳�ϵͳ����
			w.exitSystem();
			break;
		case 1:             /*����ְ����Ϣ*/
			w.addPerson();
			break;
		case 2:			    /*��ʾְ����Ϣ*/
			w.showAll();
			break;		
		case 3:				/*ɾ����ְԱ��*/
			w.delPe();
			break;
		case 4:				/*�޸�ְ����Ϣ*/
			w.modiPe();
			break;
		case 5:				/*����ְ����Ϣ*/
			w.findPe();
			break;
		case 6:				/*���ձ������*/
			w.idSort();
			break;
		case 7:				/*��������ĵ�*/
			w.cleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}