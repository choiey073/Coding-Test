#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

//올바른 문자열인지 확인하는 함수
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
    // 올바른 문자열이거나, 빈 문자열이라면 해당 문자열 바로 반환
    if(check(p))    return p;   
   
    // 균형잡힌 문자열 u,v -> '(' 와 ')'의 갯수가 같은 경우
    string u, v;
    int cnt = 0;
    
    // 조건 2
    // 두 균형잡힌 문자열(u,v)로 분리
    for(int i =0;i<p.size();i++){
        if(p[i]=='(')   cnt++;
        else    cnt--;
        
        // '('와  ')'의 개수가 같아질 때 -> 균형잡힌 문자열일 때
        if(cnt==0){
            u = p.substr(0, i+1);
            v = p.substr(i+1);  // v는 빈 문자열이 될 수 있음.
            break;
        }
    }
    
    // 조건 3
    // u가 올바른 문자열인 경우
    // 문자열 v에 대해서 재귀
    if(check(u)){
        return u + solution(v);   // 수행한 결과 문자열을 u에 이어 붙인 후 반환
    }
    
    // 조건 4
    // u가 올바른 문자열이 아닌 경우
    
    // 조건 4-1) 첫번째 문자로 "(" 붙이기
    // 조건 4-2) 문자열 v에 대해서 재귀적 수행
    // 조건 4-3) 마지막 문자열로 ")" 붙이기
    string answer = "(" + solution(v) + ")";
    
    // 조건 4-4) u의 첫번째와 마지막 문자 제거 (반복문을 1부터 u.size()-2 까지만 돌리는 것)
    // 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙이기
    // "("가 나오면 ")"를 뒤에 붙이고, ")"가 나오면 "("를 뒤에 붙이기.
    for(int i = 1; i<u.size()-1; i++){
        if(u[i]=='(')   answer+=')';
        else answer+='(';
    }
    
    // 조건 4-5) 생성된 문자열 반환
    return answer;
}