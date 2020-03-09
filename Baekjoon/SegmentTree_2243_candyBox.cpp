// 2243 사탕상자 자료구조(세그먼트트리)
#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;

vector<int> tree(1 << ((int)ceil(log2(1000000)) + 1));

int query(int node, int rank, int start, int end){
	int mid = (start + end) / 2;
	int l_node = node * 2;
	int r_node = node * 2 + 1;

	// 범위 밖 (일어날 일 없음)
	if(tree[node] < rank) return 0;

	// 찾는 값. 인덱스 반환
	if(start == end){
		tree[node] -= 1;
		return start;
	}

	// 해당 범위 내의 사탕이 빠질거니까 -1
	tree[node] -= 1;

	// 왼쪽 노드의 값이 rank보다 크면 왼쪽 트리 탐색
	if(tree[l_node] >= rank) return query(l_node, rank, start, mid);
	// 작은 경우, rank-왼쪽노드의 값을 가지고 오른쪽 트리 탐색
	else return query(r_node, rank - tree[l_node], mid+1, end);
}

int update(int node, int taste, int cnt, int start, int end){
	// 범위 밖
	if(taste < start || end < taste) return tree[node];
	// 해당 노드
	if(start == taste && taste == end){
		tree[node] += cnt;
		return tree[node];
	}

	int mid = (start + end) / 2;
	tree[node] = update(node*2, taste, cnt, start, mid) + update(node*2+1, taste, cnt, mid+1, end);
	return tree[node];
}


int main(){
	int n, candy = 1000000;
	scanf("%d", &n);

	int a, b, c;
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		if(a == 1){
			scanf("%d", &b);

			int num = query(1, b, 0, candy-1);
			printf("%d\n", num);
		} else if(a == 2){
			scanf("%d %d", &b, &c);

			update(1, b, c, 0, candy-1);
		}
	}
	
	return 0;
}
