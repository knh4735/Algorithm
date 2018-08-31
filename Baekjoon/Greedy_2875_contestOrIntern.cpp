/*
2875 대회or인턴 Greedy
n명의 여학생과 m명의 남학생이 2여1남으로 팀을짜야한다. 이중 k명은 팀을 짤 수 없을때 최대 팀의 수
입력 : 0 <= n, m <= 100, 0 <= k <= n+m
출력 : 최대 팀의 수
*/
#include <stdio.h>

int main(){
	int n, m, k, r = 0;
	scanf("%d %d %d", &n, &m, &k);

	if(n == 0 || m == 0){
		printf("%d", 0);
		return 0;
	}

	if(n - 2 * m > 0){	//여자가 남음 -> k = 남는여자들 + 팀에서 3명씩 + 나머지한팀에서 1-2명
		k -= n - 2 * m;

		r = m;

		if(k > 0){
			r -= k / 3;

			k = k % 3;
			if(k > 0) r -= 1;
		}
	}
	else if(n / 2 - m < 0){	//남자가 남음 -> k = 남는 남자들
		k -= m - n / 2;

		//여자도 1명 남음
		if(n % 2 == 1) k -= 1;

		r = n / 2;

		if(k > 0){
			r -= k / 3;

			k = k % 3;
			if(k > 0) r-= 1;
		}
	}
	else{	//같음
		r = m;

		if(k > 0){
			r -= k / 3;

			k = k % 3;
			if(k > 0) r-= 1;
		}
	}

	printf("%d", r);

	return 0;
}
