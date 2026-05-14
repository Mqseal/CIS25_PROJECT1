#include <iostream>
#include <cstdlib>
#include <ctime>
#include "markov.h"

using namespace std;

const int MAX_WORDS = 10000;
const int MAX_CHAIN = 10000;

string words[MAX_WORDS];
string prefixes[MAX_CHAIN];
string suffixes[MAX_CHAIN];

int main()
{
    srand(time(0));

    string filename;
    int order;
    int numWords;

    cout << "Enter input filename: ";
    cin >> filename;

    cout << "Enter order (1, 2, or 3): ";
    cin >> order;

    cout << "Enter number of words to generate: ";
    cin >> numWords;

    if (order < 1 || order > 3)
    {
        cout << "Invalid order. Use 1, 2, or 3." << endl;
        return 1;
    }

    int wordCount = readWordsFromFile(filename, words, MAX_WORDS);

    if (wordCount == -1)
    {
        cout << "Could not open file." << endl;
        return 1;
    }

    if (wordCount <= order)
    {
        cout << "Not enough words in the file." << endl;
        return 1;
    }

    int chainSize = buildMarkovChain(words, wordCount, order, prefixes, suffixes, MAX_CHAIN);

    if (chainSize <= 0)
    {
        cout << "Chain is empty." << endl;
        return 1;
    }

    string output = generateText(prefixes, suffixes, chainSize, order, numWords);

    cout << endl;
    cout << "Generated text:" << endl;
    cout << output << endl;

    return 0;
}
