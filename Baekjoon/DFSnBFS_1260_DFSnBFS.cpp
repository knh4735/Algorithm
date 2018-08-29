//1260 DFS와BFS DFSnBFS
//그래프를 두 방식으로 각각 순회하여 출력
//정점의 개수 <= 1000, 간선의 개수 <= 10000, 시작정점번호 \n ~간선이 연결하는 두정점 번호 (중복시 하나로 취급)
//DFS와 BFS로 방문된 점을 각각 순서대로 출력
#include <stdio.h>
#include <queue>
using namespace std;

int n, m, s;	//정점, 간선 수, 시작 번호
int edge[1001][1001];

int resultDfs[1001], resultBfs[1001];
int checkDfs[1001], idxDfs, flagDfs;
int checkBfs[1001], idxBfs;
queue<int> bfsQ;

void printResult(int result[]){
	for(int i = 0; i < n; i++) printf("%d ", result[i]);
	printf("\n");
	return;
}

void dfs(int w){	//현재, 현재 방문수
	if(idxDfs == n){
		printResult(resultDfs);
		flagDfs = 1;
		return;
	}

	resultDfs[idxDfs++] = w;
	for(int i = 1; i <= n; i++){
		if(edge[w][i] == 1 && checkDfs[i] == 0){
			checkDfs[i] = 1;
			dfs(i);
		}
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &s);

	for(int i = 0; i < m; i++){
		int q, w;
		scanf("%d %d", &q, &w);
		edge[q][w] = 1;
		edge[w][q] = 1;
	}

  //DFS 시작
	checkDfs[s] = 1;
	resultDfs[idxDfs++] = s;
	for(int i = 1; i <= n; i++){
		if(edge[s][i] == 1){
			checkDfs[i] = 1;
			dfs(i);
		}
		if(flagDfs) break;
	}
	if(!flagDfs) printResult(resultDfs);

  //BFS 
	bfsQ.push(s);
	checkBfs[s] = 1;
	while(!bfsQ.empty()){
		int cur = bfsQ.front();
		bfsQ.pop();

		resultBfs[idxBfs++] = cur;
		for(int i = 1; i <= n; i++){
			if(edge[cur][i] == 1 && checkBfs[i] == 0){
				bfsQ.push(i);
				checkBfs[i] = 1;
			}
		}
	}
	printResult(resultBfs);

	return 0;
}
