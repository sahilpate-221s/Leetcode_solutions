class Solution {
public:
    int n;

    // int solve(int index, vector<int>& heights, int bricks, int ladders,
    //           vector<vector<int>>& dp) {
    //     if (index == n - 1)
    //         return 0;

    //     if (dp[bricks][ladders] != -1)
    //         return dp[bricks][ladders];

    //     if (heights[index + 1] < heights[index]) {
    //         return dp[bricks][ladders] =
    //                    1 + solve(index + 1, heights, bricks, ladders, dp);
    //     } else {
    //         int byBricks = 0;
    //         int byLadder = 0;

    //         int diff = heights[index + 1] - heights[index];
    //         if (bricks >= diff) {
    //             byBricks =
    //                 1 + solve(index + 1, heights, bricks - diff, ladders, dp);
    //         }

    //         if (ladders > 0) {
    //             byLadder =
    //                 1 + solve(index + 1, heights, bricks, ladders - 1, dp);
    //         }
    //         return dp[bricks][ladders] = max(byLadder, byBricks);
    //     }
    //     return -1;
    // }       // ye memory limit exceed dega memoisation ka code ahi ye 
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        n = heights.size();
        // vector<vector<int>> dp(bricks + 1, vector<int>(ladders + 1, -1));
        // return solve(0, heights, bricks, ladders, dp);



        //abb lazy greedy dekhenge 
        priority_queue<int> pq; //max heap
        int i=0;
        for(;i<n-1;i++)
        {
            if(heights[i+1] < heights[i])
                continue;
            
            int diff = heights[i+1]-heights[i];

            if(bricks >= diff)
            {
                bricks-=diff;
                pq.push(diff);
            }
            else if(ladders > 0)
            {
                if(!pq.empty())
                {
                    int past_bircks_used = pq.top();
                    if(past_bircks_used > diff)
                    {
                        pq.pop();
                        bricks += past_bircks_used;
                        bricks-=diff;
                        pq.push(diff);
                        ladders--;
                    }
                    else
                    {
                        ladders--;
                    }
                }
                else
                {
                    ladders--;
                }
            }
            else break;
        }
        return i;


    }
};