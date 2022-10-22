#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int board[102][102];
int cnt;

void DFS(int x, int y) {
    board[x][y] = 0;
    cnt++;  // 호출 횟수 == 호수의 크기
    for (int i = 0; i < 4; i++) {
        if (board[x + dx[i]][y + dy[i]] == 1) {
            DFS(x + dx[i], y + dy[i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    int result = INT_MIN;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;    // 물이 차 있는 곳은 1으로
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == 1) {
                cnt = 0;
                DFS(i, j);
                result = max(cnt, result);  // 가장 큰 호수의 크기 구하기
            }
        }
    }

    cout << result;

    return 0;
}