#include <iostream>
#include <cstdlib>
#include <ctime>
#include "markov.h"

using namespace std;

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


    return 0;
}