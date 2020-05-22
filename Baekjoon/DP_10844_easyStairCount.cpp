#include <stdio.h>
using namespace std;

const int MAX = 1000000000;
int dp[101][10];  //끝자리가 j인 i자리 계단수의 개수

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= 9; i++) dp[1][i] = 1;

    for(int i = 2; i <= n; i++){
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];

        for(int j = 1; j < 9; j++)
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MAX;
        
    }

    int sum = 0;
    for(int i = 0; i < 10; i++){
        sum += dp[n][i];
        sum %= MAX;
    }

    printf("%d", sum);

    return 0;
}
