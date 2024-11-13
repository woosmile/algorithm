#include <iostream>

using namespace std;

int tc;
int arr[11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 초기값 
    arr[1] = 1;  // 1을 만드는 경우의 수 (1)
    arr[2] = 2;  // 2를 만드는 경우의 수 (1+1, 2)
    arr[3] = 4;  // 3을 만드는 경우의 수 (1+1+1, 2+1, 1+2, 3)

    // arr[i - 1]은 +1을 했을 때 i를 만들 수 있는 경우의 수
    // arr[i - 2]는 +2를 했을 때 i를 만들 수 있는 경우의 수
    // arr[i - 3]은 +3을 했을 때 i를 만들 수 있는 경우의 수
    for (int i = 4; i < 11; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        cout << arr[n] << '\n';
    }

    return 0;
}