#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

// stack을 사용하여 효율성을 높여야하는게 포인트인 문제.
int solution(string s)
{
    int answer = 0;
    
    if(s.size()%2 == 1 || s.empty())
        return answer;
    
    stack <char> st;
    
    for(int i = 0 ; i<s.size(); i++){
        // stack이 비었거나, stack의 top이 현재 문자와 같지 않다면 stack에 해당 문자 push
        if(st.empty() || st.top() != s[i]){
            st.push(s[i]);
        }
        // stack의 top이 현재 문자와 같다면 pop
        else if(st.top() == s[i]){
            st.pop();
        }
    }
    
    if(st.empty())   answer = 1;

    return answer;
}