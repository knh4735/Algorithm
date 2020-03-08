// 2843 스택 자료구조(스택)
#include <stdio.h>
#include <string.h>

int sp = -1;
int stack[10001];

void push(int x){
	sp++;
	stack[sp] = x;
}

void pop(){
	if(sp == -1){
		printf("-1\n");
		return;
	}
	printf("%d\n", stack[sp]);
	sp--;
}

void size(){
	printf("%d\n", sp + 1);
}

void empty(){
	printf("%d\n", sp == -1 ? 1 : 0);
}

void top(){
	if(sp == -1){
		printf("-1\n");
		return;
	}
	printf("%d\n", stack[sp]);
}

int main(){
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		const char *PUSH = "push", *POP = "pop", *SIZE = "size", *EMPTY = "empty", *TOP = "top";

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
		} else if(strcmp(s, TOP) == 0){
			top();
		}
	}

	return 0;
}
