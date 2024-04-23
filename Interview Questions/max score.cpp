class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int max_score = 0;
        int left = 0;
        for(;left<k;left++) {
            max_score += cardPoints[left];
        }
        left--;
        int right = cardPoints.size()-1;
        int current_score = max_score;
        while(left >= 0) {
            current_score = current_score - cardPoints[left];
            current_score += cardPoints[right];
            max_score = max(max_score, current_score);
            left--;
            right--;
        }
        return max_score;
    }
};
