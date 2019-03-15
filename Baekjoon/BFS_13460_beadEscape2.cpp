/*
13460 구슬탈출2 BFS
# 벽, . 공간, O 구멍, R 빨간 구슬, B 파란 구슬 로 이루어진 NxM 공간에서 상하좌우로 기울여 구슬을 끝까지 이동시키는 과정을 통해 빨간 구슬만 구멍으로 넣는 최소 이동 횟수
입력 : 공간 크기 3 ≤ N, M ≤ 10 \n ~M N개의 문자열 (#.ORB)
출력 : 빨간 구슬이 구멍에 들어가게하는 최소 횟수 (파란 구슬이 들어가면 무효, 10번 이상이면 -1 출력)
*/
#include <stdio.h>
#include <queue>

struct loc{
    //blue y, x, red y, x
	char by;
	char bx;
	char ry;
	char rx;
};

//zy, zx = hole y, x
int n, m;
char zy, zx;
char map[11][11];

int isGoal(loc bead){
	//0 : No Goal, 1 : Only Red, -1 : Blue Included or Blue=Red
	if(bead.by == zy && bead.bx == zx) return -1;
	else if(bead.by == bead.ry && bead.bx == bead.rx) return -1;
	else if(bead.ry == zy && bead.rx == zx) return 1;
	else return 0;
}

loc moveBead(loc bead, char y, char x){
	loc orgBead = bead;
	//v
	if(y > 0){
		//Move both beads in front of wall or in the hole
		while(map[bead.by+1][bead.bx] != '#' && map[bead.by][bead.bx] != 'O')
			bead.by += 1;
		while(map[bead.ry+1][bead.rx] != '#' && map[bead.ry][bead.rx] != 'O')
			bead.ry += 1;

		//if the beads are in same position
		if(bead.by == bead.ry && bead.bx == bead.rx){
			//and in hole -> will be out with isGoal Func
			if(bead.by == zy && bead.bx == zx)
				return bead;
			
			//not in hole -> correct each bead's position
			else{
				if(orgBead.by > orgBead.ry) bead.ry--;
				else bead.by--;
			}
		}
	}
	//^
	else if(y < 0){
		while(map[bead.by-1][bead.bx] != '#' && map[bead.by][bead.bx] != 'O')
			bead.by -= 1;
		while(map[bead.ry-1][bead.rx] != '#' && map[bead.ry][bead.rx] != 'O')
			bead.ry -= 1;
		
		if(bead.by == bead.ry && bead.bx == bead.rx){
			if(bead.by == zy && bead.bx == zx)
				return bead;
			
			else{
				if(orgBead.by < orgBead.ry) bead.ry++;
				else bead.by++;
			}
		}
	}
	//>
	else if(x > 0){
		while(map[bead.by][bead.bx+1] != '#' && map[bead.by][bead.bx] != 'O')
			bead.bx += 1;
		while(map[bead.ry][bead.rx+1] != '#' && map[bead.ry][bead.rx] != 'O')
			bead.rx += 1;
		
		if(bead.by == bead.ry && bead.bx == bead.rx){
			if(bead.by == zy && bead.bx == zx)
				return bead;
			
			else{
				if(orgBead.bx > orgBead.rx) bead.rx--;
				else bead.bx--;
			}
		}
	}
	//<
	else if(x < 0){
		while(map[bead.by][bead.bx-1] != '#' && map[bead.by][bead.bx] != 'O')
			bead.bx -= 1;
		while(map[bead.ry][bead.rx-1] != '#' && map[bead.ry][bead.rx] != 'O')
			bead.rx -= 1;
		
		if(bead.by == bead.ry && bead.bx == bead.rx){
			if(bead.by == zy && bead.bx == zx)
				return bead;
			
			else{
				if(orgBead.bx < orgBead.rx) bead.rx++;
				else bead.bx++;
			}
		}
	}

	return bead;
}

int main(){
	scanf("%d %d", &n, &m);

	loc bead;

	for(char i = 0; i < n; i++){
		for(char j = 0; j < m; j++){
			scanf(" %c", &map[i][j]);
			if(map[i][j] == 'O'){
				zy = i;
				zx = j;
			}
			else if(map[i][j] == 'B'){
				bead.by = i;
				bead.bx = j;
			}
			else if(map[i][j] == 'R'){
				bead.ry = i;
				bead.rx = j;
			}
		}
	}

	std::queue<loc> q;
	q.push(bead);

	//temp Queue for each level
	std::queue<loc> tmpQ;

	int cnt = 0;

	while(cnt < 11){
		while(!q.empty()){
			bead = q.front();
			q.pop();

			if(isGoal(bead) == 1){
				printf("%d", cnt);

				return 0;
			}
			else if(isGoal(bead) == -1) continue;

			tmpQ.push(moveBead(bead, 1, 0));
			tmpQ.push(moveBead(bead, -1, 0));
			tmpQ.push(moveBead(bead, 0, 1));
			tmpQ.push(moveBead(bead, 0, -1));
		}

		while(!tmpQ.empty()){
			q.push(tmpQ.front());
			tmpQ.pop();
		}

		cnt++;
	}

	printf("-1");

	return 0;
}
