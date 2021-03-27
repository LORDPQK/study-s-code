#pragma once
#include<iostream>
using namespace std;
#ifndef __LINK_LIST_H__
#endif
#define __LINK_LIST_H__
#include "Node.h"     // 结点类
// 单链表类
template <class ElemType>
class LinkList
{
protected:
	//  单链表的数据成员
	Node<ElemType> *head;    // 头结点指针
	int length;     // 单链表长度 
public:
	// 无参数的构造函数
	LinkList() {
		this->head = new Node<ElemType>();
		this->length = 0;
	}
	// 有参数的构造函数
	LinkList(ElemType v[], int n) {
		this->length = n;
		for (int i = 0; i < n; i++) {
			Node<ElemType> *a = new Node<ElemType>;
			a->data = v[i];
			a->next = this->head->next;
			this->head->next = a;
		}
	}
	// 析构函数
	virtual ~LinkList() {
	}
	// 求单链表长度 
	int GetLength() const {
		return this->length;
	}
	// 判断单链表是否为空
	bool IsEmpty() const {
		return this->length == 0;
	}
	// 将单链表清空
	void Clear() {
		Node<ElemType>*p = this->head;
		while (this->head->next != nullptr) {
			p = p->next;
			this->head->next = this->head->next->next;
			delete p;
		}
		if (this->head->next == nullptr)
			this->length = 0;
		else
			cout << "清空失败！*********" << endl;
	}
	// 遍历单链表
	void Traverse(void(*Visit)(const ElemType &)) const {
		Node<ElemType>*p = this->head->next;
		while (p != nullptr) {
			(*Visit)(p->data);
			p = p->next;
		}
	}// 元素定位 
	int LocateElem(const ElemType &e) const {
		int sign = 0;
		int areyou = 0;
		Node<ElemType> *p = this->head;
		for (int i = 0; i < this->length; i++) {
			sign++;
			if (p->next->data == e) {
				areyou = 1;
				return sign;
			}
		}
		if (areyou = 0)
			cout << "没有这个数据" << endl;
		return 0;
	}
	// 求指定位置的元素
	int  GetElem(int index, ElemType &e) const {
		if (index > this->length)
			cout << "超出界限！" << endl;
		else {
			Node<ElemType> *p = this->head;
			for (int i = 0; i < index; i++) {
				p = p->next;
			}
			e = p->data;
		}
		return 0;
	}
	// 设置指定位置的元素值
	int SetElem(int index, const ElemType &e) {
		if (index > this->length)
			cout << "超出界限！" << endl;
		else {
			Node<ElemType> *p = this->head;
			for (int i = 0; i < index; i++) {
				p = p->next;
			}
			p->data = e;
		}
		return 0;
	}
	// 删除元素
	int DeleteElem(int index, ElemType &e) {
		if (index > this->length)
			cout << "超出界限！" << endl;
		else {
			Node<ElemType> *p = this->head;
			Node<ElemType> *m;
			for (int i = 1; i <= index - 1; i++) {
				p = p->next;
			}
			m = p->next;
			e = p->next->data;
			p->next = p->next->next;
			delete m;
			m = nullptr;
		}
		this->length--;
		return 0;
	}
	// 在制定位置插入元素
	int InsertElem(int index, const ElemType &e) {
		Node<ElemType> *p = this->head;
		Node<ElemType> *q = new Node<ElemType>();
		q->data = e;
		if (index > this->length + 1) {
			cout << "超出界限！" << endl;
		}
		else {
			this->length++;
			for (int i = 1; i < index; i++) {
				p = p->next;
			}
			q->next = p->next;
			p->next = q;
		}
		return 0;
	}
	//交换两个相邻元素的位置
	void change_two(int a) {
		Node<ElemType> *m1 = this->head;
		for (int i = 0; i < a - 1; i++)
			m1 = m1->next;
		Node<ElemType> *m2 = m1->next;
		Node<ElemType> *m3 = m2->next;
		m1->next = m3;
		m2->next = m3->next;
		m3->next = m2;
	}
	// 在表尾插入元素
	int InsertElem(const ElemType &e) {
		Node<ElemType> *p = this->head;
		Node<ElemType> *q = new Node<ElemType>();
		q->data = e;
		for (int i = 0; i < this->length; i++) {
			p = p->next;
		}
		p->next = q;
		this->length++;
		return 0;
	}
	// 复制构造函数
	LinkList(const LinkList<ElemType> &la) {
		Node<ElemType>*p;
		Node<ElemType>*q;
		p = this->head;
		q = la.head;
		for (int i = 0; i < this->length; i++) {
			Node<ElemType>*a = new Node<ElemType>;
			a->data = p->data;
			p = p->next;
			a->next = q->next;
			q->next = a;
		}
	}
	// 重载赋值运算
	LinkList<ElemType> &operator =(const LinkList<ElemType> &la) {
		LinkList(la);
		return *this;
	}
};