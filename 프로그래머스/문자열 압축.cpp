#include <string>
using namespace std;

int solution(string s) {
    int answer = s.size();
    
    for(int i =1;i<=s.size()/2;i++){
        string result = "";
        string sub = s.substr(0,i);
        int cnt = 1;
        
        for(int j=i;j<s.size();j+=i){
            if(sub == s.substr(j,i)){
                cnt ++;
            }
            else{  
                if(cnt > 1){
                    result += to_string(cnt);
                }
                result += sub;
                sub = s.substr(j,i);
                cnt = 1;
            }
        }
        if (cnt > 1) result += to_string(cnt);
        result += sub;
        if (answer > result.size()) answer = result.size();
    }
    
    return answer;
}