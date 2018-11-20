#include "Dijkstra.h"

Grap_DG::Grap_DG(int vexnum, int edge){

	//初始化顶点和边数
	this->vexnum = vexnum;
	this->edge = edge;
	//为邻接矩阵开辟空间并进行复制
	arc = new int*[this->vexnum];
	dis = new Dis[this->edge];
	for (int i = 0; i < this->vexnum; i++){
		arc[i] = new int[this->vexnum];
		for (int k = 0; k < this->vexnum; k++){
			arc[i][k] = INT_MAX;
		}

	}

}

//析构函数
Grap_DG::~Grap_DG(){
	delete[] dis;
	for (int i = 0; i < this->vexnum; i++){
		delete this->arc[i];
	}
	delete arc;
}

//判断我们每次输入的边是否合法
bool Grap_DG::check_edge_value(int start, int end, int weight){
	if (start<1 || end<1 || start>vexnum || end>vexnum || weight < 0)
		return false;
	return true;
}

//创建邻接矩阵的函数
void Grap_DG::createGraph(){

	cout << "请输入每条边的起点和终点(顶点编号从1开始)以及其权重" << endl;
	int start;
	int end;
	int weight;
	int count = 0;
	while (count != this->edge){
		cin >> start >> end >> weight;
		//首先判断输入的信息是否合法
		if (!this->check_edge_value(start, end, weight)){
			cout << "你输入的信息有误，请再重新输入:" << endl;
			cin >> start >> end >> weight;
			//对邻接矩阵上对应的点进行赋值
		}
		arc[start - 1][end - 1] = weight;
		//如果为无向图请加上这一行
		//arc[end - 1][start - 1] = weight
		++count;
	}
}

//图的打印的函数
void Grap_DG::print(){

	cout << "图的邻接矩阵为:" << endl;
	int count_row = 0;      //打印的行的标签
	int count_col = 0;      //打印的列的标签
	while (count_row != this->vexnum){
		count_col = 0;
		while (count_col != this->vexnum){
			if (arc[count_row][count_col] == INT_MAX){
				cout << "*" << " ";
			}
			else{
				cout << arc[count_row][count_col] << " ";
			}
			++count_col;
		}
		cout << endl;
		++count_row;
	}
}

//Dijkstra核心的算法
void Grap_DG::Dijkstra(int begin){
	//首先初始化数组
	int i;
	for (i = 0; i < this->vexnum; i++){
		dis[i].path = "v" + to_string(begin) + "--->v" + to_string(i + 1);
		dis[i].value = arc[begin - 1][i];
	}
	//设置起点到起点的路径为0
	dis[begin - 1].value = 0;
	dis[begin - 1].visit = true;

	int count = 1;
	//计算剩余顶点的路径，剩余顶点的个数为(this->vexnum-1)
	while (count != this->vexnum){
		//tmp用于保存当前dis数组中最小的值的下标
		//min用于保存当前dis数组中的最小的值
		int tmp = 0;
		int min = INT_MAX;
		for (i = 0; i < this->vexnum; i++){
			if (!dis[i].visit&&dis[i].value < min){
				min = dis[i].value;
				tmp = i;
			}
		}
		//把tmp对应的顶点加入到已经找到最短路径的集合
		dis[tmp].visit = true;
		++count;
		for (i = 0; i < this->vexnum; i++){
			//注意这里的条件arc[tmp][i]!=INT_MAX必须加，不然会出现溢出的情况，导致程序的异常执行
			if (!dis[i].visit&&arc[tmp][i] != INT_MAX && (dis[tmp].value + arc[tmp][i]) < dis[i].value){
				//如果新加入的点可以影响到其他的顶点，那就更新它的最短路径和长度
				dis[i].value = dis[tmp].value + arc[tmp][i];
				dis[i].path = dis[tmp].path + "--->" + to_string(i + 1);
			}
		}

	}
}

//打印路径函数
void Grap_DG::print_path(int begin){
	string str;
	str = "v" + to_string(begin);
	cout << "以" << str << "为起点的最短的路径为:" << endl;
	for (int i = 0; i < this->vexnum; i++){
		if (dis[i].value != INT_MAX){
			cout << dis[i].path << "=" << dis[i].value << endl;
		}
		else{
			cout << dis[i].path << "是无最短路径的!" << endl;
		}
	}
}