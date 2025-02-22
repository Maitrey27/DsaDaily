class Solution {
public:

    bool isVowel(char ch)
    {
        return ch =='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int maxVowels(string s, int k) {
        int n =  s.length();

        //to find substr of size k with max vowels-->sliding window

        int i =0;
        int j =0;

        int cnt =0;

        int maxVowel =INT_MIN;

        while(j<n)
        {
            if(isVowel(s[j]))
            {
                cnt++;
            }

            if(j-i+1==k)
            {
                //found a substr of size k
                if(maxVowel<cnt)
                {
                    maxVowel = cnt; //update the max var
                }

                //slide the window
                if(isVowel(s[i]))
                {
                    cnt--;
                }
                i++;
            }
            j++;
        }

        return maxVowel;
    }
};