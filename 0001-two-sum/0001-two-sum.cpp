class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int, int> hashmap;
        int n = nums.size();
        vector<int> res;

        

        for(int i=0; i<n; i++) {

            if(hashmap.count(target-nums[i])) {

                res.push_back(i);
                res.push_back(hashmap[target-nums[i]]);
                

            } else {
                hashmap.insert(make_pair(nums[i], i));
            }

        }

        return res;
        
    }
};