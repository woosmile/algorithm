#include <iostream>

using namespace std;

int n, k;
int coin[10];
int ans;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        if (coin[i] > k)
            continue ;
        ans = ans + (k / coin[i]);
        k = k % coin[i];
    }

    cout << ans;
    
    
    return 0;
}