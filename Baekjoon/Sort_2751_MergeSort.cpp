/*
2751 수정렬하기2 Merge Sort
머지소트 사용해서 정렬하기
*/
#include <stdio.h>

//병합 정렬
void merge(int a[], int l, int m, int r){
	//i : 왼쪽 배열 인덱스, j : 오른쪽 배열 인덱스, tempIdx : 임시 저장배열 인덱스
	int i = l, j = m + 1, tempIdx = l;
	int temp[1000001];

	//왼쪽과 오른쪽 배열의 값을 비교하며 작은 값으 임시 배열에 저장
	while(i <= m && j <= r){
		if(a[i] > a[j]) temp[tempIdx++] = a[j++];
		else temp[tempIdx++] = a[i++];
	}

	//남은 배열의 경우 순서대로 임시 배열에 저장
	if(i <= m) for(int k = i; k <= m; k++) temp[tempIdx++] = a[k];
	else if(j <= r) for(int k = j; k <= r; k++) temp[tempIdx++] = a[k];

	//원래 배열로 옮기기
	for(int k = l; k <= r; k++) a[k] = temp[k];
}

//나누기
void merge_sort(int a[], int l, int r){
	if(l < r){
		int m = (l + r) / 2;

		//반씩 나눔
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
