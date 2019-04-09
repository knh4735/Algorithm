/*
5658 보물상자 비밀번호 Simulation
N개의 16진수 수열을 N/4개씩 끊어서 숫자를 생성할 수 있다. 수열을 로테이션시켜 같은 방식으로 생성되는 숫자들 중에 K번째로 큰 수 구하기
입력 : Test Case \n 수열의 개수 8 ≤ N ≤ 28, 몇번째로 큰지 K (생성되는 수를 넘지않음) \n N개의 16진수 (A~F는 대문자로 입력되며 공백없이 주어진다.)
출력 : 규칙에 따라 생성된 수 중 K번째로 큰 수 (중복 제외)
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, k;
int num[29];
int r[29], r_idx;

void rotate(){
	int tmp = num[n-1];
	for(int i = n-1; i > 0; i--)
		num[i] = num[i-1];
	num[0] = tmp;

	return;
}


void calc(){
	for(int i = 1; i <= 4; i++){
		int sum = 0, mul = 1;
		for(int j = i*(n/4) - 1; j >= (i-1)*(n/4); j--, mul *= 16)
			sum += mul * num[j];

		int flag = 1;
		for(int j = 0; j < r_idx; j++){
			if(sum == r[j]){
				flag = 0;
				break;
			} 
		}

		if(flag) r[r_idx++] = sum;
	}

	return;
}

int main(){
	int T;
	scanf("%d", &T);

	for(int t = 1; t <= T; t++){
		r_idx = 0;
		scanf("%d %d", &n, &k);
		
		char c;
		for(int i = 0; i < n; i++){
			scanf(" %c", &c);
			if(c >= 'A') num[i] = 10 + c - 'A';
			else num[i] = c-'0';
		}

		calc();
		for(int i = 0; i < n/4; i++){
			rotate();
			calc();
		}

		sort(r, r+r_idx);
		
		/*
		for(set<int>::iterator i = s.begin(); i != s.end(); i++) printf("%d ", *i);
		printf("\n");
		*/

		printf("#%d %d\n", t, r[r_idx-k]);
	}
}
