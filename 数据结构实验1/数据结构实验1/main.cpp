#include<iostream>
#include"SqList.h"
#include<string>
#include<cstring>
using namespace std;

typedef struct student {
	student() {
	}
	string name;
	string number;
	double performance;
public:
	void set_student() {
		cout << "输入姓名：" << endl;
		cin >> this->name;
		cout << "输入学号：" << endl;
		cin >> this->number;
		cout << "输入绩点：" << endl;
		cin >> this->performance;
	}
}student;
void print_student(const student& a) {
	cout << "姓名：" << a.name << " 学号：" << a.number << " 绩点：" << a.performance << endl;
}
void show_list() {
	cout << "1.显示：显示当前所有学生信息记录;" << endl;
	cout << "2.录入：从键盘输入一条学生信息记录，插入到表中指定的位置；" << endl;
	cout << "3.查找：根据学号或者记录的位置查找学生的各项信息；" << endl;
	cout << "4.删除：删除指定位置的学生信息记录；" << endl;
	cout << "5.更新：更新指定位置的学生信息记录；" << endl;
	cout << "6.统计：统计表中学生人数。" << endl;
	cout << "7. 排序：按照学号或者绩点进行排序." << endl;
	cout << "8.清空：清空表中所有记录." << endl;
	cout << "9.退出。" << endl;
}
//显示：显示当前所有学生信息记录；
void show_student(SqList<student>& a) {
	if (a.IsEmpty())
		cout << "没有学生" << endl;
	else {
		a.Traverse(print_student);
	}
}
//录入：从键盘输入一条学生信息记录，插入到表中指定的位置；
void set_massage(SqList<student>& a) {
	system("cls");
	int sign = 0;
	cout << "1.在尾部插入" << endl;
	cout << "2.输入插入位置" << endl;
	cin >> sign;
	if (sign == 1) {
		student m;
		m.set_student();
		a.InsertElem(m);
	}
	else if (sign == 2) {
		cout << "输入位置：(在1-" << a.GetLength() << "之间)" << endl;
		int i = 0;
		cin >> i;
		if (i<1 && i>a.GetLength()) {
			cout << "输入错误" << endl;
		}
		else {
			student m;
			m.set_student();
			a.InsertElem(i, m);
		}
	}
	else {
		cout << "输入错误" << endl;
	}

}
//查找：根据学号或者记录的位置查找学生的各项信息；
void find(SqList<student>& a) {
	system("cls");
	int sign = 0;
	student s;
	cout << "1.位置查找" << endl;
	cout << "2.学号查找" << endl;
	cout << "3.姓名查找" << endl;
	cin >> sign;
	if (sign == 1) {
		int m = 0;
		cout << "输入位置：(在1-" << a.GetLength() << "之间)" << endl;
		cin >> m;
		if (m > 0 && m <= a.GetLength()) {
			a.GetElem(m, s);
		}
		else {
			cout << "位置查找错误" << endl;
		}
		print_student(s);
	}
	else if (sign == 2) {
		string m;
		int ok = 0;
		cout << "输入学号：" << endl;
		cin >> m;
		for (int i = 1; i <= a.GetLength(); i++) {
			a.GetElem(i, s);
			if (s.number == m) {
				print_student(s);
				ok = 1;
				break;
			}
		}
		if (ok == 0)
			cout << "没找到" << endl;
	}
	else if (sign == 3) {
		string m;
		int ok = 0;
		cout << "输入姓名：" << endl;
		cin >> m;
		for (int i = 1; i <= a.GetLength(); i++) {
			a.GetElem(i, s);
			if (s.name == m) {
				print_student(s);
				ok = 1;
				break;
			}
		}
		if (ok == 0)
			cout << "没找到" << endl;
	}
	else {
		cout << "输入错误，请按序号输入" << endl;
	}
}
//删除：删除指定位置的学生信息记录；
void delete_him(SqList<student>& a) {
	int sign = 0;
	student s;
	cout << "输入位置：(在1-" << a.GetLength() << "之间)" << endl;
	cin >> sign;
	if (sign > 0 && sign <= a.GetLength()) {
		a.DeleteElem(sign, s);
		cout << "删除成功" << endl;
		cout << "信息：";
		print_student(s);
	}
	else {
		cout << "位置查找错误" << endl;
	}
}
//更新：更新指定位置的学生信息记录；
void change(SqList<student>& a) {
	system("cls");
	int sign = 0;
	student s;
	cout << "输入位置：(在1-" << a.GetLength() << "之间)" << endl;
	cin >> sign;
	if (sign > 0 && sign <= a.GetLength()) {
		a.GetElem(sign, s);
		cout << "原学生信息为：" << endl;
		print_student(s);
		cout << "更改为：" << endl;
		s.set_student();
		a.SetElem(sign, s);
		cout << "更新成功" << endl;
	}
	else {
		cout << "输入错误" << endl;
	}
}
//统计：统计表中学生人数。
void sum_student(SqList<student>& a) {
	system("cls");
	cout << "学生人数为：" << a.GetLength() << endl;
}
//排序：按照学号或者绩点进行排序
void sort(SqList<student>& a) {
	system("cls");
	if (a.GetLength() < 2) {
		cout << "人数过少，无法排序" << endl;
		return;
	}
	int sign = 0;
	cout << "1.按学号排列" << endl;
	cout << "2.按绩点排列" << endl;
	cin >> sign;
	if (sign < 1 && sign>2) {
		cout << "输入错误" << endl;
	}
	else {
		for (int i = 0; i < a.GetLength(); i++) {
			for (int j = 1; j < a.GetLength() - i; j++) {
				student s1, s2;
				a.GetElem(j, s1);
				a.GetElem(j + 1, s2);
				if (sign == 2) {
					if (s1.performance > s2.performance)
						a.change_two(j);
				}
				else {
					if (s1.number > s2.number) {
						a.change_two(j);
					}
				}
			}
		}
	}
	cout << "排序完成" << endl;
}
//清空：清空表中所有记录
void clear_all(SqList<student>& a) {
	for (int i = a.GetLength(); i > 0; i--) {
		student s;
		a.DeleteElem(i, s);
	}
	cout << "清空完成" << endl;
}
int main() {
	SqList<student>* list = new SqList<student>();
	while (1) {
		system("cls");
		show_list();
		int choise;
		cin >> choise;
		if (!(choise < 10 && choise>0))
			continue;
		switch (choise) {
		case 1: {
			show_student(*list);
			system("pause");
			break;
		}
		case 2: {
			set_massage(*list);
			system("pause");
			break;
		}
		case 3: {
			find(*list);
			system("pause");
			break;
		}
		case 4: {
			delete_him(*list);
			system("pause");
			break;
		}
		case 5: {
			change(*list);
			system("pause");
			break;
		}
		case 6: {
			sum_student(*list);
			system("pause");
			break;
		}
		case 7: {
			sort(*list);
			system("pause");
			break;
		}
		case 8: {
			clear_all(*list);
			system("pause");
			break;
		}
		case 9: {
			return 0;
			break;
		}
		}
	}
	system("pause");
	return 0;
}
