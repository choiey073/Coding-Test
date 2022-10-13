#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue <int> Q;
    int size = progresses.size();
    
    for(int i=0; i<size;i++){
        int rest = 100-progresses[i];   // 남은 작업량
        if(rest % speeds[i]==0){    // 나누어떨어지면
            Q.push(rest/speeds[i]);
        }
        else{   // 나누어 떨어지지 않으면
            Q.push(rest/speeds[i]+1);    // 나눈거 +1일 더 걸림
        }
    }
    
    while(!Q.empty()){
        int cnt = 1;
        int current = Q.front();   
        Q.pop();
        
        while(!Q.empty() && current >= Q.front()){
            cnt++;
            Q.pop();
        }
        answer.push_back(cnt);
    
    }
    
    return answer;
}