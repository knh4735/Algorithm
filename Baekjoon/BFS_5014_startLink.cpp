/*
5014 스타트링크 BFS
총 N층의 건물, 현재 층에서 목표 층으로 가기위해 위로 u만큼 이동하거나 아래로 d만큼 이동할 수 있는 엘베를 탈때 버튼을 몇번 눌러야하는지 구하기
입력 : 1 ≤ 현재층, 목표층 ≤ 높이 ≤ 1000000, 0 <= u, d <= 1000000
출력 : 눌러야하는 버튼의 최소값, 이동이 불가능할 경우 'use the stairs'
*/
#include <stdio.h>
#include <queue>

int h, src, dst, u, d;
int numButton[1000001];
std::queue<int> floorQ;

int main(){
	scanf("%d %d %d %d %d", &h, &src, &dst, &u, &d);


	numButton[src] = 1;
	floorQ.push(src);
	while(!floorQ.empty()){
		int cur = floorQ.front();
		floorQ.pop();

		if(cur == dst){
			printf("%d", numButton[cur] - 1);

			return 0;
		}

		if(cur + u <= h && numButton[cur+u] == 0){
			numButton[cur+u] = numButton[cur] + 1;
			floorQ.push(cur + u);
		}
		if(cur - d > 0 && numButton[cur-d] == 0){
			numButton[cur-d] = numButton[cur] + 1;
			floorQ.push(cur - d);
		}
	}

	printf("use the stairs");


	return 0;
}
