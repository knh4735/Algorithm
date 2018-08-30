/*
1931 회의실배정 Greedy
회의실에서 n개의 회의가 겹치지 않게 시간표를 만들어 최대한 많은 회의가 열리도록 하기
입력 : 1 <= n <= 100000 \n ~ 0 <= 시작시간 끝시간  <= 2^31 - 1
출력 : 최대 회의 수
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

struct t{
	int s;
	int e;
};

int compare(const void* a, const void* b){
	t *q = (t*)a;
	t *w = (t*)b;

	if(q->e == w->e) return q->s - w->s;
	else return q->e - w->e;
}

int main(){
	int n, m = 0, e = 0;
	scanf("%d", &n);

	t meeting[n];
	for(int i = 0; i < n; i++) scanf("%d %d", &meeting[i].s, &meeting[i].e);

	qsort(meeting, n, sizeof(t), compare);

	for(int i = 0; i < n; i++){
		if(e <= meeting[i].s){
			e = meeting[i].e;
			m++;
		}
	}

	printf("%d", m);


	return 0;
}
