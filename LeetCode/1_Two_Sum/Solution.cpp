#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> hashmap;
        std::vector<int> answer;

        for(int i = 0; i < nums.size(); i++){

            int compliment = target - nums[i];

            if(hashmap.find(compliment) != hashmap.end()){
                answer.push_back(i);
                answer.push_back(hashmap.find(compliment)->second);
                break;
            }
            
            hashmap.insert(std::make_pair(nums[i], i));
        
        }

        return answer;
    }
};