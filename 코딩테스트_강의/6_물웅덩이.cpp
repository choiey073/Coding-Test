#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    
    int n, m, cnt=0;
    cin >> n >> m;

    //vector < vector <char> > board(n);
    char board[100][100];

    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '#') {   //웅덩이라면
                cnt++;
                board[i][j + 1] = '.';
                board[i + 1][j] = '.';
            }
        }
    }

    cout << cnt;

    return 0;
}