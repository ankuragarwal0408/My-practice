class Solution 
{
public:
unordered_map<string,int>mp;
int recurse(int ptr1,int ptr2,int ptr3,string s1,string s2,string s3)
{
    if(ptr3>=s3.length()&&ptr1>=s1.length()&&ptr2>=s2.length())
       return 1;
    if(ptr3>=s3.length())
        return 0;
    string dp=to_string(ptr1)+" "+to_string(ptr2)+" "+to_string(ptr3);
    if(mp.find(dp)!=mp.end())
          return mp[dp];
    int a=0,b=0;
    if(ptr3<s3.length()&&s3[ptr3]==s1[ptr1])
      a=recurse(ptr1+1,ptr2,ptr3+1,s1,s2,s3);
    if(ptr2<s2.length()&&s3[ptr3]==s2[ptr2])
      b=recurse(ptr1,ptr2+1,ptr3+1,s1,s2,s3);
    return mp[dp]=a||b;
}
    bool isInterleave(string s1, string s2, string s3) 
    {
        mp.clear();
      return recurse(0,0,0,s1,s2,s3);
    }
};
