// 2042 구간합구하기 자료구조(세그먼트트리)
#include <stdio.h>
#include <cmath>

long long update(long long tree[], int node, long long value, int idx, int start, int end){
	// 포함되지 않음
	if(start > idx || end < idx){
		// printf("%d~%d %lld\n", start, end, tree[node]);
		return tree[node];
	}

	// 해당 노드 업데이트
	if(start == idx && idx == end){
		tree[node] = value;
		// printf("UPDATED %d~%d %lld\n", start, end, tree[node]);
		return tree[node];
	}

	// 해당 노드를 포함하는 부분합
	int mid = (start + end) / 2;
	tree[node] = update(tree, node*2, value, idx, start, mid) + update(tree, node*2 + 1, value, idx, mid + 1, end);
	// printf("UPDATED %d~%d %lld\n", start, end, tree[node]);
	return tree[node];
}

long long query(long long tree[], int node, int l, int r, int start, int end){
	// 해당 범위에 포함됨
	if(l <= start && end <= r) return tree[node];

	// 완전 다른 범위
	if(r < start || end < l) return 0;


	// 해당 범위를 포함하는 노드 - 쪼갬
	int mid = (start + end) / 2;
	return query(tree, node*2, l, r, start, mid) + query(tree, node*2 + 1, l, r, mid + 1, end);
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	long long tree[1 << ((int)ceil(log2(n)) + 1)] = {0, };
	for(int i = 0; i < n; i++){
		long long tmp;
		scanf("%lld", &tmp);

		update(tree, 1, tmp, i, 0, n - 1);
	}

	int a;
	long long b, c;
	for(int i = 0; i < m + k; i++){
		scanf("%d %lld %lld", &a, &b, &c);

		if(a == 1) update(tree, 1, c, b-1, 0, n - 1);
		else printf("%lld\n", query(tree, 1, b-1, c-1, 0, n - 1));
	}
	

	return 0;
}
