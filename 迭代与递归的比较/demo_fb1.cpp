#include<stdio.h>
#include<time.h>
#define MAXSIZE 150
#define ture 0

int main(){
	
	int i = 2;
	clock_t start, finish;
	double Total_time;
	double a[MAXSIZE];
	a[0] = 0;
	a[1] = 1;
	start = clock();
	printf("%.0f\n", a[0]);
	printf("%.0f\n", a[1]);
	for (; i < MAXSIZE; i++){
		a[i] = a[i - 1] + a[i - 2];
		printf("%.0f\n", a[i]);
	}
	finish = clock();
	Total_time = (double)(finish - start) / 1000;
	printf("程序执行的时间为:%.6fsec\n",Total_time);

	return ture;
}