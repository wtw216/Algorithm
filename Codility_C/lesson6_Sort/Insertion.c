void insert(int *A, int s_pos, int d_pos)
{	
	int temp = A[s_pos];
	int idx;
	for(idx = s_pos; idx > d_pos; idx--){
		A[idx] = A[idx - 1];
	}
	A[d_pos] = temp;
}

void solution(int* A, int N){
	printf("Insertion Sort\n");
	int idx;
	int point;
	for(idx = 1; idx < N; idx++){
		for(point = 0; point < idx; point++){
			if(A[idx] < A[point]){
				insert(A, idx, point);
				break;
			}
		}
	}

	
}