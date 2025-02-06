class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        //this is basic greedy type of question

        //start from target and reach 1

        //reverse process from target -> 1 so  for instead of increment-> decrement
        //doubles ->divide by 2

        int moves =0;

        while(target>1)
        {
            if(target%2==0 && maxDoubles>0)
            {
                //target even so can use doubles 
                target = target/2;
                maxDoubles--;
            }
            else if(maxDoubles>0)
            {
                //target odd so derement
                target = target-1;
            }
            else{
                //max doubles finish
                moves+=target-1; 
                break;
            }
            moves++;
        }

        return moves;
    }
};