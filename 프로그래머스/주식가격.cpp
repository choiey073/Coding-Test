#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    
    int n = prices.size();
    vector<int> answer(n,0);
    stack<int> s;
    
    for(int i=0;i<n;i++){
        while(!s.empty() && prices[i]<prices[s.top()]){ //가격이 떨어진 경우
            answer[s.top()] = i-s.top();    // 떨어지지 않은 경우 계산. 현재시점-떨어진시점
            s.pop();    // 떨어진 시점 pop
        }
        s.push(i);  // 현재 시점 push
    }
    
    while(!s.empty()){  // 가격이 끝까지 떨어지지 않은 경우에는 stack에 남아있음.
        answer[s.top()] = (n-1)-s.top();    // 떨어지지 않은 기간 계산
        s.pop();
    }
    
    return answer;
}