class Solution 
{
public:
    string minRemoveToMakeValid(string s) 
    {
        int len=s.length();
        stack<pair<char,int>>st;
        vector<int>dele(len,0);
        int i=0,cnt=0;
        while(i<len)
        {
            if(s[i]=='(')
                st.push({s[i],i});
            else if(s[i]==')'&&st.empty())
                dele[i]=1;
            else if(s[i]==')'&&st.empty())
                dele[i]=1;
            else if(s[i]==')'&&st.top().first=='(')
               st.pop();
           i++;   
        }
        while(!st.empty())
        {
            dele[st.top().second]=1;
            st.pop();
        }
        string res="";
        for(int i=0;i<len;i++)
        {
            if(dele[i]==0)
                res+=s[i];
        }
        return res;
    }
};
