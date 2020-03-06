// 1072 게임 시간복잡도(이분탐색)
#include <stdio.h>

int main(){
	long long x, y;
	scanf("%lld %lld", &x, &y);

	long long z = (y * 100ll) / x;

	if(z >= 99){
		printf("-1");
		return 0;
	}

	long long max = 1;
	long long nx, ny, nz;
	do{
		nx = x + max;
		ny = y + max;
		nz = (ny * 100ll) / nx;
		max *= 2;
	} while(z == nz);

	max /= 2;
	long long min = max / 2;
	long long i = (max + min) / 2;
	while(1){
		nx = x + i;
		ny = y + i;
		nz = (ny * 100ll) / nx;
		if(nz == z){
			min = i;
			i = (max + min) / 2;
		} else {
			max = i;
			i = (max + min) / 2;
		}

		if(min == i){
			printf("%lld", max);
			return 0;
		}
	}

	return 0;
}
