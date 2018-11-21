#include "Dijkstra.h"

Grap_DG::Grap_DG(int vexnum, int edge){

	//��ʼ������ͱ���
	this->vexnum = vexnum;
	this->edge = edge;
	//Ϊ�ڽӾ��󿪱ٿռ䲢���и���
	arc = new int*[this->vexnum];
	dis = new Dis[this->edge];
	for (int i = 0; i < this->vexnum; i++){
		arc[i] = new int[this->vexnum];
		for (int k = 0; k < this->vexnum; k++){
			arc[i][k] = INT_MAX;
		}

	}

}

//��������
Grap_DG::~Grap_DG(){
	delete[] dis;
	for (int i = 0; i < this->vexnum; i++){
		delete this->arc[i];
	}
	delete arc;
}

//�ж�����ÿ������ı��Ƿ�Ϸ�
bool Grap_DG::check_edge_value(int start, int end, int weight){
	if (start<1 || end<1 || start>vexnum || end>vexnum || weight < 0)
		return false;
	return true;
}

//�����ڽӾ���ĺ���
void Grap_DG::createGraph(){

	cout << "������ÿ���ߵ������յ�(�����Ŵ�1��ʼ)�Լ���Ȩ��" << endl;
	int start;
	int end;
	int weight;
	int count = 0;
	while (count != this->edge){
		cin >> start >> end >> weight;
		//�����ж��������Ϣ�Ƿ�Ϸ�
		if (!this->check_edge_value(start, end, weight)){
			cout << "���������Ϣ����������������:" << endl;
			cin >> start >> end >> weight;
			//���ڽӾ����϶�Ӧ�ĵ���и�ֵ
		}
		arc[start - 1][end - 1] = weight;
		//���Ϊ����ͼ�������һ��
		//arc[end - 1][start - 1] = weight
		++count;
	}
}

//ͼ�Ĵ�ӡ�ĺ���
void Grap_DG::print(){

	cout << "ͼ���ڽӾ���Ϊ:" << endl;
	int count_row = 0;      //��ӡ���еı�ǩ
	int count_col = 0;      //��ӡ���еı�ǩ
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

//Dijkstra���ĵ��㷨
void Grap_DG::Dijkstra(int begin){
	//���ȳ�ʼ������
	int i;
	for (i = 0; i < this->vexnum; i++){
		dis[i].path = "v" + to_string(begin) + "--->v" + to_string(i + 1);
		dis[i].value = arc[begin - 1][i];
	}
	//������㵽����·��Ϊ0
	dis[begin - 1].value = 0;
	dis[begin - 1].visit = true;

	int count = 1;
	//����ʣ�ඥ���·����ʣ�ඥ��ĸ���Ϊ(this->vexnum-1)
	while (count != this->vexnum){
		//tmp���ڱ��浱ǰdis��������С��ֵ���±�
		//min���ڱ��浱ǰdis�����е���С��ֵ
		int tmp = 0;
		int min = INT_MAX;
		for (i = 0; i < this->vexnum; i++){
			if (!dis[i].visit&&dis[i].value < min){
				min = dis[i].value;
				tmp = i;
			}
		}
		//��tmp��Ӧ�Ķ�����뵽�Ѿ��ҵ����·���ļ���
		dis[tmp].visit = true;
		++count;
		for (i = 0; i < this->vexnum; i++){
			//ע�����������arc[tmp][i]!=INT_MAX����ӣ���Ȼ������������������³�����쳣ִ��
			if (!dis[i].visit&&arc[tmp][i] != INT_MAX && (dis[tmp].value + arc[tmp][i]) < dis[i].value){
				//����¼���ĵ����Ӱ�쵽�����Ķ��㣬�Ǿ͸����������·���ͳ���
				dis[i].value = dis[tmp].value + arc[tmp][i];
				dis[i].path = dis[tmp].path + "--->" + to_string(i + 1);
			}
		}

	}
}

//��ӡ·������
void Grap_DG::print_path(int begin){
	string str;
	str = "v" + to_string(begin);
	cout << "��" << str << "Ϊ������̵�·��Ϊ:" << endl;
	for (int i = 0; i < this->vexnum; i++){
		if (dis[i].value != INT_MAX){
			cout << dis[i].path << "=" << dis[i].value << endl;
		}
		else{
			cout << dis[i].path << "�������·����!" << endl;
		}
	}
}