#include <bits/stdc++.h>
using namespace std;
//STL Set 자료구조. 중복을 없앨 때 사용
int main()
{
    vector<int> a={1,2,3,2, 3, 2, 1, 2, 3};
    set<int> s; // set은 균형잡힌 이진트리 구조
    
    for(int i=0;i<a.size();i++){
        s.insert(a[i]); // set에 들어가면서 자동정렬+중복제거
    }    
    //cout << s.size();
    
    for(auto it=s.begin(); it !=s.end(); it++){
        cout<<*it<<" ";
    }
    for(auto x:s) cout <<x<<" "; //위의 for문이랑 완전 같은 코드
    
    if(s.find(3) == s.end())    cout <<"false"; // set에 찾는 원소가 없는 경우
    else cout<<true;
    
    
    
    return 0;
}
