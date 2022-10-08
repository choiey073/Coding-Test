#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    
    string a;
    cin>>a;
    int sum=0, res=0;
    for(char x:a){
        if(x>=48 && x <=57){    // 숫자 '0'~'9'는 ASCII CODE로 48~57
        // if(isdigit(x)){       // 위의 코드와 같음. 숫자를 만나면 true
            res=res*10+(x-48);  // 아스키코드가 아니라 숫자로 나오려면 x에서 48을 빼줘야함.
        }
        else{   // 문자가 나왔을 때
            sum+=res;
            res=0;
        }
    }
    cout <<sum+res; // 마지막에 숫자로 끝나는 경우에 res 더해줌

    return 0;
}
