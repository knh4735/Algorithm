/*
2352 반도체설계 LIS
n개의 포트가 맞은편의 n개의 다른 포트와 연결될 때 서로 겹치지 않고 연결될 수 있는 최대의 연결 수
입력 : 1 <= n <= 40000 \n ~ 1 <= i번 포트와 연결되어야하는 포트번호 <= n
출력 : 최대 연결 개수
*/
#include <stdio.h>
#include <algorithm>

int compare(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int main(){
	int n;
	scanf("%d", &n);

	int con[n];
	for(int i = 0; i < n; i++) scanf("%d", &con[i]);


	int list[n], len = 0;
	for(int i = 0; i < n; i++) list[i] = 0;
	list[len++] = con[0];
	for(int i = 1; i < n; i++){
		if(list[len-1] < con[i]) list[len++] = con[i];
		else{
			int* lb = std::lower_bound(list, list+len, con[i]);
			*lb = con[i];
		}
	}

	printf("%d", len);

	return 0;
}
