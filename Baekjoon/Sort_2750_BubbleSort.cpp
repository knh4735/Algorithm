/*
2750 수정렬해보기1 Bubble Sort
*/
#include <stdio.h>

int main(){
	int n, a[1000];
	scanf("%d", &n);

	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[i] < a[j]){
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}

	for(int i = 0; i < n; i++) printf("%d\n", a[i]);

	return 0;
}
