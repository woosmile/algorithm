#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100005];

    
// 테이블 : dp[i] = i번째 수까지 더했을 때 누적값
int dp[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // 점화식 : dp[1] = a[1], dp[2] = a[1] + a[2], dp[3] = a[1] + a[2] + a[3]
    // 단, a[i]를 누적시켰을 때 0보다 작아다면 a[i] 부터 다시 수열을 누적
    for (int i = 1; i <= n; i++)
        dp[i] = max(dp[i - 1], 0) + a[i];

    cout << *max_element(dp + 1, dp + n + 1);

    return 0;
}