class Solution {
public:
    int dp[5001][3];
    int solve(int ind, int n, vector<int>&prices,int buy)
    {
        if(ind>=n)
        {
            //out of bound then no profit
            return 0;
        }

        if(dp[ind][buy]!=-1)
        {
            return dp[ind][buy];
        }

        int profit = 0;
        //choices either to buy or sell a stock
        if(buy==0)
        {
            //buy a stock
            profit = max(-prices[ind] + solve(ind+1,n,prices,1), solve(ind+1,n,prices,0) );
        }

        if(buy==1)
        {
            //sell a stock

            //cooldown day so cant buy on next day so ind+2
            profit = max( prices[ind] + solve(ind+2,n,prices,0), solve(ind+1,n,prices,1) );
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 0; //0->buy and 1->sell
        memset(dp,-1,sizeof(dp));
        return solve(0,n,prices,buy);
    }
};