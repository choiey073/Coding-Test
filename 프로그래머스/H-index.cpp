#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    // 내림차순 정렬
    sort(citations.begin(), citations.end(),greater<>());
    
    if(!citations[0])   return 0;   // 가장 많이 인용된 논문의 수가 0일때 0 반환
    
    for(int h=0;h<n;h++){
        if(citations[h]>=h+1){
            answer = h+1;
        }
    }
    
    return answer;
}