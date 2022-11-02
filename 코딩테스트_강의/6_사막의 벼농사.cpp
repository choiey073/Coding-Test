#include <bits/stdc++.h>
using namespace std;

int len, n, res;
int length[21], capability[21]; // 길이, 용량 배

void DFS(int L, int sum, int cap) {

    if (sum > len)   return;    // 이미 길이를 넘어갔다면 return
    
    if (L == n) {   // 부분 집합이 만들어졌다면,
        if (sum == len) {
            res = max(res, cap);    // 여러 조합들의 결과 중 최대 용량
        }
    }
    else {
        //L번째 인덱스를 사용한다.
        DFS(L + 1, sum + length[L], min(cap, capability[L]));
        
        //L번째 인덱스를 사용하지 않는다.
        DFS(L + 1, sum, cap);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);

    cin >> len >> n;

    for (int i = 0; i < n; i++) {
        cin >> length[i] >> capability[i];
    }
    
    DFS(0, 0, INT_MAX);

    cout << res;

    return 0;
}