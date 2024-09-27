#include <iostream>
#include <queue>

using namespace std;

int n, w, l;  // n: 트럭 수, w: 다리 길이, l: 다리가 버틸 수 있는 하중
queue<int> truck;  // 트럭 무게를 저장할 큐
int bridge[101];  // 다리 배열(길이 = 배열 길이)

int ans;  // 출력값

bool check_bridge_empty(void) {  // 다리가 비어있는지 확인
    for (int i = 0; i < w; i++) {
        if (bridge[i])
            return false;
    }
    return true;
}

int truck_on_bridge(void) {  // 다리에 있는 트럭 무게의 총합을 구함
    int sum = 0;

    for (int i = 0; i < w; i++) {
        sum = sum + bridge[i];
    }
    
    return sum;
}

void go_truck(void) {  // 다리 위에있는 모든 트럭을 한 칸 전진시키고 시작점인 0은 0으로 초기화
    for (int i = w - 1; i > 0; i--) {
        bridge[i] = bridge[i - 1];
    }
    bridge[0] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> l;

    for (int i = 0; i < n; i++) {
        int weight;
        cin >> weight;
        truck.push(weight);
    }

    do {
        int total_weight = truck_on_bridge();

        if (total_weight <= l) {  // 다리에 있는 모든 트럭의 중량이 하중 이하일 때
            total_weight = total_weight - bridge[w - 1];  // 빠져나갈 트럭의 무게를 빼고
            go_truck();  // 트럭을 한 칸 전진시킴
            if (total_weight + truck.front() <= l && !truck.empty()) {  // 다음 트럭이 있고 다리 위에 놓일 수 있다면
                bridge[0] = truck.front();  // 다리의 시작점에 트럭을 놓고
                truck.pop();  // 그 트럭을 큐에서 뺌
            }
        }
        ans++;  // 1번에 1칸씩 이동할 수 있음 (=단위 시간 당 단위 길이만큼 이동한다)
    } while(!check_bridge_empty());  // 다리에 트럭이 남아있지 않을 때까지 반복

    cout << ans;
    
    return 0;
}