// 1717 집합의표현 그래프1(disjoint-set)
#include <stdio.h>

int find(int set[], int q){
	if(set[q] == q) return q;
	return find(set, set[q]);
}

void u(int set[], int q, int w){
	q = find(set, q);
	w = find(set, w);
	if(q > w) set[q] = w;
	else set[w] = q;
}

int main(){
	int set[1000001];

	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i <= n; i++) set[i] = i;

	int cmd, a, b;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &cmd, &a, &b);
		if(cmd == 0){
			u(set, a, b);
			// for(int i = 0; i <= n; i++) printf("%d ", find(set, i));
			// printf("\n");
		} else {
			if(find(set, a) == find(set, b)) printf("YES\n");
			else printf("NO\n");
		}
	}


	return 0;
}
