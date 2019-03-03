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
#include <utility> //make_pair
#include <gmpxx.h>
#include <stdlib.h> // malloc
//#include "linked_list.hpp"
#include "tree.hpp" //tree and treeNode

#define integer mpz_t

using namespace std;

enum states {e, a, b, c, ab, ac, ba, bc, ca, cb, aa, bb, cc, abc, acb, bac, bca, cab, cba, aab, aba, abb, aac, aca, acc, baa, bab, bba, bbc, bcb, bcc, caa, cac, cca, cbb, cbc, ccb, BAD};

int delta(int curState, int character, int k);

int main(int argc, const char * argv[])
{
    int n;
    
    cout << "enter a number: ";
    cin >> n;
    string input;
    
    int transitions[BAD+1][3] =
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
        {BAD,ccb,BAD},
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
    
    int initializer[BAD+1]  = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
    integer currentCount[BAD+1];
    integer nextCount[BAD+1];

    for (int i = 0; i <= BAD; i++)
    {
        mpz_init(currentCount[i]);
        mpz_init(nextCount[i]);
    }
    for (int i = 0; i <= BAD; i++)
    {
        mpz_set_si(currentCount[i], initializer[i]);
    }
    mpz_init2(currentCount[BAD], 0);

    for(int i = 0; i < n; i++)
    {
        for (int st = 0; st < BAD; st++)
        {
            for (int let = 'a'-'a'; let <= 'c'-'a'; let++)
            {
                if ((transitions[st][let] != BAD))
                {
                    mpz_add(nextCount[st], nextCount[st], currentCount[st]);
                }
            }
        }

        for (int i = 0; i < BAD; i++)
        {
            mpz_set(currentCount[i], nextCount[i]);
            mpz_set_si(nextCount[i], 0);
        }

    }
    
    cout << "answer: " << endl << "6119266976149912241614898841866546736" << endl << "found:" << endl << currentCount[0] << endl;
    
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
    
    int k;
    string alphaString;
    
    cout << "Enter and integer k: ";
    cin >> k;
    cout << "Enter the digits to be included in the multiple of k: ";
    cin >> alphaString;
    
    vector<int> alphabet;
    for (auto c: alphaString)
    {
        alphabet.push_back(c-'0');
    }
    
    queue<pair<int, treeNode<int>*> > Q;
    
    vector<bool> visited;
    visited.push_back(true); //(start state’s visited status is set to true.)
    for (int i = 0; i < k; i++)
    {
        visited.push_back(false);
    }

    tree<int> ParentLabel;
    
    Q.push(make_pair(0, ParentLabel.getRoot()));//insert k into QUEUE;
    pair<int, treeNode<int>*> current = make_pair(0, ParentLabel.getRoot());
    auto& [cur_val, cur_parent] = current;
    //same as:
//    int& cur_val = current.first;
//    treeNode<int>* T = current.second;
    int next = 0;
    while (!Q.empty())//QUEUE is not empty):
    {
        if (next == 0) { break; }//accept state reached
        current = Q.front();
        Q.pop();

        for (auto c : alphabet)//for each c in R do:
        {
            next = delta(cur_val, c, k);
            if (next == 0)// accepting state reached
                break;
            else if (!visited[next])
            {
                visited[next] = true;

                Q.push(make_pair
                (
                    next,
                    ParentLabel.add(cur_parent, c - '0'))
                );
            }
        }
    }
    
    //output “no “solution // or null-string so that the return type will always be a string
    if (next != 0) { cout << "No solution" << endl; }
    else
    {
        string answer = "";
        treeNode<int>* parent = cur_parent;
        while (parent)
        {
            //trace the string using PARENT pointers and concatenate LABEL symbols as you trace until start state is reached.
            answer += (parent->getValue() + '0');
            parent = parent->getParent();
        }
        //output the string.
        cout << answer << endl;
            
    }
    return 0;
}

int delta(int curState, int character, int k)
{
    return (10*curState + character)%k;
}
