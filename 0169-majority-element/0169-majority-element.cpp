class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //-------------------------------- brute force approach
        // int ans = 0 , n = nums.size();
        // if(n == 1) return nums[0];
        // for(int i = 0 ; i < n ; i++) {
        //     int cnt = 1;
        //     for(int j = i+1 ; j < n ; j++) {
        //         if(nums[i] == nums[j]) cnt++;
        //         if(cnt > n/2) return nums[i];
        //     }
        // }
        // return 0;
        
        //------------------------------------- using map
        // unordered_map<int,int>mpp;
        // int ans = 0;
        // for(auto it: nums) mpp[it]++;
        // for(auto it: nums) {
        //     if(mpp[it] > nums.size()/2) ans = it;
        // }
        // return ans;
        
        //------------------------------------- Moore’s Voting Algorithm
        int cnt = 0 , ele = 0;
        for(int it: nums) {
            if(cnt == 0) ele = it;
            if(ele == it) cnt++;
            else cnt--;
        }
        return ele;
    }
};