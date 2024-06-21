/*
    Given an integer array nums, return true if any value appears at least twice
    in the array, and return false if every element is distinct

    Example 1:

    Input: nums = [1,2,3,1]
    Output: true
    Example 2:

    Input: nums = [1,2,3,4]
    Output: false
    Example 3:

    Input: nums = [1,1,1,3,3,4,3,2,4,2]
    Output: true
 

    Constraints:

    1 <= nums.length <= 105
    -109 <= nums[i] <= 109
*/

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        // Create an unordered set to store the numbers
        std::unordered_set<int> hashSet;
        
        // Iterate through the numbers in the vector
        for (int num : nums) {
            // If the number is already in the set, return true
            if (hashSet.find(num) != hashSet.end()) {
                return true;
            }
            
            // Store the number in the set
            hashSet.insert(num);
        }
        
        // Return false if no duplicates were found
        return false;
    }
};
