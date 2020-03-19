// 1837 암호제작 정수론(Modulo)
#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;

int mod(char *s, int p){
	int ret = 0;
	while(*s != '\0'){
		ret = (ret * 10 + (*s - '0')) % p;
		s++;
	}
	return ret;
}

int main(){
	char p[102];
	int k;
	scanf("%s %d", p, &k);

	int a[1000001] = {0, };
	vector<int> prime;
	for(int i = 2; i < k; i++){
		if(a[i] == 1) continue;

		prime.push_back(i);
		if(i > sqrt(k)) continue;
		for(int j = i; j < k; j += i) a[j] = 1;
	}

	for(auto n: prime){
		if(mod(p, n) == 0){
			printf("BAD %d", n);
			return 0;
		}
	}

	printf("GOOD");

	return 0;
}
