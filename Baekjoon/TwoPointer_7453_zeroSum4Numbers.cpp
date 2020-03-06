// 7453 합이0인네정수 시간복잡도(TwoPointer)
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n;
	int a[4001], b[4001], c[4001], d[4001];

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	}

	// a+b, c+d 쌍으로 조합 구성
	vector<int> ab, cd;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ab.push_back(a[i] + b[j]);
			cd.push_back(c[i] + d[j]);
		}
	}
	
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());
	// printf("SIZE %d %d\n", ab.size(), cd.size());

	int size = n * n;
	int idx_ab = 0, idx_cd = size-1;
	long long cnt = 0ll;
	while(idx_ab < size && idx_cd >= 0){
		long long sum = ab[idx_ab] + cd[idx_cd];
		if(sum < 0){
			idx_ab++;
		} else if(sum > 0){
			idx_cd--;
		} else {
			// 같으면 두 인덱스를 움직이며 다른값이 나올때까지 찾는다
			int tmp_1 = idx_ab+1;
			long long cnt_1 = 1;
			while(tmp_1 < size && ab[tmp_1] + cd[idx_cd] == 0){
				cnt_1++;
				tmp_1++;
			}
			int tmp_2 = idx_cd-1;
			long long cnt_2 = 1;
			while(tmp_2 >= 0 && ab[idx_ab] + cd[tmp_2] == 0){
				cnt_2++;
				tmp_2--;
			}

			// 같은 값이 많은 경우 경우의 수를 고려해 계산 (곱해서 더함)
			cnt += cnt_1 * cnt_2;
			idx_ab = tmp_1;
			idx_cd = tmp_2;
		}
	}

	printf("%lld", cnt);

	return 0;
}
