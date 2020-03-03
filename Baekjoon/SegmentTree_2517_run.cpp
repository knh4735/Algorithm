// 2517 달리기 시간복잡도(세그먼트트리)
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

struct runner{
	int rank;	// 현재 등수
	int spd;	// 실력
};

int n;
runner run[500001];

int cmp_by_spd(runner a, runner b){
	return a.spd < b.spd;
}
int cmp_by_rank(runner a, runner b){
	return a.rank < b.rank;
}

int update(int tree[], int node, int value, int start, int end){
	// 해당 실력의 노드에 1 등록
	if(start == value && value == end) {
		tree[node] = 1;
		return 1;
	}
	// 찾는 노드가 아니므로 그냥 값 반환
	if(start > value || end < value) return tree[node];

	// 범위 안에 찾는 노드가 포함됨. 탐색 진행
	int mid = (start + end) / 2;
	tree[node] = update(tree, node*2, value, start, mid) + update(tree, node*2+1, value, mid+1, end);
	return tree[node];
}

// value 이상, n-1 이하의 실력의 수를 반환
int query(int tree[], int node, int value, int start, int end){
	// value 이상의 실력을 포함하므로 그대로 반환
	if(value < start) return tree[node];

	// value 미만의 범위, 또는 그안에 포함된 리프노드는 세면 안됨
	if(end < value || start == end) return 0;

	// 쪼개서 탐색
	int mid = (start + end) / 2;
	return query(tree, node*2, value, start, mid) + query(tree, node*2+1, value, mid+1, end);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &run[i].spd);
		run[i].rank = i;
	}
	
	// 좌표압축
	sort(run, run+n, cmp_by_spd);
	for(int i = 0; i < n; i++) run[i].spd = i;

	// 순서대로 복구
	sort(run, run+n, cmp_by_rank);

	// 적절한 크기의 세그먼트 트리 생성
	// x~y는 x에서 y사이의 실력을 가진 사람 수
	int tree[1 << ((int)ceil(log2(n)) + 1)] = {0, };
	for(int i = 0; i < n; i++){
		printf("%d\n", 1 + query(tree, 1, run[i].spd, 0, n-1));
		update(tree, 1, run[i].spd, 0, n-1);
	}

	return 0;
}
