#include <bits/stdc++.h>
using namespace std;

int player[9], ch[9], team[3], res = INT_MAX;

void DFS(int L) {
    
    if (L == 9) {
        vector <int> sum(3);    // 각 팀의 합
        for (int i = 0; i < 9; i++) {
            sum[ch[i]] += player[i];    //i번째 선수의 팀에 점수 더하기
        }
        int high = max(sum[0], max(sum[1], sum[2]));
        int low = min(sum[0], min(sum[1], sum[2]));
        res = min(res, high - low); // 차이가 가장 작은 값을 결과에 저장.
    }
    else {
        for (int i = 0; i < 3; i++) {
            if (team[i] < 3) {  // 각 팀이 3명 이하인 경우에만 뻗어나가기
                team[i]++;  // i번 팀의 인원 한명 증가
                ch[L] = i;  // L번 선수는 i번 팀이다.
                DFS(L + 1); // L번 선수의 다음 선수 뻗어나가기
                team[i]--;  // 뒤로 돌아갔을 경우 i번 팀에서 한명 빼기.
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);

    for (int i = 0; i < 9; i++) {
        cin >> player[i];
    }
    DFS(0); // 0번 선수부터 시작
    
    cout << res;

    return 0;
}