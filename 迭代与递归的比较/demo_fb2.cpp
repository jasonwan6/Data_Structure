#include<stdio.h>
#include<time.h>
#define ture 1
/*�õݹ�ʵ��쳲��������е����*/

int Fbi(int i){

	if (i < 2)
		return i == 0 ? 0 : 1;
	return Fbi(i - 1) + Fbi(i - 2);
}

int main(){

	clock_t start, finish;
	double Total_time;
	int i = 0;
	start = clock();
	for (; i < 45; i++){
	
		printf("%d\n", Fbi(i));
	}
	finish = clock();
	printf("%d",finish);
	Total_time = (double)(finish - start) / 1000;
	printf("����ִ�е���ʱ��Ϊ:%.6fsec\n",Total_time);
	return ture;
}