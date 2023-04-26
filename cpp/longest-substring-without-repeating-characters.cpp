#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        // get the longest substring without repeating characters
        int lengthOfLongestSubstring(string s) {
            // initialize answer
            int ans = 0;
            // initialize the vector to size 128
            vector<int> count(128);
            // initialize the left and right pointers
            for (int l=0, r=0; r<s.length(); ++r){
                // increment the count of the character at the right pointer
                ++count[s[r]];
                // while the count of the character at the right pointer is greater than 1
                while (count[s[r]] > 1){
                    // decrement the count of the character at the left pointer
                    --count[s[l++]];
                }
                // update the answer
                // the answer is the max of the current answer and the difference between the right and left pointers
                // the difference between the right and left pointers is the length of the lengthOfLongestSubstring
                ans = max(ans, r-l+1);
            }
            // return the answer
            return ans;
        }
};
