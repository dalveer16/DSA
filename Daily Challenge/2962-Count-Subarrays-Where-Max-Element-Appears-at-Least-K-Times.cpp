class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        long long res = 0;
        int cnt = 0;
        int left = 0;

        for(int right = 0; right < nums.size(); ++right){
            if(nums[right] == mx){
                ++cnt;
            }

            while(cnt >= k){
                res += nums.size() - right;
                if(nums[left] == mx){
                    --cnt;
                }
                ++left;
            }
        }

        return res;
    }
};
