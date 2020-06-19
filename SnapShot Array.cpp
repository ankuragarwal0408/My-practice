class SnapshotArray 
{
public:
    int n;
    unordered_map<int,unordered_map<int,int>>mp;
    int snapindex;
    SnapshotArray(int length) 
    {
        n=length;
        mp.clear();
        snapindex=0;
    } 
    void set(int index, int val) 
    {
         mp[snapindex][index]=val;
    }
    int snap() 
    {
       snapindex++;
       mp[snapindex]=mp[snapindex-1];
       return snapindex-1;
    }
    int get(int index, int snap_id) 
    {
        return mp[snap_id][index];
    }
};
