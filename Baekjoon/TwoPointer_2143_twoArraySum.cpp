// 2143 두배열의합 시간복잡도(투포인터)
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	long long t;
	int n, m;
	int a[1001], b[1001];

	scanf("%lld", &t);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	scanf("%d", &m);
	for(int i = 0; i < m; i++) scanf("%d", &b[i]);

	// 각 배열의 부분합 계산
	vector<long long> sum_a;
	for(int i = 0; i < n; i++){
		long long sum = (long long)a[i];
		sum_a.push_back(sum);
		for(int j = i+1; j < n; j++){
			sum += (long long)a[j];
			sum_a.push_back(sum);
		}
	}
	
	vector<long long> sum_b;
	for(int i = 0; i < m; i++){
		long long sum = (long long)b[i];
		sum_b.push_back(sum);
		for(int j = i+1; j < m; j++){
			sum += (long long)b[j];
			sum_b.push_back(sum);
		}
	}

	sort(sum_a.begin(), sum_a.end());
	sort(sum_b.begin(), sum_b.end());
	// printf("SIZE %d %d\n", sum_a.size(), sum_b.size());

	int idx_a = 0, idx_b = sum_b.size()-1;
	long long cnt = 0ll;
	while(idx_a < sum_a.size() && idx_b >= 0){
		long long sum = sum_a[idx_a] + sum_b[idx_b];
		if(sum < t){
			idx_a++;
		} else if(sum > t){
			idx_b--;
		} else {
			// 같으면 두 인덱스를 움직이며 다른값이 나올때까지 찾는다
			int tmp_a = idx_a+1;
			long long cnt_1 = 1;
			while(tmp_a < sum_a.size() && sum_a[tmp_a] + sum_b[idx_b] == t){
				cnt_1++;
				tmp_a++;
			}
			int tmp_b = idx_b-1;
			long long cnt_2 = 1;
			while(tmp_b >= 0 && sum_a[idx_a] + sum_b[tmp_b] == t){
				cnt_2++;
				tmp_b--;
			}

			// 같은 값이 많은 경우 경우의 수를 고려해 계산 (곱해서 더함)
			cnt += cnt_1 * cnt_2;
			idx_a = tmp_a;
			idx_b = tmp_b;
		}
	}

	printf("%lld", cnt);

	return 0;
}
