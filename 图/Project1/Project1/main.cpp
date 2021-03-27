#include<iostream>
#include<string>
#include"Graph.h"
#include"SqList.h"
using namespace std;

void test01(Graph* graph) {
	//输入测试数据
	Vex v1; v1.code = "V1"; v1.Name = "北京";
	Vex v2; v2.code = "V2"; v2.Name = "成都";
	Vex v3; v3.code = "V3"; v3.Name = "武汉";
	Vex v4; v4.code = "V4"; v4.Name = "上海";
	Vex v5; v5.code = "V5"; v5.Name = "广州";
	Vex v6; v6.code = "V6"; v6.Name = "深圳";
	graph->InsertVex(v1);
	graph->InsertVex(v2);
	graph->InsertVex(v3);
	graph->InsertVex(v4);
	graph->InsertVex(v5);
	graph->InsertVex(v6);
	Edge e1; e1.vex1 = v1; e1.vex2 = v2; e1.weight = 6;
	Edge e2; e2.vex1 = v1; e2.vex2 = v3; e2.weight = 1;
	Edge e3; e3.vex1 = v1; e3.vex2 = v4; e3.weight = 5;
	Edge e4; e4.vex1 = v2; e4.vex2 = v3; e4.weight = 5;
	Edge e5; e5.vex1 = v2; e5.vex2 = v5; e5.weight = 3;
	Edge e6; e6.vex1 = v3; e6.vex2 = v4; e6.weight = 5;
	Edge e7; e7.vex1 = v3; e7.vex2 = v5; e7.weight = 6;
	Edge e8; e8.vex1 = v3; e8.vex2 = v6; e8.weight = 4;
	Edge e9; e9.vex1 = v4; e9.vex2 = v6; e9.weight = 2;
	Edge e10; e10.vex1 = v5; e10.vex2 = v6; e10.weight = 6;
	graph->InsertEdges(e1);
	graph->InsertEdges(e2);
	graph->InsertEdges(e3);
	graph->InsertEdges(e4);
	graph->InsertEdges(e5);
	graph->InsertEdges(e6);
	graph->InsertEdges(e7);
	graph->InsertEdges(e8);
	graph->InsertEdges(e9);
	graph->InsertEdges(e10);
	cout << "添加成功" << endl;
	system("pause");
}
int main() {
	Graph *graph = new Graph();
	Edge a[10];
	while (1) {
		system("cls");
		cout << "1.测试案例" << endl;
		cout << "2.添加顶点" << endl;
		cout << "3.添加边" << endl;
		cout << "4.prim算法" << endl;
		cout << "5.kruskal算法" << endl;
		cout << "6.删除修改信息" << endl;
		cout << "7.打印顶点和边的信息" << endl;
		cout << "8.退出" << endl;
		int m;
		cin >> m;
		switch (m) {
		case 1: {
			test01(graph);
			break;
		}
		case 2: {
			cout << "输入要添加的顶点数：" << endl;
			int n = 0;
			cin >> n;
			for (int i = 0; i < n; i++) {
				Vex v;
				cout << "输入顶点编号" << endl;
				cin >> v.code;
				cout << "输入顶点名称" << endl;
				cin >> v.Name;
				graph->InsertVex(v);
			}
			break;
		}
		case 3: {
			cout << "输入要添加的边数：" << endl;
			int n = 0;
			cin >> n;
			for (int i = 0; i < n; i++) {
				Edge e;
				cout << "输入边的一个顶点" << endl;
				cin >> e.vex1.code;
				cout << "输入另一个顶点" << endl;
				cin >> e.vex2.code;
				cout << "输入权值" << endl;
				cin >> e.weight;
				graph->InsertEdges(e);
			}
			break;
		}
		case 4: {
			graph->PrimMinTree(a);
			system("pause");
			break;
		}
		case 5: {
			graph->KruskalMinTree(a);
			system("pause");
			break;
		}
		case 6: {
			cout << "1.修改顶点" << endl;
			cout << "2.删除顶点" << endl;
			cout << "3.修改边" << endl;
			cout << "4.删除边" << endl;
			int m;
			cin >> m;
			if (m == 1) {
				Vex a;
				cout << "输入修改的顶点的编号" << endl;
				cin >> a.code;
				cout << "输入修改的顶点的名称" << endl;
				cin >> a.Name;
				graph->UpdateVex(a);
			}
			else if (m == 2) {
				Vex b;
				cout << "输入修改的顶点的编号" << endl;
				cin >> b.code;
				graph->DeleteVex(b);
			}
			else if (m == 3) {
				Edge c;
				cout << "输入修改边的第一个顶点编号" << endl;
				cin >> c.vex1.code;
				cout << "输入修改边的第二个顶点编号" << endl;
				cin >> c.vex2.code;
				cout << "输入修改边的权值" << endl;
				cin >> c.weight;
				graph->UpdateEdges(c);
			}
			else if (m == 4) {
				Edge d;
				cout << "输入修改边的第一个顶点编号" << endl;
				cin >> d.vex1.code;
				cout << "输入修改边的第二个顶点编号" << endl;
				cin >> d.vex2.code;
				graph->DeleteEdges(d);
			}
			else {
				cout << "输入错误" << endl;
			}
			system("pause");
			break;
		}
		case 7: {
			graph->showMassage();
			system("pause");
			break;
		}
		case 8: {
			return 0;
			break;
		}
		}
		
		}
	
}