//
//  main.cpp
//  454P1
//
//  Created by student on 2/15/19.
//  Copyright © 2019 Will-Martin. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm> //reverse
#include <queue>
#include <vector>
#include <gmpxx.h>
#include <stdlib.h> // malloc
#include "linked_list.hpp"
#include "tree.hpp"

#define integer mpz_t

using namespace std;

enum states {e, a, b, c, ab, ac, ba, bc, ca, cb, aa, bb, cc, abc, acb, bac, bca, cab, cba, aab, aba, abb, aac, aca, acc, baa, bab, bba, bbc, bcb, bcc, caa, cac, cca, cbb, cbc, ccb, BAD};

//string alphabet = "abc";
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
    integer currentCount[BAD+1];// = malloc((BAD+1) * sizeof(mpz_t));
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

    
//    int states[k];
    //int p2transitions[k][alphabet.size()];
    
//    for (int i = 0; i < k ; i++)
//    {
//        for (int j = 0; j < alphabet.size(); j++)
//        {
//            p2transitions[i][j] = delta(i, j);
//        }
//    }
    
    
    
    queue<pair<int, Node*> > Q;
    
    vector<bool> visited; //(start state’s visited status is set to true.)
    
    for (int i = 0; i < k-1; i++)
    {
        visited.push_back(false);
    }
    visited.push_back(true);
    
    LinkedList ParentLabel;
    
    Q.push(make_pair(k, ParentLabel.head));//insert k into QUEUE;
    pair<int, Node*> current = Q.front();
    auto& [cur_val, cur_parent] = current;
    int next = 1;
    while (!Q.empty())//QUEUE is not empty):
    {
        if (next == 0) { break; }
        current = Q.front();
        Q.pop();
        for (auto c : alphabet)//for each c in R do:
        {
            next = delta(cur_val, c, k);//next = delta(curr,c); // Recall delta(q, r) = (10×q+r)%k.
            if (next == 0) // accepting state reached
            {
                ParentLabel.add(c, cur_parent);
                break;
            }
            else if (!visited[next])
            {
                
                visited[next] = true;

//                PARENT.push_back(curr);
//                LABEL.push_back(c);
                ParentLabel.add(c, cur_parent);
                Q.push(make_pair
                    (
                        next,
                        ParentLabel.head
                    )
                );
            }
        }
    }
                    
    if (next != 0)
        cout << "No solution" << endl;//output “no “solution // or null-string so that the return type will always be a string
    else
    {
        string answer = "";
        //int curState = PARENT.size() - 1;
        Node* cur_parent = ParentLabel.head;
        while (cur_parent)
        {
            //trace the string using PARENT pointers and concatenate LABEL symbols as you trace until start state is reached.
            answer += cur_parent->data+'0';
            cur_parent = cur_parent->parent;
        }
        //output the string.
        
        reverse(answer.begin(), answer.end());
        cout << answer << endl;
            
    }
    return 0;
}

int delta(int curState, int character, int k)
{
//    if (character == k) return 0;
    return (10*curState + character)%k;
}
