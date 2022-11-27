#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <set>
using namespace std;

int solution(vector<string> id_list, int k) {
    int answer = 0;

    map<string, int> mp;

    for(int i=0;i<id_list.size();i++){
        set <string> st;
        string s;
        string str = id_list[i];
        stringstream stream;
        stream.str(str);

        while(stream >> s){
            st.insert(s);
        }
        for(auto x : st){
            if(mp[x] < k){
                mp[x]++;
            }
        }
    }
    for(auto x : mp){
        answer += mp[x.first];
    }

    return answer;
}