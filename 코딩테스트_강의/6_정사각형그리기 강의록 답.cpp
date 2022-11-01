#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);

    int n, m;
    cin >> n >> m;

    vector <string> board;
    vector < vector <int> > dy(n, vector <int>(m, 0));
    vector <int> answer(min(n, m) + 5,0); // 0번부터 사용, 0 만나면 break;

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        board.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (board[i][j] == '0')  continue;    // 0이면 그냥 넘기기
            int a = 0, b = 0, c = 0;
            if (i - 1 >= 0)     a = dy[i - 1][j];
            if (j - 1 >= 0)     b = dy[i][j - 1];
            if (i - 1 >= 0 && j - 1 >= 0)       c = dy[i - 1][j - 1];
            int m = min(a, min(b, c));
            dy[i][j] = m + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 1; k <= dy[i][j]; k++) {   // k크기 이하인 정사각형 개수 세기
                answer[k]++;
            }
        }
    }

    for (int i = 1;; i++) {
        if (answer[i] == 0)    break;
        cout << i << " " << answer[i] << endl;
    }

    return 0;
}