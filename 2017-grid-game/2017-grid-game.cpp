class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

        long long firstRowRemSum     = accumulate(begin(grid[0]),end(grid[0]),0LL);

        long long secondRowRemainSum = 0;

        long long minimizedRobot2Sum  = LONG_LONG_MAX;


        for(int robot1Col  =0; robot1Col<grid[0].size(); robot1Col++)
        {
            //Robot1 took this startegy
            firstRowRemSum -= grid[0][robot1Col];

            //Robot2 will try to do best after Robot1 has taken the above strategy

            long long bestofRobot2 = max(firstRowRemSum,secondRowRemainSum);

            minimizedRobot2Sum    = min(minimizedRobot2Sum,bestofRobot2);

            secondRowRemainSum += grid[1][robot1Col];
        }
    	
        return minimizedRobot2Sum;
    }
};