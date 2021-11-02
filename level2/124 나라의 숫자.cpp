// level2
// Created by nec on 2021-11-02.
// 성공. 수학.
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int reminder;

    while(n>0){
        reminder = n%3;
        n = n/3;

        if(reminder==0){
            n-=1;
            reminder=4;
        }

        answer = to_string(reminder) + answer;
    }
    return answer;
}
