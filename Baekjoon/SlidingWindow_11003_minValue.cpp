// 11003 최솟값찾기 시간복잡도(슬라이딩윈도우, Deque)
#include <stdio.h>

struct arr {
	int idx;
	long long val;
};

int hd = 0, tl = 5000000, len = 0;
arr deq[5000001];

// void push_front(int idx, long long val){
// 	hd = (hd - 1) % 5000001;
// 	deq[hd].idx = idx;
// 	deq[hd].val = val;
// 	len++;
// }

void push_back(int idx, long long val){
	tl = (tl + 1) % 5000001;
	deq[tl].idx = idx;
	deq[tl].val = val;
	len++;
}

arr front(){
	arr ret = deq[hd];
	return ret;
}

arr back(){
	arr ret = deq[tl];
	return ret;
}

void pop_front(){
	hd = (hd + 1) % 5000001;
	len--;
}

void pop_back(){
	tl = (tl - 1) % 5000001;
	len--;
}

int is_empty(){
	return len == 0;
}

void print_deq(){
	printf("\n\n");
	for(int i = hd; i <= tl; i++)
		printf("%d %lld\n", deq[i].idx, deq[i].val);
	printf("HD:%d TL:%d LEN:%d\n", hd, tl, len);
}

int main(){
	int n, l;
	long long tmp;
	
	scanf("%d %d", &n, &l);
	for(int i = 0; i < n; i++){
		scanf("%lld", &tmp);

		// 들어온 값보다 큰 값들은 POP
		while(!is_empty() && back().val > tmp)
			pop_back();
		push_back(i, tmp);

		// 유효기간 지난 값 POP
		if(front().idx < i - l + 1) pop_front();

		// print_deq(); 디버그 용
		// 맨앞의 값이 범위 내에서 가장 작은 값이 된다
		printf("%lld ", front().val);
	}

	return 0;
}
