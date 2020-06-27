class Solution 
{
public:
    /*
     below explanation is for those who want to give try without seeing the code and attempting themselves 
     Tried my best to explain my approach if any doubts please ask me 
      1)It's question of normal topological sort but the twist is that every time we can pick only k courses only if 
      no of courses taken at a time crosses k at a time then we have to come out of the loop 
      2)and second variation is that we can't push in the queue the vertex as soon as the indegree for that vertex becomes zero 
      we have to first push it some set and when we have already taken all the k courses whose indegree was previously zero means whose
      prerequisites are over then only we have to push the new vertex in the queue whose indegree has become zero in the previous loop
      3)Rest all is same topological sort only 
    */
    int minNumberOfSemesters(int n, vector<vector<int>>& d, int k) 
    {
        int s=d.size();
        if(s==0)
        {
            if(n%k==0)
                 return (n/k);// if n is divisble by k then we can complete it in n/k days easily
           else if(n%k!=0)
                return (n/k)+1; // if n is divisble by k then we can complete it in (n/k)+1
        }
        
        vector<vector<int>>graph(n);
        vector<int>ind(n,0);
        for(int i=0;i<s;i++)
        {
            graph[d[i][0]-1].push_back(d[i][1]-1);// contructing the graph
            ind[d[i][1]-1]++;// counting the indegree of the vertices 
        } 
        // using kahn's algorithm for topological sort since it's simple to implement 
        // those who don't know kahn's algo please refer
        //https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
        
         queue<int> q;
        for(int i=0;i<n;i++)
        {
           if(ind[i]==0) q.push(i);
        }
        int cnt=n,semester=0;
        // semseter keeps the number of semesters needed to complete all the courses 
        while(cnt>0)
        {
            int temp=k;
             semester++;// counting the  number of semesters needed to complete the courses in k sets 
            unordered_set<int>z;// using set to store that vertices whose indegree becomes zero in below loop
            // since in the question it's given we can take only those courses whose pre-requisites have been completed 
            // previously 
            while(!q.empty()&&temp>0)
           {
              int p=q.front();
              temp--;
              cnt--;
              q.pop();
              for(int i=0;i<graph[p].size();i++)
              {
                ind[graph[p][i]]--;// since we took this course it means that this pre-requisite got over 
                  // so we can decrement the indegree of all the connected vertices to it 
                if(ind[graph[p][i]]==0)
                    z.insert(graph[p][i]);
                  // here is the second variation for which i was taking about previously
              }
          }
          if(z.size()!=0)
          {
             for(auto it=z.begin();it!=z.end();it++)
             {   
                q.push(*it);  // now pushing those vertices in the queue whose indegree  has become zero in the above loop
                 // because if we don't push them in the queue then it might be possible that it will not satisfy the criteria
                 // given in the question 
             }
          }   
        }
        return semester;
   }
};
