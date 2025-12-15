#include <map>
#include <string>
#include <fstream>
using namespace std;

class WordCounter
{
    map<string, int> words;

    bool isLetter(char c);
    string toLowerStr(const string& s);

public:
    void loadFromFile(const string& file);
    void printAll();
    string getTopWord();
    int getTopCount();
    void saveToFile(const string& file);
};
