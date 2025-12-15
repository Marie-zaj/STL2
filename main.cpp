#include <fstream>
#include <iostream>
#include "WordCounter.h"
using namespace std;

int main()
{
    WordCounter wc;

    wc.loadFromFile("C:\\Users\\Acer\\source\\repos\\WordCounter\\x64\\Debug\\input.txt");
    wc.printAll();

    cout << "\nMost used word: "
        << wc.getTopWord()
        << " (" << wc.getTopCount() << ")\n";

    wc.saveToFile("C:\\Users\\Acer\\source\\repos\\WordCounter\\WordCounter\\output.txt");

    cout << "\nSaved to file.\n";

    return 0;
}