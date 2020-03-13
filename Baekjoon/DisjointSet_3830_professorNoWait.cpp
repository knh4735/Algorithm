// 3830 교수님은기다리지않는다 그래프1(disjoint-set)
#include <stdio.h>

int find(long long weight[], int group[], int q){
	if(group[q] == q) return q;

	int root = find(weight, group, group[q]);
	weight[q] += weight[group[q]];
	group[q] = root;

	return root;
}

long long diff(long long weight[], int group[], int q, int rq){
	long long wq = weight[q];
	int gq = group[q];
	while(gq != rq){
		wq += weight[gq];
		gq = group[gq];
	}

	return wq;
}

int main(){
	while(1){
		int n, m;
		int group[100001];
		long long weight[100001] = {0ll, };

		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0) break;
		for(int i = 0; i <= n; i++) group[i] = i;

		char cmd;
		int a, b, w;
		for(int i = 0; i < m; i++){
			scanf(" %c", &cmd);
			
			if(cmd == '!'){
				scanf("%d %d %d", &a, &b, &w);
				
				int ra = find(weight, group, a);
				int rb = find(weight, group, b);
				if(ra == rb) continue;


				// a - ra = weight[a]
				// b - rb = weight[b]
				// b - a = w

				// rb - ra = weight[rb] = w + weight[a] - weight[b]

				group[rb] = ra;
				weight[rb] = (long long)w + weight[a] - weight[b];

				// printf("\nGROUP: ");
				// for(int i = 1; i <= n; i++) printf("%d ", group[i]);
				// printf("\nWEIGHT:");
				// for(int i = 1; i <= n; i++) printf("%lld ", weight[i]);
				// printf("\n");
			} else if(cmd == '?'){
				scanf("%d %d", &a, &b);

				int ra = find(weight, group, a);
				int rb = find(weight, group, b);

				if(ra != rb){
					printf("UNKNOWN\n");
					continue;
				}
				
				// printf("%d %d %d %d\n", a, ra, b, rb);
				printf("%lld\n", weight[b] - weight[a]);
			}
		}
	}

	return 0;
}
