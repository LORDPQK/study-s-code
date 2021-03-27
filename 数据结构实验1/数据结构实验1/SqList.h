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


template <class ElemType>
class SqList
{
protected:
	// 顺序表的数据成员
	int length;     // 顺序表的当前长度 
	int maxLength;    // 顺序表的最大容量
	ElemType* data;   // 元素存储空间的首地址 
public:
	// 顺序表的函数成 构造一个空表 
	SqList(int size = DEFAULT_SIZE) {
		this->length = 0;
		this->maxLength = size;
		data = new ElemType[DEFAULT_SIZE];
	}
	// 根据数组v的内容构造顺序表 
	template <class ElemType>
	SqList(ElemType v[], int n, int size = DEFAULT_SIZE) {
		this->data = new ElemType(DEFAULT_SIZE);
		this->length = n;
		this->maxLength = size;
		for (int i = 0; i < n; i++) {
			ElemType* p = new ElemType;
			*p = v[i];
			data[i] = *p;
		}
	}
	// 析构函数
	virtual ~SqList() {
	}
	// 取顺序表长度 
	int GetLength() const {
		return this->length;
	}
	// 判断顺序表是否为空
	bool IsEmpty() const {
		return this->length == 0;
	}
	// 将顺序表清空
	void Clear() {
		delete[] data;
		//this->length = 0;
	}
	// 遍历顺序表
	template <class ElemType>
	void Traverse(void(*Visit)(const ElemType&)) const {
		for (int i = 0; i < this->length; i++) {
			(*Visit)(data[i]);
		}
		if (this->length == 0)
			cout << "没有成员" << endl;
	}
	// 元素定位，求指定元素在顺序表中的位置
	template <class ElemType>
	int LocateElem(const ElemType& e) {
		int sign = 0;
		for (int i = 0; i < this->length; i++) {
			if (this->data[i] == e) {
				sign = 1;
				return i + 1;
			}
		}
		if (sign == 0)
			cout << "没有找到" << endl;
		return -1;
	}
	// 取顺序表中第i个元素的值
	template <class ElemType>
	int GetElem(int i, ElemType& e) const {

		if ((i - 1 <= this->length - 1) && i >= 0)
			e = data[i - 1];
		else
			cout << "没有找到" << endl;
		return 0;
	}
	// 修改顺序表中第i个元素的值
	template <class ElemType>
	int SetElem(int i, const ElemType& e) {
		if ((i <= this->length) && i >= 0)
			this->data[i - 1] = e;
		else
			cout << "没有找到" << endl;
		return 0;
	}
	// 删除顺序表中第i个元素  
	template <class ElemType>
	int DeleteElem(int i, ElemType& e) {
		e = this->data[i - 1];
		if ((i <= this->length) && i >= 0) {
			for (int j = i - 1; j < this->length - 1; j++)
				this->data[j] = this->data[j + 1];
			this->length--;
		}
		else
			cout << "没有找到" << endl;
		return 0;
	}
	// 在顺序表第i个位置插入元素
	template <class ElemType>
	int InsertElem(int i, const ElemType& e) {
		if (((i - 1 <= this->length) && i > 0)) {
			for (int j = this->length; j > i - 1; j--) {
				this->data[j] = this->data[j - 1];
			}
			this->data[i - 1] = e;
		}
		else
			cout << "没有找到" << endl;
		this->length++;
		return 0;
	}
	void change_two(int m) {
		ElemType a;
		a = this->data[m - 1];
		this->data[m - 1] = this->data[m + 1 - 1];
		this->data[m + 1 - 1] = a;
	}
	// 在顺序表表尾插入元素
	template <class ElemType>
	int InsertElem(const ElemType& e) {
		this->data[this->length] = e;
		this->length++;
		return 0;
	}
	// 复制构造函数
	template <class ElemType>
	SqList(const SqList<ElemType>& sa) {
		for (int i = 0; i < sa.GetLength(); i++) {
			this->data[i] = sa.data[i];
		}
		this->length = sa.GetLength();
	}
	// 赋值语句重载
	template <class ElemType>
	SqList<ElemType>& operator =(const SqList<ElemType>& sa) {
		SqList(sa);
		return *this;
	}
};