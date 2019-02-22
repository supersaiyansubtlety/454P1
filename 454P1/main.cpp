//
//  main.cpp
//  454P1
//
//  Created by student on 2/15/19.
//  Copyright © 2019 Will-Martin. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

enum states {a, b, c, ab, ac, ba, bc, ca, cb, aa, bb, cc, abc, acb, bac, bca, cab, cba, aab, aba, abb, aac, aca, acc, baa, bab, bba, bbc, bcb, bcc, caa, cac, cca, cbb, cbc, ccb, aaa, bbb, ccc, BAD};

string alphabet = "abc";

int main(int argc, const char * argv[])
{
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
        {aaa,aab,aac},
        {bba,bbb,bbc},
        {cca,ccb,ccc},
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
        {BAD,BAD,BAD},
        {BAD,BAD,BAD},
        {BAD,BAD,BAD},
        {BAD,BAD,BAD}
    };
    
    int currentCount[38];
    int nextCount[38];
    
    for (int i = 0; i < 38; i++)
    {
        currentCount[i] = 1;
        nextCount[i] = 0;
    }
    currentCount[37] = 0;
    
    
    
    for (int st = 0; st < 38; st++)
    {
        for (int let = 0; let < 3; let++)
        {
            if (transitions[st][let] != BAD)
            {
                nextCount[st] += currentCount[st];
            }
        }
    }
    
    for (int i = 0; i < 38; i++)
    {
        currentCount[i] = nextCount[i];
        nextCount[i] = 0;
    }
    
    return 0;
}
