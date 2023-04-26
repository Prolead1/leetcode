#include <iostream>
#import <vector>
#import <unordered_map>
using namespace std;
class Solution{
    public:
        // return a vector of indices of the two numbers such that they add up to target
        vector<int> twoSum(vector<int> nums, int target){
            // create a map to store the number and its index
            unordered_map<int, int> numToInts;
            // iterate through the vector, and check if the target - nums[i] is in the map
            for(int i = 0; i < nums.size(); i++){
                // if the target - nums[i] is in the map, return the index of the target - nums[i] and the current index
                if(numToInts.count(nums[i]-target)){
                    return {numToInts[nums[i]-target], i};
                }
                // if the target - nums[i] is not in the map, add the current number and its index to the map
                numToInts[nums[i]] = i;
            }
            throw invalid_argument("No two sum solution");
        }
};

int main(){
    Solution s;
    for (const auto& i : s.twoSum({2, 7, 11, 15}, 9)) {
        cout << i << ' ';
    };
    cout << endl;
    return 0;
}
