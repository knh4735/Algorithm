//2661 좋은수열 Backtracking
//1,2,3으로만 이뤄진 수열 중에 임의의 길이의 인접한 두 개의 부분 수열이 동일한 것이 있으면 나쁜수열, 아니면 좋은수열
//길이가 n인 좋은수열 중에 가장 작은 수를 구하라
//입력 : 1 <= n <= 80
//출력 : 길이가 n이고 1,2,3으로만 이뤄진 좋은 수열 중 가장 작은 수열
#include <stdio.h>

int n, end;
int seq[81];

//num을 추가햇을때 좋은 수열이 되는지 확인
int checkSeq(int num, int idx){
	seq[idx] = num; 

	//길이가 i인 부분수열을
	for(int i = 1; i <= (idx + 1) / 2; i++){	
		int flag = 1;

		//뒤에 추가한 수를 기준으로 검사
		for(int j = 0; j < i; j++) if(seq[idx - j] != seq[idx - j - i]) flag = 0;

		if(flag) return 0;
	}

	return 1;
}

void addSeq(int length){	//현재 수열 길이
	if(length == n){
		end = 1;
		return;
	}

	//작은 수부터 넣어봐서 좋은 수열이면 수열에 넣고 진행
	for(int i = 1; i <= 3; i++){
		if(checkSeq(i, length)){
			seq[length] = i;
			addSeq(length+1);
			if(end) return;
		}
	}

}

int main(){
	scanf("%d", &n);

	seq[0] = 1;
	addSeq(1);
	
	for(int i = 0; i < n; i++) printf("%d", seq[i]);

	return 0;
}
