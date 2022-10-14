#include<vector>
#include<queue>
#include<iostream>
using namespace std;

// 테케 20개 중에 하나 틀림.. 뭐지?

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool check[101][101]={0};

int solution(vector<vector<int> > maps)
{   
    int answer = 0;
    int n = maps.size();    //  x
    int m = maps[1].size(); //  y
    
    queue < pair<int,int> > Q;
    Q.push({0,0});  //  처음에 캐릭터의 위치(좌측 최상단)
    
    if(n==1){
        for(int i =0; i<m; i++){
            if(maps[0][i]==0)   return -1;
        }    
        return m;
    }
    if(m==1){
        for(int i =0; i<n; i++){
            if(maps[i][0]==0)   return -1;
        }    
        return n;
    }
    
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        
        for(int i =0;i<4;i++){
            int nx = dx[i]+x;
            int ny = dy[i]+y;
            
            if(nx < 0 || nx >=n || ny < 0 || ny >= m)   continue;
            if(maps[nx][ny]==0) continue;
            if(maps[nx][ny]==1){
                maps[nx][ny] = maps[x][y] + 1;
                Q.push({nx,ny});
            }
        }
    }
    if(maps[n-1][m-1]==1)   return -1;
    else    return maps[n-1][m-1];
}