class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        set<int> hashset;
        int longestSub = 0;
        
        //Inserting the values present in given array into a set to make it easier to check for sequence.
        for(auto num: nums) {
            hashset.insert(num);
        }
        
        
        //Iterating through the given array
        for(auto num: nums) {
            //checking if left neighbour is present or Not. Enter if not present.
            if(!hashset.count(num-1)) {
                int currentNum = num;
                int currentStreak = 1;

                while(hashset.count(currentNum+1)){
                    currentNum++;
                    currentStreak++;
                }

                longestSub = max(longestSub, currentStreak);
            }
            

        }

        return longestSub;
        
    }
};