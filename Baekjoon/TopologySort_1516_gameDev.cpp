// 1516 게임개발 그래프1(위상정렬)
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int max(int q, int w){
	return q > w ? q : w;
}

int main(){
	int inbound[501] = {0, };
	vector<int> order[501];	// 다음에 지을 건물들
	queue<int> q;

	int n;
	int ans[501], time[501];
	scanf("%d", &n);

	int tmp;
	for(int i = 1; i <= n ; i++){
		scanf("%d", &tmp);
		time[i] = tmp;
		ans[i] = tmp;

		while(1){
			scanf("%d", &tmp);
			if(tmp == -1) break;

			inbound[i]++;
			order[tmp].push_back(i);
		}
	}

	for(int i = 1; i <= n; i++){
		if(inbound[i] == 0) q.push(i);
	}

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		for(int i = 0; i < order[cur].size(); i++){
			int idx = order[cur][i];
			// (지금까지 지은 건물들의 시간 + 이건물 짓는데 걸리는 시간) vs 기존 계산값
			ans[idx] = max(ans[idx], ans[cur] + time[idx]);

			inbound[idx]--;
			if(inbound[idx] == 0) q.push(idx);
		}
	}

	for(int i = 1; i <= n; i++) printf("%d\n", ans[i]);

	return 0;
}
