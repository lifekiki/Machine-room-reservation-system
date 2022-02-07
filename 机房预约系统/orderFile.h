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
	//构造函数
	OrderFile();

	//更新预约次数
	void updateOrder();

	//记录的容器 key---记录的次数  value---具体记录的键值对信息
	map<int, map<string, string>> m_orderData;

	//预约记录次数
	int m_Size;
};