#pragma once
#include<iostream>
#include<String>

using namespace std;

/*
本程序用Dijkstra算法来实现单源路径的最短求和，采用邻接矩阵来存图
*/

//记录起点到每个节点最短路径的信息
struct Dis{

	string path;
	int value;
	bool visit;
	Dis(){
		visit = false;
		value = 0;
		path = "";
	}
};

class Grap_DG{

private:
	int vexnum;     //图的顶点的个数
	int edge;       //图的边数
	int **arc;      //邻接矩阵
	Dis *dis;       //记录各个顶点最短的路径的信息
public:
	//构造函数
	Grap_DG(int vexnum, int edge);
	//析构函数
	~Grap_DG();
	//判断我们每次输入的信息是否合法
	bool check_edge_value(int start, int end, int weight);
	//创建图
	void createGraph();
	//打印邻接矩阵
	void print();
	//求最短路径
	void Dijkstra(int begin);
	//打印最短路径
	void print_path(int);
};
