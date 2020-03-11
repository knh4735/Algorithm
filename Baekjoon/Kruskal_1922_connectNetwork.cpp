// 1922 네트워크연결 그래프1(크루스칼)
#include <stdio.h>
#include <algorithm>

struct EDGE {
  int n1, n2;
  int cost;
};

// true면 q w 순서
int cmp(EDGE q, EDGE w){
	return q.cost < w.cost;
}

int find(int set[], int n){
	if(set[n] == 0) return n;
	return find(set, set[n]);
}

void union_set(int set[], int q, int w){
	int s1 = find(set, q);
	int s2 = find(set, w);

	// 더 작은 수로 루트 지정
	if(s1 > s2) set[s1] = s2;
	else set[s2] = s1;
}

int main(){
  int e_cnt = 0;
  EDGE e[100001];
	int set[1001] = {0, };

  int n, m;
  scanf("%d %d", &n, &m);

  int a, b, c;
  for(int i = 0; i < m; i++){
    scanf("%d %d %d", &a, &b, &c);

    e[e_cnt].n1 = a;
    e[e_cnt].n2 = b;
    e[e_cnt].cost = c;
    e_cnt++;
  }

	std::sort(e, e+m, cmp);

  int sum = 0;
	for(int i = 0; i < m; i++){
		if(find(set, e[i].n1) == find(set, e[i].n2)) continue;

		sum += e[i].cost;
		union_set(set, e[i].n1, e[i].n2);
	}

	printf("%d", sum);

	return 0;
}
