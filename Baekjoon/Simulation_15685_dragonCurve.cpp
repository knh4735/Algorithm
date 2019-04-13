/*
15685 드래곤커브 Simulation
드래곤 커브 : 끝점을 기준으로 시계방향 90도 회전한 좌표를 만들고 세대수만큼 반복.
주어진 드래곤커브를 0 ≤ x, y ≤ 100 좌표계에 표시했을때, 네 꼭지점이 모두 1인 1x1 정사각형의 개수 구하기
입력 : 드래곤커브의 개수 1 ≤ N ≤ 20, \n ~N 시작좌표 0 ≤ x, y ≤ 100, 방향 0 ≤ d ≤ 3 (0123 : >v<^), 세대 0 ≤ g ≤ 10
출력 : 네 꼭지점이 모두 1인 1x1 정사각형의 개수
*/
#include <stdio.h>
#include <vector>
using namespace std;

struct Pos{
	int x;
	int y;
};

int n;
bool map[101][101];

int dx[4] = {1, 0, -1, 0},
	dy[4] = {0, -1, 0, 1};


void make_dragon_curve(int x, int y, int d, int g){
	vector<Pos> v;
	v.push_back((Pos){x, y});
	v.push_back((Pos){x+dx[d], y+dy[d]});

	while(g > 0){
		int len = v.size()-2,
			px = v[v.size()-1].x,
			py = v[v.size()-1].y;

		for(int i = len; i >= 0; i--)
			v.push_back((Pos){px+py-v[i].y, py-px+v[i].x});

		g--;
	}

	for(int i = 0; i < v.size(); i++)
		map[v[i].y][v[i].x] = true;

	/*
	printf("\n");
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++) printf("%d ", map[i][j]);
		printf("\n");
	}
	*/
	return;
}

int main(){
	scanf("%d", &n);

	int x, y, d, g;
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d", &x, &y, &d, &g);
		make_dragon_curve(x, y, d, g);
	}

	int cnt = 0;
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			if(map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1]) cnt++;

	printf("%d", cnt);

	return 0;
}
