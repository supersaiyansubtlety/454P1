//
//  main.cpp
//  454P1
//
//  Created by student on 2/15/19.
//  Copyright © 2019 Will-Martin. All rights reserved.
//

#include <iostream>
#include <map>
#include <utility>
#include <string>

using namespace std;

enum states {e,a,b,c,ab,ac,ba,bc,ca,cb,aa,bb,cc,abc,acb,bac,bca,cab,cba,aab,aba,abb,aac,aca,baa,bab,bba,bbc,bcb,caa,cac,cca,aaa,bbb,ccc,BAD};

string alphabet = "abc";

int N(int length);

int main(int argc, const char * argv[])
{
    map<pair<int, char>, int> transitions =
    {
        {{e,'a'},a},
        {{a,'a'},aa},
        {{b,'a'},ba},
        {{c,'a'},ca},
        {{ab,'a'},aba},
        {{ac,'a'},aca},
        {{ba,'a'},baa},
        {{bc,'a'},bca},
        {{ca,'a'},caa},
        {{cb,'a'},cba},
        {{aa,'a'},aaa},
        {{bb,'a'},bba},
        {{cc,'a'},cca},
        {{abc,'a'},bca},
        {{acb,'a'},cba},
        {{bac,'a'},aca},
        {{bca,'a'},caa},
        {{cab,'a'},aba},
        {{cba,'a'},baa},
        {{aab,'a'},BAD},
        {{aba,'a'},BAD},
        {{abb,'a'},BAD},
        {{aac,'a'},BAD},
        {{aca,'a'},BAD},
        {{baa,'a'},BAD},
        {{bab,'a'},BAD},
        {{bba,'a'},BAD},
        {{bbc,'a'},BAD},
        {{bcb,'a'},cba},
        {{caa,'a'},BAD},
        {{cac,'a'},BAD},
        {{cca,'a'},BAD},
        {{aaa,'a'},BAD},
        {{bbb,'a'},BAD},
        {{ccc,'a'},BAD},
        {{BAD,'a'},BAD},
        
        {{e,'b'},b},
        {{a,'b'},ab},
        {{b,'b'},bb},
        {{c,'b'},cb},
        {{ab,'b'},abb},
        {{ac,'b'},acb},
        {{ba,'b'},bab},
        {{bc,'b'},bcb},
        {{ca,'b'},cab},
        {{cb,'b'},cbb},
        {{aa,'b'},aab},
        {{bb,'b'},bbb},
        {{cc,'b'},ccb},
        {{abc,'b'},bcb},
        {{acb,'b'},cbb},
        {{bac,'b'},acb},
        {{bca,'b'},cab},
        {{cab,'b'},abb},
        {{cba,'b'},bab},
        {{aab,'b'},BAD},
        {{aba,'b'},BAD},
        {{abb,'b'},BAD},
        {{aac,'b'},acb},
        {{aca,'b'},cab},
        {{baa,'b'},BAD},
        {{bab,'b'},BAD},
        {{bba,'b'},BAD},
        {{bbc,'b'},BAD},
        {{bcb,'b'},BAD},
        {{caa,'b'},aab},
        {{cac,'b'},acb},
        {{cca,'b'},cab},
        {{cbc,'b'},BAD},
        {{ccb,'b'},BAD},
        {{aaa,'b'},BAD},
        {{bbb,'b'},BAD},
        {{ccc,'b'},BAD},
        {{BAD,'b'},BAD}
    };
    
    int transitions[38][3]={};
    
    return 0;
}


int N(int length)
{
    int currentCount[38];
    int nextCount[38];
    
    for (int i = 0; i < 38; i++)
    {
        currentCount[i] = 1;
        nextCount[i] = 0;
    }
    currentCount[37] = 0;
    
    
    
    for (int st = 0; state < 38; state++)
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
}
