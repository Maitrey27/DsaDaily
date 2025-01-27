class Solution {
public:
    int dayOfYear(string date) {
        // write your code here
        
        int year;
        int month;
        int day;
        
        stringstream ss(date);
        string temp;
        
        getline(ss,temp,'-');
        year = stoi(temp);
        
        getline(ss,temp,'-');
        month = stoi(temp);
        
        getline(ss,temp,'-');
        day = stoi(temp);
        
        vector<int>arr{31,28,31,30,31,30,31,31,30,31,30,31};
         if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            arr[1]=29; //leap year
        }
        
        int cntDays =0;
        for(int i =0; i<month-1; i++)
        {
            cntDays+=arr[i];
        }
        
        cntDays+=day;
        
        return cntDays;
        
    }
};