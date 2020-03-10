// 1275 커피숍2 자료구조(세그먼트트리)
#include <stdio.h>
#include <cmath>
using namespace std;

long long tree[1 << ((int)ceil(log2(100000)) + 1)] = {0, };

long long update(long long tree[], int node, int value, int idx, int start, int end){
	if(idx < start || end < idx) return tree[node];
	if(start == idx && idx == end){
		tree[node] = (long long) value;
		return tree[node];
	}

	int mid = (start + end) / 2;
	tree[node] = update(tree, node * 2, value, idx, start, mid) + update(tree, node*2 + 1, value, idx, mid+1, end);
	return tree[node];
}

long long query(long long tree[], int node, int l, int r, int start, int end){
	if(end < l || r < start) return 0;
	if(l <= start && end <= r) return tree[node];
	
	int mid = (start + end) / 2;
	return query(tree, node * 2, l, r, start, mid) + query(tree, node*2 + 1, l, r, mid+1, end);
}

int main(){
	int n, q, tmp;

	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; i++){
		scanf("%d", &tmp);
		update(tree, 1, tmp, i, 0, n-1);
	}

	int a, b, x, y;
	long long sum;
	for(int i = 0; i < q; i++){
		scanf("%d %d %d %d", &x, &y, &a, &b);
		x--; y--; a--;
		if(x > y) sum = query(tree, 1, y, x, 0, n-1);
		else sum = query(tree, 1, x, y, 0, n-1);
		printf("%lld\n", sum);

		update(tree, 1, b, a, 0, n-1);
	}
	
	return 0;
}
