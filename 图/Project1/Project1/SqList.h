#pragma once
#ifndef __SQ_LIST_H__
#endif
#define __SQ_LIST_H__
// ANSI C++标准库头文件
#include <cstring>     // 标准串操作
#include <iostream>     // 标准流操作
using namespace std;
// 宏定义
#define DEFAULT_SIZE 1000   // 缺省元素个数
#define DEFAULT_INFINITY 1000000 // 缺省无穷大
// 顺序表模板类的申明 
template <class ElemType>
class SqList
{
protected:
	// 顺序表的数据成员
	int length;     // 顺序表的当前长度 
	int maxLength;    // 顺序表的最大容量
	ElemType* data;   // 元素存储空间的首地址 
public:
	// 顺序表的函数成员
	SqList(int size = DEFAULT_SIZE); // 构造一个空表 
	virtual ~SqList();   // 析构函数
	int GetLength() const;  // 取顺序表长度    
	int GetElem(int i, ElemType& e) const; // 取顺序表中第i个元素的值 
	int SetElem(int i, const ElemType& e); // 修改顺序表中第i个元素的值
	int DeleteElem(int i, ElemType& e);      // 删除顺序表中第i个元素  
	int InsertElem(const ElemType& e);        // 在顺序表表尾插入元素
};
// 构造一个空表
template<class ElemType>
SqList<ElemType>::SqList(int size) {
	this->length = 0;
	this->maxLength = size;
	data = new ElemType[DEFAULT_SIZE];
}
// 析构函数
template<class ElemType>
SqList<ElemType>::~SqList() {
}
// 取顺序表长度 
template<class ElemType>
int SqList<ElemType>::GetLength() const {
	return this->length;
}
// 取顺序表中第i个元素的值
template<class ElemType>
int SqList<ElemType>::GetElem(int i, ElemType& e) const {
	if ((i < this->length) && i >= 0)
		e = data[i];
	else
		cout << "没有找到" << endl;
	return 0;
}
// 修改顺序表中第i个元素的值
template<class ElemType>
int SqList<ElemType>::SetElem(int i, const ElemType& e) {
	if ((i < this->length) && i >= 0)
		this->data[i] = e;
	else
		cout << "没有找到" << endl;
	return 0;
}
// 删除顺序表中第i个元素  
template<class ElemType>
int SqList<ElemType>::DeleteElem(int i, ElemType& e) {
	e = this->data[i];
	if ((i < this->length) && i >= 0) {
		for (int j = i; j < this->length - 1; j++)
			this->data[j] = this->data[j + 1];
		this->length--;
	}
	else
		cout << "没有找到" << endl;
	return 0;
}
// 在顺序表表尾插入元素
template<class ElemType>
int SqList<ElemType>::InsertElem(const ElemType& e) {
	this->data[this->length] = e;
	this->length++;
	return 0;
}
#pragma once
