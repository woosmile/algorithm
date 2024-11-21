#include <iostream>

using namespace std;

char field[2300][2300];
int n;

// n/3 x n/3 크기의 정사각형 9개로 나누면서 재귀를 호출함
// 각 정사각형의 x, y 시작 좌표는 n/3 만큼 떨어져있음
void star_recursive(int n, int x, int y) {
    if (n == 1) {
        field[y][x] = '*';
        return ;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1)  // 3x3 칸의 중간은 비어있어야 하므로 재귀에 들어가지 않고 continue로 넘어감
                continue ;
            star_recursive(n / 3, x + n / 3 * i, y + n / 3 * j);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        fill(field[i], field[i] + n, ' ');  // 우선 모든 칸을 빈 칸으로 채우기

    star_recursive(n, 0, 0);  // 별 찍는 재귀함수
    
    for (int i = 0; i < n; i++)
        cout << field[i] << '\n';  // 별이 찍힌 배열 출력 (배열 한 줄 끝에는 NULL이 들어있어야 제대로 출력됨, 여기에서는 전역변수로 선언해서 문제가 없음)
    
    return 0;
}