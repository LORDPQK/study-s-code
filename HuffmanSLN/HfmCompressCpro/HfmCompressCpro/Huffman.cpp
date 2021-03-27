#define _CRT_SECURE_NO_WARNINGS
#include"Huffman.h"
#include<iostream>
#include<malloc.h>

#define OK 1
#define ERROR 0

using namespace std;

//create Huffman tree
int CreateHuffmanTree(HuffmanTree pHT, int weight[], int n)
{
	int s1, s2, i;
	int m = 2 * n - 1;
	
	//initialization
	for (i = 1; i <= n; i++) {
		pHT[i].weight = weight[i - 1];
		pHT[i].lchild = 0;
		pHT[i].rchild = 0;
		pHT[i].parent = 0;
	}
	for (i = n + 1; i <= m; i++) {
		pHT[i].weight = 0;
		pHT[i].lchild = 0;
		pHT[i].rchild = 0;
		pHT[i].parent = 0;
	}
	for (i = n + 1; i <= m; i++)
	{
		//从pHT[1...i-1]中选择parent为0且weight最小的两个结点，其序号分别s1,s2
		Select(pHT, i - 1,s1,s2);

		//修改s1,s2结点的父指针parent
		pHT[s1].parent = i;
		pHT[s2].parent = i;

		//修改i结点的左右孩子指针
		pHT[i].lchild = s1;
		pHT[i].rchild = s2;

		pHT[i].weight = pHT[s1].weight + pHT[s2].weight;//修改权值
	}
		return OK;

	}


// 查找Huffman树节点数组中权值最小的节点
void Select(HuffmanTree &pHT, int i, int &s1, int &s2) {
	int minValue = 0x7FFFFFFF;

	//找到最小的一个权值
	for (int j = 1; j <= i; j++) {
		if (pHT[j].parent == 0 && pHT[j].weight < minValue) {
			minValue = pHT[j].weight;
			s1 = j;
		}
	}

	minValue = 0x7FFFFFFF;
	//找到倒数第二小的权值
	for (int j = 1; j <= i; j++) {
		if (j != s1 && pHT[j].parent == 0 && pHT[j].weight < minValue) {
			minValue = pHT[j].weight;
			s2 = j;
		}
	}
}

int TestHuTree(HuffmanTree pHT) {
	cout << "huffmanTree的每个结点的信息为" << endl;
	cout << "Byte\t\tWeight\tParent\tLchild\tRchild\n";
	for (int i = 1; i < 512; i++) {
		//判断语句为了对齐格式
		if(i<=99)
			cout << "pHT[" << i << "]\t\t" << pHT[i].weight << "\t" << pHT[i].parent << "\t" << pHT[i].lchild << "\t" << pHT[i].rchild << endl;
		else
			cout << "pHT[" << i << "]\t" << pHT[i].weight << "\t" << pHT[i].parent << "\t" << pHT[i].lchild << "\t" << pHT[i].rchild << endl;
		}
	return OK;
}


//生成Huffman编码 
int HuffmanCoding(HuffmanCode &pHC, HuffmanTree &pHT)
{
	//无栈非递归遍历Huffman树，求Huffman编码
	char cd[256] = { '\0' };	//记录访问路径
	int cdlen = 0;				//记录当前路径长度

	for (int i = 1; i < 512; i++)
		pHT[i].weight = 0;	//遍历Huffman树时用做节点的状态标志

	int p = 511;			//根节点
	while (p != 0) {
		//向左
		if (pHT[p].weight == 0) {
			pHT[p].weight = 1;
			if (pHT[p].lchild != 0) {
				p = pHT[p].lchild;
				cd[cdlen++] = '0';
			}
			//登记叶子节点的字符的编码
			else if (pHT[p].rchild == 0) {
				pHC[p] = (char*)malloc((cdlen + 1) * sizeof(char));
				cd[cdlen] = '\0';
				strcpy(pHC[p], cd);//复制编码
			}
		}
		//向右
		else if (pHT[p].weight == 1) {
			pHT[p].weight = 2;
			//右孩子为叶子节点
			if (pHT[p].rchild != 0) {
				p = pHT[p].rchild;
				cd[cdlen++] = '1';
			}
		}
		//退回父节点，编码长度减一
		else {
			pHT[p].weight = 0;
			p = pHT[p].parent;
			cdlen--;
		}
	}
	return OK;
}


void TestHufCode(int root, HuffmanTree &pHT, HuffmanCode &pHC) {
	if (root <= 1) return;

	if (pHT[root].lchild == 0 && pHT[root].rchild == 0)
		printf("0x%02X\t%s\n", root - 1, pHC[root - 1]);
	if (pHT[root].lchild)//访问左孩子
		TestHufCode(pHT[root].lchild, pHT, pHC);
	if (pHT[root].rchild)//访问右孩子
		TestHufCode(pHT[root].rchild, pHT, pHC);
}





