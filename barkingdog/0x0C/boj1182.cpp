#include <iostream>

using namespace std;

int arr[30];
int n, s;
int cnt;

void func(int depth, int total)
{
    if (depth == n)  // 현재 depth가 n과 같아지면 현재 단계에서 부분수열이 만들어졌음을 의미하므로 합계를 확인함
    {
        if (total == s)
            cnt++;
        return ;
    }
    func(depth + 1, total);  // 처음에는 아무것도 더하지 않는 공집합에서 시작 (depth 최대값)
    func(depth + 1, total + arr[depth]);  // 마지막 원소부터 하나씩 더하고 재귀를 탈출하면서 depth 값이 줄어드는 만큼 더하는 원소의 개수가 늘어남 (부분수열을 만들면서 합계에 반영함)
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    func(0, 0);
    if (s == 0)  // 문제 조건 상 공집합의 개수는 카운트에서 제외함
        cnt--;
    cout << cnt;
    return (0);
}