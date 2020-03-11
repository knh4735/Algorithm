// 1922 네트워크연결 그래프1(프림)
#include <stdio.h>

struct EDGE {
	int to;
	int cost;
	EDGE *next = nullptr;
};

EDGE pool[200001];
int pool_cnt = 0;

void add_edge(EDGE e[], int from, int to, int cost){
	EDGE *cur = &e[from];
	while(cur->next != nullptr) cur = cur->next;
	pool[pool_cnt].to = to;
	pool[pool_cnt].cost = cost;
	cur->next = &pool[pool_cnt];
	pool_cnt++;
}

struct HEAP {
	EDGE q[200001];
	int cnt = 0;
};

void push(HEAP *heap, EDGE value){
	heap->cnt++;
	heap->q[heap->cnt] = value;

	int cur = heap->cnt, p = cur / 2;
	while(heap->q[p].cost > heap->q[cur].cost && p > 0){
		EDGE tmp = heap->q[p];
		heap->q[p] = heap->q[cur];
		heap->q[cur] = tmp;

		cur = p;
		p = cur / 2;
	}
}

EDGE pop(HEAP *heap){
	EDGE ret = heap->q[1];
	EDGE last = heap->q[heap->cnt];
	heap->cnt--;

	int cur = 1, child = cur * 2;
	while(child <= heap->cnt){
		// child = 더 작은 노드
		if(child < heap->cnt && heap->q[child].cost > heap->q[child+1].cost) child += 1;

		if(last.cost < heap->q[child].cost) break;

		heap->q[cur] = heap->q[child];
		cur = child;
		child = cur * 2;
	}

	heap->q[cur] = last;
	return ret;
}

int main(){
	EDGE e[1001];
	HEAP pq;
	int visit[1001] = {0, };

  int n, m;
  scanf("%d %d", &n, &m);

  int a, b, c;
  for(int i = 0; i < m; i++){
    scanf("%d %d %d", &a, &b, &c);

		add_edge(e, a, b, c);
		add_edge(e, b, a, c);
  }

	int sum = 0, cnt = 1;
	visit[1] = 1;

	// 시작점과 연결된 간선들 push
	EDGE *cur = &e[1];
	while(cur->next != nullptr){
		cur = cur->next;
		push(&pq, *cur);
	}

	while(cnt < n){
		EDGE edge = pop(&pq);
		if(visit[edge.to] == 1) continue;

		// printf("ADD %d - cost %d\n", edge.to, edge.cost);
		visit[edge.to] = 1;
		sum += edge.cost;
		cnt++;

		// 해당 노드와 연결된 간선들 push
		cur = &e[edge.to];
		while(cur->next != nullptr){
			cur = cur->next;
			if(visit[cur->to] == 0) push(&pq, *cur);
		}
	}

	printf("%d", sum);

	return 0;
}
