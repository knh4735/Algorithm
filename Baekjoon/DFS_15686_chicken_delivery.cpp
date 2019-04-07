/*
15686 치킨배달 DFS(Brute Force)
NxN 지도에 1은 집, 2는 치킨집이 표시된다. 집마다 가장 가까운 치킨집과의 거리를 치킨 거리라 한다. 치킨 거리 = |r0-r1| + |c0-c1|
최대 M개의 치킨집만 남겨두고 폐점시킬 때 치킨거리의 총 합을 구하기
입력 : 지도의 크기 2 ≤ N ≤ 50, 남겨둘 치킨집의 최대 개수 1 ≤ M ≤ 13 \n ~N N 지도 요소
출력 : 가능한 치킨 거리의 최솟값
*/
#include <stdio.h>

int n, m, min = -1;
int map[51][51];
int c[14][2], c_len, h[101][2], h_len;
int opt_c[14];

int calc(int cnt){
	int sum = 0;
	for(int i = 0; i < h_len; i++){
		int c_d = -1;
		for(int j = 0; j < cnt; j++){
			int x = h[i][0] - c[opt_c[j]][0],
				y = h[i][1] - c[opt_c[j]][1];
			x = x > 0 ? x : -x;
			y = y > 0 ? y : -y;
			if(c_d == -1 || c_d > x+y) c_d = x+y;
		}
		sum += c_d;
	}
	
	return sum;
}

void dfs(int idx, int cnt){
	int tmp = calc(cnt);
	if(min == -1 || min > tmp) min = tmp;

	if(cnt >= m) return;

	for(int i = idx+1; i < c_len; i++){
		opt_c[cnt] = i;
		dfs(i, cnt+1);
	}

	return;
}

int main(){
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 2){
				c[c_len][0] = i;
				c[c_len][1] = j;
				c_len++;
			}
			else if(map[i][j] == 1){
				h[h_len][0] = i;
				h[h_len][1] = j;
				h_len++;
			}
		}
	}

	for(int i = 0; i < c_len; i++){
		opt_c[0] = i;
		dfs(i, 1);
	}

	printf("%d", min);

	return 0;
}
