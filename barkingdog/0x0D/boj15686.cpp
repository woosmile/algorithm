#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define X second
#define Y first

using namespace std;

int n, m;
int board[60][60];  // 맵 정보
vector< pair<int, int> > chicken;  // 치킨집 좌표
vector< pair<int, int> > house;  // 집 좌표

int ans = 2147483647;  // 결과값 변수

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> board[y][x];
            if (board[y][x] == 1)
                house.push_back({y, x});  // 집
            if (board[y][x] == 2)
                chicken.push_back({y, x});  // 치킨집
        }
    }

    vector<int> brute(chicken.size(), 1);  // 치킨집의 개수만큼 1로 초기화
    fill(brute.begin(), brute.begin() + chicken.size() - m, 0);  // 수열에서 1을 치킨집으로 선택함
    
    do {
        int dist = 0;
        for (int i = 0; i < house.size(); i++) {
            int temp = 2147483647;  // 최소값을 구하기 위해 최대값으로 먼저 설정
            for (int j = 0; j < chicken.size(); j++) {
                if (brute[j] == 0)  // 치킨집이 아닌 경우는 패스
                    continue ;
                temp = min(temp, abs(house[i].X - chicken[j].X) + abs(house[i].Y - chicken[j].Y));  // 집에서 치킨집까지의 최소 거리를 구함
            }
            dist = dist + temp;  // 집마다 구한 최소의 치킨거리를 더함
        }
        ans = min(ans, dist);  // 최소값 갱신
    }while(next_permutation(brute.begin(), brute.end()));  // 조합 생성

    cout << ans;
    
    return (0);
}