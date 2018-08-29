//2644 촌수계산 DFS
//촌수를 계산해서 출력, 관계없으면 -1
//전체사람의수 <= 100 \n 촌수를 계산할 사람의 번호 둘 \n 관계의 수 \n ~ 부 자 관계번호
#include <stdio.h>

int n, t0, t1, flag;	//전체 수, 촌수를 계산할 번호, 끝 플래그
int jokbo[101][101];	//부자관계저장 jokbo[부][자] = jokbo[자][부] = 1

void dfs(int q, int w, int x){	//부, 자, 현재 촌수
	for(int i = 1; i <= n; i++){
		if(jokbo[w][i] == 1 && i != q){	//관계가 있고, 방문하지 않은 사람으로
			if(i == t1){
				printf("%d", x + 1);
				flag = 1;
				return;
			}
			else dfs(w, i, x+1);
		}
	}
}

int main(){
	scanf("%d", &n);
	scanf("%d %d", &t0, &t1);

	int c;
	scanf("%d", &c);

	for(int i = 0; i < c; i++){
		int q, w;
		scanf("%d %d", &q, &w);
		jokbo[q][w] = 1;
		jokbo[w][q] = 1;
	}

	for(int i = 1; i <= n; i++){
		if(i == t1 && jokbo[t0][i] == 1){
			printf("%d", 1);
			return 0;
		} 
		if(jokbo[t0][i] == 1){	//관계가 있는 사람에게 방문
			dfs(t0, i, 1);
			if(flag) return 0;
		}
	}

	//관계가 없는 걸로 밝혀짐
	printf("-1");

	return 0;
}
