#include <iostream>

using namespace std;

int n;
int arr[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    arr[1] = 0;  // 초기값 (인덱스는 수를 의미하고 인덱스에 해당하는 값은 1이 되기 위한 연산 횟수를 의미함)

    // DP
    // 숫자 2에서 n까지 1로 만들 수 있는 최소 연산 횟수를 구함 (/2, /3, -1)
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + 1;  // -1 했을 때의 연산횟수를 먼저 넣고 (이전 횟수에 + 1)
        if (i % 2 == 0)
            arr[i] = min(arr[i], arr[i / 2] + 1);  // /2 했을 때
        if (i % 3 == 0)
            arr[i] = min(arr[i], arr[i / 3] + 1);  // /3 했을 때와 비교해서 최소값으로 넣음
    }
    
    cout << arr[n];
    
    return 0;
}