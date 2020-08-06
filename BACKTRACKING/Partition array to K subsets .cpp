bool partition(vector<int> p, int A[], int r, int s)
{
    if(r<0)// if array is now finished 
    return true;// then it means we have found out the answer
    
    int x = A[r];
    r--;
    
    for(int i=0;i<p.size();i++)
    {
        if(p[i]+x <= s)
        {
            p[i] += x;
            
            if(partition(p, A, r, s))
               return true;
            
            p[i] -= x;// backtracking 
        }
        
        if(p[i] == 0)
        break;
    }
    
    return false;
}

bool isKPartitionPossible(int A[], int N, int K)
{
     //Your code here
     
     sort(A, A+N);// for eradicating the numbers greater than the 
     // required sum in the search space 
     
     int sum=0;
     for(int i=0;i<N;i++)
     sum += A[i];
     
     if(sum % K !=0)
     return false;
     
     int r = N-1;
     int s = sum/K;
     
     if(A[N-1] > s)
     return false;
     
     int n = K;
     
     while(A[r] == s)// if already exist the element
     {// equal to required sum then it means we have found out one
     // subset and we need to decrease it 
         r--;
         K--;
     }
     
     vector<int> p;
     // represents that we will use k length array to
     // partition the array into K subsets 
     for(int i=0;i<K;i++)
     p.push_back(0);
     
     return partition(p, A, r, s);
}
