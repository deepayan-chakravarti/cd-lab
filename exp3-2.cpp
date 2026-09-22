#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> keywords = {
    "int","float","double","char","if","else","for","while","do",
    "switch","case","break","continue","return","void","struct",
    "static","const"
};

bool isKeyword(const string &word) {
    for (const string &k : keywords) {
        if (word == k) return true;
    }
    return false;
}

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    if (isKeyword(word))
        cout << word << " is a keyword\n";
    else
        cout << word << " is an identifier\n";

    return 0;
}