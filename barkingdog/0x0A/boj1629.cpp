#include <iostream>

using namespace std;

using ll = long long;

ll recursive(ll a, ll b, ll c)
{
    if (b == 1) return a % c;  // b/2로 재귀를 들어가다가 1이 되면 탈출(base condition)
    ll val = recursive(a, b/2, c);  // b/2 를 하면서 재귀 진행
    val = val * val % c;  // base condition에서 a를 c로 나누었을 때의 나머지 값을 리턴 받았고 이 값을 제곱하고 c로 나누었을 때의 나머지 값을 가져감
    if (b % 2 == 0) return val;  
    return val * a % c;  // b가 홀수면 한번 더 곱함
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;

    cout << recursive(a, b, c);
    
    return 0;
}