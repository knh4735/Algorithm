/*
12100  2048(Easy) DFS (Brute Force)
2048 게임룰대로 5회 움직였을 때 최댓값 구하기
입력 : 판의 크기 1 ≤ N ≤ 20 \n ~N N개 판의 숫자 요소
출력 : 5회 이내 움직였을 때 숫자 최댓
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>

int n, max;
int map[21][21];

//복사본으로 방향(d)에 따라 이동시키기
void move(int tmp[][21], int d){		//0123 : ^v<>
	std::queue<int> q;

	if(d == 0){			//^
		for(int j = 0; j < n; j++){
			//0이 아닌 값만 큐에 추가
			for(int i = 0; i < n; i++)
				if(tmp[i][j] != 0)
					q.push(tmp[i][j]);

			//큐에 추가된 값으로 같은 값, 이동 처리
			for(int i = 0; i < n; i++){
				if(q.empty())
					tmp[i][j] = 0;

				else{
					int f1, f2 = 0;
					f1 = q.front(); q.pop();

					if(q.empty()){
						tmp[i][j] = f1;
						continue;
					}

					f2 = q.front();

					//더블
					if(f1 == f2){
						tmp[i][j] = f1 * 2;
						q.pop();
						max = max > tmp[i][j] ? max : tmp[i][j];
					}
					
					else
						tmp[i][j] = f1;
				}
			}
		}
	} else if(d == 1){	//v
		for(int j = 0; j < n; j++){
			for(int i = n-1; i >= 0; i--)
				if(tmp[i][j] != 0)
					q.push(tmp[i][j]);

			for(int i = n-1; i >= 0; i--){
				if(q.empty())
					tmp[i][j] = 0;
				
				else{
					int f1, f2 = 0;
					f1 = q.front(); q.pop();

					if(q.empty()){
						tmp[i][j] = f1;
						continue;
					}

					f2 = q.front();

					if(f1 == f2){
						tmp[i][j] = f1 * 2;
						q.pop();
						max = max > tmp[i][j] ? max : tmp[i][j];
					}
					
					else
						tmp[i][j] = f1;
				}
			}
		}
	} else if(d == 2){	//<
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				if(tmp[i][j] != 0)
					q.push(tmp[i][j]);

			for(int j = 0; j < n; j++){
				if(q.empty())
					tmp[i][j] = 0;
				
				else{
					int f1, f2 = 0;
					f1 = q.front(); q.pop();

					if(q.empty()){
						tmp[i][j] = f1;
						continue;
					}

					f2 = q.front();

					if(f1 == f2){
						tmp[i][j] = f1 * 2;
						q.pop();
						max = max > tmp[i][j] ? max : tmp[i][j];
					}
					
					else
						tmp[i][j] = f1;
				}
			}
		}
	} else if(d == 3){	//>
		for(int i = 0; i < n; i++){
			for(int j = n-1; j >= 0; j--)
				if(tmp[i][j] != 0)
					q.push(tmp[i][j]);

			for(int j = n-1; j >= 0; j--){
				if(q.empty())
					tmp[i][j] = 0;
				
				else{
					int f1, f2 = 0;
					f1 = q.front(); q.pop();

					if(q.empty()){
						tmp[i][j] = f1;
						continue;
					}

					f2 = q.front();

					if(f1 == f2){
						tmp[i][j] = f1 * 2;
						q.pop();
						max = max > tmp[i][j] ? max : tmp[i][j];
					}
					
					else
						tmp[i][j] = f1;
				}
			}
		}
	}

	return;
}

//복사본 생성, 생성된 방향 시퀀스에 따라 이동 (seq : [0123]으로 구성된 5자리 수열, 0123 순서대로 상하좌우를 나타냄)
void calc(int seq){
	int tmp[21][21], org_seq = seq;
	memcpy(tmp, map, sizeof(map));

	for(int i = 10000; i > 0; i /= 10){
		int d = seq / i;
		seq -= d * i;
		
		move(tmp, d);
		
	}

	/* 디버그용
	printf("%5d\n", org_seq);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) printf("%d ", tmp[i][j]);
		printf("\n");
	}
	printf("\n");
	*/
	return;
}

//방향 시퀀스 누적, cnt : 자릿수 - 5가 되면 시퀀스에 따라 실행
void dfs(int seq, int cnt){
	if(cnt == 5){
		calc(seq);

		return;
	}

	for(int i = 0; i < 4; i++)
		dfs(seq * 10 + i, cnt+1);

	return;
}

int main(){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &map[i][j]);
			max = max > map[i][j] ? max : map[i][j];
		}
	}
	
	for(int i = 0; i < 4; i++)
		dfs(i, 1);
	
	printf("%d", max);

	return 0;
}
