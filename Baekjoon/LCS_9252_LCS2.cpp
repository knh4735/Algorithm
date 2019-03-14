/*
9252 LCS LCS(Longest Common Subsequence)-DP
두 문자열에 포함된 부분 수열 중 가장 긴 것을 찾기
입력 : ~2 문자열 (최대 1000자)
출력 : LCS의 길이 \n LCS 문자열
*/
#include <stdio.h>
#include <string.h>

char s1[1001], s2[1001], s[1001];
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

	int lastIdx = 0, last1, last2;
	char lastC;

	int max1 = n1+1,
		max2 = n2+1;
	while(lastIdx != 1){
		lastIdx = 0;
		for(int i = 1; i < max1; i++){
			for(int j = 1; j < max2; j++){
				if(lcs[i][j] > lastIdx){
					lastIdx = lcs[i][j];
					last1 = i;
					last2 = j;
					lastC = s1[i-1];
				}
			}
		}
		s[lastIdx-1] = lastC;
		max1 = last1;
		max2 = last2;
	}

	s[lcs[n1][n2]] = '\0';
	printf("%d\n%s", lcs[n1][n2], s);

	return 0;
}
