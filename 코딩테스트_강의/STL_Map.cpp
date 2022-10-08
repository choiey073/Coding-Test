#include <bits/stdc++.h>
using namespace std;
// MAP을 알고리즘에서 사용할 때는 Hash 형태로 counting 할때.
// MAP은 정렬된다!

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt", stdin);
    
    string a="It is time to Study Go Go";
    
    map<char, int> ch;  // map<key,value> pair형 자료구조가 생기는 것.
    // map은 균형잡힌 이진트리
    // 자동으로 insert 될 때마다 자동으로 정렬됨.
    
    // cf) unordered_map도 있음.
    // 이건 hash처럼 사용.
    // Data가 많아지면 unordered_map 사용하면 hash 충돌이 많아져서 사용 안함.
    
    for(auto x:a){
        if(x !=' ') ch[x]++;    // char를 index 처럼 사용 가능
    }
    for(auto it = ch.begin(); it!=ch.end(); it++){  // 여기서 it는 포인터처럼 사용하는것.
        cout << it -> first << " " << it->second << endl;
    }
    
    // 위 for문이랑 완전 같은거!
    for(auto x:ch) cout<<x.first <<" "<<x.second << endl ;
    
    ch['K'];    // 이렇게 하면 key가 K이고 value=0인게 생김.
    
    
    map<string, int> str_map;   // key가 string 형태인 map
    string tmp;
    for(auto x:a){
        if(x==' '){
            str_map[tmp]++; // string을 key로 해서 value 증가시킴.
            tmp.clear();
        }
        else tmp +=x;
    }
    str_map[tmp]++; // 마지막에는 띄어쓰기가 없으므로 마지막 문자열 추가해줘야함.
    
    for(auto x:str_map) cout<<x.first <<" "<<x.second << endl ;
    
    return 0;
}
