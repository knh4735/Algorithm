/*
9251 LCS LCS(Longest Common Subsequence)-DP
두 문자열에서 LCS인 부분 문자열의 길이 구하기
입력 : ~2 문자열 (최대 1000자)
출력 : LCS의 길이
*/
#include <stdio.h>
#include <string.h>

char s1[1001], s2[1001];
int lcs[1001][1001];

int max(int a, int b){return a > b ? a : b;}

int main(){
	scanf("%s", s1);
	scanf(" %s", s2);

	int n1 = strlen(s1),
		n2 = strlen(s2);

	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= n2; j++){
			if(s1[i-1] == s2[j-1])
				lcs[i][j] = lcs[i-1][j-1] + 1;
			
			else
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}
	}

	printf("%d", lcs[n1][n2]);

	return 0;
}
