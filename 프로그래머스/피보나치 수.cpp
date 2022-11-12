#include <string>
#include <vector>
#include <iostream>

using namespace std;
// Memorization
// 배열을 만들어서 재귀로 만든 값을 저장해야함

int fibo[100001] = {0,1,1};    // F(0), F(1), F(2)

// 피보나치 배열에 해당 값이 저장되어 있으면 바로 꺼내기
// 피보나치 배열에 해당 값이 저장되어 있지 않으면 계산 후 저장하기.
int F(int n){
    
    if(n<=2){
        return fibo[n];
    }
    
    // 계산 안되어 있으면 피보나치 수열 계산해서 배열에 저장하기
    if(fibo[n]==0){ 
        fibo[n] = (F(n-1) + F(n-2)) % 1234567;
    }
    return fibo[n];
    
}

int solution(int n) {
    int answer = F(n);
    return answer;
}