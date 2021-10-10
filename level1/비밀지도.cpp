// leve1
// 성공. 이전에 시간초과(테스트1,3)문제가 있었는데 3진법 뒤집기처럼 진수변환시 num!=1을 피하니 시간초과문제 해결.
#include <string>
#include <vector>
#include<iostream>
using namespace std;

string makeBinary(int num, int n){
    string an="";
    while(num){ // 시간초과문제 관련 수정
        int temp = num%2;
        num/=2;
        an=to_string(temp)+an;
    }
    //an='1'+an;
    while(an.size()!=n){
        an='0'+an;
    }
    return an;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0;i<n;i++){
        string temp1=""; int num1=arr1[i];
        string temp2=""; int num2=arr2[i];
        while(num1!=0){ // 시간초과문제 관련 수정
            int temp = num1%2;
            num1/=2;
            temp1=to_string(temp)+temp1;
        }
        //temp1='1'+temp1;
        while(temp1.size()!=n){
            temp1='0'+temp1;
        }
        while(num2!=0){ // 시간초과문제 관련 수정
            int temp = num2%2;
            num2/=2;
            temp2=to_string(temp)+temp2;
        }
        //temp2='1'+temp2;
        while(temp2.size()!=n){
            temp2='0'+temp2;
        }

        string tempStr="";
        for(int j=0;j<n;j++){
            if(temp1[j]=='0'&&temp2[j]=='0') tempStr+=" ";
            else tempStr+="#";
        }
        answer.push_back(tempStr);
    }
    return answer;
}
/*
테스트 1 〉	통과 (0.03ms, 4.27MB)
테스트 2 〉	통과 (0.06ms, 3.66MB)
테스트 3 〉	통과 (0.02ms, 3.74MB)
테스트 4 〉	통과 (0.04ms, 4.32MB)
테스트 5 〉	통과 (0.03ms, 4.27MB)
테스트 6 〉	통과 (0.04ms, 3.87MB)
테스트 7 〉	통과 (0.03ms, 4.32MB)
테스트 8 〉	통과 (0.03ms, 4.33MB)
 */
