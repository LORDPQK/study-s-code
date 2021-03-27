#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Graph.h"
#include"Tourism.h"
using namespace std;


int main(void)
{
	int choice;
	while (true)
	{
		cout << "==== 景区管理系统 ====" << endl;
		cout << "1.创建景区景点图" << endl;
		cout << "2.查询景点信息" << endl;
		cout << "3.旅游景点导航" << endl;
		cout << "4.搜索最短路径" << endl;
		cout << "5.铺设电路规划" << endl;
		cout << "0.退出" << endl;
		cout << "请输入操作编号(0~5):" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			CreateGraph();
			system("pause");
			break;
		case 2:
			system("cls");
			GetSpotInfo();
			system("pause");
			break;
		default:
			cout << "输入错误编号 默认退出系统" << endl;
			exit(0);
			break;
		}
	}
}