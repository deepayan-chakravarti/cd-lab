#include <iostream>
#include <vector>
#include <string>
#include <map>
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
    string paragraph;
    cout << "Enter a paragraph: ";
    getline(cin, paragraph);

    map<string, int> counts;
    for (const string &token : tokenize(paragraph)) {
        if (isKeyword(token)) counts[token]++;
    }

    for (const auto &pair : counts) {
        cout << pair.first << " : " << pair.second << "\n";
    }

    return 0;
}