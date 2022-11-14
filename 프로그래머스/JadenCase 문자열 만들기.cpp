#include <string>
#include <vector>
#include <ctype.h>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    // 처음부터 끝까지 일단 소문자로 바꿔주기
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if(isalpha(s[0]))   s[0] = toupper(s[0]);
    
    // 모든 단어의 첫 문자만 대문자로 바꿔주기
    for(int i =1;i<s.size();i++){
        if(s[i-1]==' ' && isalpha(s[i]))
            s[i]=toupper(s[i]);
    }
        
    return s;
}