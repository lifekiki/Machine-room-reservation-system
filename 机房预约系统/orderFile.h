#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"student.h"
#include"globalFile.h"
#include<map>

class OrderFile
{
public:
	//���캯��
	OrderFile();

	//����ԤԼ����
	void updateOrder();

	//��¼������ key---��¼�Ĵ���  value---�����¼�ļ�ֵ����Ϣ
	map<int, map<string, string>> m_orderData;

	//ԤԼ��¼����
	int m_Size;
};