/*
10610 삼십 Greedy
양수 n의 수 조합을 섞어서 30의 배수로 만들기, 불가능하면 -1
입력 : n
출력 : 30의 배수, 없다면 -1
*/
#include <stdio.h>
#include <algorithm>

int main(){
	int n[100001], l = 0;

	char c = getchar();
	while(c != '\n' && c != EOF){
		n[l++] = c - '0';
		c = getchar();
	}

	int sum = 0, zFlag = -1;
	for(int i = 0; i < l; i++){
		sum += n[i];
		if(n[i] == 0) zFlag = i;
	}

	if(zFlag > -1 && sum % 3 == 0){
		std::sort(n, n+l);
		for(int i = l - 1; i >= 0; i--) printf("%d", n[i]);
	}

	else printf("-1");

	return 0;
}
