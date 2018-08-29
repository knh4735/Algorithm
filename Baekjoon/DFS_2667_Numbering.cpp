//2667 단지번호붙이기 DFS
//지도에서 집들이 모여있는 단지를 구분해서 단지 수와 각 단지별 세대수를 오름차순 정렬해 출력
//5 <= 지도의 크기 <= 25 \n ~ 1 : 집 / 0 : X로 지도 입력
//단지 수 \n ~세대수 오름차순 출력
#include <stdio.h>

int n;
int map[26][26], isVisit[26][26];	//지도 0 : X, 1 : 집 / isVisit -1 : 방문 불가, 0 : 방문가능, 1 : 방문함
int result[25 * 25], idx;


void dfs(int q, int w){

	if(q + 1 < n && map[q+1][w] == 1 && isVisit[q+1][w] == 0){
		result[idx]++;
		isVisit[q+1][w] = 1;
		dfs(q+1, w);
	}
	if(q - 1 >= 0 && map[q-1][w] == 1 && isVisit[q-1][w] == 0){
		result[idx]++;
		isVisit[q-1][w] = 1;
		dfs(q-1, w);
	}
	if(w + 1 < n && map[q][w+1] == 1 && isVisit[q][w+1] == 0){
		result[idx]++;
		isVisit[q][w+1] = 1;
		dfs(q, w+1);
	}
	if(w - 1 >= 0 && map[q][w-1] == 1 && isVisit[q][w-1] == 0){
		result[idx]++;
		isVisit[q][w-1] = 1;
		dfs(q, w-1);
	}

	return;
}

int main(){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%1d", &map[i][j]);
			isVisit[i][j] = (map[i][j] == 1 ? 0 : -1);
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(map[i][j] == 1 && isVisit[i][j] == 0){
				isVisit[i][j] = 1;
				result[idx]++;
				dfs(i, j);
				idx++;
			}
		}
	}

	for(int i = 0; i < idx; i++){
		for(int j = i; j < idx; j++){
			if(result[i] > result[j]){
				int temp = result[i];
				result[i] = result[j];
				result[j] = temp;
			}
		}
	}
	
	printf("%d\n", idx);
	for(int i = 0; i < idx; i++) printf("%d\n", result[i]);

	return 0;
}
