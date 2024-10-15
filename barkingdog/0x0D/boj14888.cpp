#include <iostream>

using namespace std;

int n;
int num[12];
int op[4];

int mx = -2147483648;
int mn = 2147483647;

void func(int ans, int k) {
    if (k == n) {
        mx = max(ans, mx);
        mn = min(ans, mn);
        
        return ;
    }
    for (int i = 0; i < 4; i++) {
        if (op[i] == 0)
            continue ;
        op[i]--;
        if (i == 0)
            func(ans + num[k], k + 1);
        else if (i == 1)
            func(ans - num[k], k + 1);
        else if (i == 2)
            func(ans * num[k], k + 1);
        else if (i == 3)
            func(ans / num[k], k + 1);
        op[i]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    func(num[0], 1);
    cout << mx << '\n' << mn;
        
    return 0;
}