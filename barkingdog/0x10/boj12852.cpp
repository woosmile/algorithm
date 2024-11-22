#include <iostream>

using namespace std;

int n;
int d[1000005];  // 인덱스는 수, 값은 그 수가 1이 되는데 까지의 연산 횟수
int pre[1000005];   // 인덱스는 수, 값은 그 수가 1이 되는데 까지의 숫자 기록임 (ex. pre[10] = 9 > pre[9] > 3 > pre[3] = 1)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[1] = 0;  // DP 초기값

    for (int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + 1;  // 이전 수를 -1 했을 때의 연산 횟수에서 +1
        pre[i] = i - 1;  // 현재 수 i에서 -1을 한 수를 기록함
        if (i % 3 == 0 && d[i] > d[i / 3] + 1) {  // 3으로 나누었을 때 최소값이라면 갱신
            d[i] = d[i / 3] + 1;
            pre[i] = i / 3;
        }

        if (i % 2 == 0 && d[i] > d[i / 2] + 1) {  // 2로 나누었을 때 최소값이라면 갱신
            d[i] = d[i / 2] + 1;
            pre[i] = i / 2;
        }
    }

    cout << d[n] << '\n';

    int cur = n;  // 원래 수부터 출력

    while (1) {
        cout << cur << ' ';
        if (cur == 1)
            break ;
        cur = pre[cur];  // 1이 되기까지의 기록한 수를 순회 (ex. 10 > 9 > 3 > 1)
    }
    
    return 0;
}
