#include<iostream>
#include<string>
#include"SqStack.h"
using namespace std;
void zhong(SqStack<char>& s2) {
	string all;
	cout << "请输入中缀表达式：" << endl;
	cin >> all;
	int a = 0;
	for (int i = 0; i <= all.length(); i++) {
		if (all[i] <= '9' && all[i] >= '0') {
			while (true) {
				a = a * 10 + (int)(all[i] - '0');
				i++;
				if (!(all[i] <= '9' && all[i] >= '0')) {
					cout << a << " ";
					a = 0;
					break;
				}
			}
		}
		if (all[i] == '(')
			s2.push(all[i]);
		if (all[i] == '+' || all[i] == '-' || all[i] == '*' || all[i] == '/') {
			while (true) {
				char p;
				if (s2.isEmpty()) {
					s2.push(all[i]);
					break;
				}
				else
					s2.getTop(p);
				if (p == '(') {
					s2.push(all[i]);
					break;
				}
				else if (all[i] == '+' || all[i] == '-') {
					s2.pop(p);
					cout << p;
					s2.push(all[i]);
					break;
				}
				else {
					if (p == '*' || p == '/') {
						s2.pop(p);
						cout << p;
						break;
					}
					else
					{
						s2.push(all[i]);
						break;
					}
				}
			}
		}
		if (all[i] == ')') {
			while (true) {
				char n;
				s2.getTop(n);
				if (n == '(') {
					s2.pop(n);
					break;
				}
				else {
					cout << n;
					s2.pop(n);
				}
			}
		}
	}
	while (true) {
		if (s2.isEmpty())
			break;
		else {
			char c;
			s2.pop(c);
			cout << c;
		}
	}
	cout << endl;
}
void hou(SqStack<int>& s1) {
	cout << "输入后缀表达式：" << endl;
	string all;
	string f;
	getline(cin, f);
	getline(cin, all);
	int a = 0;
	for (int i = 0; i < all.length(); i++) {
		if (all[i] <= '9' && all[i] >= '0') {
			while (true) {
				a = a * 10 + (int)(all[i] - '0');
				i++;
				if (!(all[i] <= '9' && all[i] >= '0')) {
					s1.push(a);
					a = 0;
					break;
				}
			}
		}
		if (all[i] == ' ') {
			continue;
		}
		else if (!(all[i] <= '9' && all[i] >= '0')) {
			int a;
			int b;
			s1.pop(a);
			s1.pop(b);
			if (all[i] == '+')
				s1.push(b + a);
			else if (all[i] == '-')
				s1.push(b - a);
			else if (all[i] == '*')
				s1.push(b * a);
			else if (all[i] == '/')
				s1.push(b / a);
			else
				cout << "输入错误" << endl;
		}
	}
	int ave;
	s1.getTop(ave);
	cout << "结果是：" << ave << endl;
}
int main() {
	SqStack<int>* z_stack = new SqStack<int>();
	SqStack<char>* h_stack = new SqStack<char>();
	int sign = 0;
	while (true) {
		cout << "（1）从键盘录入中缀表达式，将中缀表达式转换为后缀表达式输出" << endl;
		cout << "（2）输入后缀表达式，计算后缀表达式的值" << endl;
		cout << "（3）退出" << endl;
		cin >> sign;
		switch (sign) {
		case 1:
			zhong(*h_stack);
			break;
		case 2:
			hou(*z_stack);
			break;
		case 3:
			return 0;
			break;
		}
	}
	system("pause");
	return 0;
}