/*
1697 숨바꼭질 BFS
현재 위치 +-1, 또는 2 * 현재위치로 이동할 수 있을 때 동생을 찾을 수 있는 최단시간을 구하기
입력 : 현재 위치, 동생의 위치 0 <=  N, K <= 100000
출력 : 동생을 찾을 수 있는 가장 빠른 시간
*/
#include <stdio.h>
#include <queue>
using namespace std;

int curr, dst, cnt;
int isVisit[200001];

int main(){
	scanf("%d %d", &curr, &dst);

	queue<int> q;
	int qArr[200001], idx = 0;;

	isVisit[curr] = 1;
	q.push(curr);
	while(1){
		while(!q.empty()){
			int cur = q.front();
			q.pop();

			if(cur == dst){
				printf("%d", cnt);
				return 0;
			}
			
			if(cur > dst){
				if(cur - 1 >= 0 && isVisit[cur - 1] == 0){
					isVisit[cur - 1] = 1;
					qArr[idx++] = cur - 1;
				}
			}

			else{

				if(cur != 0 && isVisit[cur * 2] == 0){
					isVisit[cur * 2] = 1;
					qArr[idx++] = cur * 2;
				}

				if(cur - 1 >= 0 && isVisit[cur - 1] == 0){
					isVisit[cur - 1] = 1;
					qArr[idx++] = cur - 1;
				}

				if(cur + 1 <= dst && isVisit[cur + 1] == 0){
					isVisit[cur + 1] = 1;
					qArr[idx++] = cur + 1;
				}
			}
		}

		for(int i = 0; i < idx; i++) q.push(qArr[i]);

		idx = 0;
		cnt++;
	}

	return 0;
}
