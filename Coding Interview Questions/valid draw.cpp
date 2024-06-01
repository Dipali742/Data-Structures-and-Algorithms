/* There is a N player tournament. Players have rank 1 to N and each player has a unique rank. Assume that the best player always wins, where the best player is the player with rank 1.

The tournament is a knockout tournament. This means if we have 8 players with their ranks [1 2 3 4 5 6 7 8], the tournament will look like this:
1st round: [1 2] [3 4] [5 6] [7 8]
2nd round: [1 3] [5 7]
3rd round: [1 5]
champion : [1]

We are calling [1 2 3 4 5 6 7 8] a "draw" where in the 1st round: the first two players meet in the first match, the next two players meet in the second match, and so on.

In the 2nd round: in the first match, the winner of the first match of the 1st round and the winner of the second match of the 1st round will play together. And similarly, in the second match, the winner of the third match of the 1st round and the winner of the fourth match of the 1st round will play together.

In short: given a draw, if we don't change the order of the players, players will meet in their order on the draw, and of course the winner moves to the next round. The tournament ends when there is only a single player remaining.

Problem:
A draw is a valid draw when in each round, the best (based on rank) player plays with the worst player, the second best player plays with the second worst player, and so on.
*/

/*
Problem 1:
Given a draw, find out whether it is a valid draw.

Sample Input: [1 2 3 4 5 6 7 8]
Output: False
*/
bool isValidDraw(vector<int>rank) {
    int n = rank.size();
    if(n == 1)
        return true;
    if(n % 2 != 0)
        return false;
    vector<int>new_rank;
    for(int i = 0; i < n-1; i+=2) {
        int second = rank[i+1];
        int first = rank[i];
        if(second != n - first + 1) {
             return false;
        }
        if(first > second)
            new_rank.push_back(second);
        else
            new_rank.push_back(first);
    }
    return isValidDraw(new_rank);
}

/*
Problem 2:
Given an integer N, find a valid draw (return a list of integers of length N). For example: the example above is not a valid draw. A valid draw example for N=4 would be: [1 4 2 3]
*/
vector<int>findValidDraw(int n) {
    if(n == 1)
        return {1};
    if(n % 2 != 0) //not possible
        return {};
    vector<int>rank = findValidDraw(n/2);
    vector<int>new_rank;
    for(int i = 0; i < rank.size(); i++) {
        new_rank.push_back(rank[i]);
        new_rank.push_back(n - rank[i] + 1);
    }
    return new_rank;
}
