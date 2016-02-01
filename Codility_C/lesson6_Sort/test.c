// test.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

void solution(int *A, int N){
}

int main(){
	int A[1] = {1};
	int B[5] = {1, 1, 1, 1, 1};
	int C[2] = {4, 4};
	int D[10] = {2,5,4,6,10,2,5,3,6,4};
	int E[9] = {1,4,6,3,6,2,3,7,4};
	int idx;
	
	solution(A, 1);
	printf("A[1]=[1], \nafter sorted:[%d]\n", A[0]);

	solution(B, 5);
	printf("B[5]=[1, 1, 1, 1, 1], \nafter sorted:[");
	for(idx = 0; idx < 5; idx ++){
		printf("%d, ", B[idx]);
	}
	printf("]\n");

	solution(C, 2);
	printf("C[2]=[4,4], \nafter sorted:[%d, %d]\n", C[0], C[1]);

	solution(D, 10);
	printf("D[10]=[2,5,4,6,10,2,5,3,6,4],\nafter sorted:[");
	for(idx = 0; idx < 10; idx ++){
		printf("%d, ", D[idx]);
	}
	printf("]\n");

	solution(E, 9);
	printf("E[9]=[1,4,6,3,6,2,3,7,4], \nafter sorted:[");
	for(idx = 0; idx < 9; idx ++){
		printf("%d, ", E[idx]);
	}
	printf("]\n");
	getchar();

}
