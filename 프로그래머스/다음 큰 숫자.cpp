#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 2진수 구하는 함수
string getBinary(int n){
    string result = "";
    
    while(n>0){
        int remain = n%2;
        n = n/2;
        
        result = to_string(remain) + result;
    }
    return result;    
}

// 2진수로 바꿨을 때 1의 갯수 구하는 함수
int cnt_one(string s){
    int cnt=0;
    
    for(auto x : s){
        if(x=='1')  cnt++;
    }
    return cnt;
}

int solution(int n) {
    
    // n의 1의 개수 구하기
    int one = cnt_one(getBinary(n));
    
    while(1){
        n++;
        if(cnt_one(getBinary(n))==one)  break;
    }
    
    return n;
}