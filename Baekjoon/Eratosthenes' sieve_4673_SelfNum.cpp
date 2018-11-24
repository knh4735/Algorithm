/*
4673 셀프넘버 에라토스테네스의 체
자연수 n에서 n + n의 각 자릿수의 합을 구하는 함수 d가 있다. 10000 이하의 수 중 d로 만들 수 없는 수를 셀프 넘버라고 부른다.
입력 : 없응
출력 : ~10000 이하의 셀프 넘버들을 출력
*/

#include <stdio.h>

int a[10001];	//0이면 생성자 없음, 1이면 잇음

int getD(int n){	//생성 함수
	int sum = n, div = 1000;
	while(n / div == 0) div /= 10;

	while(n > 0){
		sum += n / div;
		n -= (n / div) * div;
		div /= 10;
	}

	return sum;
}

void rec(int n){	//입력받은 수로 다음 생성 진행
	if(n > 10000) return;

	//다음 수 생성
	int g = getD(n);

	//이미 생성됬던 수이면 더 진행할 필요없음
	if(a[g] == 1) return;

	rec(g);

	//생성된 수에 1 저장
	a[g] = 1;

	return;
}

int main(){
	//모든 수로 생성 진행
	for(int i = 1; i <= 10000; i++) rec(i);

	for(int i = 1; i <= 10000; i++){
		if(a[i] == 0) printf("%d\n", i);
	}

    
    return 0;
}
