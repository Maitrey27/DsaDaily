class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();

        int i =0;
        int j =0;
        int maxConsective = INT_MIN;

        //to find the max Consective true/false

        int maxFalse =0; //first cnt max cnsctive false  by replacing T with F
        while(j<n)
        {
            if(answerKey[j]=='F')
            {
                maxFalse++;
            }

            while(maxFalse>k)
            {
                if(answerKey[i]=='F')
                {
                    maxFalse--;
                }
                i++;
            }

            //now maxFalse<=k
            maxConsective = max(maxConsective,j-i+1);
            j++;
        }
        i=0;
        j=0;
        //now similary find max cnsctive true by replacing F with T
        int maxTrue =0; 
        while(j<n)
        {
            if(answerKey[j]=='T')
            {
                maxTrue++;
            }

            while(maxTrue>k)
            {
                if(answerKey[i]=='T')
                {
                    maxTrue--;
                }
                i++;
            }

            //now maxFalse<=k
            maxConsective = max(maxConsective,j-i+1);
            j++;
        }

        return maxConsective;
    }
};