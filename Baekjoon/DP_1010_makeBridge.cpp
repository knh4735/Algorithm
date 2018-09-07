/*
1010 다리놓기 Dynamic Programming
강의 서쪽에 n개, 동쪽에 m(<= n)개의 사이트를 이어 다리를 n개 만들때 경우의 수를 구하기
입력 : 테스트케이스의 수 t \n ~ 0 < n <= m < 30
출력 : 각 테스트케이스에 대한 경우의 수
*/
#include <stdio.h>

int main(){
	int tc;
	scanf("%d", &tc);

	for(int t = 0; t < tc; t++){
		int n, m;
		scanf("%d %d", &n, &m);

		int r[m+1];
		for(int i = 0; i <= n; i++){
			r[i] = 1;
		}

		for(int i = n + 1; i <= m; i++){
			r[i] = (r[i-1] * i) / (i - n);
		}
		
		printf("%d\n", r[m]);
	}

	return 0;
}
