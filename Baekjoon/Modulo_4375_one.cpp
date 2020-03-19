// 4375 1 정수론(Modulo)
#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;

int mod(int p){
	int ret = 0, cnt = 0;

	do {
		ret = (ret * 10 + 1) % p;
		cnt++;
	} while(ret != 0);

	return cnt;
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		printf("%d\n", mod(n));
	}

	return 0;
}
