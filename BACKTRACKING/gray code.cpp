class Solution 
{
public:
    vector<int>res;
unordered_set<int>vis;
void recurse(int temp,int lastbit,int noofbits)
{
// base condition
    if(vis.find(temp)!=vis.end())  // if that number has been found previously then return back
      return;
    vis.insert(temp);
    res.push_back(temp);
    for(int i=0;i<noofbits;i++)
    {
        if(i!=lastbit)// because we don't want to set the last changed bit
        {
            if(temp&(1<<i))// if i th bit is set then unset it
            recurse((temp & ~(1 << (i))),i,noofbits);
            else// if i the bit is unset then set it
            recurse(temp|(1<<i),i,noofbits);
        }   
    }
}
vector<int> grayCode(int n) 
{
       vis.clear();
       res.clear();
      recurse(0,-1,n);
       return res;
}
};
