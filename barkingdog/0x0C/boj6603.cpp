#include <iostream>

using namespace std;

int inused[20];
int arr[20];
int num[20];
int n;

void func(int k)
{
    if (k == 6)  // base condition (배열에 6개의 숫자를 다 채웠을 때)
    {
        for (int i = 0; i < 6; i++)
            cout << num[arr[i]] << ' ';  // arr 배열에는 고른 숫자의 인덱스가 들어있음
        cout << '\n';
        return ;
    }
    int st = arr[k];  // 오름차순 수열만 만들도록 변수지정
    if (k != 0)
        st = arr[k - 1] + 1;  // 이전 인덱스 기준 다음 인덱스를 시작으로 설정
    for (int i = st; i < n; i++)
    {
        if (!inused[i])
        {
            inused[i] = true;
            arr[k] = i;  // 고른 숫자의 인덱스 저장
            func(k + 1);
            inused[i] = false;  // 이전 상태로 돌아왔을 때 이전 상태를 포함한 다른 상태를 탐색하기 위해 false로 변경
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> n;
        if (n == 0)
            break ;
        
        for (int i = 0; i < n; i++)
            cin >> num[i];
        
        func(0);
        cout << '\n';
        fill(inused, inused + 20, false);  // 다음 테스트케이스를 위한 변수 초기화
        fill(arr, arr + 20, 0);
        fill(num, num + 20, 0);
    }
    return (0);
}