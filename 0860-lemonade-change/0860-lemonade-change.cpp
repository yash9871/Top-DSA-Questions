class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0 , count10 = 0 , n = bills.size();
        for(int i = 0 ; i < n ; i++) {
            if(bills[i] == 5) count5++;
            else if(bills[i] == 10) {
                if(!count5) return false;
                count10++;
                count5--;
            }
            else {
                int val = 15;
                if(!count5) return false;
                if(count10) {
                    count10--;
                    val -= 10;
                }
                while(count5 && val) {
                    val -= 5;
                    count5--;
                }
                if(val) return false;
            }
        }
        return true;
    }
};