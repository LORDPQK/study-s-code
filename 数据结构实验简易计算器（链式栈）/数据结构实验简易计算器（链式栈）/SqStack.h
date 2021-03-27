#pragma once
#include"Node.h"
#include<iostream>
using namespace std;
template <class ElemType>
class SqStack {
protected:
	Node<ElemType>* top = new Node<ElemType>();
public:
	SqStack();    // 构造函数
	virtual ~SqStack();       // 析构函数
	int getLength() const;       // 求栈的长度  
	bool isEmpty() const;       // 判断栈是否为空
	void clear();         // 将栈清空
	void traverse(void(*Visit)(const ElemType&)) const; // 遍历栈
	int push(const ElemType e);        // 入栈
	int getTop(ElemType& e) const;        // 取顶元素
	int pop(ElemType& e);         // 出栈
	SqStack(const SqStack<ElemType>& s);  // 复制构造函数
	SqStack<ElemType>& operator =(const SqStack<ElemType>& s); // 赋值语句重载
};
// 构造函数
template <class ElemType>
SqStack<ElemType>::SqStack() {
	this->top->next = nullptr;
}
// 析构函数
template <class ElemType>
SqStack<ElemType>::~SqStack() {
}
// 求栈的长度    
template <class ElemType>
int SqStack<ElemType>::getLength() const {
	Node<ElemType>* a = this->top->next;
	int num = 0;
	while (a != nullptr) {
		num++;
		a = a->next;
	}
	return num;
}
// 判断栈是否为空
template <class ElemType>
bool SqStack<ElemType>::isEmpty() const {
	return this->top->next == nullptr;
}
// 将栈清空
template <class ElemType>
void SqStack<ElemType>::clear() {
	while (this->top->next != nullptr) {
		Node<ElemType>* a = this->top->next;
		this->top->next = this->top->next->next;
		delete a;
	}
}
// 遍历栈
template <class ElemType>
void SqStack<ElemType>::traverse(void(*Visit)(const ElemType&)) const {
	Node<ElemType>* a = this->top->next;
	while (a != nullptr) {
		(*Visit)(a->data);
		a = a->next;
	}
}
// 入栈
template <class ElemType>
int SqStack<ElemType>::push(const ElemType e) {
	Node<ElemType>* a = new Node<ElemType>();
	a->data = e;
	a->next = this->top->next;
	this->top->next = a;
	return 0;
}
// 取顶元素
template <class ElemType>
int SqStack<ElemType>::getTop(ElemType& e) const {
	if (this->top->next == nullptr) {
		cout << "栈空了" << endl;
	}
	else {
		e = this->top->next->data;
	}
	return 0;
}
// 出栈
template <class ElemType>
int SqStack<ElemType>::pop(ElemType& e) {
	if (this->top->next == nullptr)
		cout << "栈空了" << endl;
	else {
		e = this->top->next->data;
		this->top->next = this->top->next->next;
	}
	return 0;
}
// 复制构造函数
template <class ElemType>
SqStack<ElemType>::SqStack(const SqStack<ElemType>& s) {
	Node<ElemType>* a = s.top->next;
	Node<ElemType>* b = new Node<ElemType>();
	this->top->next = b;
	while (a != nullptr) {
		b->data = a->data;
		b = b->next;
		a = a->next;
		b = new Node<ElemType>();
	}
}
// 赋值语句重载
template <class ElemType>
SqStack<ElemType>& SqStack<ElemType>:: operator =(const SqStack<ElemType>& s) {
	SqStack(s);
}
