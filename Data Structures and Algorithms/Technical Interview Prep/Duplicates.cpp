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
