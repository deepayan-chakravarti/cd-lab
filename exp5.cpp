#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> splitAlternatives(const string &rhs) {
    vector<string> parts;
    string current = "";
    for (char c : rhs) {
        if (c == '|') {
            parts.push_back(current);
            current = "";
        } else {
            current += c;
        }
    }
    parts.push_back(current);
    return parts;
}

string longestCommonPrefix(const vector<string> &group) {
    string prefix = group[0];
    for (size_t i = 1; i < group.size(); i++) {
        int j = 0;
        while (j < (int)prefix.length() && j < (int)group[i].length() && prefix[j] == group[i][j]) {
            j++;
        }
        prefix = prefix.substr(0, j);
    }
    return prefix;
}

void leftFactor(const string &production) {
    int arrowPos = production.find("->");
    string lhs = production.substr(0, arrowPos);
    string rhs = production.substr(arrowPos + 2);

    vector<string> alternatives = splitAlternatives(rhs);

    map<char, vector<string>> groups;
    vector<char> order;
    for (const string &alt : alternatives) {
        char firstChar = alt.empty() ? '\0' : alt[0];
        if (groups.find(firstChar) == groups.end()) {
            order.push_back(firstChar);
        }
        groups[firstChar].push_back(alt);
    }

    vector<string> mainAlternatives;
    vector<string> newProductions;
    int counter = 1;

    for (char c : order) {
        vector<string> &group = groups[c];
        if (group.size() == 1) {
            mainAlternatives.push_back(group[0]);
        } else {
            string prefix = longestCommonPrefix(group);
            string newNonTerminal = lhs + string(counter, '\'');
            counter++;
            mainAlternatives.push_back(prefix + newNonTerminal);

            string newProd = newNonTerminal + " -> ";
            for (size_t i = 0; i < group.size(); i++) {
                string suffix = group[i].substr(prefix.length());
                if (suffix.empty()) suffix = "e";
                newProd += suffix;
                if (i != group.size() - 1) newProd += " | ";
            }
            newProductions.push_back(newProd);
        }
    }

    cout << lhs << " -> ";
    for (size_t i = 0; i < mainAlternatives.size(); i++) {
        cout << mainAlternatives[i];
        if (i != mainAlternatives.size() - 1) cout << " | ";
    }
    cout << "\n";

    for (const string &np : newProductions) {
        cout << np << "\n";
    }
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string production;
        cout << "Enter production " << (i + 1) << " (format A->aB|aC|b): ";
        getline(cin, production);
        leftFactor(production);
    }

    return 0;
}