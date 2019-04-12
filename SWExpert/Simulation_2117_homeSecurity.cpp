/*
2117 홈방범서비스 Simulation(Brute Force)
NxN 지도에서 마름모 형태의 방범 서비스를 제공한다. 운영비용(면적)은 K*K + (K-1)*(K-1)이고 가구당 M원을 받는다.
이익(M*가구수 - 운영비용)이 0 이상이고 최대한 많은 가구를 지원할 수 있는 경우에 지원 받는 가구 수 구하기
입력 : TC \n 지도 크기 5 ≤ N ≤ 20, 비용 1 ≤ M ≤ 10 \n 지도 내용 (1이 집)
출력 : 손해보지 않고 최대한 많은 가구에 서비스를 제공할 때의 
*/
#include <stdio.h>

int n, m;
int map[21][21];
int home[21][21][41];

int count_home(int r, int c, int k){
	int num = 0;

	if(k == 1) return home[r][c][1];

	for(int i = 1; i <= k; i++){

		if(c+k-i < n){
			if(r+i-1 < n && map[r+i-1][c+k-i] == 1) num++;
			if(i != 1 && r-i+1 >= 0 && map[r-i+1][c+k-i] == 1) num++;
		}

		if(i < k && c-k+i >= 0){
			if(r+i-1 < n && map[r+i-1][c-k+i] == 1) num++;
			if(i != 1 && r-i+1 >= 0 && map[r-i+1][c-k+i] == 1) num++;
		}
	}
	
	home[r][c][k] = home[r][c][k-1] + num;

	return home[r][c][k];

}

int main(){
	int T;
	scanf("%d", &T);

	for(int tc = 1; tc <= T; tc++){
		int r = 0,
			total = 0;
		scanf("%d %d", &n, &m);

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &map[i][j]);
				if(map[i][j] == 1){
					home[i][j][1] = 1;
					total++;
				}
				else home[i][j][1] = 0;
 			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int k = 1;
				while(1){
					int num = count_home(i, j, k);
					if(num * m - (k*k + (k-1)*(k-1))>= 0 && num > r) r = num;
					//printf("%d %d %d %d\n", i, j, k, num);
					if(num == total) break;

					k++;
				}			
			}
		}

		printf("#%d %d\n", tc, r);
	}
}
