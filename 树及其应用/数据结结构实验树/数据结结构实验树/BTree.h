#pragma once
#ifndef __BTREE_H__
#define __BTREE_H__

#include <stdio.h>
#include<malloc.h>
#include<iostream>
#include"Node.h"
#include"Stack.h"
#define MaxSize 100


using namespace std;

template <class ElemType>
class BTree
{
	//树的结构体定义
	typedef struct node
	{
		ElemType data;//树节点值
		struct node* lchild;//树节点左孩子
		struct node* rchild;//树节点右孩子
	}BTNode;
	BTNode* b;//根节点

public:
	BTree(std::string str);//根据括号表示法初始化树
	~BTree();
	void PostOrder();
	void PostOrderRe(BTNode* b = b);//后序遍历非递归算法
	void PreOrderNotRe();//先序遍历非递归算法
	void FindAllAncestor(char object);//输出节点obiectの所有长辈
	void ShowAncestor(BTNode* ancestor);//输出ancestor的值及其同辈的值
	                                    //孩子兄弟表示法中右子树代表兄弟
	void DestroyBTree(BTNode* &b);//销毁树

};

#endif __BTREE_H__

template<class ElemType>
BTree<class ElemType>::BTree(std::string str) {
	Node<ElemType>* node = NULL;//临时节点指针
	int n = 1;//1.左孩子 2.右孩子
	//用于装每个二叉树节点的栈
	Stack<Node<ElemType>*> *stack = new Stack<Node<ElemType>*>();


	while (*p != '0') {
		switch (*p)
		{
		case'(':
			stack->Push(node);
			n = 1;
			break;
		case',':
			n = 2;
			break;
		case')':
			stack->Pop();
			break;
		default:
			node->generationLevel = 1;
			if (b == NULL) {

			}

		}
	}

}
