class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {  // using bottom-up dp
        vector<int> dp=grid[0];
        for(int row=1;row<grid.size();row++){
            vector<int> currentRowMins={100000, 100000, -1};
            for(int col=0;col<grid[0].size();col++){
                if(currentRowMins[0]>dp[col]){
                    if(currentRowMins[0]!=100000)
                        currentRowMins[1]=currentRowMins[0];
                    currentRowMins[0]=dp[col];
                    currentRowMins[2]=col;
                }
                else if(currentRowMins[0]==dp[col] || currentRowMins[1]>dp[col])
                    currentRowMins[1]=dp[col];
            }
            for(int col=0;col<grid[0].size();col++)
                dp[col]=grid[row][col]+(currentRowMins[2]==col ? currentRowMins[1] : currentRowMins[0]);
        }
        return *min_element(dp.begin(), dp.end());
    }
};
