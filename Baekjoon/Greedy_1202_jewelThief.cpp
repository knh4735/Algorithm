/*
1202 보석도둑 Greedy
무게 Mi와 가격 Vi의 n개의 보석을 Ci의 무게까지 담을수 있는 k개의 가방에 각각 담아 가져갈떄 훔칠 수 있는 최대 가격 구하기
입력 : 1 ≤ N, K ≤ 300,000 \n ~보석의 무게와 가격 0 ≤ Mi, Vi ≤ 1,000,000 \n 가방 용량 1 ≤ Ci ≤ 100,000,000
출력 : 훔칠 수 있는 보석들의 최대 가격
*/
#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;

int n, k;
long long int value;

struct jewerly{
	int m;
	int v;
};

//가격내림 -> 무게오름 
int cmpJ(const void* a, const void* b){
	jewerly* q = (jewerly*)a;
	jewerly* w = (jewerly*)b; 

	if(w->v == q->v) return w->m - q->m;
	return w->v - q->v;
}

//용량오름
int orm(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int main(){
	scanf("%d %d", &n, &k);

	jewerly j[n];
	for(int i = 0; i < n; i++) scanf("%d %d", &j[i].m, &j[i].v);

	multiset<int> bag;
	multiset<int>::iterator iter;
	for(int i = 0; i < k; i++){
		int temp;
		scanf("%d", &temp);
		bag.insert(temp);
	}

	qsort(j, n, sizeof(j[0]), cmpJ);

	for(int i = 0; i < n; i++){
		if(bag.size() == 0) break;

		auto lb = bag.lower_bound(j[i].m);
		if(lb != bag.end()){
			value += j[i].v;
			bag.erase(lb);
		}
	}

	printf("%lld", value);

	return 0;
}
