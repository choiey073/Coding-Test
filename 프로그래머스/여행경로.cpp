#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int visited[10000] = {0,};
bool flag = false;
vector <string> answer;

void DFS(string curr, vector<vector<string>> tickets, int cnt){
    
    if(tickets.size() == cnt)   flag = true; // 모든 공항을 다 방문했다면 끝!
    
    answer.push_back(curr); // 현재 방문한 공항을 push
    
    for(int i =0;i<tickets.size();i++){
        // 아직 방문하지 않았고, 현재 공항(curr)과 이어져 있다면
        if(visited[i]==0 && tickets[i][0] == curr){
            visited[i]=1;
            DFS(tickets[i][1], tickets, cnt+1);
            
            // 길이 끊어진 경우. back trace
            if(!flag){  
                answer.pop_back();  // 방문 공항 경로에서 빼기
                visited[i] = 0;     // 방문하지 않은 것으로 변경
            }
        }
    }    
}

vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(), tickets.end());
    DFS("ICN", tickets,0);
    
    return answer;
}