#include <iostream>

using namespace std;

// d[i] = 2 x i 크기의 직사각형을 채우는 방법의 수
int d[10005];
int n;
int mod = 10007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[1] = 1;  // 2x1 크기의 직사각형을 채우는 방법의 수
    d[2] = 2;  // 2x2 크기의 직사각형을 채우는 방법의 수

    // 2x1 타일로 채웠을 때의 방법의 수는 d[i - 1], 1x2 타일로 채웠을 때의 방법의 수는 d[i - 2]
    // mod로 나눈 값을 바로 출력하지 않는 이유는 int overflow 때문임
    for (int i = 3; i <= n; i++)
        d[i] = (d[i - 1] + d[i - 2]) % mod;  

    cout << d[n];
    
    return 0;
}