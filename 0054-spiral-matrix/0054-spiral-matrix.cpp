class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int cs=0,ce = matrix[0].size()-1,rs = 0,re = matrix.size()-1,cnt = 0,total =(ce+1)*(re+1);
        vector<int>v;
        while(cnt < total) {
            for(int i = cs ; i <= ce && cnt < total ; i++) {
                v.push_back(matrix[rs][i]);
                cnt++;
            }
            rs++;
            for(int i = rs ; i <= re && cnt < total ; i++) {
                v.push_back(matrix[i][ce]);
                cnt++;
            } 
            ce--;
            for(int i = ce ; i >= cs && cnt < total ; i--) {
                v.push_back(matrix[re][i]);
                cnt++;
            }
            re--;
            for(int i = re ; i >= rs && cnt < total ; i--) {
                v.push_back(matrix[i][cs]);
                cnt++;
            }
            cs++;
        }
        return v;
    }
};