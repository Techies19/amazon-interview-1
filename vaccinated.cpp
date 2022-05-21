 #include<bits/stdc++.h>
 using namespace std;
 int min_days_taken(vector<vector<char>>& arr) 
    {
        
        vector<int> dir={-1,0,1,0,-1}; //used for finding all 4 adjacent coordinates
        int m=arr.size();
        int n=arr[0].size();
        
        queue<pair<int,int>> q; // queue to store indexes
        int not_vaccinated=0; //To keep track of non_vaccinated countries
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]=='#')
                    q.push({i,j});
                if(arr[i][j]=='0')
                    not_vaccinated++;
            }
        int days_taken=0; 
        while(!q.empty())
        {
            int sz=q.size(); //size of queue
            while(sz--)
            {
                pair<int,int> p=q.front(); 
                q.pop(); // pop the indexes from  the queue
                for(int i=0;i<4;i++)
                {
                    int row=p.first+dir[i];
                    int col=p.second+dir[i+1];
                    if(row>=0 && row<m && col>=0 && col<n &&arr[row][col]=='0')
                    {
                        arr[row][col]='#';
                        q.push({row,col});
                        not_vaccinated--; // decrement by 1 foreach not vaccinated countries which are now vaccinated
                    }
                    
                }
            }
            if(!q.empty())
            days_taken++; //incremented after each day passes
        }
        if(not_vaccinated>0) return -1; //if not_vaccinated>0 it means all countries of category B are not vaccinated
        if(days_taken==0) return 0;
        return days_taken;
        
    }
    int main(){
        vector<vector<char>>vec={{'#','0','0'},{'*','0','0'},{'0','0','0'}};
        cout<<min_days_taken(vec);

    }
