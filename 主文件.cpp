#include<iostream>
using namespace std;
#include<string>
#include"workManger.h"  //包含自己的类
#include"worker.h"

//class workManger;   不需要再次声明
 int main()
{
	/*worker *w=NULL;      测试代码
	w=new boss(1,"gby",2);
	w->showInfo();
	w=new normalPe(1,"gby",2);
	w->showInfo();*/
	workManger w;
	int choice=0;
	while (true)
	{
		w.showMenu();  //展示主菜单，接下来就是实现功能
		cout<<"请输入你的选择:"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 0:           //退出管理系统,实现退出系统函数
			w.exitSystem();
			break;
		case 1:             /*增加职工信息*/
			w.addPerson();
			break;
		case 2:			    /*显示职工信息*/
			w.showAll();
			break;		
		case 3:				/*删除离职员工*/
			w.delPe();
			break;
		case 4:				/*修改职工信息*/
			w.modiPe();
			break;
		case 5:				/*查找职工信息*/
			w.findPe();
			break;
		case 6:				/*按照编号排序*/
			w.idSort();
			break;
		case 7:				/*清空所有文档*/
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