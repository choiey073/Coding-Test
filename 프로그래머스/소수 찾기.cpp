#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

// 순열 구하는게 포인트!!

bool isPrime(int num){
    if(num == 0 || num == 1){
        return false;
    }
    for(int i=2;i<=sqrt(num);i++){
        if(num % i == 0)    return false;   
    }
    return true;
}


int solution(string numbers) {
    
    // 순열함수 사용 전에 오름차순 정렬.
    sort(numbers.begin(), numbers.end());
    int num = stoi(numbers);
    unordered_set <int> prime;
    
    do{
        for(int i = 1; i < numbers.size()+1; i++){
            int n = stoi(numbers.substr(0,i));
            cout << n << endl;
            if(isPrime(n)){
                // 중복되는 순열이 있을수 있으므로 집합에 insert
                prime.insert(n);
            } 
        } 
    }while(next_permutation(numbers.begin(), numbers.end()));
    // next_permutation은 순열을 구하는 함수.
    // numbers의 처음~끝까지 순열 구함.
    // 현재 나와 있는 수열에서 인자로 넘어간 범위에 해당하는 다음 순열을 구하고 true를 반환
    // 다음 순열이 없다면 false 반환

    return prime.size();
}