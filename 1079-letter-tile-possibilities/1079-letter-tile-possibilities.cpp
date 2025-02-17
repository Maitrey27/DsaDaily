class Solution {
public:
    void solve(int ind, int n, unordered_set<string>&st, string &subsets)
    {
        if(ind>=n)
        {
            st.insert(subsets);
            return;
        }

        for(int j = ind; j<n; j++)
        {
            swap(subsets[ind],subsets[j]);

            solve(ind+1,n,st,subsets);

            swap(subsets[ind],subsets[j]);


        }
    }

    void findSubset(string tiles, int ind,int n,unordered_set<string>&subsets,string &op)
    {
        if(!op.empty())
        {
            solve(0,op.size(),subsets,op);
        }

       for (int i = ind; i < n; i++) {
            op.push_back(tiles[i]);
            findSubset(tiles, i + 1, n, subsets, op);
            op.pop_back();  // Backtrack
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.length();

        unordered_set<string>subsets;
        string op;
        findSubset(tiles,0,n,subsets,op);
        for(auto s : subsets)
        {
            cout<<s<<" ";
        }
        return subsets.size();
    }
};