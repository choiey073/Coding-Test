#include <string>
#include <vector>

using namespace std;

// 'O'인 경우 상하좌우에서 'P'가 두개 이상 나오면 거리두기를 지키지 않은 것
// 'P'인 경우 상하좌우에서 'P'가 1개 이상 나오면 거리두기를 지키지 않은 것
// 'X'인 경우 상하좌우에 'P'가 몇개라도 상관 없음

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

bool BFS(int x, int y, vector<string> place){
    int f=0;
    
    for(int i=0;i<4;i++){
        int xx = x+dx[i];
        int yy = y+dy[i];
        
        if(xx >=0 && xx <=4 && yy >=0 && yy<=4){
            if(place[xx][yy] == 'P'){
                f++;
            }
            if(place[x][y]=='O'){
                if(f==2){
                    return false;
                }
            }
            else{
                if(f){
                    return false;
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    bool ch = true;
    
    for(auto place : places){
        for(int i =0;i<5&&ch;i++){
            for(int j =0;j<5&&ch;j++){
                if(place[i][j] !='X'){
                    ch = BFS(i,j,place);
                }
            }
        }
        if(ch)  answer.push_back(1);
        else    answer.push_back(0);
        ch=true;
    }
    
    return answer;
}