class Solution {
public:

    int dp[501][501];
    int lcs(int i, int j, string &s1,string &s2)
    {
        if(i==0)
        {
            //s1 is empty 
            return 0;
        }

        if(j==0)
        {
            //s2 is empty
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(s1[i-1]==s2[j-1])
        {
            return dp[i][j] = 1 + lcs(i-1,j-1,s1,s2);
        }

        return dp[i][j] = max(lcs(i-1,j,s1,s2),lcs(i,j-1,s1,s2));
    }
    int minDistance(string word1, string word2) {
        //no of deletions = word1+word2 -2*lcs

        int n = word1.size();
        int m = word2.size();

        memset(dp,-1,sizeof(dp));
        int LCS = lcs(n,m,word1,word2);

        //sea+eat-2*(ea) -->s and t chars to be deleted
        return n+m-2*(LCS);

    }
};