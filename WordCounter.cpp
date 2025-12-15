#include "WordCounter.h"
#include <iostream>
using namespace std;

bool WordCounter::isLetter(char c)
{
    return (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9');
}

string WordCounter::toLowerStr(const string& s)
{
    string out = s;
    for (size_t i = 0; i < out.size(); i++)
    {
        if (out[i] >='A' && out[i] <= 'Z')
            out[i] = out[i] - 'A' + 'a';
    }
    return out;
}

void WordCounter::loadFromFile(const string& file)
{
    ifstream fin(file);
    if (!fin.is_open())
    {
        cout << "Can't open file!\n";
        return;
    }
    string w = "";
    char c;

    while (fin.get(c))
    {
        cout << c;
        if (isLetter(c))
        {
            w += c;
        }
        else
        {
            if (!w.empty())
            {
                w = toLowerStr(w);
                words[w]++;
                w.clear();
            }
        }
    }
    if (!w.empty())
    {
        w = toLowerStr(w);
        words[w]++;
    }

    fin.close();
    cout << endl;
}

void WordCounter::printAll()
{
    cout << "Words:\n";
    for (auto& p : words)
        cout << p.first << " = " << p.second << endl;
}

string WordCounter::getTopWord()
{
    string top = "";
    int count = 0;

    for (auto& p : words)
    {
        if (p.second > count)
        {
            count = p.second;
            top = p.first;
        }
    }
    return top;
}

int WordCounter::getTopCount()
{
    int count = 0;
    for (auto& p : words)
        if (p.second > count)
            count =p.second;
   return count;
}

void WordCounter::saveToFile(const string& file)
{
    ofstream fout(file);
    if (!fout.is_open())
    {
        cout << "Can't write file!\n";
        return;
    }

    fout << "Words:\n";
    for (auto& p : words)
        fout << p.first << " = " << p.second << "\n";

    fout << "\nMost used word: " << getTopWord()
        << " (" <<getTopCount() <<")\n";

    fout.close();
}

