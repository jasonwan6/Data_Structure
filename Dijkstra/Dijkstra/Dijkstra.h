#pragma once
#include<iostream>
#include<String>

using namespace std;

/*
��������Dijkstra�㷨��ʵ�ֵ�Դ·���������ͣ������ڽӾ�������ͼ
*/

//��¼��㵽ÿ���ڵ����·������Ϣ
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
	int vexnum;     //ͼ�Ķ���ĸ���
	int edge;       //ͼ�ı���
	int **arc;      //�ڽӾ���
	Dis *dis;       //��¼����������̵�·������Ϣ
public:
	//���캯��
	Grap_DG(int vexnum, int edge);
	//��������
	~Grap_DG();
	//�ж�����ÿ���������Ϣ�Ƿ�Ϸ�
	bool check_edge_value(int start, int end, int weight);
	//����ͼ
	void createGraph();
	//��ӡ�ڽӾ���
	void print();
	//�����·��
	void Dijkstra(int begin);
	//��ӡ���·��
	void print_path(int);
};
