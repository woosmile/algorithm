#include <iostream>

using namespace std;

int fibo[40][2];  // [피보나치 N번째 수가][피보나치 0 또는 1을 호출한 횟수] 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fibo[0][0] = 1;  // 피보나치 0이 피보나치 0을 호출한 횟수는 1번
    fibo[1][1] = 1;  // 피보나치 1이 피보나치 1을 호출한 횟수는 1번

    // 피보나치 40번째 까지 구함
    for (int i = 2; i <= 40; i++) {
        fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];  // fibo 0을 호출한 횟수
        fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];  // fibo 1을 호출한 횟수
    }
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        cout << fibo[n][0] << ' ' << fibo[n][1] << '\n';
    }
    
    return 0;
}