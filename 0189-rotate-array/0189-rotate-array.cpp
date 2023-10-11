class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    // vector<int>ans; // created a vector in which I'll push all elements that appear before last k elements & then the k elements
    //     int n=nums.size();
    //     k=k%n; // even when>n it'll adjust
    //     for (int i=n-k; i<n; i++){
    //         ans.push_back(nums[i]);
    //     }
    //     for (int i=0; i<=n-k-1; i++){ // pushing the last k elements
    //         ans.push_back(nums[i]);
    //     }
    //     nums=ans;
        k=k%nums.size();
        if(nums.size()==1)
            return;
        // agr right mein reverse krna ho toh pelhe pura reverse kar do 
        // or agr left mein reverse krna ho toh full reverse bad mei karo
        reverse(nums.begin(),nums.end()); 
        
        
        // ye dono steps left or right dono mein same rahenge 
        reverse(nums.begin(),nums.begin()+k); 
        reverse(nums.begin()+k,nums.end());
    }
};