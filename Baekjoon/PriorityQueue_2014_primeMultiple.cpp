// 2014 소수의곱 자료구조(우선순위큐)
#include <stdio.h>
#include <map>

struct HEAP {
	long long q[400001] = {0, };
	int cnt = 0;
};

// 중복체크 직접하려다 시간초과뜨고 버림... map으로 
// int find(HEAP *heap, int cur, long long value){
// 	if(cur > heap->cnt) return 0;

// 	if(heap->q[cur] == value) return 1;
// 	else if(heap->q[cur] > value) return 0;

// 	return find(heap, cur*2, value) + find(heap, cur*2+1, value);
// }

void push(HEAP *heap, long long value){
	heap->cnt++;
	heap->q[heap->cnt] = value;

	int cur = heap->cnt, p = cur / 2;
	while(heap->q[p] > heap->q[cur] && p > 0){
		long long tmp = heap->q[p];
		heap->q[p] = heap->q[cur];
		heap->q[cur] = tmp;

		cur = p;
		p = cur / 2;
	}
}

long long pop(HEAP *heap){
	long long ret = heap->q[1];
	long long last = heap->q[heap->cnt];
	heap->cnt--;

	int cur = 1, child = cur * 2;
	while(child <= heap->cnt){
		// child = 더 작은 노드
		if(child < heap->cnt && heap->q[child] > heap->q[child+1]) child += 1;

		if(last < heap->q[child]) break;

		heap->q[cur] = heap->q[child];
		cur = child;
		child = cur * 2;
	}

	heap->q[cur] = last;
	return ret;
}

int main(){
	HEAP heap;
	std::map<long long, bool> visit;

	int k, n;
	int a[101];

	scanf("%d %d", &k, &n);
	for(int i = 0; i < k; i++) scanf("%d", &a[i]);

	push(&heap, 1);
	long long max = 0;
	for(int i = 0; i < n; i++){
		long long cur = pop(&heap);
		// printf("\nPOP %lld SIZE %d MAX %lld\n", cur, heap.cnt, max);
		
		for(int j = 0; j < k; j++){
			long long mul = cur * a[j];
			// printf("VALIDATE %lld\n", mul);

			// if(find(&heap, 1, mul) > 0) continue;
			if(visit.count(mul) > 0) continue;
			if(heap.cnt > n-i && mul > max) break;

			visit[mul] = true;
			if(max < mul) max = mul;

			// printf("PUSH %lld\n", mul);
			push(&heap, mul);
		}
	}

	printf("%lld", pop(&heap));

	return 0;
}
