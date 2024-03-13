class Solution {
public:
    int pivotInteger(int n) {
        int sum=0;
        sum=(n*(n+1))/2;
        int sum1=0;
        for(int i=1;i<=n;i++){
            int sum2=sum-sum1-i;
            if(sum2==sum1){
                return i;
            }
            sum1+=i;
        }
        return -1;
    }
};
