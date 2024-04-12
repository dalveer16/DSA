class Solution {
public:
   vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> leftProducts(n);
    vector<int> rightProducts(n);
    vector<int> answer(n, 1);

    // Calculate products of elements to the left of each element
    int product = 1;
    for (int i = 0; i < n; i++) {
        leftProducts[i] = product;
        product *= nums[i];
    }

    // Calculate products of elements to the right of each element
    product = 1;
    for (int i = n - 1; i >= 0; i--) {
        rightProducts[i] = product;
        product *= nums[i];
    }

    // Multiply corresponding left and right products to get the final answer
    for (int i = 0; i < n; i++) {
        answer[i] = leftProducts[i] * rightProducts[i];
    }

    return answer;
}
};
