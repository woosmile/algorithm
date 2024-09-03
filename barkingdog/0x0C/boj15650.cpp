#include <iostream>

using namespace std;

int n, m;
int inused[10];
int arr[10];

bool issort()
{
    int min = arr[0];  // 초기값으로 배열의 첫번째 값 지지정

    for (int i = 0; i < m; i++)  // min 값을 갱신하면서 오름차순으로 되어있는지 확인
    {
        if (min > arr[i])  // 오름차순이 아니면 false 반환
            return false;
        min = arr[i];  // min 값 갱신
    }

    return true;
}

void func(int k)
{
    if (k == m)
    {
        if (issort() == true)  // 오름차순이 아니면 출력 안하고 넘어감
        {
            for (int i = 0; i < m; i++)
                cout << arr[i] << ' ';
            cout << '\n';
        }
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!inused[i])
        {
            inused[i] = true;
            arr[k] = i;
            func(k + 1);
            inused[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);

    return (0);
}