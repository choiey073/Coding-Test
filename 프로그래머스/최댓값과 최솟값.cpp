#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    string tmp="";
    vector <int> num;
    
    for(auto c : s){
        if(c==' '){
            num.push_back(stoi(tmp));
            tmp = "";
        }
        else{
            tmp+=c;
        }
    }
    num.push_back(stoi(tmp));
    
    for(auto i : num){
        cout << i << endl;
    }
    sort(num.begin(), num.end());
    
    answer+=to_string(num[0])+" ";
    answer+=to_string(num[num.size()-1]);
    
    return answer;
}