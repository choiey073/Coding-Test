#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GCD(int a, int b){
    int A = max(a, b);
    int B = min(a, b);
    
    while(A%B != 0){
        int R = A%B;
        A = B;
        B = R;
    }
    return B;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int i = 1; i<arr.size(); i++){
        int gcd = GCD(answer, arr[i]);
        int lcm = (answer * arr[i]) / gcd;
        answer = lcm;
    }
    
    return answer;
}