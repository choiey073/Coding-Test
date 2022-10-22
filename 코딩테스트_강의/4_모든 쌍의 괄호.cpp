#include <bits/stdc++.h>
using namespace std;

// 모든 경우의 수 ->  재귀
// Tree 구조로 생각하기
// 왼쪽 sub tree : 여는 괄호
// 오른쪽 sub tree : 닫는 괄호

int n;
int cnt;    // 경우의 수

void DFS(int open, int close, string res) {

    // 여는괄호나 닫는 괄호의 갯수가 n개보다 많아지거나, 닫는 괄호가 여는 괄호보다 많으면 return
    if (open > n || close > n || open < close)   return; 

    if (open == n && close == n) {
        cout << res << endl;
        cnt++;
    }
    else {
        DFS(open + 1, close, res + "(");    // 여는 괄호 추가
        DFS(open, close + 1, res + ")");    // 닫는 괄호 추가
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
   
    cin >> n;

    DFS(0, 0, "");  // (여는 괄호의 갯수, 닫는 괄호의 갯수, 결과 string)
    cout << cnt;    // 경우의 수 출력

    return 0;
}