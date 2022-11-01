#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);

    int n, m;
    cin >> n >> m;

    vector < vector <int> > board(n, vector <int>(m, 0));
    vector < vector <int> > dy(n, vector <int>(m, 0));
    vector <int> answer(min(n, m) + 5,0); // 0번부터 사용, 0 만나면 break;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &board[i][j]);

            if (board[i][j] == 0)  continue;    // 0이면 그냥 넘기기

            if (i > 0 && j > 0) {   // 경계선 밖으로 나가지 않고, board[i][j]==1이라면
                dy[i][j] = min(dy[i - 1][j - 1], min(dy[i - 1][j], dy[i][j - 1])) + 1;
            }
            else {  // i가 0이거나 j가 0일때는 i-1, j-1이 경계에서 벗어나므로 그대로 입력
                dy[i][j] = board[i][j];
            }
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