#include <string>
#include <vector>

using namespace std;

// 3진법으로 풀 수 있음.

string solution(int n) {
    string answer = "";
    int share = n;  //  몫
    int remainder;  // 나머지
    
    while(share!=0){
        remainder = share % 3;
        share = share / 3;
        
        if(remainder == 1){
            answer = "1" + answer;
        }
        else if(remainder == 2){
            answer = "2" + answer;
        }
        else if(remainder == 0){    // 완전히 나누어 떨어지는 경우
            answer = "4" + answer;
            share --;
        }
    }
    
    return answer;
}