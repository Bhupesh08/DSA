class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        //Most optimal solution using Boyer-Moore Voting algorithm.
        //Remember it using a game. Candidate is the protaganist (kinda our majority element in the end) and as soon as an element i.e not our candidate
        //is found, the life of candidate gets decremented, and we know that majority element/candidate appears more than half times, so it will somehow be alive at 
        //the end as we only decrement the life when any minority element is found.
        int candidate = INT_MIN;
        int life = 0;
        
        for(int i=0; i<n; i++) {
            if(life==0) {
                candidate = nums[i];
            }
            
            if(nums[i]==candidate) {
                life++;
            } else {
                life--;
                
            }
        }
        
        return candidate;
    }
};

// Brute force se thoda better solution using Hashmap.
//         int res;
//         map<int, int> mpp;

//         for(int i=0; i<n; i++) {
//             mpp[nums[i]]++;
//         }

//         for(auto it=mpp.begin(); it!=mpp.end(); it++) {
//             if(it->second > n/2) {
//                 res = it->first;
//             }
//         }

//         return res;
        
