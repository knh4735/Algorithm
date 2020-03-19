// 5376 소수를분수로 정수론(유클리드호제법)
#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;

long long euclidean(long long a, long long b){
	long long tmp;
	while(b > 0){
		tmp = a;
		a = b;
		b = tmp % a;
	}

	return a;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int tc = 0; tc < T; tc++){
		char tmp;
		
		// 0.
		scanf(" %c", &tmp);
		scanf(" %c", &tmp);

		int cycle_cnt = 0, cnt = 0;
		long long total_num = 0ll, num = 0ll;
		int cycle_flag = 0;
		while(scanf("%c", &tmp) && tmp != '\n'){
			if(tmp == ')') break;
			else if(tmp == '(') cycle_flag = 1;
			else {
				if(cycle_flag == 1) cycle_cnt++;
				else {
					cnt++;
					num = num * 10ll + (long long)(tmp - '0');
				}

				total_num = total_num * 10ll + (long long)(tmp - '0');
			}
		}
		// printf("%d %d %lld %lld\n", cycle_cnt, cnt, total_num, num);
		long long denom = 1ll;

		if(cycle_flag == 1){
			num = total_num - num;

			denom = 0ll;
			for(int i = 0; i < cycle_cnt; i++) denom = denom * 10ll + 9ll;
		}

		for(int i = 0; i < cnt; i++) denom *= 10ll;
		// printf("%lld %lld\n", num, denom);

		long long gcd = euclidean(num, denom);
		printf("%lld/%lld\n", num / gcd, denom / gcd);
	}

	return 0;
}
