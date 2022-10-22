#include <bits/stdc++.h>
using namespace std;
//BFS
int n, result=INT_MIN;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0,1, 0 };


int main() {
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    
    cin >> n;

    vector < vector<int> > board(n, vector<int>(n, 0));
    vector < vector<int> > dist(n, vector<int>(n, 0));

    queue <pair <int, int> > Q;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                Q.push({ i,j });
            }
        }
    }

    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == 0) {

                board[nx][ny] = 1;  // 방문처리
                dist[nx][ny] = dist[x][y] + 1;  
                Q.push({ nx,ny });
                result = max(result, dist[nx][ny]);
            }
        }
    }

    cout << result;

    return 0;
}