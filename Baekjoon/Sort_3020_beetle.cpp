// 3020 개똥벌레 자료구조(정렬?)
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int n, h;
	scanf("%d %d", &n, &h);

	int bot[100001], top[100001];
	for(int i = 0; i < n ; i++){
		if(i % 2 == 0) scanf("%d", &bot[i/2]);
		else{
			scanf("%d", &top[i/2]);
			top[i/2] = h - top[i/2];
		}
	}

	sort(top, top+n/2);
	sort(bot, bot+n/2);
	// top : 2 3 1 1 2 3 2 => 1 1 2 2 2 3 3
	// bot : 1 4 2 3 3 3 3 => 1 2 3 3 3 3 4

	int min = -1, cnt = 0;
	int t_idx = 0, b_idx = 0;
	for(int i = 1; i <= h; i++){
		while(top[t_idx] < i && t_idx < (n/2)) t_idx++;
		while(bot[b_idx] < i && b_idx < (n/2)) b_idx++;

		int pass = t_idx + (n/2) - b_idx;
		//printf("h %d through %d\n", i, pass);
		if(min == -1 || pass < min){
			min = pass;
			cnt = 1;
		}	else if(min == pass) cnt++;
	}

	printf("%d %d", min, cnt);
	
	return 0;
}
