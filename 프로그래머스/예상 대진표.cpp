#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
   
    // 다음 라운드에 배정되는 숫자 = (현재 숫자 + 1) / 2 
    while(a!=b){
        a = (a+1)/2;
        b = (b+1)/2;
        answer++;
    }
    
    return answer;
}