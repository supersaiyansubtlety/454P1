//
//  main.cpp
//  454P1
//
//  Created by student on 2/15/19.
//  Copyright © 2019 Will-Martin. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "DFA-master/DFA.cpp"
#include </usr/local/include/gmp.h>
//#include "/Users/willlucic/Documents/Education/SSU/CS_454/454P1/454P1/DFA-master/DFA.h"

using namespace std;

enum states {e, a, b, c, ab, ac, ba, bc, ca, cb, aa, bb, cc, abc, acb, bac, bca, cab, cba, aab, aba, abb, aac, aca, acc, baa, bab, bba, bbc, bcb, bcc, caa, cac, cca, cbb, cbc, ccb, BAD};

int k;
string alphabet;
////string alphabet = "abc";
int delta(int curState, int character);

int main(int argc, const char * argv[])
{
//        int n;
//
//        cout << "enter a numer";
//        cin >> n;
//        string input;
//
//        int transitions[41][3] =
//                {
//                        {a,b,c},
//                        {aa,ab,ac},
//                        {ba,bb,bc},
//                        {ca,cb,cc},
//                        {aba,abb,abc},
//                        {aca,acb,acc},
//                        {baa,bab,bac},
//                        {bca,bcb,bcc},
//                        {caa,cab,cac},
//                        {cba,cbb,cbc},
//                        {BAD,aab,aac},
//                        {bba,BAD,bbc},
//                        {cca,ccb,BAD},
//                        {bca,bcb,bcc},
//                        {cba,cbb,cbc},
//                        {aca,acb,acc},
//                        {caa,cab,cac},
//                        {aba,abb,abc},
//                        {baa,bab,bac},
//                        {BAD,BAD,abc},
//                        {BAD,BAD,bac},
//                        {BAD,BAD,bbc},
//                        {BAD,acb,BAD},
//                        {BAD,cab,BAD},
//                        {BAD,acb,BAD},
//                        {BAD,BAD,aac},
//                        {BAD,BAD,abc},
//                        {BAD,BAD,bac},
//                        {bca,BAD,BAD},
//                        {cba,BAD,BAD},
//                        {cca,BAD,BAD},
//                        {BAD,aab,BAD},
//                        {BAD,acb,BAD},
//                        {BAD,cab,BAD},
//                        {bba,BAD,BAD},
//                        {bca,BAD,BAD},
//                        {cba,BAD,BAD},
//                        {BAD,BAD,BAD}
//                };
//
//    //    while (input != "0")
//    //    {
//    //    cout << "enter a string input: ";
//    //    cin >> input;
//    //
//    //    int curInp = finput[0] - 'a';
//    //    int curState = 0;
//    //    for (int i = 1; i < input.size(); i++)
//    //    {
//    //        curState = transitions[curState][curInp];
//    //        curInp = input[i]-'a';
//    //    }
//    //    cout << curState << endl;}
//
//
//        mpz_t currentCount = currentCount[BAD+1];
//        mpz_t nextCount[BAD+1];
//
//        for (int i = 0; i < BAD; i++)
//        {
//            currentCount[i] = 1;
//            nextCount[i] = 0;
//        }
//        currentCount[BAD] = 0;
//
//        for(int i = 0; i < n; i++){
//
//            for (int st = 0; st < BAD; st++)
//            {
//                for (int let = 'a'-'a'; let <= 'c'-'a'; let++)
//                {
//                    if (transitions[st][let] != BAD)
//                    {
//                        nextCount[st] += currentCount[st];
//                    }
//                }
//            }
//
//            for (int i = 0; i < BAD; i++)
//            {
//                currentCount[i] = nextCount[i];
//                nextCount[i] = 0;
//            }
//
//        }
//
//        cout << currentCount[0] << endl;

        /*
         -
         -
         -
         -
         -
         -
         -
         -
         -
         -
         */
    
    
    cout << "Enter and integer k: ";
    cin >> k;
    cout << "Enter the digits to be included in the multiple of k: ";
    cin >> alphabet;
    
    //    int states[k];
    //int p2transitions[k][alphabet.size()];
    
    //    for (int i = 0; i < k ; i++)
    //    {
    //        for (int j = 0; j < alphabet.size(); j++)
    //        {
    //            p2transitions[i][j] = delta(i, j);
    //        }
    //    }
    
    
    
    queue<int> que;
    
    vector<int>visited(k+1);
    for (int i = 0; i < k+1; i++)
    {
        visited[i] = false;
        //cout << visited[i];
    }
    visited.at(0) = true; //(start state’s visited status is set to true.)
    
    vector<int> PARENT, LABEL;
    
    que.push(k);//insert k into QUEUE; //que is not pushing k or any value... size is still 0 after this line
    int curr = 0;
    int next = 0;
    while (!que.empty())//QUEUE is not empty):
    {
        curr = que.front();
        que.pop();
        for (auto c : alphabet)//for each c in R do:
        {
            next = delta(curr, c);//next = delta(curr,c); // Recall delta(q, r) = (10×q+r)%k.
            if (next == 0)//: // accepting state reached
                break;
            else if (!visited[next])
            {
                
                visited[next] = true;
                
                PARENT.push_back(curr);
                LABEL.push_back(c);
                que.push(next);
            }
        }
    }
    
    if (next != 0)
        cout << "No solution" << endl;//output “no “solution // or null-string so that the return type will always be a string
    else
    {
        string answer = "";
        long curState = PARENT.size() - 1;
        while (curState > 0)
        {
            //trace the string using PARENT pointers and concatenate LABEL symbols as you trace until start state is reached.
            answer += LABEL[curState];
            curState = PARENT[curState];
        }
        //output the string.
        cout << answer << endl;
        
    }
    return 0;
}

int delta(int curState, int character)
{
    if (character == k) return 0;
    return (10*curState + character)%k;
}
