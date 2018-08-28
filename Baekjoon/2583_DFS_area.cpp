//2583 영역구하기 DFS
#include <stdio.h>
#include <stdlib.h>

struct nemo{
	int y;
	int x;
};

int area[10001], areaIdx;
int h, w, k;

void dfs(int i, int j, int **pan){
	pan[i][j] = 1;
	area[areaIdx]++;

	if(i + 1 < h && pan[i+1][j] == 0) dfs(i+1, j, pan);
	if(i - 1 >= 0 && pan[i-1][j] == 0) dfs(i-1, j, pan);
	if(j + 1 < w && pan[i][j+1] == 0) dfs(i, j+1, pan);
	if(j - 1 >= 0 && pan[i][j-1] == 0) dfs(i, j-1, pan);
}

int main(){

	scanf("%d %d %d", &h, &w, &k);

	//배열 생성 후 0으로 초기화
	int **pan = (int**) malloc(sizeof(int*) * h);
	for(int i = 0; i < h; i++) pan[i] = (int*) calloc(w, sizeof(int));


	//왼쪽아래 오른쪽위
	nemo spArr[k], epArr[k];

	for(int i = 0; i < k; i++){
		scanf("%d %d %d %d", &spArr[i].x, &spArr[i].y, &epArr[i].x, &epArr[i].y);
		epArr[i].x--;
		epArr[i].y--;

		for(int a = spArr[i].y; a <= epArr[i].y; a++) for(int b = spArr[i].x; b <= epArr[i].x; b++) pan[a][b] = -1;
	}
	
	for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) if(pan[i][j] == 0){
		dfs(i, j, pan);
		areaIdx++;
	}

	for(int i = 0; i < areaIdx; i++){
		for(int j = i; j < areaIdx; j++){
			if(area[i] > area[j]){
				int t = area[i];
				area[i] = area[j];
				area[j] = t;
			}
		}
	}


	printf("%d\n", areaIdx);
	for(int i = 0; i < areaIdx; i++) printf("%d ", area[i]);


	for(int i = 0; i < h; i++) free(pan[i]);
	free(pan);

	return 0;
}
