# c-program
一个自己练手的基于多态的职工管理系统职工管理系统用于管理公司内所有员工的信息
利用c++来实现一个基于多态的职工管理系统
职工分为三类：普通员工、经理和老板
显示信息时，需要显示职工编号、职工姓名、职工岗位以及职责
普通员工：完成经理交给的任务
经理职责：完成老板交给的任务，并下放任务给员工
老板职责：管理公司所有事物

实现的功能：
1.退出管理程序
2.增加职工信息：实现批量增加职工功能，将信息录入到文件中，职工信息为职工编号、姓名、部门编号
3.显示职工信息：显示公司内部所有职工信息
4 删除离职员工  根据编号删除
5 修改职工信息，根据编号修改
6 查找职工信息 根据编号和姓名
7.按照编号排序 排序规则由用户指定
8 清空所有文档 清空前再次确认 防止误删
 
 每次运行程序需要将文件中数据读取到程序中，有三种情况
 1. 第一次使用，文件未创建
 2. 文件存在，但是数据被清空
 3. 文件存在，且保存职工的所有数据
 在构造函数里实现


 删除 更改职工需要先查找职工是否存在
