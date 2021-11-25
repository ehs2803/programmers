// level2
// 성공. 구현.
#include <iostream>
#include<vector>
using namespace std;

int solution(int n, int a, int b)
{
    int round=0;
    vector<int> Game;
    vector<int> nextGame;
    for(int i=1;i<=n;i++) Game.push_back(i);

    while(1){
        bool check= false;
        round++;
        for(int i=0;i<Game.size();){
            if(i%2==0){
                if((Game[i]==a&&Game[i+1]==b)||(Game[i]==b&&Game[i+1]==a)) {
                    check= true;
                    break;
                }
                if(Game[i]==a || Game[i]==b){
                    nextGame.push_back(Game[i]);
                }
                else if(Game[i+1]==a || Game[i+1]==b){
                    nextGame.push_back(Game[i+1]);
                }
                else{
                    nextGame.push_back(Game[i+1]);
                }
                i+=2;
            }
        }
        if(check) break;

        Game.clear();
        for(int i=0;i<nextGame.size();i++) Game.push_back(nextGame[i]);
        nextGame.clear();
    }

    return round;
}
/*
정확성  테스트
테스트 1 〉	통과 (0.01ms, 4.32MB)
테스트 2 〉	통과 (0.01ms, 4.2MB)
테스트 3 〉	통과 (0.01ms, 4.2MB)
테스트 4 〉	통과 (0.01ms, 3.66MB)
테스트 5 〉	통과 (0.02ms, 3.75MB)
테스트 6 〉	통과 (0.01ms, 3.67MB)
테스트 7 〉	통과 (0.01ms, 4.33MB)
테스트 8 〉	통과 (0.02ms, 4.26MB)
테스트 9 〉	통과 (0.02ms, 4.33MB)
테스트 10 〉	통과 (0.02ms, 4.27MB)
테스트 11 〉	통과 (0.04ms, 4.34MB)
테스트 12 〉	통과 (0.04ms, 3.62MB)
테스트 13 〉	통과 (0.04ms, 3.68MB)
테스트 14 〉	통과 (0.04ms, 4.27MB)
테스트 15 〉	통과 (0.04ms, 4.38MB)
테스트 16 〉	통과 (0.04ms, 4.27MB)
테스트 17 〉	통과 (0.04ms, 4.32MB)
테스트 18 〉	통과 (0.04ms, 4.27MB)
테스트 19 〉	통과 (0.04ms, 3.69MB)
테스트 20 〉	통과 (0.04ms, 4.33MB)
테스트 21 〉	통과 (0.04ms, 4.2MB)
테스트 22 〉	통과 (0.04ms, 4.32MB)
테스트 23 〉	통과 (0.04ms, 4.33MB)
테스트 24 〉	통과 (0.04ms, 4.26MB)
테스트 25 〉	통과 (0.01ms, 4.21MB)
테스트 26 〉	통과 (0.02ms, 4.33MB)
테스트 27 〉	통과 (11.19ms, 11.2MB)
테스트 28 〉	통과 (10.60ms, 11.2MB)
테스트 29 〉	통과 (9.58ms, 11.2MB)
테스트 30 〉	통과 (9.43ms, 11.2MB)
테스트 31 〉	통과 (10.19ms, 11.2MB)
테스트 32 〉	통과 (9.73ms, 11.2MB)
테스트 33 〉	통과 (11.00ms, 11.2MB)
테스트 34 〉	통과 (9.55ms, 11.2MB)
 */
