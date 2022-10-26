#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    
    string s;
    int n, result = 0;

    cin >> s >> n;

    string pattern;

    for (int i = 3; i < s.size(); i++) {    // 패턴찾기 코드
        if (s.substr(0, i) == s.substr(i, i)) { // 0 ~ i-1 까지의 문자열과 i ~ i-1 의 문자열이 같다면 패턴!
            pattern = s.substr(0, i);

            for (auto x : pattern) {
                result += x - '0'; // char to int
            }
            break;
        }
    }

    result = result * (n / pattern.size());
    
    for (int i = 0; i < n % pattern.size(); i++) {
        result += pattern[i] - '0';
    }
    
    cout << result;

    return 0;
}