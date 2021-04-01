class HitCounter {
    queue<pair<int,int>> q;
    int count;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        count = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        pair<int, int> p(timestamp, 1);
        if (q.empty()) {
            q.push(p);
            count++;
            return;
        } 
        
        pair<int, int> bk = q.back();
        if (timestamp == bk.first) {
            bk.second++;
            q.back() = bk;
            count++;
            return;
        } 
        
        while (!q.empty()) {
            pair<int, int> ft = q.front();
            if (timestamp - ft.first >= 300) {
                count -= ft.second;
                q.pop();
            } else {
                break;
            }
        }
        count++;
        q.push(p);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!q.empty()) {
            pair<int, int> ft = q.front();
            if (timestamp - ft.first >= 300) {
                q.pop();
                count -= ft.second;
            } else {
                break;
            }
        }
        return count;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
