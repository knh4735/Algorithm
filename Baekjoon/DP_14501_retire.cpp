/*
14501 퇴사 Dynamic Programming
상담원이 퇴사하기까지 N일 남았다. 하루에 한개씩 상담이 잡혀있고 상담은 각각 Ti일 걸리고, Pi원 받는다. 상담원이 가장 많이 벌고 퇴사할 수 있는 금액 구하기
입력 : 1 ≤ N ≤ 15 \n ~N 소요시간, 보수 1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1,000
출력 : 보수의 
*/
#include <stdio.h>

int n;
int t[16], p[16];
int dp[16];

int calc(int idx){
	int max = p[idx], tmp = 0;
	for(int i = 0; i < idx; i++){
		if(t[i] < idx){
			tmp = dp[i] + p[idx];
			max = tmp > max ? tmp : max;
		}
	}

	return max;
}

int main(){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d %d", &t[i], &p[i]);
		t[i] += i - 1;
	}

	dp[0] = p[0];
	for(int i = 1; i < n; i++){
		if(t[i] < n) dp[i] = calc(i);
		else dp[i] = dp[i-1];
	}

	int m_idx = -1;
	for(int i = 0; i < n; i++){
		if(dp[i] > 0){
			if(m_idx == -1 || dp[i] > dp[m_idx]){
				m_idx = i;
			}
		}
	}

	if(t[0] >= n && m_idx == 0){
		printf("0");
		return 0;
	}
	
	printf("%d", m_idx == -1 ? 0 : dp[m_idx]);


	return 0;
}
