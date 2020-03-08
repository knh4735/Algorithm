// 2504 괄호의값 자료구조(스택)
#include <stdio.h>

int stack[31];
int top = -1;

void push(int c){
	top++;
	stack[top] = c;
}

int pop(){
	if(top == -1) return -1;
	int ret = stack[top];
	top--;
	return ret;
}

int main(){
	char c = getchar();
	int score = 0;
	while(c != '\n' && c != EOF){
		if(c == '(') push(-2);
		else if(c == '[') push(-3);
		else if(c == ')'){
			int sum = 0;
			int j;
			do{
				j = pop();
				if(j == -1 || j == -3){
					printf("0");
					return 0;
				} else if(j == -2){ 
					break;
				} else {
					sum += j;
				}
			}while(1);

			if(sum == 0) push(2);
			else push(2 * sum);
		} else if(c == ']'){
			int sum = 0;
			int j;
			do{
				j = pop();
				if(j == -1 || j == -2){
					printf("0");
					return 0;
				} else if(j == -3){ 
					break;
				} else {
					sum += j;
				}
			}while(1);

			if(sum == 0) push(3);
			else push(3 * sum);
		}

		c = getchar();
	}

	int sum = 0;
	int tmp;
	do{
		tmp = pop();
		if(tmp == -1) break;
		else if(tmp == -2 || tmp == -3){
			printf("0");
			return 0;
		}
		sum += tmp;
	}while(1);

	printf("%d", sum);
	return 0;
}
