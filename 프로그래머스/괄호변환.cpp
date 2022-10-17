#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

//올바른 문자열인지 확인
bool check(string p){
    stack <char> s;
    
    for(auto c:p){
        if(c=='('){
            s.push(c); 
        }  
        else{
            if(s.empty())   return false;
            else    s.pop();    // ')'를 만나면 '('를 pop           
        }
    }
    return true;
}

string solution(string p) {
    
    // 조건1
    if(check(p))    return p;   // 올바른 문자열이라면 바로 리턴
    if(p=="")   return "";      // 빈 문자열이라면 빈 문자열 반환
 
    string u, v;
    int cnt = 0;
    
    for(int i =0;i<p.size();i++){
        if(p[i]=='(')   cnt++;
        else    cnt--;
        
        // '('와  ')'의 개수가 같아질 때
        if(cnt==0){
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break;
        }
    }
    
    // u가 올바른 문자열인 경우
    if(check(u)){
        return u+solution(v);
    }
    
    // u가 올바른 문자열이 아닌 경우
    string answer = "(" + solution(u) + ")";
    
    for(int i = 1; i<u.size()-1; i++){
        if(u[i]=='(')   answer+=')';
        else answer+='(';
    }
    

    return answer;
}