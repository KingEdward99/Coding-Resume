/*
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109s
*/
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap; // Create a hash map to store the value and its index
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // Calculate the complement
            
            // Check if the complement exists in the map
            if (numMap.find(complement) != numMap.end()) {
                // If found, return the indices of the current number and the complement
                return {numMap[complement], i};
            }
            
            // Otherwise, add the current number and its index to the map
            numMap[nums[i]] = i;
        }
        
        // If no solution is found (which should not happen according to the problem statement), return an empty vector
        return {};
    }
};