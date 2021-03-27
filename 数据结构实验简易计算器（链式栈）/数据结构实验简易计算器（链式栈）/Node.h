#ifndef __NODE_HPP__
#endif
#define __NODE_HPP__
// 结点类
template <class ElemType>
struct Node
{
	// 数据成员:
	ElemType data;   // 数据域
	Node<ElemType>* next;  // 指针域
   // 构造函数: 
	Node();      // 无参数的构造函数
	Node(ElemType item, Node<ElemType>* link = NULL); // 已知数数据元素值和指
};
template <class ElemType>
Node<ElemType>::Node() {
	this->data = -1;
	this->next = nullptr;
}
template <class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType>* link) {
	this->data = item;
	link = this;
	this->next = nullptr;
}
