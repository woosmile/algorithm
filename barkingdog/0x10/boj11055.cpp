#include <bits/stdc++.h>

using namespace std;

int n;
int a[1010];
int dp[1010];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[i] = a[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // i 이전 자리수인 j 원소보다 값이 크다면 증가하는 수열이므로 이를 dp 배열의 j번째 원소에 더함
            // max를 통해 i 이전보다 큰 j 원소를 더할 때 최대값을 유지하게 함
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + a[i]);  
        }
    }
    
    cout << *max_element(dp, dp + n);

    return 0;
}