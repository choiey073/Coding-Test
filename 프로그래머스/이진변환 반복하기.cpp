#include <string>
#include <vector>

using namespace std;

string binary(int num){
    string binary = "";
    while(1){
        if(num == 0)    break;
        binary.insert(0, to_string(num%2));
        num = num/2;
    }
    return binary;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int cnt = 0;    // 이진 변환 횟수
    int zero = 0;   // 제거된 0의 개수
    
    while(1){
        int tmp=0;
        if(s.size() == 1){
            answer.push_back(cnt);
            answer.push_back(zero);
            break;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                tmp++;
            }
        }
        zero += tmp;
        s = binary(s.size()-tmp);
        cnt++;
    }    
    return answer;
}