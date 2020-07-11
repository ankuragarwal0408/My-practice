string Solution::solve(string s) 
{
int n = s.size();
int index=-1;
for(int i=n-2;i>=0;i--)
{
     if(s[i]<s[i+1])
     { 
         index=i;
         break;
     }
}
if(index==-1)
return "-1";


else
{
   for(int j=n-1;j>=0;j--) 
  {
    if(s[index]<s[j])
    {
      swap(s[index],s[j]); 
       break;
    }
   }

   sort(s.begin()+index+1,s.end());

  return s;
    
 }
}

