#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include"student.h"
#include<vector>
class Teacher:public Identity
{
public:
	

	 //Ĭ�Ϲ���
	Teacher();

	Teacher(string name, string pwd, int empId);
	
	//�вι���
	Teacher(int empId,string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validMyOrder();

	//ְ�����
	int m_Emid;
};
