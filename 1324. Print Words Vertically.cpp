class Solution 
{
public:
    vector<string> printVertically(string s) 
    {
        vector<string>ans;
        stringstream ss(s);
        int maxlen=0;
        string word;
        while(ss>>word)
        {
            ans.push_back(word);
            maxlen=max(maxlen,(int)word.length());
        }  
        string a(ans.size(),' ');
        vector<string>result(maxlen,a);
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<min((int)ans[i].length(),maxlen);j++)
            {
               result[j][i]=ans[i][j];
            }
        }
        for(int i=0;i<maxlen;i++)
        {
            while(result[i][result[i].length()-1]==' ')
                result[i].pop_back();
        }
        return result;
    }
};
