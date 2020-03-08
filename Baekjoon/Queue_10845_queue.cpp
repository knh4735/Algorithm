// 10845 큐 자료구조(큐)
#include <stdio.h>
#include <string.h>

int hd = 0, tl = -1;
int q[10001];

void push(int x){
	tl++;
	q[tl] = x;
}

void pop(){
	if(tl - hd == -1){
		printf("-1\n");
		return;
	}
	printf("%d\n", q[hd]);
	hd++;
}

void size(){
	printf("%d\n", tl - hd + 1);
}

void empty(){
	printf("%d\n", (tl - hd == -1) ? 1 : 0);
}

void front(){
	if(tl - hd == -1){
		printf("-1\n");
		return;
	}
	printf("%d\n", q[hd]);
}

void back(){
	if(tl - hd == -1){
		printf("-1\n");
		return;
	}
	printf("%d\n", q[tl]);
}

int main(){
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		const char *PUSH = "push", *POP = "pop", *SIZE = "size", *EMPTY = "empty", *FRONT = "front", *BACK = "back";

		char s[6];
		int x;
		scanf(" %s", s);

		if(strcmp(s, PUSH) == 0){
			scanf("%d", &x);
			push(x);
		} else if(strcmp(s, POP) == 0){
			pop();
		} else if(strcmp(s, SIZE) == 0){
			size();
		} else if(strcmp(s, EMPTY) == 0){
			empty();
		} else if(strcmp(s, FRONT) == 0){
			front();
		} else if(strcmp(s, BACK) == 0){
			back();
		}
	}

	return 0;
}
