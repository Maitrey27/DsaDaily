class NumberContainers {
public:
    unordered_map<int,set<int>>numtoind;
    unordered_map<int,int>indtonum;
    NumberContainers() {
    }
    
    void change(int index, int number) {

        if(indtonum.find(index)!=indtonum.end())
        {
            int prevNum = indtonum[index];
            numtoind[prevNum].erase(index);

            if(numtoind[prevNum].empty())
            {
                //no ind stored wrt to num
                numtoind.erase(prevNum);
            }
        }

        indtonum[index]=number;
        numtoind[number].insert(index);
    }
    
    int find(int number) {
        
        if(numtoind.find(number)!=numtoind.end())
        {
            //number not exist in container
            return numtoind[number].begin();
        }

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */