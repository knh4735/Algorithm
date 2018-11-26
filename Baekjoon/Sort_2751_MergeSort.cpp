/*
2751 수정렬하기2 Merge Sort
머지소트 사용해서 정렬하기
*/
#include <stdio.h>

void merge(int a[], int l, int m, int r){
	int i = l, j = m + 1, tempIdx = l;
	int temp[1000001];

	while(i <= m && j <= r){
		if(a[i] > a[j]) temp[tempIdx++] = a[j++];
		else temp[tempIdx++] = a[i++];
	}

	if(i <= m) for(int k = i; k <= m; k++) temp[tempIdx++] = a[k];
	else if(j <= r) for(int k = j; k <= r; k++) temp[tempIdx++] = a[k];

	for(int k = l; k <= r; k++) a[k] = temp[k];
}

void merge_sort(int a[], int l, int r){
	if(l < r){
		int m = (l + r) / 2;

		merge_sort(a, l, m);
		merge_sort(a, m + 1, r);

		merge(a, l, m, r);
	}
}

int main(){
	int n, a[1000001];
	scanf("%d", &n);

	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	merge_sort(a, 0, n - 1);

	for(int i = 0; i < n; i++) printf("%d\n", a[i]);

	return 0;
}
