#pragma once
#ifndef _STACK_H_
#define _STACK_H_

#define MaxSize 100

#include <iostream>
using namespace std;
template<class ElemType>
class Stack
{
private:
	typedef struct
	{
		ElemType*  data[MaxSize];  //栈数据表            
		int    top;  //栈顶指针
	} SqStack;
	SqStack* S;
	
public:

	Stack() {
			S = (SqStack*)malloc(sizeof(SqStack));
			S->top = -1;
	}

	bool Push( ElemType* e)
	{
		if (S->top == MaxSize - 1)  //栈满，即栈上溢
			return false;
		S->top++;            //栈顶指针增1
		S->data[S->top] = e;  //元素e放在栈顶处
		return true;
	}

	bool Pop(ElemType*& e)
	{
		if (S->top == -1)    //栈为空，即栈下溢出
		return false;
		e = S->data[S->top];   //取栈顶指针元素
		S->top--;		//栈顶指针减1
		return true;
	}

	void Copy(Stack s) {
		Stack v;
		ElemType* p;
		while (!s.StackEmpty())
		{
			s.Pop(p);
			v.Push(p);
		}
		while (!v.StackEmpty())
		{
			v.Pop(p);
			Push(p);
		}
	}

	bool GetTop( ElemType* &e)
	{
		if (S->top == -1)  //栈为空，即栈下溢出 	   
			return false;
		e = S->data[S->top];   //取栈顶元素
		return true;
	}

	bool StackEmpty()
	{
		if (S->top == -1)
			return true;
		else
		{
			return false;
		}
	}

	int GetNum() 
	{
		return S->top;
	}

	void DestroyStack()
	{
		free(S);
	}

	ElemType* GetElemType(int suf)//得到栈中指针为suf的元素
	{
		return S->data[suf];
	}

};


#endif // !_STACK_H_
