#include <iostream>
#include <algorithm>

using namespace std;

int l, c;
char input[20];
char ans[20];
int inused[20];

void func(int k, int v_cnt, int c_cnt)
{
    if (k == l)
    {
        if (v_cnt >= 1 && c_cnt >= 2)   // 모음과 자음의 개수 확인
        {
            for (int i = 0; i < l; i++)
                cout << input[ans[i]];
            cout << '\n';
        }
        return ;
    }

    int st = ans[k];
    if (k != 0)
        st = ans[k - 1] + 1;

    for (int i = st; i < c; i++)
    {
        if (!inused[i])
        {
            inused[i] = true;
            ans[k] = i;
            bool is_vowel = (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u');
            if (is_vowel)
                v_cnt++;
            else
                c_cnt++;
            func(k + 1, v_cnt, c_cnt);
            // 백트래킹 시 값 복구 (이전 상태로 되돌아갈 때 이전 상태에서의 상태값도 같이 되돌려서 이후 계산에 영향을 미치지 않도록 함)
            if (is_vowel)
                v_cnt--;
            else
                c_cnt--;
            inused[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;
    for (int i = 0; i < c; i++)
        cin >> input[i];
    sort(input, input + c);
    func(0, 0, 0);
    return (0);
}