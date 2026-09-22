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

vector<string> tokenize(const string &text) {
    vector<string> tokens;
    string current = "";
    for (char c : text) {
        if (isalnum(c) || c == '_') {
            current += c;
        } else {
            if (!current.empty()) {
                tokens.push_back(current);
                current = "";
            }
        }
    }
    if (!current.empty()) tokens.push_back(current);
    return tokens;
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    int count = 0;
    for (const string &token : tokenize(sentence)) {
        if (isKeyword(token)) count++;
    }

    cout << "Number of keywords = " << count << "\n";
    return 0;
}