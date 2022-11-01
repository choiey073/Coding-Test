#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 50;    // 단어의 개수가 최대 50개이므로
bool visited[50];   // 방문했는지 check;
// 한번 사용한 단어를 재사용하면 변환 단계가 길어져 최소값이 될 수 없음

// 다른 문자가 1개인지 check
bool diff(string a, string b){
    int cnt = 0;
    for(int i =0;i<a.size();i++){
        if(a[i]!=b[i]){
            cnt++;
        }
    }
    if(cnt==1)  return true;    // 다른 문자가 딱 한개일 때
    else        return false;
}

void DFS(string current, string target, vector <string> words, int step){
    // current : 현재 탐색중인 단어
    // step : 현재 단어 변환이 몇 단계째인지
    
    if(answer <=step){  // step이 이전에 찾은 answer보다 크면 탐색할 필요 X
        return;
    }
    
    if(current == target){ // 일치하면 답 찾기
        answer = min(answer, step);
        return;
    }
    
    for(int i =0;i<words.size();i++){
        if(diff(current, words[i]) && !visited[i]){
            // 단어가 딱 하나만 다르고, 아직 방문하지 않았다면
            // 해당 단어 방문처리
            visited[i]=true;    
            // 해당 단어부터 탐색 시작. 단계 하나 추가
            DFS(words[i], target, words, step+1);    
            // DFS 재귀 호출 후 종료되어 여기로 오면,
            // 백트래킹(방문 표시 해제) 하여 다음 분기점부터 다시 탐색 시작
            visited[i] = false; 
        }
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    
    DFS(begin, target, words, 0);
    
    // 탐색 후 target을 찾지 못한 경우
    if(answer == 50){
        return 0;   
    }
    
    return answer;
}