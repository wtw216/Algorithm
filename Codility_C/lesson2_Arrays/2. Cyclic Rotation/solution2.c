/*time=O(log(N)), space =O(log(1))*/

void reverse(int A[], int start, int end){
    int temp;
    int idx;
    int middle = (end - start) / 2;
    if(start < end)
        for(idx = 0; idx <= middle; idx++){
            temp = A[start + idx];
            A[start + idx] = A[end - idx];
            A[end - idx] = temp;
        }
}
        
        
struct Results solution(int A[], int N, int K) {
    struct Results result;
    if(N){                      //check empty array!
        K = K % N;
        reverse(A, 0, N-K-1);
        reverse(A, N-K, N-1);
        reverse(A, 0, N-1);   
    }
    result.A = A;
    result.N = N;
    return result;
}