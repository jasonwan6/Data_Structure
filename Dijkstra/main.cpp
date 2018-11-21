#include"Dijkstra.h"

//检验输入的顶点的个数和边数是否符合正确的要求
bool check(int Vexnum, int edge){
	if (Vexnum <= 0 || edge <= 0 || (Vexnum*(Vexnum - 1) / 2) < edge)
		return false;
	return true;
}

int main(){
	int vexnum;
	int edge;
	cout << "输入的顶点的个数和边的条数:" << endl;
	cin >> vexnum >> edge;
	while (!check(vexnum, edge)){
		cout << "你输入的顶点的个数和边的条数不合法，请重新输入!" << endl;
		cin >> vexnum >> edge;
	}
	Grap_DG graph(vexnum,edge);
	graph.createGraph();
	graph.print();
	graph.Dijkstra(1);
	graph.print_path(1);
	system("pause");
	return 0;

}