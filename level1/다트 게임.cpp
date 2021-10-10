// level1
// 성공. 구현, string
#include <string>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int preScore = 0;
    int index=0;
    while(true){
        if(dartResult.substr(index,2)=="10"){
            if(index+3<=dartResult.size()-1 && (dartResult[index+2]=='*'||dartResult[index+2]=='#')){
                string result = dartResult.substr(index,4);
                int score = 10;
                int resultscore;
                if(result[2]=='S'){
                    resultscore = pow(score, 1);
                }
                else if(result[2]=='D'){
                    resultscore = pow(score, 2);
                }
                else if(result[2]=='T'){
                    resultscore = pow(score, 3);
                }

                if(result[3]=='*'){
                    resultscore*=2;
                    answer -= preScore;
                    answer += preScore*2;
                }
                else if(result[3]=='#'){
                    resultscore = -resultscore;
                    //answer -= preScore;
                    //answer += preScore*-1;
                }
                answer += resultscore;
                preScore = resultscore;

                index = index+4;
            }
            else{
                string result = dartResult.substr(index,3);
                int score = 10;
                int resultscore;
                if(result[2]=='S'){
                    resultscore = pow(score, 1);
                }
                else if(result[2]=='D'){
                    resultscore = pow(score, 2);
                }
                else if(result[2]=='T'){
                    resultscore = pow(score, 3);
                }
                answer += resultscore;
                preScore = resultscore;
                index = index+3;
            }
        }
        else if(index+2<=dartResult.size()-1 && (dartResult[index+2]=='*'||dartResult[index+2]=='#')){
            string result = dartResult.substr(index, 3);
            index = index + 3;
            int score = result[0]-'0';
            int resultscore;
            if(result[1]=='S'){
                resultscore = pow(score, 1);
            }
            else if(result[1]=='D'){
                resultscore = pow(score, 2);
            }
            else if(result[1]=='T'){
                resultscore = pow(score, 3);
            }

            if(result[2]=='*'){
                resultscore*=2;
                answer -= preScore;
                answer += preScore*2;
            }
            else if(result[2]=='#'){
                resultscore = -resultscore;
                //answer -= preScore;
                //answer += preScore*-1;
            }
            answer += resultscore;
            preScore = resultscore;
        }
        else if(index+1<=dartResult.size()-1){
            string result = dartResult.substr(index, 2);
            index = index +2;
            int score = result[0]-'0'; // 방법2
            int resultscore;
            if(result[1]=='S'){
                resultscore = pow(score, 1);
            }
            else if(result[1]=='D'){
                resultscore = pow(score, 2);
            }
            else if(result[1]=='T'){
                resultscore = pow(score, 3);
            }
            preScore = resultscore;
            answer+=resultscore;
        }
        else break;
        if(index>dartResult.size()-1) break;
    }
    return answer;
}
/*
테스트 1 〉	통과 (0.01ms, 4.32MB)
테스트 2 〉	통과 (0.01ms, 4.26MB)
테스트 3 〉	통과 (0.02ms, 4.27MB)
테스트 4 〉	통과 (0.01ms, 4.33MB)
테스트 5 〉	통과 (0.01ms, 4.31MB)
테스트 6 〉	통과 (0.01ms, 4.27MB)
테스트 7 〉	통과 (0.02ms, 4.32MB)
테스트 8 〉	통과 (0.02ms, 3.75MB)
테스트 9 〉	통과 (0.02ms, 3.8MB)
테스트 10 〉	통과 (0.02ms, 4.21MB)
테스트 11 〉	통과 (0.03ms, 4.21MB)
테스트 12 〉	통과 (0.02ms, 3.85MB)
테스트 13 〉	통과 (0.02ms, 3.85MB)
테스트 14 〉	통과 (0.02ms, 4.33MB)
테스트 15 〉	통과 (0.02ms, 4.27MB)
테스트 16 〉	통과 (0.02ms, 4.32MB)
테스트 17 〉	통과 (0.02ms, 4.28MB)
테스트 18 〉	통과 (0.02ms, 4.33MB)
테스트 19 〉	통과 (0.02ms, 4.26MB)
테스트 20 〉	통과 (0.02ms, 4.32MB)
테스트 21 〉	통과 (0.02ms, 4.33MB)
테스트 22 〉	통과 (0.02ms, 4.32MB)
테스트 23 〉	통과 (0.02ms, 4.27MB)
테스트 24 〉	통과 (0.02ms, 3.88MB)
테스트 25 〉	통과 (0.02ms, 4.32MB)
테스트 26 〉	통과 (0.02ms, 4.27MB)
테스트 27 〉	통과 (0.01ms, 4.33MB)
테스트 28 〉	통과 (0.02ms, 4.27MB)
테스트 29 〉	통과 (0.02ms, 4.32MB)
테스트 30 〉	통과 (0.02ms, 4.33MB)
테스트 31 〉	통과 (0.02ms, 3.69MB)
테스트 32 〉	통과 (0.02ms, 4.33MB)
 */