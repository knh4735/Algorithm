/*
1958 LCS3 LCS(Longest Common Subsequence)-DP
3개의 문자열에서 LCS의 길이를 구하기
입력 : ~3 문자열 (최대 100자)
출력 : LCS의 길이
*/
#include <stdio.h>
#include <string.h>

char s1[101], s2[101], s3[101];
int lcs[101][101][101];

int max(int a, int b, int c){
	int tmp = (a > b ? a : b); 
	return  tmp > c ? tmp : c;
}

int main(){
	scanf("%s", s1);
	scanf(" %s", s2);
	scanf(" %s", s3);

	int n1 = strlen(s1),
		n2 = strlen(s2),
		n3 = strlen(s3);

	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= n2; j++){
			for(int k = 1; k <= n3; k++){
				if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
					lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
				
				else
					lcs[i][j][k] = max(lcs[i-1][j][k], lcs[i][j-1][k], lcs[i][j][k-1]);
			}
		}
	}

	printf("%d", lcs[n1][n2][n3]);

	return 0;
}
