/*
1120 문자열 Greedy
길이가 n인 두 문자열 x와 y의 차이는 x[i] != y[i]인 i의 개수이다.
길이가 b보다 작거나 같은 문자열 a가 b와 최소로 차이나도록 앞이나 뒤에 알파벳을 붙일수 있을때 최소가 되는 차이를 구하기
입력 : 문자열 a와 b (길이 <= 50)
출력 : 두 문자열의 최소 차이
*/
#include <stdio.h>

char a[51], b[51], idx, min = 51;
int lenA, lenB;

int getDiff(int addIdx){
	int diff = 0;
	for(int i = 0; i < lenA; i++) if(a[i] != b[i + addIdx]) diff++;

	return diff;
}

int main(){

	char c = getchar();
	while(c != ' ' && c != EOF){
		a[idx++] = c;
		c = getchar();
	}
	lenA = idx;

	idx = 0;
	c = getchar();
	while(c != '\n' && c != EOF){
		b[idx++] = c;
		c = getchar();
	}
	lenB = idx;

	for(int i = 0; i <= lenB - lenA; i++){
		int temp = getDiff(i);
		if(min > temp) min = temp;
	}

	printf("%d", min);


	return 0;
}
