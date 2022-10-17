#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// string 합친 것 비교
// a+b가 b+a보다 크다면 true이므로 a먼저 return, b를 그 다음으로 return
bool cmp(const string &a, const string &b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector <string> str;
    
    for(int i =0;i<numbers.size();i++){
        // 숫자를 전부 string으로 변환해서 저장
        str.push_back(to_string(numbers[i]));
    }
    sort(str.begin(), str.end(), cmp);  // 숫자를 합치는 경우 가장 큰 수부터 오름차순 정렬.
    
    for(auto x : str){
        answer+=x;
    }
    
    // 가장 큰 수가 0인 경우에는 0 return
    if(answer[0]=='0')  answer = "0";
    
    return answer;
}