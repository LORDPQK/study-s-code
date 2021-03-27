#ifndef __SQ_STACK_HPP__
#endif
#define __SQ_STACK_HPP__
// ANSI C++标准库头文件
#include <cstring>     // 标准串操作
#include <iostream>     // 标准流操作
using namespace std;
#define DEFAULT_SIZE 100
template<class ElemType>
class SqStack
{
protected:
	// 顺序栈的数据成员:
	int top;          // 栈顶指针 
	int maxSize;         // 栈的最大容量 
	ElemType* data;        // 元素存储空间
public:
	//  顺序栈的方法声明及重载编译系统默认方法声明:
	SqStack(int size = DEFAULT_SIZE);    // 构造函数
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
template<class ElemType>
SqStack<ElemType>::SqStack(int size) {
	this->top = -1;
	this->maxSize = size;
	this->data = new ElemType[size];
}
// 析构函数
template<class ElemType>
SqStack<ElemType>::~SqStack() {
	delete[] data;
}
// 求栈的长度
template<class ElemType>
int SqStack<ElemType>::getLength() const {
	return this->top + 1;
}
// 判断栈是否为空
template<class ElemType>
bool SqStack<ElemType>::isEmpty() const {
	return this->top == -1;
}
// 将栈清空
template<class ElemType>
void SqStack<ElemType>::clear() {
	this->top = -1;
}
// 遍历栈
template<class ElemType>
void SqStack<ElemType>::traverse(void(*Visit)(const ElemType&)) const {
	for (int i = 0; i <= this->top; i++) {
		(*Visit)(data[i]);
	}
}
// 入栈
template<class ElemType>
int SqStack<ElemType>::push(const ElemType e) {
	if (this->top == DEFAULT_SIZE - 1)
		cout << "栈满了" << endl;
	else {
		this->data[this->top + 1] = e;
		this->top++;
	}
	return 0;
}
// 取顶元素
template<class ElemType>
int SqStack<ElemType>::getTop(ElemType& e) const {
	if (this->top == -1)
		cout << "栈空了" << endl;
	else
		e = this->data[this->top];
	return 0;
}
// 出栈
template<class ElemType>
int SqStack<ElemType>::pop(ElemType& e) {
	if (this->top == -1)
		cout << "栈空了" << endl;
	else {
		e = this->data[this->top];
		this->top--;
	}
	return 0;
}
// 复制构造函数
template<class ElemType>
SqStack<ElemType>::SqStack(const SqStack<ElemType>& s) {
	this->top = s.top;
	for (int i = 0; i < s.top; i++) {
		this->data[i] = s.data[i];
	}
}
// 赋值语句重载
template<class ElemType>
SqStack<ElemType>& SqStack<ElemType>::operator =(const SqStack<ElemType>& s) {
	this->top = s.top;
	for (int i = 0; i < s.top; i++) {
		this->data[i] = s.data[i];
	}
}
