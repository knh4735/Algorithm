// 2824 최대공약수 정수론(최대공약수)
#include <stdio.h>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

map<int, int> gcd1, gcd2;

int isPrime(int a){
	for(int i = 2; i <= sqrt(a); i++){
		if(a % i == 0) return 0;
	}

	return 1;
}

int main(){
	// 범위 내 소수 배열 생성
	int cnt = 2;
	int max_size = 31624;	// sqrt(1000000000) ~ 31622.7~
	int a[max_size] = {0, };
	vector<int> prime;
	while(cnt < max_size-1){
		int min;
		for(int i = 2; i < max_size; i++){
			if(a[i] == 0){
				min = i;
				prime.push_back(i);
				break;
			}
		}

		for(int i = min; i < max_size; i += min){
			if(a[i] == 1) continue;
			a[i] = 1;
			cnt++;
		}
	}

	int n;
	int tmp;

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &tmp);

		for(auto p: prime){
			while(tmp % p == 0){
				tmp = tmp / p;
				gcd1[p]++;
			}

			if(tmp == 1) break;
		}
		if(tmp != 1) gcd1[tmp]++;
	}
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &tmp);

		for(auto p: prime){
			while(tmp % p == 0){
				tmp = tmp / p;
				gcd2[p]++;
			}

			if(tmp == 1) break;
		}
		if(tmp != 1) gcd2[tmp]++;
	}

	int flag = 0;
	long long ans = 1ll;
	for(auto i: gcd1){
		int gcd = i.first;
		if(gcd2.count(gcd) == 0) continue;
		int m = min(gcd1[gcd], gcd2[gcd]);
		while(m > 0){
			ans = ans * gcd;
			m--;
			if(ans > 1000000000){
				// 오버플로우 방지
				ans %= 1000000000;
				flag = 1;
			}
		}
	}

	if(flag == 1) printf("%09lld", ans % 1000000000ll);
	else printf("%lld", ans);

	return 0;
}
