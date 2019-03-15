/*
5550 나는 개구리로소이다 Greedy
c, r, o, a, k 들의 문자열에서 동시에 몇 개의 croak이 나타나는지 구하기
입력 : 테스트케이스 \n ~t 문자열 (5 <= Length <= 2500)
출력 : #t 개구리 마릿수
*/
#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(int argc, char** argv)
{
	int t;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(t = 1; t <= T; ++t)
	{

		int croak[5], flag = 1, num = 0, dup = 0;
		for(int i = 0; i < 5; i++) croak[i] = 0;

		char s[2501];
		scanf(" %s", s);
		for(int i = 0; i < strlen(s); i++){
			char c = s[i];
			switch(c){
				case 'c':
					num += (dup > 0 ? 0 : 1);
					dup -= (dup == 0 ? 0 : 1);
					croak[0]++;
					break;
				case 'r':
					croak[1]++; break;
				case 'o':
					croak[2]++; break;
				case 'a':
					croak[3]++; break;
				case 'k':
					dup++;
					croak[4]++; break;
			}

			for(int i = 0; i < 4; i++){
				if(croak[i] < croak[i+1]){
					flag = 0;
					break;
				}
			}
		}

		for(int i = 0; i < 4; i++){
			if(croak[i] != croak[i+1]){
				flag = 0;
				break;
			}
		}

		printf("#%d %d\n", t, flag > 0 ? num : -1);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
