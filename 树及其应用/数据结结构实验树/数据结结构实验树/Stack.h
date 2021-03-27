#pragma once
#include<stdio.h>
#include<malloc.h>
#include<iostream>
#define MaxSize 100

template<class ElemType>
class Stack
{
private:
	typedef struct
	{
		ElemType* data[MaxSize];
		int Top;//栈顶指针1
	}SqStack;
	SqStack* s;
public:
	Stack();
	~Stack();
	bool Push(ElemType* e);//将元素e压入栈中
	bool Pop(ElemType* e);//将栈顶元素出栈赋值给e
	bool GetTop(ElemType* e);//将栈顶元素赋值给e,并不进行出栈操作
	bool StackEmpty();//判断栈是否为空
	int GetNum();//得到栈顶指针
	ElemType* GetElement(int suf);//得到栈中指针为suf的元素

};

//构造函数
template<class ElemType>
Stack<ElemType>::Stack() {
	this->Top = -1;
	this->data = new ElemType[MaxSize];
}

//析构函数
template<class ElemType>
Stack<ElemType>::~Stack() {
	delete[]data;
}

//将元素压入栈中
template<class ElemType>
bool Stack<ElemType>::Push(ElemType* e) {
	if (this->Top == MaxSize - 1)
		cout << "栈满了" << endl;
	else {
		this->data[this->Top + 1] = e;
		this->Top++;
	}
	return 1;
}

//将栈顶元素出栈赋值给e
template <class ElemType>
bool Stack<ElemType>::Pop(ElemType* e) {
	if (this->GetTop == -1) {
		return 0;
	}
	else {
		*e = this->data[this->top];
		this->Top--;
	}
	return 1;

}

//将栈顶元素赋值给e，并不进行出栈操作
template <class ElemType>
bool Stack<ElemType>::GetTop(ElemType* e) {
	*e = this->data[this->Top];
	return 1;
}

//判断栈是否为空
template <class ElemType>
bool Stack<ElemType>::StackEmpty() {
	if (this->Top == -1)
		return 0;//空
	else
		return 1;//非空
}

//得到栈顶指针
template<class ElemType>
int Stack<ElemType>::GetNum() {
	return this->Top;
}

//得到栈中指针为suf的指针
template <class ElemType>
ElemType* Stack<ElemType>::GetElement(int suf) {
	for (int i = 0; i <Top; i++) {
		if (i == suf)
		{
			return ElemType * i;
		}
	}
}