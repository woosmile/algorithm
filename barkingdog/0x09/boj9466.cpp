#include <iostream>

using namespace std;

int arr[100002];
int state[100002];

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void run(int x)
{
    int cur = x;  // 현재 위치

    while (1)
    {
        state[cur] = x;  // 현재 위치의 상태를 현재 위치 값으로 저장
        cur = arr[cur];  // 다음 위치
        if (state[cur] == x)  // 다음 위치로 왔는데 지나갔던 학생의 위치와 일치하는 경우는 다시 되돌아온 것임 (Cycle 형성 = 팀 형성)
        {
            while (state[cur] != CYCLE_IN)
            {
                state[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            return ;
        }
        else if (state[cur] != 0)  // 다음 위치로 왔는데 0이 아니라는 것은 이전에 방문한 적이 있는 학생임 (Cycle이 만들어지지 않았음)
            return ;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;

    cin >> tc;

    while (tc--)
    {
        int n;

        cin >> n;
        
        fill(state + 1, state + n + 1, 0);  // 인덱스를 0이 아닌 1부터 시작함

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++)
        {
            if (state[i] == NOT_VISITED)  // 이전에 방문하지 않은 곳이라면 방문 체크 진행
                run(i);
        }

        int cnt = 0;

        for (int i = 1; i <= n; i++)  // 팀(Cycle)이 만들어지지 않은 학생들의 수를 출력함
        {
            if (state[i] != CYCLE_IN)
                cnt++;
        }
        cout << cnt << '\n';
    }

    return (0);
}