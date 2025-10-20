class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //map that will store the sorted str and all the remainig str that match the corresponding sorted str
        unordered_map<string,vector<string>> mp;

        for(auto i : strs)
        {
            string word = i;
            sort(word.begin(),word.end());

            //store all the rem strs that match the sorted sts in vector<string>
            mp[word].push_back(i);
        }

        //now put all the vector<string> to new array
        vector<vector<string> > ans;
        for(auto i : mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};