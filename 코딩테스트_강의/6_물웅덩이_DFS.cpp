#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[100][100];

bool DFS(int x, int y) {
    if (x <= -1 || x >= n || y <= -1 || y >= m) {
        return false;
    }
    if (board[x][y] == '#') {
        board[x][y] = '.';

        DFS(x - 1, y);
        DFS(x, y - 1);
        DFS(x + 1, y);
        DFS(x, y + 1);

        return true;
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);

    int cnt = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (DFS(i, j))    cnt++;
        }
    }
    cout << cnt;

    return 0;
}