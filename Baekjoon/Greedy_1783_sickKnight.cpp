/*
1783 병든나이트 Greedy
NxM 체스판의 왼쪽아래 끝에서 이동하는 병든나이트가 이동할 수 잇는 최대 칸수 구하기
2상1우, 1상2우, 1하2우, 2하1우 로만 이동 가능하며 4번 이상 이동시 각 이동방식을 최소 한번씩은 사용해야함
입력 : 1 <= n, m <= 2,000,000,000
출력 : 이동할 수 있는 최대 칸 수
*/
#include <stdio.h>

int main(){
	long long int h, w;
	scanf("%lld %lld", &h, &w);

  //이동 불가
	if(h == 1) printf("1");
  
  //1상2우, 1하2우만 이동 가능 / 7번째칸 이후로는 이동 불가
	else if(h == 2){
		if(w > 6) printf("4");
		else printf("%lld", (w + 1) / 2);
	}
  
  //4번째열까진 2상1우, 2하1우로 모든 열에 한번씩 이동가능
	else if(w < 4) printf("%lld", w);
  
  //4번째 열까지 모든열 찍고 5,6번째 열은 이동불가
	else if(w <= 6) printf("4");
  
  //4번 이상 이동시 각 이동방식을 최소 한번씩은 사용해야함 -> 한번씩 사용하면 7번째열 이후 모든 열에 한번씩 방문 가능
	else printf("%lld", w - 2);

	return 0;
}