// 3830 도로네트워크 그래프1(LCA)
#include <stdio.h>
#include <vector>
using namespace std;

struct ROAD {
	int city;
	int len;
};

vector<ROAD> road[100001];
int d[100001];
int p[100001][17];
int mn[100001][17];
int mx[100001][17];
int min_len, max_len;

void set_depth(int city, int depth){
	d[city] = depth;
	for(int i = 0; i < road[city].size(); i++){
		ROAD next = road[city][i];
		if(d[next.city] != 0) continue;
		p[next.city][0] = city;
		mn[next.city][0] = next.len;
		mx[next.city][0] = next.len;
		set_depth(next.city, depth + 1);
	}
}

void lca(int h, int l){
	if(d[h] > d[l]){
		int tmp = h;
		h = l;
		l = tmp;
	}

	for(int j = 16; j >= 0; j--){
		if(d[l] - d[h] >= (1 << j)){
			if(min_len == 0 || min_len > mn[l][j]) min_len = mn[l][j];
			if(max_len == 0 || max_len < mx[l][j]) max_len = mx[l][j];
			l = p[l][j];
		}
	}


	if(h == l) return;

	int tmp;
	for(int j = 16; j >= 0; j--){
		if(p[h][j] != p[l][j]){
			tmp = min(mn[l][j], mn[h][j]);
			if(min_len == 0 || min_len > tmp) min_len = tmp;
			tmp = max(mx[l][j], mx[h][j]);
			if(max_len == 0 || max_len < tmp) max_len = tmp;

			h = p[h][j];
			l = p[l][j];
		}
	}

	tmp = min(mn[l][0], mn[h][0]);
	if(min_len == 0 || min_len > tmp) min_len = tmp;
	tmp = max(mx[l][0], mx[h][0]);
	if(max_len == 0 || max_len < tmp) max_len = tmp;
}

int main(){
	int n;
	int a, b, l;
	scanf("%d", &n);
	for(int i = 1 ; i < n; i++){
		scanf("%d %d %d", &a, &b, &l);

		road[a].push_back({b, l});
		road[b].push_back({a, l});
	}

	set_depth(1, 1);

	for(int j = 1; j < 17; j++){
		for(int i = 1; i <= n; i++){
			int grandfather = p[i][j-1];
			p[i][j] = p[grandfather][j-1];
			mn[i][j] = min(mn[i][j-1], mn[grandfather][j-1]);
			mx[i][j] = max(mx[i][j-1], mx[grandfather][j-1]);
		}
	}

	int k;
	scanf("%d", &k);
	for(int i = 0 ; i < k; i++){
		scanf("%d %d", &a, &b);

		min_len = 0;
		max_len = 0;
		lca(a, b);

		printf("%d %d\n", min_len, max_len);
	}


	return 0;
}
