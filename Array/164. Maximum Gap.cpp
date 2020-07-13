class Solution 
{
public:
void sort(vector<int>&arr,int n,int exp)
{
    queue<int>q[10];
    for(int i=0;i<n;i++)
    q[(arr[i]/exp)%10].push(arr[i]);
     int k=0;
    for(int i=0;i<10;i++)
    {
        while(q[i].empty()==0)
        {
            arr[k]=q[i].front();
            k++;
            q[i].pop();
        }
    }
}
void radixsort(vector<int>&arr,int n)
{
   int ma=*max_element(arr.begin(),arr.end());
    for(int exp=1;ma/exp>0;exp*=10)
    sort(arr,n,exp);
}
int maximumgap(vector<int> &A)
{
    if(A.size()==1)
     return 0;
    int maxa=INT_MIN;
     radixsort(A,A.size());
     for(int i=0;i<(A.size()-1);i++)
     {
        int d=A[i+1]-A[i];
        maxa=max(maxa,d);
     }
    return maxa;
}
    int maximumGap(vector<int>& nums) 
    {
        int n=nums.size();
         if(n<2)
               return 0;
        return maximumgap(nums);
    }
};
