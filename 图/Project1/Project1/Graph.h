#pragma once
#pragma once
#define numMAX 20
#define StrMAX 100
#define MAX 1000
#include<iostream>
#include<string>
#include"SqList.h"
#include<vector>
using namespace std;
//节点结构体
struct Vex {
	string code;
	string Name;
};
//边结构体
struct Edge {
	Vex vex1;
	Vex vex2;
	int weight = -1;
};
class Graph {
private:
	int AdjMatrix[numMAX][numMAX];//邻接矩阵
	SqList<Vex>Vexs;   //点的集合
	SqList<Edge>Edges;   //边的集合
	int VexNum;     //点的个数
public:
	Graph();
	~Graph();
	bool InsertVex(Vex svex);    //增加节点
	bool DeleteVex(Vex svex);    //删除节点
	bool UpdateVex(Vex svex);    //更新节点
	bool InsertEdges(Edge sedge);   //增加边
	bool DeleteEdges(Edge sedge);   //删除边
	bool UpdateEdges(Edge sedge);   //更新边
	Edge GetEdge(char* vex1Code, char* vex2Code);//得到边
	Vex GetVex(char*vex1Code);    //得到点
	void SetVexNum(int);     //更新节点数
	int PrimMinTree(Edge aPath[]);   //prim算法实现最小生成树
	int KruskalMinTree(Edge aPath[]);  //kruskal算法实现最小生成树
	void showMassage();      //打印顶点和边的信息
private:
	bool isConnect(Edge b, Edge outEdges[], int n);
};
