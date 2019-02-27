//
//  main.cpp
//  454P1
//
//  Created by student on 2/15/19.
//  Copyright © 2019 Will-Martin. All rights reserved.
//

#include <iostream>
#include <string>
#include "DFA-master/DFA.cpp"
//#include "/Users/willlucic/Documents/Education/SSU/CS_454/454P1/454P1/DFA-master/DFA.h"

using namespace std;

enum states {e, a, b, c, ab, ac, ba, bc, ca, cb, aa, bb, cc, abc, acb, bac, bca, cab, cba, aab, aba, abb, aac, aca, acc, baa, bab, bba, bbc, bcb, bcc, caa, cac, cca, cbb, cbc, ccb, BAD};

string alphabet = "abc";

int main(int argc, const char * argv[])
{
    int n;
    
    cout << "enter a numer";
    cin >> n;
    string input;
    
    int transitions[41][3] =
    {
        {a,b,c},
        {aa,ab,ac},
        {ba,bb,bc},
        {ca,cb,cc},
        {aba,abb,abc},
        {aca,acb,acc},
        {baa,bab,bac},
        {bca,bcb,bcc},
        {caa,cab,cac},
        {cba,cbb,cbc},
        {BAD,aab,aac},
        {bba,BAD,bbc},
        {cca,ccb,BAD},
        {bca,bcb,bcc},
        {cba,cbb,cbc},
        {aca,acb,acc},
        {caa,cab,cac},
        {aba,abb,abc},
        {baa,bab,bac},
        {BAD,BAD,abc},
        {BAD,BAD,bac},
        {BAD,BAD,bbc},
        {BAD,acb,BAD},
        {BAD,cab,BAD},
        {BAD,acb,BAD},
        {BAD,BAD,aac},
        {BAD,BAD,abc},
        {BAD,BAD,bac},
        {bca,BAD,BAD},
        {cba,BAD,BAD},
        {cca,BAD,BAD},
        {BAD,aab,BAD},
        {BAD,acb,BAD},
        {BAD,cab,BAD},
        {bba,BAD,BAD},
        {bca,BAD,BAD},
        {cba,BAD,BAD},
        {BAD,BAD,BAD}
    };
    
//    while (input != "0")
//    {
//    cout << "enter a string input: ";
//    cin >> input;
//
//    int curInp = input[0] - 'a';
//    int curState = 0;
//    for (int i = 1; i < input.size(); i++)
//    {
//        curState = transitions[curState][curInp];
//        curInp = input[i]-'a';
//    }
//    cout << curState << endl;}
    
    
    long int currentCount[BAD+1];
    long int nextCount[BAD+1];

    for (int i = 0; i < BAD; i++)
    {
        currentCount[i] = 1;
        nextCount[i] = 0;
    }
    currentCount[BAD] = 0;

    for(int i = 0; i < n; i++){

        for (int st = 0; st < BAD; st++)
        {
            for (int let = 'a'-'a'; let <= 'c'-'a'; let++)
            {
                if (transitions[st][let] != BAD)
                {
                    nextCount[st] += currentCount[st];
                }
            }
        }

        for (int i = 0; i < BAD; i++)
        {
            currentCount[i] = nextCount[i];
            nextCount[i] = 0;
        }

    }
    
    cout << currentCount[0] << endl;
    return 0;
}
