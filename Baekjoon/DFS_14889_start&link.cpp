/*
14880 스타트와링크 DFS
N명을 두 팀으로 나눈다. 사람마다 같은 팀이 되었을 때 추가되는 능력치가 있는데, 두 팀간의 능력치 차가 최소가 되는 경우의 최솟값 구하기
입력 : 사람 수 4 ≤ N ≤ 20, N은 짝수 \n ~N 능력치 행렬값
출력 : 능력치 차이의 최솟값
*/
#include <stdio.h>

int n, min = -1;
int s[21][21];
int m[21];

void cal(){
	int st = 0, lt = 0, tmp;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(m[i] == m[j]){
				if(m[j] == 1)
					st += s[i][j];
				else
					lt += s[i][j];
			}
		}
	}

	tmp = st > lt ? st - lt : lt -st;
	if(min == -1 || min > tmp) min = tmp;
}

void dfs(int h, int cnt){
	if(cnt == n / 2){
		cal();

		return;
	}

	for(int i = h+1; i < n; i++){
		if(m[i] == 0){
			m[i] = 1;
			dfs(i, cnt+1);
			m[i] = 0;
		}
	}
}

int main(){
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &s[i][j]);

	m[0] = 1;
	dfs(0, 1);

	printf("%d", min);

	return 0;
}
