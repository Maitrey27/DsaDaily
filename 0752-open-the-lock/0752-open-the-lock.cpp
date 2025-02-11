class Solution {
public:
    void fillNeighbours(queue<string>& q, string lock,
                        unordered_set<string>& st) {
        for (int c = 0; c < 4; c++) {

            int ch = lock[c];

            char dec = ch == '0' ? '9' : ch - 1;
            char inc = ch == '9' ? '0' : ch + 1;

            lock[c] = dec;
            if (st.find(lock) == st.end()) {
                // not in deadend then only contnue;
                st.insert(lock);
                q.push(lock);
            }

            lock[c] = inc;
            if (st.find(lock) == st.end()) {
                // not in deadend then only contnue;
                st.insert(lock);
                q.push(lock);
            }

            lock[c] = ch;
        }
    }
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> st(deadends.begin(), deadends.end());

        string start = "0000";

        if (st.find(start) != st.end()) {
            return -1;
        }

        queue<string> q;
        q.push(start);

        int turns = 0;
        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                string lock = q.front();
                q.pop();

                if (lock == target) {
                    // we got the target and open the lock
                    return turns;
                }

                fillNeighbours(q, lock, st);
            }
            turns++;
        }

        return -1;
    }
};