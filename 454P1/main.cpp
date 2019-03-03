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
#include <gmpxx.h>
#include <stdlib.h> // malloc
#include "linked_list.hpp"
#include "tree.hpp"

#define integer mpz_t

using namespace std;

enum states {e, a, b, c, ab, ac, ba, bc, ca, cb, aa, bb, cc, abc, acb, bac, bca, cab, cba, aab, aba, abb, aac, aca, acc, baa, bab, bba, bbc, bcb, bcc, caa, cac, cca, cbb, cbc, ccb, BAD};

int k;
string alphabet;
//string alphabet = "abc";
int delta(int curState, int character);

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
    
    int initializer[BAD+1]  = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
    integer currentCount[BAD+1];// = malloc((BAD+1) * sizeof(mpz_t));
    //currentCount = (mpz_t *)malloc((BAD+1) * sizeof(mpz_t));//[BAD+1];
    integer nextCount[BAD+1];
    //nextCount = (mpz_t *)malloc((BAD+1) * sizeof(mpz_t));//[BAD+1];

    for (int i = 0; i <= BAD; i++)
    {
//        mpz_init(**(currentCount + (i*sizeof(mpz_t))));
//        mpz_set_si(**(currentCount + (i*sizeof(mpz_t))), initializer[i]);
//        mpz_init(**(nextCount + (i*sizeof(mpz_t))));
        mpz_init(currentCount[i]);
//        mpz_set_si(currentCount[i], initializer[i]);
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
    
    
    
    queue<pair<int, Node*> > Q;
    
    vector<int> visited(k+1);
    for (int i = 0; i < k+1; i++)
    {
        visited[i] = false;
    }
    
    
    visited[k] = true; //(start state’s visited status is set to true.)
    
    LinkedList ParentLabel;
//    Node* parent = ParentLabel.head;
    
    Q.push(make_pair(0, ParentLabel.head));//insert k into QUEUE;
    pair<int, Node*> current = make_pair(0, ParentLabel.head);
    auto& [cur_val, cur_parent] = current;
    int next = 0;
    while (!Q.empty())//QUEUE is not empty):
    {
        current = Q.front();
        Q.pop();
        for (auto c : alphabet)//for each c in R do:
        {
            next = delta(cur_val, c-'0');//next = delta(curr,c); // Recall delta(q, r) = (10×q+r)%k.
            if (next == 0)//: // accepting state reached
                break;
            else if (!visited[next])
            {
                
                visited[next] = true;

//                PARENT.push_back(curr);
//                LABEL.push_back(c);
                ParentLabel.add(c - '0', cur_parent);
                Q.push(make_pair
                    (
                        next-'0',
                        cur_parent
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
        Node* parent = cur_parent;
        while (parent)
        {
            //trace the string using PARENT pointers and concatenate LABEL symbols as you trace until start state is reached.
            answer += ParentLabel.head->data;
            parent = ParentLabel.head->parent;
        }
        //output the string.
        cout << answer << endl;
            
    }
    return 0;
}

int delta(int curState, int character)
{
//    if (character == k) return 0;
    return (10*curState + character)%k;
}
