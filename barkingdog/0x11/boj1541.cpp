#include <iostream>

using namespace std;

int ans, temp;
int sign = 1;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;
    
    for (char c: input) {
        if (c == '+' || c == '-') {
            ans = ans + (temp * sign);
            temp = 0;
            if (c == '-')   // 뺄셈 이후의 숫자를 전부 괄호로 묶는다면 가장 작은 수를 구할 수 있음
                sign = -1;  // 이후에 덧셈이 나와도 괄호로 묶이면 빼야 하는 수가 커지는 것이고 뺄셈이 나오면 괄호로 안묶이고 그대로 뺄셈임
        }
        else {
            temp = temp * 10;
            temp = temp + (c - '0');
        }
    }

    ans = ans + (temp * sign);  // 수식의 끝에는 연산기호가 없으므로 마지막 숫자 처리
    cout << ans;

    return 0;
}