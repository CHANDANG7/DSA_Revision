// Recursion: Print All Subsequences
#include <iostream>
#include <vector>
using namespace std;

void printSubsequences(string s, int index, string curr) {
    if (index == s.length()) {
        cout << curr << endl;
        return;
    }
    // Include current character
    printSubsequences(s, index + 1, curr + s[index]);
    // Exclude current character
    printSubsequences(s, index + 1, curr);
}
