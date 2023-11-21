class Solution {
public:
    bool check(vector<int>& nums) {
        // -------------------- runs for distinct elements-------------------
        // int mini = nums[0] , n = nums.size() , mi = 0;
        // for(int i = 1 ; i < n ; i++) {
        //     if(mini >= nums[i]) {
        //         mini = nums[i];
        //         mi = i;
        //     }
        // }
        // if(mi == 0) return 1;
        // for(int i = (mi+1)%n ; i != mi ;i =(i+1)%n) {
        //     int j = (i+1)%n;
        //     if(j != mi && nums[j] < nums[i]) return false;
        // }
        // return true;
        int cnt = 0 , n = nums.size();
        for(int i = 1 ; i < n ; i++) 
            if(nums[i-1] > nums[i]) cnt++;
        if(nums[0] < nums[n-1]) cnt++;
        return cnt <= 1;
    }
};