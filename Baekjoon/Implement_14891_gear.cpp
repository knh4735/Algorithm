/*
14891 톱니바퀴 구현(시뮬레이션)
합이 8개인 N, S극으로 이루어진 톱니바퀴 4개가 일렬로 있다. 이때 한 톱니바퀴를 돌리면 맞닿은 부분이 서로 다른 극이던 톱니바퀴가 연쇄적으로 반대 방향으로 돈다.
돌린 후에 12시 방향이 N극인 것들에 따라 점수를 계산하기 (1, 2, 4, 8점)
입력 : ~4 8개의 숫자 (N : 0, S : 1) \n 회전 횟수 1 ≤ K ≤ 100 \n ~K 돌릴 톱니바퀴 번호와 돌리는 방향 (1 : 시계, -1 : 반시계)
출력 : 돌린 후에 12시 방향이 N극인 톱니바퀴에 따른 점수 계산 값
*/
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> s[4];
int n;

void one_rot(int gear, int d){
	int tmp;
	if(d > 0){
		s[gear].insert(s[gear].begin(), s[gear][7]);
		s[gear].erase(s[gear].begin()+8);
	}
	else{
		s[gear].push_back(s[gear][0]);
		s[gear].erase(s[gear].begin());
	}
}

void rot(int gear, int d){
	int diff[3];
	for(int i = 0; i < 3; i++){
		if(s[i][2] != s[i+1][6]) diff[i] = 1;
		else diff[i] = 0;
	}

	one_rot(gear, d);

	int tmp_d = d;
	for(int i = gear; i < 3; i++){
		if(diff[i]){
			tmp_d = -tmp_d;
			one_rot(i+1, tmp_d);
		}
		else break;
	}
	
	tmp_d = d;
	for(int i = gear-1; i >= 0; i--){
		if(diff[i]){
			tmp_d = -tmp_d;
			one_rot(i, tmp_d);
		}
		else break;
	}
}

int cal(){
	int score = 0;

	if(s[0][0]) score += 1;
	if(s[1][0]) score += 2;
	if(s[2][0]) score += 4;
	if(s[3][0]) score += 8;

	return score;
}


int main(){
	char k;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 8; j++){
			scanf(" %c", &k);
			s[i].push_back(k-'0');
		}
	}

	scanf("%d", &n);

	int gear, d;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &gear, &d);

		rot(gear-1, d);
	}

	printf("%d", cal());

	return 0;
}
