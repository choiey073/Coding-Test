#include <bits/stdc++.h>
using namespace std;
// Stack
int main() {
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    
    string s, res = "";
    cin >> s ;
    stack <char> st;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') {  
            string tmp;
            while (!st.empty() && st.top() != '(') {       // 여는 괄호 아니라면 계속 tmp에 더하기  
                tmp += st.top();
                st.pop();
            }
            st.pop();   // 여는 괄호는 그냥 pop
            reverse(tmp.begin(), tmp.end());    // 뽑은 문자열 뒤집기
            string num;
            if (st.empty()) {   // 앞에 1이 생략된 경우
                num = "1";      // 1번 반복하기 위해서 num = 1
            }
            while (!st.empty()) {
                num += st.top();    // 숫자 뽑기
                st.pop();
            }
            reverse(num.begin(), num.end());    // 숫자도 reverse;
            int n = stoi(num);      // string to int
            for (int j = 0; j < n; j++) {       // 해당 숫자만큼 반복
                res += tmp;
            }
        }
        else {  // 닫는 괄호가 아니면 push
            st.push(s[i]);
        }
    }
    cout << res;

    return 0;
}