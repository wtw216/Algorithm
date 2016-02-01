/* Bublle sort */


void solution(int* A, int N){
	printf("Bublle Sort:\n");
	int i, j;
	int temp;
	for(j = N - 1; j > 0; j --){
		for(i = 0; i < j; i++){
			if(A[i] > A[i + 1]){
				temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
			}
		}

	}
}