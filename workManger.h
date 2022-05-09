#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
#define FILENAME "file.txt"
#include<fstream>
//头文件写声明，定义

class workManger
{
public:
	workManger();
	void showMenu();  //展示菜单
	void exitSystem();  //退出系统函数
	void addPerson();  //增加职工函数，并且要搞个文件保存
	void save();       //添加职工之后，保存到文件中
	int getNum();  //获得文件内职工的个数
	void init_tP();  //初始化数组指针
	void showAll();   //显示所有员工信息
	void delPe();     //删除员工操作
	void modiPe();    //修改职工操作
	void findPe();    //查找职工，根据名字或编号
	void idSort();    //根据升序或者降序排列
	void upSort();    //升序排列
	void lowSort();		//降序排列
	void cleanFile();   //清空文件操作
	int IsExist(int id);   // 判断职工是否存在，存在返回下标，不存在就返回-1
	~workManger();    //直接声明即可，定义在源文件中写空实现

	int num;     //记录文件中人的个数
	worker **tP; //员工数组的指针
	bool Exist;  //标志文件是否存在
	
};