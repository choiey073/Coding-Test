#include <string>
#include <vector>
using namespace std;

int check[200] = {0,};   // 컴퓨터 방문했는지 check

void DFS(int current_computer, int n,vector<vector<int>> computers){
    // current_computer를 check 했다고 표시
    check[current_computer] = 1;
    
    for(int i = 0; i<n ;i++){
        if(check[i]==0 && computers[current_computer][i]==1){
            // 아직 i번째 컴퓨터를 방문하지 않았고,
            // current_computer와 i번째 컴퓨터가 연결되어있다면
            // i번째 컴퓨터 탐색 시작
            DFS(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0 ; i<n;i++){
        // 아직 방문하지 않은 컴퓨터라면 탐색
        if(check[i]==0){    
            DFS(i, n, computers);
            
            // 재귀적으로 호출한 DFS 함수가 전부 반환됐을 때
            // 연결된 하나의 그래프를 모두 탐색한 것이므로
            // 네트워크의 갯수를 하나 더해주는 것
            answer++;
        }
    }
    return answer;
}