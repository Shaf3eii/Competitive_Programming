// problem link : https://leetcode.com/problems/valid-palindrome/
// problem sol : https://leetcode.com/problems/valid-palindrome/submissions/1340015780

//# Intuition
//  remove all unwanted characters
//
//# Approach
//  create new string with wanted character then iterate over it to check
//
//# Complexity
//- Time complexity:
//O(n)
//
//- Space complexity:
//O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool isPalindrome(string &s) {
        string res;
        auto alpha = [](char c)->bool{
            return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');};
        for(auto &c : s)
        {
            if(alpha(c))
                res += char(tolower(c));
        }
        int l = 0 , r = (int)res.size() - 1;
        while(l <= r)
        {
            if(res[l] != res[r])
                return false;
            ++l;
            --r;
        }
        return true;
    }
};

int main() {
    string s;
    getline(cin,s);
    cout << Solution::isPalindrome(s);
    return 0;
}
