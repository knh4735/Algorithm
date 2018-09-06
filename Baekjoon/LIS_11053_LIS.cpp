/*
11053 가장긴증가하는부분수열 LIS
수열 A에서 가장 긴 증가하는 부분수열을 구하기
입력 : 수열의 크기 1 <= n <= 1000
출력 : 1 <= Ai <= 1000
*/
#include <stdio.h>
#include <algorithm>


int main(){
	int n;
	scanf("%d", &n);

	int a[n];
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	int result[n], rIdx = 0;
	result[rIdx++] = a[0];
	for(int i = 1; i < n; i++){
		if(result[rIdx-1] < a[i]) result[rIdx++] = a[i];
		else{
			int *lb = std::lower_bound(result, result+rIdx, a[i]);
			*lb = a[i];
		}
	}

	printf("%d", rIdx);


	return 0;
}
