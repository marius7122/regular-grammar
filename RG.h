#ifndef RG_H_INCLUDED
#define RG_H_INCLUDED

/**
 * READ FORMAT:
 * line 1: N (ex: ABCS)
 * line 2: T (ex: abc)
 * next lines: production rules (ex: S aS)      //eps - null string
**/

#include <map>
#include <string>

using namespace std;

class RG
{
    string N, T;
    map<pair<char, char>, char> trans;
    map<char, bool> isFinal;
    bool isLeftRegular;

public:
    void readFromFile(const string &fileName);
    bool wordIsCorrect(string s);
    bool testWord(string s);
    void testWordsFromFile(const string &fileName);
    void afis();

};


#endif // RG_H_INCLUDED
