#include "RG.h"

#include <iostream>
#include <fstream>

bool isUpper(char c)
{
    return c >= 'A' && c <= 'Z';
}

bool isLower(char c)
{
    return c >= 'a' && c <= 'z';
}

void RG::readFromFile(const string &fileName)
{
    ifstream fin(fileName);

    fin>>N>>T;

    isLeftRegular = false;
    string x, y;
    while(fin>>x>>y)
    {
        if(y == "eps")
        {
            isFinal[x[0]] = true;
            continue;
        }

        if(isUpper(y[0]))
        {
            isLeftRegular = true;
            swap(y[0], y[1]);
        }

        if(y.length() == 2)
            trans[{x[0], y[0]}] = y[1];
        else
            isFinal[x[0]] = true;
    }

    fin.close();
}

void reverse(string &s)
{
    int i, j;
    i = 0;
    j = s.length()-1;

    while(i < j)
    {
        swap(s[i], s[j]);
        i++; j--;
    }
}

bool RG::wordIsCorrect(string s)
{
    for(char c : s)
        if(T.find(c) == string::npos)
        {
            return false;
        }
    return true;
}

bool RG::testWord(string s)
{
    if(wordIsCorrect(s) == false)
    {
        cout<<"cuvantul nu este corect ";
        return false;
    }

    if(s.length() == 0)
        return false;

    if(isLeftRegular)
        reverse(s);

    char state = 'S';

    for(char c : s)
        state = trans[{state, c}];

    return isFinal[state] || isLower(state);
}

void RG::testWordsFromFile(const string &fileName)
{
    ifstream fin(fileName);

    string w;

    while(fin>>w)
        cout<<w<<' '<<testWord(w)<<'\n';

    fin.close();
}

void RG::afis()
{
    for(auto x : trans)
        cout<<x.first.first<<'+'<<x.first.second<<'='<<x.second<<'\n';

    cout<<"\n";

    for(auto x : isFinal)
        cout<<x.first<<" is final\n";
}
