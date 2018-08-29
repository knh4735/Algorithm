//11057 오르막수 Dynamic Programming
#include <stdio.h>

int n;
long long int r[1001][11];	//r[자릿수][앞자리수]

int sumTo9(int s, int i){
	int sum = 0;
	for(int q = s; q < 10; q++){
		sum += r[i][q] % 10007;
	}
	return sum % 10007;
}

int main(){

	scanf("%d", &n);

	for(int i = 0; i < 10; i++){
		r[1][i] = 1;
		r[1][10] += r[1][i];
	}

/*
	r[n][0] = r[n-1][0] + r[n-1][1] + ... + r[n-1][9];
+	r[n][1] = r[n-1][1] + ... + r[n-1][9];
+	r[n][2] = r[n-1][2] + ... + r[n-1][9];
+	...
+	r[n][9] = r[n-1][9];

=>	r[n][10] = r[n][0] + ... r[n][9] = r[n-1][0] + ... + (i + 1) * r[n-1][i] + ... + 9 * r[n-1][9];
*/

	for(int i = 1; i < n; i++){
		for(int j = 0; j < 10; j++){
			r[i+1][j] = sumTo9(j, i);
		}

		r[i+1][10] = sumTo9(0, i+1);
	}


	printf("%lld", r[n][10]);

	return 0;
}
