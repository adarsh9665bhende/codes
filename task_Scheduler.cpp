class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>heap;
        vector<int>mp(26,0);
        queue<pair<int,int>>q;
        for(char c:tasks){
            mp[c-'A']++;
        }
        for(int i=0;i<26;i++){
            if(mp[i]>0){
                heap.push(mp[i]);
            }
        }
        int time =0;
        while(!heap.empty() || !q.empty()){
            time++;
            if(!heap.empty()){
                int process = heap.top() -1;
                heap.pop();
                if(process){
                    q.push({process,time+n});
                }
            }
            if(!q.empty() && q.front().second==time){
                pair<int,int>temp = q.front();
                q.pop();
                heap.push(temp.first);
            }
        }
        return time;
    }
};