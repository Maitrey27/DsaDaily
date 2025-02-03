class Solution {
public:
    bool isVowel(char ch)
    {
        ch =tolower(ch);
        return ch=='a' || ch=='e' || ch=='i'|| ch=='o' || ch =='u';
    }
    string sortVowels(string s) {
        int n = s.length();

        string vowelStr;

        for(auto ch : s)
        {
            if(isVowel(ch))
            {
                vowelStr.push_back(ch);
            }
        }

        sort(vowelStr.begin(),vowelStr.end());

        int i =0;

        for(int j=0 ; j<n; j++)
        {
            if(isVowel(s[j]))
            {
                s[j] = vowelStr[i];
                i++;
            }

        }


        return s;
    }
};