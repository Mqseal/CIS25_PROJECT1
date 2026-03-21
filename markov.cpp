#include "markov.h"
#include <fstream>
#include <cstdlib>

using namespace std;

string joinWords(const string words[], int startIndex, int count)
{
    string result = "";

    for (int i = 0; i < count; i++)
    {
        result += words[startIndex + i];

        if (i < count - 1)
        {
            result += " ";
        }
    }

    return result;
}

int readWordsFromFile(string filename, string words[], int maxWords)
{
    ifstream inputFile(filename);

    int count = 0;

    while (count < maxWords && inputFile >> words[count])
    {
        count++;
    }

    inputFile.close();
    return count;
}

int buildMarkovChain(const string words[], int numWords, int order,
                     string prefixes[], string suffixes[],
                     int maxChainSize)
{
    int count = 0;

    for (int i = 0; i < numWords - order; i++)
    {
        if (count >= maxChainSize)
        {
            break;
        }

        prefixes[count] = joinWords(words, i, order);
        suffixes[count] = words[i + order];
        count++;
    }

    return count;
}

string getRandomSuffix(const string prefixes[], const string suffixes[],
                       int chainSize, string currentPrefix)


string getRandomPrefix(const string prefixes[], int chainSize)


string generateText(const string prefixes[], const string suffixes[],
                    int chainSize, int order, int numWords)