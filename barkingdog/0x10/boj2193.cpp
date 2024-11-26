#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll dp[100][2];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dp[1][1] = 1;  // 자리수가 1자리인 이친수는 1밖에 없음

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];  // 0, 1 로 끝나는 모든 이친수에 대해서는 0을 붙일 수 있음
        dp[i][1] = dp[i - 1][0];  // 1이 연속으로 올 수 없으므로 0으로 끝나는 이친수에만 0을 붙일 수 있음
    }

    cout << dp[n][1] + dp[n][0];  // 1로 끝나는 이친수 개수 + 0으로 끝나는 이친수 개수
    
    return 0;
}

// 테이블 정의
// dp[자리수 N][0 또는 1로 끝나는 이친수] : 자리수에 따라서 0 또는 1로 끝나는 이친수의 개수