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

using namespace std;

int main(int argc, const char * argv[])
{
    map<pair<int, char>, int> transitions =
    {
        {{e,a},a},
        {{a,a},aa},
        {{b,a},ba},
        {{c,a},ca},
        {{ab,a},aba},
        {{ac,a},aca},
        {{ba,a},baa},
        {{bc,a},bca},
        {{ca,a},caa},
        {{cb,a},cba},
        {{aa,a},aaa},
        {{bb,a},bba},
        {{cc,a},cca},
        {{abc,a},bca},
        {{acb,a},cba},
        {{bac,a},aca},
        {{bca,a},caa},
        {{cab,a},aba},
        {{cba,a},baa},
        {{aab,a},BAD},
        {{aba,a},BAD},
        {{abb,a},BAD},
        {{baa,a},BAD},
        {{bab,a},BAD},
        {{bba,a},BAD},
        {{caa,a},BAD},
        {{cac,a},BAD},
        {{cca,a},BAD},
        {{aaa,a},BAD},
        {{bbb,a},BAD},
        {{ccc,a},BAD},
        {{BAD,a},BAD}
        
    };
    
    return 0;
}
int transitionTable(int n){
    vector<int> prev{40};
    vector<int> cur{40};
    for (auto iter = map.begin(); iter != map.end(); iter++)
        for(
}
