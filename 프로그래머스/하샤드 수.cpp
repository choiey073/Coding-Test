#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    
    int n = 0;
    int tmp = x;
    
    while(tmp!=0){
        n += tmp%10;
        tmp = tmp/10;
    }
    
    if(x%n == 0)    return true;
    else            return false;
    
}