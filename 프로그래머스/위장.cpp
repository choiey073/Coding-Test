#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map <string, int> match;
    
    for(int i =0 ;i<clothes.size();i++){    // 의상의 종류별로 의상의 이름 count
        match[clothes[i][1]]++;
    }
    
    for(auto i : match){    // 옷 종류마다 +1을 한 후 곱해주기
        answer *= (i.second+1);
    }
    
    return answer-1;    // 아무것도 안 입는 경우 빼주기(-1)
}