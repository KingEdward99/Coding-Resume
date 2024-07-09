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