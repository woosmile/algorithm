#include <iostream>

using namespace std;

int n;
int dp[1005];
int mod = 10007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dp[1] = 1;
    dp[2] = 3;  // 2x2 타일 하나가 추가되므로 2x2 영역을 채우는 방법의 수는 3가지임 (1x2 위, 아래 2개 + 2x2 타일 1개)

    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % mod;  // 2x2 타일 하나가 더 추가되므로 dp[i - 2] * 2

    cout << dp[n];

    return 0;
}