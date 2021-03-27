#pragma once
#ifndef _TREE_H_
#define _TREE_H_

#include<iostream>
#include"stack.h"

template<class ElemType>
class BTree
{
private:
	typedef struct node
	{
		ElemType data;
		struct node* lchild;
		struct node* rchild;
	} BTNode;

	BTNode* B;  //根节点
	std::string aTree;
public:
	string getatree() {
		return aTree;
	}

	BTree(std::string str)
	{
		char ch;
		BTNode* p, *r;
		p = r = NULL;
		aTree = str;
		Stack<BTNode> stack;
		int  k, j = 0;                //k决定谁是左、右孩子

		while ((ch = str[j]) != '\0')
		{
			switch (ch)
			{
			case '(':
				stack.Push(r);          //根节点入栈 
				r = p;
				k = 1;                    //1为左孩子 
				break;
			case ',':
				k = 2;					//2为右孩子 
				break;
			case ')':
				stack.Pop(r);                  //根节点出栈 
				break;
			default:
				p = (BTNode*)malloc(sizeof(BTNode));
				p->data = ch;
				p->lchild = p->rchild = NULL;
				if (B == NULL)        //树为空时 
				{
					B = p;
					r = B;
				}
				else                   //树非空时 
				{
					switch (k)
					{
					case 1:
						r->lchild = p;//根节点的左孩子 
						break;
					case 2:
						r->rchild = p;//根节点的右孩子 
						break;
					}
				}
			}
			j++;
		}
	}

	BTNode* GetBTNode() {
		return B;
	}

	void PreOrder(BTNode* B)//先序非递归
	{
		if (B != NULL)
		{
			cout << B->data;    //访问根结点
			PreOrder(B->lchild);
			PreOrder(B->rchild);
		}
	}

	void PreOrderNotRe()
	{
		BTNode* p;  Stack<BTNode> st;	//定义一个顺序栈
		p = B;
		while (!st.StackEmpty() || p != NULL)
		{
			while (p != NULL)	 //访问结点p及其所有左下结点并进栈
			{
				cout << p->data;	//访问结点p
				st.Push(p);		//结点p进栈
				p = p->lchild;		//移动到左孩子
			}
			//以下考虑栈顶结点
			if (!st.StackEmpty())	 //若栈不空
			{
				st.Pop(p);	//出栈结点p
				p = p->rchild;	//转向处理其右子树
			}
		}
		cout << endl;
	}

	void InOrderNotRe()
	{
		BTNode* p;  Stack<BTNode> st;	//定义一个顺序栈
		p = B;
		while (!st.StackEmpty() || p != NULL)
		{
			while (p != NULL)	//扫描结点p的所有左下结点并进栈
			{
				st.Push(p);		//结点p进栈
				p = p->lchild;	//移动到左孩子
			}
			//以下考虑栈顶结点
			if (!st.StackEmpty())	//若栈不空
			{
				st.Pop(p);		//出栈结点p，访问结点p
				cout << p->data;
				p = p->rchild;    //转向处理其右子树
			}
		}
		cout << endl;
	}

	void PostOrderNotRe(BTNode* b)	//后序非递归遍历算法
	{
		BTNode* p, *r;
		bool flag;
		Stack<BTNode> st;		//定义一个顺序栈
		p = b;
		do
		{
			while (p != NULL)	//扫描结点p的所有左下结点并进栈
			{
				st.Push(p);		//结点p进栈
				p = p->lchild;	//移动到左孩子
			}
			r = NULL;		//r指向刚刚访问的结点，初始时为空
			flag = true;
			while (!st.StackEmpty() && flag)
			{
				st.GetTop(p);	         //取出当前的栈顶结点p
				if (p->rchild == r)        //若结点p的右孩子为空或者为刚访问结点	
				{
					cout << p->data;    //访问结点p
					st.Pop(p);
					r = p;		 //r指向刚访问过的结点
				}
				else
				{
					p = p->rchild;	//转向处理其右子树
					flag = false;		//表示当前不是处理栈顶结点
				}
			}
		} while (!st.StackEmpty());	//栈不空循环
		cout << endl;
	}

	void DestoryTree(BTNode*& b) {
		free(b);
	}

	template<int N>
	void ShowAncenstor(int row, BTNode* e[N][N], char object) //输出长辈和其同辈以及晚辈的值
	{

		int  col = 0;
		if (row < 0)
		{
			cout << "没有该成员";
			return;
		}
		cout << object << "的长辈有：";
		for (int i = 0; i < row; i++, col = 0)
			while (e[i][col] != NULL)
			{
				cout << e[i][col]->data;
				col++;
			}
		col = 0;
		cout << endl;
		cout << object << "的同辈有:";
		while (e[row][col] != NULL)
		{
			cout << e[row][col]->data;
			col++;
		}
		col = 0;
		row++;
		cout << endl << object << "的晚辈有:";
		while (e[row][col] != NULL) {
			while (e[row][col] != NULL)
			{
				cout << e[row][col]->data;
				col++;
			}
			col = 0;
			row++;
		}
		cout << endl;
	}


	/*****************************************************************************
	用一个BTNode* e[i][j]二维数组来表示辈分，i表示不同辈分，j表示这个辈分中的人数。
	根结点添加到e[0][0],开始遍历第i行的内容直到后面的为空，再开始遍历i+1行的内容。
	遍历时，每个元素有右孩子时直接添加的当前辈分的后继，有左孩子直接添加的下一行的后继。
	直到e[i][0]=NULL为止。
	*********************************************************************************/
	template<int N>
	void ClsGenerations(BTNode* e[N][N])//对不同的辈分进行分类
	{

		BTNode* p;
		p = B;
		//i为当前层次的还没有读取的个数，now为本层次的个数。next为下一个层次的个数；
		int deep = 0, i = 0, now = 0, next = 0;
		if (p == NULL)
			return;
		e[0][0] = p;
		now++;
		while (e[deep][i] != NULL)
		{
			while (e[deep][i] != NULL)//遍历当前深度的所有数据
			{
				if (e[deep][i]->rchild != NULL)//右孩子保存至当前深度的后继
				{
					e[deep][now] = e[deep][i]->rchild;
					now++;
				}
				if (e[deep][i]->lchild != NULL)//左孩子保存在下一个深度的后继 
				{
					e[deep + 1][next] = e[deep][i]->lchild;
					next++;
				}
				i++;
			}
			deep++;
			i = 0;
			now = next;
			next = 0;
		}
	}

	void intiarray(BTNode* e[100][100])
	{
		//初始化
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				e[i][j] = NULL;

	}

	void  FindAllAncenstor(char object)//找到同辈及其长辈
	{
		BTNode* e[MaxSize][MaxSize];

		intiarray(e);

		ClsGenerations<MaxSize>(e);
		int row = -1;		//用来记录元素所在行
		int col = 0;		//记录列
		int flag = false;		//找到元素的标志
		while (!flag)
		{
			row++;
			col = 0;
			while (e[row][col] != NULL)
			{
				if (e[row][col]->data == object)
				{
					flag = true;
				}
				col++;
			}

		}
		ShowAncenstor<MaxSize>(row, e, object);
	}


};



#endif // !tree
