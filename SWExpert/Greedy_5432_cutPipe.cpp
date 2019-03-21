/*
()는 레이저, (는 쇠파이프의 시작 )는 끝을 나타내는 괄호로 이루어진 문자열을 통해 레이저로 잘라지는 파이프 조각의 수 구하기 (레이저는 파이프의 끝에 겹치지 않음)
입력 : 테스트케이스의 수 \n ~괄호로 이루어진 문자열
출력 : 나눠진 조각의 수
*/
#include <stdio.h>
#include <string.h>
#include<iostream>
#include<stack>

using namespace std;

struct Bar{
	int s;
	int e;
};

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		char s[100001];
		scanf(" %s", s);
		int n = strlen(s),
			cnt = 0,
			num = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '(' && (i < n-1 && s[i+1] != ')')){
				num++;
			}
			else if(s[i] == ')'){
				if(s[i-1] == '('){
					cnt += num;
				}
				else{
					cnt++;
					num--;
				}
			}
		}

		printf("#%d %d\n", test_case, cnt);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
