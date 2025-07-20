// Backtracking: Palindrome Partitioning
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) return false;
    }
    return true;
}

void palindromeHelper(string s, int start, vector<string>& curr, vector<vector<string>>& res) {
    if (start == s.size()) {
        res.push_back(curr);
        return;
    }
    for (int end = start; end < s.size(); end++) {
        if (isPalindrome(s, start, end)) {
            curr.push_back(s.substr(start, end - start + 1));
            palindromeHelper(s, end + 1, curr, res);
            curr.pop_back();
        }
    }
}
