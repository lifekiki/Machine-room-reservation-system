#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include"student.h"
#include<vector>
class Teacher:public Identity
{
public:
	

	 //默认构造
	Teacher();

	Teacher(string name, string pwd, int empId);
	
	//有参构造
	Teacher(int empId,string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validMyOrder();

	//职工编号
	int m_Emid;
};
