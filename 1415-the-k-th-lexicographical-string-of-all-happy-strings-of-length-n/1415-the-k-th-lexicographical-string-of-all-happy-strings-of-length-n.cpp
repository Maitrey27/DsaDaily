class Solution {
public:

    void generateHappyString(int n, string &currStr, vector<string>&happyStrings)
    {
        if(currStr.length()==n)
        {
            happyStrings.push_back(currStr);
            return;
        }

        //try every char {a,b,c}
        for(char ch = 'a'; ch<='c'; ch++)
        {
            if(currStr.size()>0 && currStr.back()==ch)
            {
                //skip if curr and prev char are smae
                continue;
            }
            
            //do
            currStr.push_back(ch);  
            //explore
            generateHappyString(n,currStr,happyStrings);

            //undo/bcktrack
            currStr.pop_back();


        }
    }
    string getHappyString(int n, int k) {
        string currStr = "";

        vector<string>happyStrings;

        generateHappyString(n,currStr,happyStrings);

        if(happyStrings.size()<k)
        {
            return ""; //happyStrings should be atleast of size k
        }
     
        return happyStrings[k-1]; //kth happy string
    }
};