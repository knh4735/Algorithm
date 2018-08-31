/*
1541 잃어버린괄호 Greedy
양수와 +, - 로 식을 만들었을 때 괄호를 적절히 사용해 결과를 최소로 만들기, 수는 5자리이상 연속되지 않고 0으로 시작가능
입력 : 식 (숫자로 시작해 숫자로 끝남, 길이는 50 이하)
출력 : 최솟값
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	char sic[51], l = 0;
	int n[51], num = 0;
	char op[51], nOp = 1;

	char c = getchar();
	while(c != '\n' && c != EOF){
		sic[l++] = c;
		c = getchar();
	}

	//인풋 정리 -> n[0~num-1] 숫자만  / op[1~num-1] 연산자만
	int newNumLoc = 0;
	for(int i = 0; i < l; i++){
		if(*(sic + i) == '+' || *(sic + i) == '-'){
			op[nOp++] = *(sic + i);
			*(sic + i) = '\0';
			n[num++] = atoi(sic + newNumLoc);
			newNumLoc = i + 1;
		}
	}
	n[num++] = atoi(sic + newNumLoc);


	//-면 다음 -까지 괄호로 묶어서 한번에 뺌
	int sum = n[0], partSum = 0;
	for(int i = 1; i < num; i++){
		if(op[i] == '-'){
			if(partSum == 0){
				partSum += n[i];
			}
			else{
				sum -= partSum;
				partSum = n[i];
			}
		}

		else if(partSum > 0){
			partSum += n[i];
		}

		else sum += n[i];
	}

	sum -= partSum;

	printf("%d", sum);
	
	return 0;
}
