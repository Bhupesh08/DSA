class Solution {
    #define pii pair<int, int>
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> freq(26, 0);
        
        for(int i=0; i<tasks.size(); i++) {
            freq[tasks[i] - 'A']++;
        }
        
        priority_queue<int> pq;
        
        for(int i=0; i<26; i++) {
            if(freq[i] > 0) {
                pq.push(freq[i]);
            }
        }
        
        queue<pii> q;
        
        //Main logic begins
        int time = 0;
        
        while(!pq.empty() || !q.empty()) {
            time += 1;
            
            if(!pq.empty()) {
                int count = pq.top();
                pq.pop();
                
                if(count > 1) {
                    q.push({count-1, time+n});
                }
            }
            
            if(!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        
        return time;
        
    }

};