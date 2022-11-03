#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector < vector <int> > graph(n+1); // 2차원 그래프, 1번 노드부터 시작
    vector <int> distance(n+1, 0);  // 1번 노드부터 각 노드까지 거리
    vector <int> visited(n+1, 0);   //방문 확인용
    queue <int> q;
    
    for(int i =0;i< edge.size();i++){
        //양방향 그래프
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    q.push(1);  
    visited[1] = 1;
    
    while(!q.empty()){
        int n = q.front();
        q.pop();
        
        for(int i =0;i<graph[n].size();i++){
            // 최단 거리를 위해 방문 유무 검사
            if(visited[graph[n][i]]==0){   // 아직 해당 노드를 방문하지 않았다면
                visited[graph[n][i]] = 1;  // 방문처리
                distance[graph[n][i]] = distance[n]+1;  // 이전방문 노드 길이에 +1
                q.push(graph[n][i]);
            }
        }
    }
   
    int max_cnt = *max_element(distance.begin(), distance.end());
    for(auto x : distance){
        if(max_cnt==x)  answer++;
    }

    return answer;
}