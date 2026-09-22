#include <iostream>
#include <string>
#include <vector>
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

void removeLeftRecursion(const string &production) {
    int arrowPos = production.find("->");
    string lhs = production.substr(0, arrowPos);
    string rhs = production.substr(arrowPos + 2);

    vector<string> alternatives = splitAlternatives(rhs);
    vector<string> alpha, beta;

    for (const string &alt : alternatives) {
        if (alt.substr(0, lhs.length()) == lhs) {
            alpha.push_back(alt.substr(lhs.length()));
        } else {
            beta.push_back(alt);
        }
    }

    if (alpha.empty()) {
        cout << production << "  (no left recursion)\n";
        return;
    }

    string newNonTerminal = lhs + "'";

    cout << lhs << " -> ";
    for (size_t i = 0; i < beta.size(); i++) {
        cout << beta[i] << newNonTerminal;
        if (i != beta.size() - 1) cout << " | ";
    }
    cout << "\n";

    cout << newNonTerminal << " -> ";
    for (size_t i = 0; i < alpha.size(); i++) {
        cout << alpha[i] << newNonTerminal << " | ";
    }
    cout << "e\n";
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string production;
        cout << "Enter production " << (i + 1) << " (format A->Aa|Ab|c): ";
        getline(cin, production);
        removeLeftRecursion(production);
    }

    return 0;
}