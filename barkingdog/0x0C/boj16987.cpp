#include <iostream>
#include <algorithm>

using namespace std;

int n;
int armor[10];
int atack[10];

int mx = 0;  // 최대로 깨진 계란의 개수
int cnt = 0;  // 깨진 계란의 개수

void func(int k)
{
    if (k == n)  // 마지막 계란까지 왔을 때
    {
        mx = max(mx, cnt);  // 깨진 계란의 최대 개수 갱신
        return ;
    }

    if (armor[k] <= 0 || cnt == n - 1)  // 현재 들고있는 계란의 내구도가 없거나 다른 모든 계란이 깨졌으면 패스
    { 
        func(k + 1);
        return ;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (i == k || armor[i] <= 0)  // 자기 자신이거나 깨트릴 계란이 이미 깨졌으면 패스
            continue ;
        
        armor[k] = armor[k] - atack[i];  // 계란 치기 진행
        armor[i] = armor[i] - atack[k];
        if (armor[k] <= 0)  // 깨졌다면 cnt 증가
            cnt++;
        if (armor[i] <= 0)
            cnt++;
        
        func(k + 1);

        if (armor[k] <= 0)  // 이전 상태로 되돌아왔으면 상태값들을 다시 원상복구하여 현재 상태를 포함한 다른 경우의 수를 찾도록 함
            cnt--;
        if (armor[i] <= 0)
            cnt--;
        armor[k] = armor[k] + atack[i];
        armor[i] = armor[i] + atack[k];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> armor[i] >> atack[i];

    func(0);
    cout << mx;
    return 0;
}