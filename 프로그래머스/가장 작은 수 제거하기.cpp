#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if(arr.size()==1){
        answer.push_back(-1);
        return answer;
    }
    
    //min_element(arr.begin(), arr.end())
    // -> arr.begin()에서 arr.end()까지 가장 작은 수의 위치(반복자) 리턴
    arr.erase(min_element(arr.begin(), arr.end()));
    
    return arr;
}