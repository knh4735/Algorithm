// 2805 나무자르기 시간복잡도(이분탐색)
#include <stdio.h>

int n, m;
long long tree[1000001];

long long get_upper_half(long long q, long long w){
	return (q + w) / 2ll;
}

long long get_lower_half(long long large, long long small){
	return small + (large - small) / 2ll;
}

long long cut_tree(long long height){
	long long sum = 0;
	for(int i = 0; i < n; i++){
		if(tree[i] <= height) continue;
		sum += tree[i] - height;
	}
	return sum;
}

int main(){
	scanf("%d %d", &n, &m);

	long long max_height = 0, min_height = 0;
	for(int i = 0; i < n; i++){
		scanf("%ld", &tree[i]);
		if(max_height < tree[i]) max_height = tree[i];
	}

	long long half = (max_height + min_height) / 2ll;
	while(1){
		long long trees = cut_tree(half);
		// printf("%ld %ld %ld %lld\n", max_height, min_height, half, trees);
		
		if(trees < m){
			max_height = half;
			half = get_lower_half(max_height, min_height);

			if(half == min_height){
				printf("%d", min_height);
				return 0;
			}
		} else if(trees > m){
			min_height = half;
			half = get_upper_half(max_height, min_height);

			if(half == min_height){
				printf("%d", min_height);
				return 0;
			}
		} else {
			printf("%d", half);
			return 0;
		}
	}

	return 0;
}
