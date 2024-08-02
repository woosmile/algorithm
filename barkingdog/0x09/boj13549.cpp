#include <iostream>
#include <queue>

using namespace std;

const int LMT = 100001;

int field[LMT + 2];
int n, k;
queue<int> q;

void teleport(int num)
{
    int temp = num;

    if (temp == 0)  // 0의 2의 배수는 0이므로 아무것도 하지 않음
        return ;
    while (temp < LMT && field[k] == 0)  // temp가 최대 사이즈에 보다 작으면서 도착지에 도달할 떄까지
    {
        if (field[temp] == 0)  // 아직 방문하지 않았다면
        {
            field[temp] = field[num];  // 텔레포트이므로 다음 위치는 현재 위치에서 +1을 하지 않고 값 그대로 대입
            q.push(temp);  // 2배수의 위치를 큐에 넣음
            if (temp == k)  // 도착지에 도달했다면 반복문 탈출 (없어도 위에 while 조건문에서 걸리긴 함)
                return ;
        }
        temp = temp << 1;  // 위치 2배 텔레포트
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    field[n] = 1;  // 시작점 1로 지정
    q.push(n);  // 시작점을 큐에 넣고 시작
    teleport(n);  // 현재 위치에서 2의 배수(텔레포트)인 위치 확인
    while (field[k] == 0)  // 도착지에 도달할 때까지
    {
        int cur = q.front();
        q.pop();
        for (int nxt : {cur - 1, cur + 1})  // range-based for
        {
            if (nxt < 0 || nxt >= 100001)  // OOB 확인
                continue ;
            if (field[nxt] > 0)  // 방문했었는지 확인
                continue ;
            field[nxt] = field[cur] + 1;  // 방문하지 않았다면 다음 위치의 거리를 현재 위치 거리 + 1 값 증가
            q.push(nxt);
            teleport(nxt);  // 2의 배수(텔레포트) 위치 확인
        }
    }
    cout << field[k] - 1;
    return (0);
}
