// level2
// 성공. 소수 알고리즘. 진법변환
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

bool isprime(long n){
    if(n <= 1) return false;
    else if(n == 2) return true;
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0) 
            return false;
    return true;
}

int solution(int n, int k) {
    string str = "";
    
    // n을 k진수로 바꾸기 
    while(n > 0) {
        str = to_string(n % k) + str;
        n /= k;
    }     
    
    int answer = 0;
    int i;
    for(i=0;i<str.size();){
        if(str[i]=='0') {
            i++;
            continue;
        }
        int cnt=1;
        for(int j=i+1; j<str.size(); j++){
            if(str[j]=='0') break;
            cnt++;
        }
        if(isprime(stol(str.substr(i, cnt)))) answer++;
        i+=cnt;
    }
    
    return answer;
}
