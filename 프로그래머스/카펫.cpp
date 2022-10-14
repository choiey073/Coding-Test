#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown+yellow;
    
    for(int h =3;;h++){ // 높이는 3부터 시작
        if(sum%h==0){   // 나누어떨어지면
            int w = sum/h;   // 너비
            if((h-2)*(w-2)==yellow){
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
    }
    return answer;
}