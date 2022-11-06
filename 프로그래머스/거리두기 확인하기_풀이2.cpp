#include <string>
#include <vector>
#include <queue>

using namespace std;

// 'O'인 경우 상하좌우에서 'P'가 두개 이상 나오면 거리두기를 지키지 않은 것
// 'P'인 경우 상하좌우에서 'P'가 1개 이상 나오면 거리두기를 지키지 않은 것
// 'X'인 경우 상하좌우에 'P'가 몇개라도 상관 없음

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

bool BFS(int x, int y, vector<string> place){
    int visited[5][5] = {1};
    queue <pair <int, int> > q;
    
    visited[x][y] = 1;  // 방문처리
    q.push({x,y});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // 3번 이상 방문할 필요 없음
        if(visited[x][y]>=3){
            break;
        }
        
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx<0 || nx>=5 || ny<0||ny>=5 || visited[nx][ny] || place[nx][ny]=='X')
                continue;
            
            if(place[nx][ny]=='P')
                return false;
            
            visited[nx][ny] = visited[x][y]+1;
            q.push({nx,ny});
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    bool ch;
    
    for(auto place : places){
        for(int i =0;i<5;i++){
            for(int j=0;j<5;j++){
                if(place[i][j] != 'P'){
                    continue;
                }
                if(!BFS(i,j,place))
                    ch = false;
            }
        }
        if(ch)  answer.push_back(1);
        else    answer.push_back(0);
        ch = true;
    }
    return answer;
}