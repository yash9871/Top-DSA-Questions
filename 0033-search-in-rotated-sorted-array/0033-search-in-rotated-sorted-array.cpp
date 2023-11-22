class Solution {
public:
    int pivot(vector<int>&nums) {
        int s = 0 , e = nums.size()-1;
        while(s < e) {
            int mid = s+(e-s)/2;
            if(nums[mid] >= nums[0]) s = mid+1;
            else e = mid;
        }
        return s;
    }
    int binary(vector<int>& nums , int s , int e , int target) {
        while(s <= e) {
            int mid = s + (e-s)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) e = mid-1;
            else s = mid+1;
        }
        return -1;
    } 
    int search(vector<int>& nums, int target) {
        if(!nums.size()) return -1;
        int p = pivot(nums) ,n = nums.size();
        if(target >= nums[p] && target <= nums[n-1]) return binary(nums,p,n-1,target);
        else return binary(nums,0,p-1,target);
    }
};