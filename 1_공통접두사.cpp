#include <bits/stdc++.h>
using namespace std;

//최대 공통 접두사 출력

int main() {
    ios_base::sync_with_stdio(false);   //동기화 비활성화 시켜 속도 높임.
    freopen("input.txt", "rt", stdin);
    
    int n, len=INT_MAX;
    string str;
    cin >> n;
    vector<string> words;
    for(int i =0;i<n;i++){
        cin >> str;
        words.push_back(str);
        len=min(len, int(str.size()));  // 공통 문자열은 가장 짧은 길이의 string의 길이 이상일 수 없으므로
    }
    
    string result="";   // 공통 접두사 결과
    
    // 1. String으로 문제 해결하기
    for(int i=0;i<len;i++){
        string tmp="";
        for(auto &s : words)    // string을 값이 아니라 주소로 받으면 속도를 높일 수 있음.
            tmp+=s[i];  // 각 단어의 i번째 index를 push
        int m = count(tmp.begin(), tmp.end(), tmp[0]);  
        if(m==n)    result+=tmp[0]; //tmp의 모든 단어가 같다면 공통 문자열에 push
        else    break;
    }
    
    // 2. Set 자료구조로 문제 해결하기
    for(int i=0;i<len;i++){
        set<char> tmp;
        for(auto &s : words)    
            tmp.insert(s[i]);  
        if(tmp.size()==1)   // set은 중복을 제거하므로 모든 문자가 같다면 size가 1
            result+=words[0][i];
        else    break;
    }
    
    cout << result;
    
    // 3. 첫번째 단어를 공통 문자열이라고 가정하기
    string res = words[0];
    for(int i = 1; i<words.size();i++){
        while(words[i].find(res)!=0){   // 일치하지 않는다면
            res = res.substr(0, res.size()-1);   // 첫번째 단어의 문자를 뒤에서 하나씩 삭제하기
        }
    }
	cout << res;
	
	return 0;
}