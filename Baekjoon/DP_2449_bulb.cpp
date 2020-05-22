#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n, k;
int dp[201][201];   // i ~ j번 전구를 전구 i의 색으로 맞추는데 드는 최소비용
int color[201];

int cnt(int s, int e){
    if(dp[s][e] != -1) return dp[s][e];

    for(int i = s; i < e; i++){
        int l = cnt(s, i);
        int r = cnt(i + 1, e);

        int val = l + r + (color[s] == color[i+1] ? 0 : 1);
        
        if(val < dp[s][e] || dp[s][e] == -1) dp[s][e] = val;
    }
    
    return dp[s][e];
}

int main(){
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++) scanf("%d", &color[i]);

    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++){
        dp[i][i] = 0;
    }
    
    printf("%d", cnt(0, n-1));    

    return 0;
}
