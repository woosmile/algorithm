#include <iostream>

using namespace std;

int t;
int a[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int max_val = a[n - 1];  // 가장 마지막 주가를 최대값으로 설정
        long long ans = 0;  // 이익

        // 핵심 부분으로 최대로 이익을 보기 위해서는 주식을 산 가장 최근의 가장 높은 주가에서 주식을 팔아야 함 (max_val - a[i])
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > max_val)  // 더 높은 주가라면 최대값 갱신
                max_val = a[i];
            ans = ans + max_val - a[i];
        }
        
        cout << ans << '\n';
    }

    
    return 0;
}