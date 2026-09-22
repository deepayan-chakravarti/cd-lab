#include <iostream>
#include <string>
using namespace std;

bool checkA(string s) {
    int n = s.length();
    int i = 0;
    while (i < n && s[i] == 'a') i++;
    if (i == 0) return false;
    int firstB = i;
    while (i < n && s[i] == 'b') i++;
    if (i != n) return false;
    if (i == firstB) return false;
    return true;
}

bool checkB(string s) {
    int n = s.length();
    if (n % 2 == 0) return false;
    int i = 0, j = n - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

bool checkC(string s) {
    int n = s.length();
    int i = 0;
    while (i < n && s[i] == 'a') i++;
    int countA = i;
    if (countA == 0) return false;
    int j = i;
    while (j < n && s[j] == 'b') j++;
    int countB = j - i;
    if (j != n) return false;
    return countB == 2 * countA;
}

bool checkD(string s) {
    int n = s.length();
    int i = 0;
    while (i < n && s[i] == 'a') i++;
    int countA = i;
    if (countA == 0) return false;
    int j = i;
    while (j < n && s[j] == 'b') j++;
    int countB = j - i;
    if (j != n) return false;
    return countA == countB;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    bool matched = false;

    if (checkA(s)) {
        cout << s << " belongs to Grammar 1 (S -> aS | Sb | ab)\n";
        matched = true;
    }
    if (checkB(s)) {
        cout << s << " belongs to Grammar 2 (S -> aSa | bSb | a | b)\n";
        matched = true;
    }
    if (checkC(s)) {
        cout << s << " belongs to Grammar 3 (S -> aSbb | abb)\n";
        matched = true;
    }
    if (checkD(s)) {
        cout << s << " belongs to Grammar 4 (S -> aSb | ab)\n";
        matched = true;
    }

    if (!matched)
        cout << s << " does not belong to any of the given grammars\n";

    return 0;
}