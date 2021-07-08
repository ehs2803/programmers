#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int Adata[5]={1,2,3,4,5};
    int Bdata[8]={2,1,2,3,2,4,2,5};
    int Cdata[10]={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int Acount=0, Bcount=0, Ccount=0;
    int k=0;
    for(int i=0;i<answers.size();i++){
        if(i%5==0) k=0;
        if(answers[i]==Adata[k]) Acount++;
        k++;
    }
    k=0;
    for(int i=0;i<answers.size();i++){
        if(i%8==0) k=0;
        if(answers[i]==Bdata[k]) Bcount++;
        k++;   
    }
    k=0;
    for(int i=0;i<answers.size();i++){
        if(i%10==0) k=0;
        if(answers[i]==Cdata[k]) Ccount++;
        k++;
    }
 
    if(Acount==Bcount){
        if(Acount>Ccount) {
            answer.push_back(1);
            answer.push_back(2);
        }
        else if(Acount==Ccount){
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
        else {
            answer.push_back(3);
        }
    }
    else if(Acount>Bcount){
        if(Acount==Ccount){
            answer.push_back(1);
            answer.push_back(3);
        }
        else if(Acount>Ccount) answer.push_back(1);
        else answer.push_back(3);
    }
    else{
        if(Bcount==Ccount){
            answer.push_back(2);
            answer.push_back(3);
        }
        else if(Bcount>Ccount) answer.push_back(2);
        else answer.push_back(3);
    }
    return answer;
}
