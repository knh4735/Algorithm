/*
11724 연결 요소의 개수 BFS
n개의 정점, m개의 간선이 주어질 때 연결 요소의 수를 구하기
입력 : 1 <= n <= 1000, 1 <= m <= n * (n-1) /2  \n ~간선의 양 끝점
출력 : 연결 요소의 수
*/
#include <stdio.h>
#include <queue>
using namespace std;

int n, m, cnt;
int isVisit[1001];
int net[1001][1001];

int main(){
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++){
		int q, w;
		scanf("%d %d", &q, &w);
		net[q][w] = 1;
		net[w][q] = 1;
	}

	queue<int> q;

	for(int i = 1; i <= n; i++){
		if(isVisit[i] == 0){
			isVisit[i] = 1;
			q.push(i);

			while(!q.empty()){
				int cur = q.front();
				q.pop();

				for(int j = 1; j <= n; j++){
					if(net[cur][j] == 1 && isVisit[j] == 0){
						isVisit[j] = 1;
						q.push(j);
					}
				}

			}
			
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}
