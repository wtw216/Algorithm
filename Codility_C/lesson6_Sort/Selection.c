void solution(int* A, int N){
	printf("Selection Sort\n");
	
	int min_idx = 0;
	int i, j;
	int temp;
	for(j = 0; j < N - 1; j++){
		for(i = j; i < N; i++){
			if(A[min_idx] > A[i]){
				min_idx = i;
			}
		}

		temp = A[min_idx];
		A[min_idx] = A[j];
		A[j] = temp;

		min_idx = j + 1;
	}	
}