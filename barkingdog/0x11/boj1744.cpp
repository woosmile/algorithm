#include <bits/stdc++.h>

using namespace std;

int n;
int ans;

void vec_sum(vector<int> &v) {
    while (v.size() > 1) {
        ans = ans + (*(v.end() - 1) * *(v.end() - 2));   // 절대값 기준으로 가장 큰 값이 우측에 위치하므로 끝, 끝 - 1 원소를 서로 곱함
        v.pop_back();  // 원소 제거
        v.pop_back();
    }

    if (!v.empty())   // 원소의 개수가 홀수면 하나가 남는 것에 대한 처리
        ans = ans + v[0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<int> vec_pos, vec_neg;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == 1)   // 1은 곱하면 자기 자신이므로 그냥 더하는 것이 더 큰값임
            ans++;
        else if (num <= 0)
            vec_neg.push_back(num);   // 0을 포함하는 음수 벡터
        else
            vec_pos.push_back(num);   // 양수 벡터
    }

    sort(vec_pos.begin(), vec_pos.end());   // 양수는 오름차순으로
    sort(vec_neg.begin(), vec_neg.end(), greater<>());   // 음수는 내림차순으로 해야 절대값 기준 가장 큰 값이 가장 우측에 옴
    
    vec_sum(vec_pos);
    vec_sum(vec_neg);

    cout << ans;
    
    return 0;
}