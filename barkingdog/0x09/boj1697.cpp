#include <queue>
#include <iostream>

using namespace std;

int dist[100002];

int main(void)
{
    int n, k;
    queue<int> q;
    fill(dist, dist + 100001, -1);

    cin >> n >> k;

    dist[n] = 0;
    q.push(n);
    while (dist[k] == -1)
    {
        int cur = q.front();
        q.pop();
        // for (int i = 0; i < 3; i++)
        // {
        //     int nxt;
        //     switch(i)
        //     {
        //         case 0 :
        //             nxt = cur - 1;
        //             break ;
        //         case 1 :
        //             nxt = cur + 1;
        //             break ;
        //         case 2 :
        //             nxt = 2 * cur;
        //             break ;
        //         default :
        //             cout << "exception in switch-case\n";
        //             return (1);
        //             break ;
        //     }
        //     if (nxt < 0 || nxt > 100000)
        //         continue ;
        //     //방문을 했던 곳인지 확인하는 조건문 반드시 필요
        //     if (dist[nxt] != -1)
        //         continue ;
        //     //방문을 했던 곳인지 확인하는 배열에 값 저장
        //     dist[nxt] = dist[cur] + 1;
        //     q.push(nxt);
        // }
        
        //range-based for
        for (int nxt : {cur - 1, cur + 1, cur * 2})
        {
            if (nxt < 0 || nxt > 100000)
                continue ;
            //방문을 했던 곳인지 확인하는 조건문 반드시 필요
            if (dist[nxt] != -1)
                continue ;
            //방문을 했던 곳인지 확인하는 배열에 값 저장
            dist[nxt] = dist[cur] + 1;
            //큐에 push
            q.push(nxt);
        }
    }
    cout << dist[k];
    return (0);
}