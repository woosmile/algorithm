#include <iostream>

using namespace std;

// 테이블 : dp[i][k], 길이가 i개이고 마지막 자리가 k인 계단 수의 개수
int dp[101][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int k = 1; k <= 9; k++)
        dp[1][k] = 1;

    // 점화식
    // 현재 자리의 k에서 이전 자리의 k - 1과 k + 1이 인접하므로 이 두 개의 개수를 더함
    for (int i = 2; i <= n; i++) {
        for (int k = 0; k <= 9; k++) {
            if (k != 0)
                dp[i][k] = dp[i][k] + dp[i - 1][k - 1];
            if (k != 9)
                dp[i][k] = dp[i][k] + dp[i - 1][k + 1];
            dp[i][k] = dp[i][k] % 1000000000;
        }
    }

    long long ans = 0;

    for (int i = 0; i <= 9; i++) {
        ans = ans + dp[n][i];
    }
    
    ans = ans % 1000000000;

    cout << ans;
    
    return 0;
}