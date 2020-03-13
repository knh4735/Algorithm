// 11266 단절점 그래프2(ArticulationPoint)
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> edge[10001];
int order[10001];	// 방문번호 및 인덱스
int idx = 1;

int ap[10001];	// i번 노드가 단절점이면 1

// dfs 탐색, 방문할 수 있는 노드 중 가장 작은 번호 반환
int min_order(int node){
	// 탐색 번호 등록
	int ret = idx;
	order[node] = idx;
	idx++;


	for(int i = 0; i < edge[node].size(); i++){
		int next = edge[node][i];

		// 이미 번호가 등록된 노드의 경우 더 깊이 가진 않고, 번호만 리턴값과 비교
		if(order[next] != 0){
			ret = min(ret, order[next]);
			continue;
		}

		int min_num = min_order(next);

		// 자식 노드가 방문할 수 있는 노드 중 자신보다 작은 번호가 없으면 단절점
		if(min_num >= order[node]) ap[node] = 1;

		// 자식이 방문할 수 있는 번호는 자신도 방문할 수 잇음
		ret = min(ret, min_num);
	}

	return ret;
}

// 루트노드
void begin_dfs(int root){
	// 탐색 번호 등록
	order[root] = idx;
	idx++;

	int child = 0;
	// 자식노드 dfs 탐색
	for(int i = 0; i < edge[root].size(); i++){
		int next = edge[root][i];

		if(order[next] != 0) continue;
		child++;

		min_order(next);
	}

	// dfs 트리에서 루트노드의 자식노드가 둘 이상이면 단절점
	if(child > 1) ap[root] = 1;
}

int main(){
	int v, e;
	scanf("%d %d", &v, &e);

	int a, b;
	for(int i = 0; i < e; i++){
		scanf("%d %d", &a, &b);

		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	for(int i = 1; i < v; i++){
		if(order[i] == 0) begin_dfs(i);
	}

	vector<int> result;
	for(int i = 1; i <= v; i++)
		if(ap[i] == 1)
			result.push_back(i);

	printf("%d\n", result.size());
	for(auto i : result)
		printf("%d ", i);

	return 0;
}
