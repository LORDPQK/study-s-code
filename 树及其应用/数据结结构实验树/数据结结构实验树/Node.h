#pragma once
template<class ElemType>
class Node
{
public:
	Node<ElemType> *leftchild;//左孩子
	Node<ElemType> *reftchild;//右孩子
	ElemType data;//节点的值
	int generationLevel;//该节点所在的辈分
	

	Node();
	Node(ElemType data);
	~Node();
};

template<class ElemType>
Node<class ElemType>::Node() {

}

template<class ElemType>
Node<class ElemType>::Node(ElemType data) {
	this->data = data;

}

template<class ElemType>
Node<class ElemType>::~Node() {

}




