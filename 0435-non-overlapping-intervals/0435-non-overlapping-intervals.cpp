class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //this ques is same as the N -meetings room
        //the interval that will end early then only it will able to start another interval
        int n = intervals.size();
        vector<pair<int,int>>arr;

        for(auto it : intervals)
        {
            arr.push_back({it[1],it[0]}); //{end,start};
        }

        sort(arr.begin(),arr.end()); //sort on the basis of endTime

        int overlaps =0;
        int lastEndTime = arr[0].first;

        for(int i = 1; i<arr.size(); i++)
        {
            int startTime = arr[i].second;

            if(startTime<lastEndTime)
            {
                overlaps++;
            }else{
                lastEndTime = arr[i].first;
            }
        }

        return overlaps;
    }
};