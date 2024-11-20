#include <iostream>

using namespace std;

int n, m;
int num[100005], d[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    d[0] = 0;

    for (int i = 1; i <= n; i++)
        cin >> num[i];

    for (int i = 1; i <= n; i++){
        d[i] = d[i - 1] + num[i];  // 수를 계속 합해서 채워나감
    }

    while (m--) {
        int i, j;
        cin >> i >> j;  // i 부터 j 까지 수의 합을 구해야 함

        cout << d[j] - d[i - 1] << '\n';  // d[j]에는 첫번째 부터 j까지 수의 합이므로 구간 합의 시작인 i 바로 전 i - 1 의 합을 뺌
    }
    
    return 0;
}