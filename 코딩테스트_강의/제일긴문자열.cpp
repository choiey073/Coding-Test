#include <bits/stdc++.h>

using namespace std;
// 가장 긴 문자열
int main()
{
    string a = "it is time to study";
    string res; // 가장 긴 문자열을 담을 결과
    int pos, max = INT_MIN;
    int len;
    while((pos=a.find(' '))!=string::npos){ // 찾는 문자열이 없는 경우 string::npos return
        string tmp = a.substr(0,pos);
        len = tmp.size();
        if(len>max){
            max=len;
            res=tmp;
        }
        cout << tmp <<endl;
        a = a.substr(pos+1);
    }
    if(len>max) res=a;
    cout<<a;

    return 0;
}
