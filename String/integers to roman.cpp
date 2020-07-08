  map<int,string,greater<int>> mp;
    mp[1000]="M";
    mp[900]="CM";
     mp[500]="D";
    mp[400]="CD";
    mp[100]="C";
    mp[90]="XC";
   mp[50]="L";
    mp[40]="XL";
    mp[10]="X";
     mp[9]="IX";
    mp[5]="V";
    mp[4]="IV";
     mp[1]="I";
   int temp=A,flag=0;
    string res;
     auto it=mp.begin();
   while(it!=mp.end()&&temp!=0)
   { 
     if((temp-it->first)>=0&&temp!=0)
     {
      int h=it->first;
      int cnt=0;
      while((temp-h)>=0)
      {
          cnt++;
          temp-=h;
      }
      for(int i=0;i<cnt;i++)
      res+=(it->second);
     }
    
     it++;
     }
return res;
