/*
1946 신입사원 Greedy
지원자가 두가지 분야 중 적어도 한 분야가 다른 지원자들보다 나은 경우만 뽑음
입력 : 테스트케이스 수 1 <= t <= 20 \n 각 테스트케이스의 지원자수 1 <= n <= 100000 \n ~각 지원자의 서류점수 면접점수
출력 : ~각 테스트케이스에서 선발할 수 있는 지원자 수
*/
#include <stdio.h>
#include <algorithm>

struct score{
	int doc;
	int view;
};

int compare(const void* a, const void* b){
	score *q = (score*)a;
	score *w = (score*)b;

	if(q->doc == w->doc) return q->view - w->view;
	else return q->doc - w->doc;
}


int main(){
	int t;
	scanf("%d", &t);

	for(int testCase = 0; testCase < t; testCase++){
		int n, r;
		scanf("%d", &n);
		r = n;

		score e[n];
		for(int i = 0; i < n; i++) scanf("%d %d", &e[i].doc, &e[i].view);

		qsort(e, n, sizeof(score), compare);

	//	for(int i = 0; i < n; i++) printf("%d %d\n", e[i].doc, e[i].view);

		int topV = e[0].view;
		for(int cur = 1; cur < n; cur++){
			if(e[cur].view > topV) r--;
			else topV = e[cur].view;
		}

		printf("%d\n", r);
	}

	return 0;
}
