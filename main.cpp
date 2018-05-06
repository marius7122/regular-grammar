#include <iostream>
#include "RG.h"

using namespace std;


int main()
{
    RG rg;

    rg.readFromFile("rg.txt");

    rg.testWordsFromFile("words.txt");

    return 0;
}
