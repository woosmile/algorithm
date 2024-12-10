#include <iostream>

using namespace std;

// 테이블
// dp[i] : 변의 길이가 1인 정삼각형부터 시작해서 i번째 정삼각형까지 나선 모양으로 누적시켰을 때 한 변의 길이
long long dp[105];  // 경계값 테스트 잘하기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;

    cin >> tc;

    // dp 초기값
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    for (int i = 6; i <= 100; i++) {
        // 점화식
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    while (tc--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    
    return 0;
}
