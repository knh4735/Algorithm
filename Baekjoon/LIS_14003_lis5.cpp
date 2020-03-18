// 14003 LIS5 DP(LIS)
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, tmp;
	int a[1000001];

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int len = 1;
	int index[1000001];
	vector<int> lis;
	lis.push_back(a[0]);
	index[0] = 0;
	for(int i = 1; i < n; i++){
		if(lis.back() < a[i]){
			lis.push_back(a[i]);
			index[i] = lis.size() - 1;
			len++;
		}
		else {
			auto insert = lower_bound(lis.begin(), lis.end(), a[i]);
			*insert = a[i];
			index[i] = insert - lis.begin();
		}
	}

	int cnt = len - 1;
	vector<int> ans;
	for(int i = n - 1; i >= 0; i--){
		if(cnt == index[i]){
			cnt--;
			ans.push_back(a[i]);
		}
	}

	printf("%d\n", len);
	for(int i = ans.size() - 1; i >= 0; i--) printf("%d ", ans[i]);

	return 0;
}
