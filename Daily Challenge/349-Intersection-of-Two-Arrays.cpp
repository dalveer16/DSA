class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> M;
        for (auto num : nums1)
            M[num]++;

        vector<int> res;
        for (auto num : nums2)
        {
            if (M.find(num) != M.end())
            {
                res.push_back(num);
                M.erase(num);
            }
        }

        return res;
    }
};
