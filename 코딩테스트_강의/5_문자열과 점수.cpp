#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    // 같을 때, 공백일 때, 다를 때

    string a, b;
    cin >> a >> b;
    a = ' ' + a;    // 맨 앞 문자열 null
    b = ' ' + b;    // 맨 앞 문자열 null

    vector < vector <int> > dy(a.size(), vector <int>(b.size(), 0));
    
    for (int i = 1; i < a.size(); i++)   dy[i][0] = n2 * i; // 공백이랑 a의 i번째 문자열까지 매치될 때 점수
    for (int i = 1; i < b.size(); i++)   dy[0][i] = n2 * i; // 공백이랑 b의 i번째 문자열까지 매치될 때 점수

    for (int i = 1; i < a.size(); i++) {
        for (int j = 1; j < b.size(); j++) {
            if (a[i] == b[j]) { // 맨 마지막 문자가 같은 경우
                dy[i][j] = dy[i - 1][j - 1] + n1;   // 대각선  + 같을 때 점수
            }
            else {  // 맨 마지막 문자열 다른 경우 ->  4가지 case
                int max;
                if (dy[i - 1][j] + n2 > dy[i][j - 1] + n2) {    // a의 마지막 문자열을 공백으로 취급
                    max = dy[i - 1][j] + n2;
                }
                else {  // b의 마지막 문자열을 공백으로 취급
                    max = dy[i][j - 1] + n2;    
                }
                if (dy[i - 1][j - 1] + (n2 * 2) > max) {    // a의 마지막 문자열과 b의 마지막 문자열 모두를 공백과 매치하는 경우
                    max = dy[i - 1][j - 1] + (n2 * 2);
                }
                if (dy[i - 1][j - 1] + n3 > max) {  // a의 마지막 문자열과 b의 마지막 문자열을 매치하는 경우(다른 문자열 두개를 매치하는 경우)
                    max = dy[i - 1][j - 1] + n3;
                }
                dy[i][j] = max;
            }
        } 
    }

    cout << dy[a.size()-1][b.size()-1];

    return 0;
}