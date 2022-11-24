#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map <char, int> tree;
    
    // 해쉬 맵에 스킬 순서 저장.
    for(int i =0;i<skill.size();i++){
        tree[skill[i]]= i+1;
    }
    
    for(auto s : skill_trees){
        int cnt = 1;
        bool ch = true;
        
        // 현재 스킬이 스킬 순서에 위배되는지 확인
        for(int i=0;i<s.size();i++){
            // 스킬 순서가 맞지 않으면 탈출
            if(tree[s[i]]>cnt){
                ch = false;
                break;
            }
            // 최초 스킬트리를 익혔으면 다음 스킬을 익힐수 있도록
            else if(tree[s[i]]==cnt){
                cnt++;
            }
        }
        // 모두 통과했으면 카운트 증가
        if(ch)  answer++;
    }
    
    return answer;
}