class Solution 
{
public:
   int checkSubstr(string &s, int i, vector<int> &l, vector<int> &r) 
   {
    int right = r[s[i] - 'a'];
    for (auto j = i; j <= right; ++j) 
    {
        if (l[s[j] - 'a'] < i)// yadi kisi ka starting current character se peeche h toh phir 
            return -1;// wo substring valid nai hogi
        right = max(right, r[s[j] - 'a']);// yahan wo window ka expand kar raha h check kar raha h dynamically 
    }
    return right;
}
vector<string> maxNumOfSubstrings(string s) 
{
    vector<int> l(26, INT_MAX), r(26, INT_MIN);
    vector<string> res(1);
    for (auto i = 0; i < s.size(); ++i) 
    {
        l[s[i] - 'a'] = min(l[s[i] - 'a'], i);// left se minuimum index uss character ke liye nikaal rahe h yahan
        r[s[i] - 'a'] = max(r[s[i] - 'a'], i);// right se maximum index nikal rahe h uss character ke liye
    }
    auto right = INT_MAX;
    for (auto i = 0; i < s.size(); ++i) 
    {
        if (i == l[s[i] - 'a'])// agar current index agar uss particular character ka starting h 
        {
            auto new_right = checkSubstr(s, i, l, r);
            if (new_right != -1) 
            {
                /* It is checking the overlapping of the previously selected substring with current valid substring and pushing the new empty string at the back so that overlapping substrings can be avoided, I hope you got it*/
              if (i > right)// agar previous right edge se jyada yadi h current right edge toh ye 
                    res.push_back("");// valid ho gyi yahan pe
                right = new_right;
                res.back() = s.substr(i, right - i + 1);// ham push kar rahe ab ye non overlapping waali string ko 
            }
        }
    }
    return res;
}
};
