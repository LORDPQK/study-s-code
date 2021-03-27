#ifndef __NODE_H__
#endif
#define __NODE_H__
// 结点类
template <class ElemType>
struct Node
{
	// 数据成员:
	ElemType data;    // 数据域
	Node<ElemType> *next;  // 指针域
   // 构造函数:
   // 无参数的构造函数
	Node() {
		this->next = nullptr;
	}
	// 已知数数据元素值和指针建立结构
	template <class ElemType>
	Node(ElemType e, Node<ElemType> *link) {
		this->data = e;
		link = this;
		this->next = nullptr;
	}
};