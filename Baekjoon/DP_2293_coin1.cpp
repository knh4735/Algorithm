/*
2293 동전1 Dynamic Programming
서로다른 n가지 종류의 동전을 적절히 사용해 k원을 만드는 경우의 수 구하기
입력 : 1 <= n <= 100, 1 <= k <= 10000 \n 동전의 가치
출력 : 경우의 수 < 2^31
*/
#include <stdio.h>
#include <algorithm>

int n, k;
int c[101];

int find(int key){
	for(int i = 0; i < n; i++) if(key == c[i]) return 1;
	return 0;
}

int main(){
	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++) scanf("%d", &c[i]);

	std::sort(c, c+n);

	int r[k+1];
	r[0] = 1;
	for(int i = 1; i <= k; i++){
		r[i] = (i % c[0] == 0 ? 1 : 0);
	}

  /*
  1원으로만 만들면 a[i] = 1;
  2원으로 만든경우 추가 => b[i] = a[i] + b[i-2];
  5원으로 만든경우 추가 => c[i] = b[i] + c[i-5];
  coin[i]원으로 만든경우 추가 => Ai[k] = A(i-1)[k] + Ai[k-coin[i]]
  */
	for(int j = 1; j < n; j++){
		int coin = c[j];
		for(int i = coin; i <= k; i++){
			r[i] = r[i] + r[i-coin];
		}
	}

	printf("%d", r[k]);
	

	return 0;
}
