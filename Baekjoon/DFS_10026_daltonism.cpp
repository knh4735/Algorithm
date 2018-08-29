//10026 적록색약 DFS
#include <stdio.h>

int n, nmNum, abNum;	//정상 구역수, 색약 구역수
char pic[100][100];
int nm[100][100], ab[100][100];	//정상 배열, 색약 배열

//정상 dfs
void nmDfs(int i, int j){
	nm[i][j] = 1;

	char cur = pic[i][j];

	if(i + 1 < n && cur == pic[i+1][j] && nm[i+1][j] == 0) nmDfs(i+1, j);
	if(i - 1 >= 0 && cur == pic[i-1][j] && nm[i-1][j] == 0) nmDfs(i-1, j);
	if(j + 1 < n && cur == pic[i][j+1] && nm[i][j+1] == 0) nmDfs(i, j+1);
	if(j - 1 >=0 && cur == pic[i][j-1] && nm[i][j-1] == 0) nmDfs(i, j-1);
}

//색약 dfs R == G
void abDfs(int i, int j){
	ab[i][j] = 1;

	char cur = pic[i][j];

	if(cur == 'R' || cur == 'G'){
		if(i + 1 < n && (pic[i+1][j] == 'R' || pic[i+1][j] == 'G') && ab[i+1][j] == 0) abDfs(i+1, j);
		if(i - 1 >= 0 && (pic[i-1][j] == 'R' || pic[i-1][j] == 'G') && ab[i-1][j] == 0) abDfs(i-1, j);
		if(j + 1 < n && (pic[i][j+1] == 'R' || pic[i][j+1] == 'G') && ab[i][j+1] == 0) abDfs(i, j+1);
		if(j - 1 >=0 && (pic[i][j-1] == 'R' || pic[i][j-1] == 'G') && ab[i][j-1] == 0) abDfs(i, j-1);
	}
	else{
		if(i + 1 < n && 'B' == pic[i+1][j] && ab[i+1][j] == 0) abDfs(i+1, j);
		if(i - 1 >= 0 && 'B' == pic[i-1][j] && ab[i-1][j] == 0) abDfs(i-1, j);
		if(j + 1 < n && 'B' == pic[i][j+1] && ab[i][j+1] == 0) abDfs(i, j+1);
		if(j - 1 >=0 && 'B' == pic[i][j-1] && ab[i][j-1] == 0) abDfs(i, j-1);
	}
}


int main(){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf(" %c", &pic[i][j]);
			nm[i][j] = 0;
			ab[i][j] = 0;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(nm[i][j] == 0){
				nmDfs(i, j);
				nmNum++;
			}

			if(ab[i][j] == 0){
				abDfs(i, j);
				abNum++;
			}
		}
	}

	printf("%d %d", nmNum, abNum);

	return 0;
}
