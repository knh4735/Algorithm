/*
1700 멀티탭스케줄링 Greedy
n구 멅티탭에 플러그를 뽑는 횟수가 최소가 되도록 어떤 플러그를 뽑을지 정하기
입력 : 멀티탭 구멍의 수 1 <= n <= 100, 전기사용횟수 1 <= k <= 100 \n 전기 제품 사용 순서 
출력 : 플러그를 뽑는 최소 횟수
*/
#include <stdio.h>

int n, k, cnt;
int ed[101], book[101]; //book[i] = i < j이고 ed[i] == ed[j]인 j의 최솟값

struct p{
	int num;
	int book;
};

p plug[101];

int find(int edIdx, int len){	//플러그에 꽂혀있으면 -1 없으면 book이 가장 큰놈 인덱스 반환
	for(int i = 0; i < len; i++){
		if(ed[edIdx] == plug[i].num){
			plug[i].book = book[edIdx];
			return -1;
		}
	}

	int max = 0, idx = 0;
	for(int i = 0; i < len; i++){
		if(max < plug[i].book){
			idx = i;
			max = plug[i].book;
		}
	}

	return idx;
}

int main(){
	scanf("%d %d", &n, &k);

	for(int i = 0; i < k; i++) scanf("%d", &ed[i]);

	for(int i = 0; i < k; i++){
		for(int j = i + 1; j < k; j++){
			if(ed[i] == ed[j]){
				book[i] = j;
				break;
			}
		}

		if(book[i] == 0) book[i] = k + 1;
	}


	int edIdx = 0, plugIdx = 0;
	while(plugIdx < n && edIdx < k){
		if(find(edIdx, plugIdx) >= 0){
			plug[plugIdx].num = ed[edIdx];
			plug[plugIdx].book = book[edIdx];
			plugIdx++;
		}
		edIdx++;
	}


	for(int i = n; i < k; i++){
		int q = find(i, n);

		if(q >= 0){
			plug[q].num = ed[i];
			plug[q].book = book[i];
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}
