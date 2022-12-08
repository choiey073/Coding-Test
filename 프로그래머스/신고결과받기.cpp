#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    map <string, int> report_cnt;   // 유저별 신고 당한 횟수
    map <string, set<string>> report_log; // 유저별 신고한 타 유저 리스트
    
    for(auto x : report){
        int blank = x.find(' ');
        string from = x.substr(0, blank);   // 신고한 유저
        string to = x.substr(blank);    // 신고당한 유저
        
        // from 이 to 를 신고한 이력이 없다면
        if(report_log[from].find(to) == report_log[from].end()){
            report_cnt[to]++;   // 신고 당한 횟수 늘리기
            report_log[from].insert(to);    // 신고한 유저 리스트에 저장.
        }
    }
    
    for(auto s : id_list){
        int cnt = 0;
        
        // k번 이상 신고당한 경우.
        for(auto str : report_log[s]){
            if(report_cnt[str] >= k)    cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}