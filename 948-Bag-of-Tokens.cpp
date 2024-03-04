class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0,i=0,j=tokens.size()-1,maxScore=0;
        sort(tokens.begin(),tokens.end());
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                maxScore=max(maxScore,score);
                power-=tokens[i++];
            
            }
            else{
                if(score>0){
                score--;
                power+=tokens[j--];
                }
                    else
                        return maxScore;
            }
        
        }
        return maxScore;
    }
};
