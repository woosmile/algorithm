#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define s second
#define e first

using namespace std;

int n;
int ans;
vector< pair<int, int> > conf;

void debug(void)
{
    for (int i = 0; i < conf.size(); i++) {
        cout << conf[i].e << ',' << conf[i].s << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // for (int i = 0; i < n; i++) {
    //     pair<int, int> time;
    //     cin >> time.s >> time.e;
    //     conf.push_back(time);
    // }

    // 아래방법 시간초과 남
    // for (int i = 0; i < conf.size(); i++) {
    //     vector< pair<int, int> > dummy;
    //     dummy.push_back(conf[i]);

    //     for (int j = i + 1; j < conf.size(); j++) {
    //         if (dummy.back().e <= conf[j].s)
    //         {
    //             dummy.push_back(conf[j]);
    //             conf
    //     }
    //     ans = max(ans, (int)dummy.size());
    // }

    // 이 방법도 시간초과 남
    // sort(conf.begin(), conf.end());
    // for (int i = 0; i < conf.size(); i++) {
    //     int cnt = 1;
    //     int temp_i = i;
    //     for (int j = i + 1; j < conf.size(); j++) {
    //         if (conf[i].e <= conf[j].s) {
    //             cnt++;
    //             i = j;
    //         }
    //     }
    //     i = temp_i;
    //     ans = max(ans, cnt);
    // }

    for (int i = 0; i < n; i++) {
        pair<int, int> time;
        cin >> time.s >> time.e;  // 종료 시간을 pair의 first로 (종료 시간 기준으로 정렬)
        conf.push_back(time);
    }
    sort(conf.begin(), conf.end());  // 끝나는 시간 기준으로 정렬
    int t = 0;  // 현재 시간
    for (int i = 0; i < conf.size(); i++) {
        if (t > conf[i].s)  // 시작 시간이 현재 시간보다 이전의 회의라면 무시(이미 시간 상 지나간 회의임)
            continue ;
        ans++;
        t = conf[i].e;  // 현재 시간을 conf[i]의 종료 시간으로 갱신
    }
    
    // debug();

    cout << ans;

    return 0;
}