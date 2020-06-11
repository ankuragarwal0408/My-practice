class Solution {
public:
    int ladderLength(string b, string e, vector<string>& wl) {
    
        map<string,int>mp;
        for(int i=0;i<wl.size();i++){
            mp[wl[i]]=1;
        }
        if(!mp.count(e)) return 0;
priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
        pq.push(make_pair(1,b));
        mp.erase(b);
        pair<int,string>p;
        bool flag=true;
        while(!pq.empty()){
            p=pq.top();
            pq.pop();
            if(p.second==e){
                flag=false;
                break;
            }
            string t=p.second;
            for(int i=0;i<t.size();i++){
                t=p.second;
                for(int j=0;j<26;j++){
                    t[i]=char(int('a')+j);
                    if(mp.count(t)){
                        pq.push(make_pair(p.first+1,t));
                        mp.erase(t);
                    }
                }
            }
        }
         if(flag) return 0;
        return p.first;
    }
};
