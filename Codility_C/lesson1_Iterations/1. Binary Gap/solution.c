int solution(int N){
	int temp = 0;
	int gap = 0;
	int idx;
	int state; 	// Use remainder to calculate the binary.
	
	// Cut the tail.
	while(N % 2 == 0)
		N /= 2;

	while(N){
		state = N % 2;
		if (state){
			if (gap < temp){
				gap = temp;
			}
			temp = 0;
		} else temp++;
		N = N / 2;
	}
	return gap;
}