#include <bits/stdc++.h>
using namespace std;

//LCS

int main() {
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    
    string a,b;
    cin >> a >> b;
    // 앞에 null 문자열 추가
    a = ' ' + a;
    b = ' ' + b;
    int n = a.size();
    int m = b.size();

    vector < vector <int> > dy(n, vector <int>(m,0));

    // dynamic
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i] == b[j]) { // 맨 끝 문자열 2개가 같다면
                dy[i][j] = dy[i - 1][j - 1] + 1;    // 이전 대각선 값에 +1
            }
            else {  // 같지 않다면
                dy[i][j] = max(dy[i - 1][j], dy[i][j - 1]);  // 위 또는 왼쪽의 최댓값
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            cout << dy[i][j] << " ";
        }
        cout << endl;
    }

    cout << dy[n - 1][m - 1];   //맨 오른쪽 아래가 최댓값

    return 0;
}