class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() , i = n-2 , x;
        for(;i >=0 ; i--) if(nums[i] < nums[i+1]) break;
        if(i < 0) {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(x = n-1;x > i ; x--) if(nums[i] < nums[x]) break;
        swap(nums[i],nums[x]);
        reverse(nums.begin()+i+1,nums.end());
    }
};