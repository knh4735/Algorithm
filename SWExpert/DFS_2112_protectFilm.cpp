/*
2112 보호필름 DFS(Brute Force Simulation)
가로 W개의 셀로 이루어진 막 D개(세로)로 보호필름을 만든다. 셀은 두가지 타입이 있고, 단면의 모든 세로방향에 대해서 같은 타입의 셀이 K개 이상 연속된 경우에만 통과한다.
약품은 막에 투여하고, 해당 막을 한가지 타입으로 바꾼다. 성능검사에 통과하기 위해 약품을 투여할 최소 횟수 구하기
입력 : TC \n 막두께 3≤D≤13, 가로크기 1≤W≤20, 통과 기준 1≤K≤D \n ~D 셀의 타입 W개 
출력 : 약품 최소 투여 횟수 
*/
#include <stdio.h>
#include <string.h>

int d, w, k, r;
int film[14][21];
int inj[14];

int check(){
	int flag = 1;
	int tmp[14][21];
	memcpy(tmp, film, sizeof(film));

	for(int i = 0; i < d; i++){
		if(inj[i] > 0){
			if(inj[i] == 1){
				for(int j = 0; j < w; j++) tmp[i][j] = 0;
			}
			else if(inj[i] == 2){
				for(int j = 0; j < w; j++) tmp[i][j] = 1;
			}
		}
	}

	/*
	printf("\n");
	for(int i = 0; i < d; i++){
		for(int j = 0; j < w; j++){
			printf("%d ", tmp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/

	for(int j = 0; j < w; j++){
		int cnt = 1,
			pass = 0;
		for(int i = 1; i < d; i++){
			if(tmp[i][j] == tmp[i-1][j]) cnt++;
			else cnt = 1;

			if(cnt >= k){
				pass = 1;
				break;
			}
		}
		if(pass == 0){
			flag = 0;
			break;
		}
	}

	return flag;
}


void add_inj(int idx, int cnt){
	if(check() && cnt < r)
		r = cnt;

	if(cnt >= r)
		return;

	for(int i = idx+1; i < d; i++){
		inj[i] = 1;
		add_inj(i, cnt+1);

		inj[i] = 2;
		add_inj(i, cnt+1);

		inj[i] = 0;
	}

	return;
}


int main(){
	int T;
	scanf("%d", &T);

	for(int tc = 1; tc <= T; tc++){
		for(int i = 0; i < 14; i++) inj[i] = 0;

		scanf("%d %d %d", &d, &w, &k);
		r = k;

		for(int i = 0; i < d; i++){
			for(int j = 0; j < w; j++){
				scanf("%d", &film[i][j]);
			}
		}

		if(check()){
			printf("#%d %d\n", tc, 0);
			continue;
		}

		for(int i = 0; i < d; i++){
			inj[i] = 1;
			add_inj(i, 1);

			inj[i] = 2;
			add_inj(i, 1);

			inj[i] = 0;
		}


		printf("#%d %d\n", tc, r);
	}

	return 0;
}
