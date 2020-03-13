// 11400 단절선 그래프2(ArticulationBridge)
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> edge[100001];
int order[100001];	// 방문번호 및 인덱스
int idx = 1;

vector<pair<int, int>> ab;	// a < b인 절단선

// dfs 탐색, 방문할 수 있는 노드 중 가장 작은 번호 반환
int min_order(int node, int parent){
	// 탐색 번호 등록
	int ret = idx;
	order[node] = idx;
	idx++;


	for(int i = 0; i < edge[node].size(); i++){
		int next = edge[node][i];

		// 직접오면 안됨, 돌아서 와야함
		if(parent == next) continue;

		// 이미 번호가 등록된 노드의 경우 더 깊이 가진 않고, 번호만 리턴값과 비교
		if(order[next] != 0){
			ret = min(ret, order[next]);
			continue;
		}

		int min_num = min_order(next, node);

		// 자식 노드가 방문할 수 있는 노드 중 자신보다 작은 번호가 없으면 단절점
		if(min_num > order[node]){
			if(node > next) ab.push_back({next, node});
			else ab.push_back({node, next});
		}

		// 자식이 방문할 수 있는 번호는 자신도 방문할 수 잇음
		ret = min(ret, min_num);
	}

	return ret;
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

	for(int i = 1; i <= v; i++){
		if(order[i] == 0) min_order(i, 0);
	}

	sort(ab.begin(), ab.end());

	printf("%d\n", ab.size());
	for(auto i : ab){
		printf("%d %d\n", i.first, i.second);
	}
	return 0;
}
