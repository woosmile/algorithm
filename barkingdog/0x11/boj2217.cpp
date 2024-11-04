#include <iostream>
#include <algorithm>

using namespace std;

int n;
int rope[100001];
int ans;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> rope[i];
    }

    sort(rope, rope + n);

    for (int i = 1; i <= n; i++)
        ans = max(ans, rope[n - i] * i);

    cout << ans;
    
    return 0;
}