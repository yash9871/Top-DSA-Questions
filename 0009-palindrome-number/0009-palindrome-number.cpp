class Solution {
public:
    // int reverse(int x) {
    //     long long ans = 0;
    //     while(x > 0) {
    //         ans = ans*10 + x%10;
    //         x = x/10;
    //     } 
    //     return ans;
    // }
    bool isPalindrome(int x) {
        // if(x < 0) return 0;
        // if(x == 2147483647) return false;
        // int y = reverse(x);
        // while(x > 0 && y > 0) {
        //     if(x%10 != y%10) return false;
        //     x = x/10 , y = y/10;
        // }
        // return true;
        long a = 0;
        int p = x;
        while(x > 0) {
            a = a*10 + x%10;
            x = x/10;
        }
        return p == a;
    }
};