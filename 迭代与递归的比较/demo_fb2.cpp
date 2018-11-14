#include<stdio.h>
#include<time.h>
#define ture 1
/*用递归实现斐波那契数列的求解*/

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
	printf("程序执行的总时间为:%.6fsec\n",Total_time);
	return ture;
}