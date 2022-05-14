void djikstra(int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    pq.push({0,s});

    while(pq.size())
    {


    }

    for(int i=0;i<n;i++){
        cout<<dist[i]<<" "<<endl;
    }
}


 vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int>ans(V+1,INT_MAX);
        ans[s]=0;
        pq.push({0,s});

        while(pq.size())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for(auto it:adj[node])
            {
                int adjnode = it[0];
                int wt = it[1];

                if(wt+dist<ans[adjnode])
                {
                    ans[adjnode] = wt+dist;
                    pq.push({wt+dist,adjnode});
                }
            }
        }
        return ans;
    }


 int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &dest)
    {

    priority_queue<pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>>pq;

    int n  = maze.size();
    int m = maze[0].size();

    vector<int> dist(n*m+1,INT_MAX);

    dist[start[0]*m+start[1]] = 0;

    pq.push({0,{start[0],start[1]}});

    int dx[] = {-1,+1,0,0};
    int dy[] = {0,0,+1,-1};

    while(pq.size())
    {
        int dis = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        for(int i =0;i<4;i++)
        {
            int nx = x;
            int ny = y;
            int c=0;
            while(nx>=0 && ny>=0 && nx<n && ny<m && maze[nx][ny]==0)
            {
                nx = nx+dx[i];
                ny = ny+dy[i];
                c++;
            }
            nx -=dx[i];
            ny -=dy[i];
            c--;

            if(dis+c<dist[nx*m+ny])
            {
                dist[nx*m+ny] = dis+c;
                pq.push({dis+c,{nx,ny}});
            }
        }
    }
    if(dist[dest[0]*m+dest[1]]==INT_MAX) return -1;

    return dist[dest[0]*m+dest[1]];
    }


 int countPaths(int n, vector<vector<int>>& roads)
    {
        long long int mod = (1e9+7);
        vector<long long > ways(n,0);
        vector<long long > dist(n,LONG_MAX);

        dist[0] = 0;
        ways[0] = 1;

        vector<pair<long long ,long long >>adj[n];

        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }


        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>, greater<pair<long long int,long long int>>>pq;
        pq.push({0,0});

        while(pq.size())
        {
            long long int node = pq.top().second;
            long long int dis = pq.top().first;
            pq.pop();

            for(auto it: adj[node])
            {
                long long int wt = it.second;
                long long int adjnode = it.first;

                if(wt+dis<dist[adjnode])
                {
                    dist[adjnode] = wt+dis;

                    ways[adjnode] = ways[node];
                    pq.push({wt+dis,adjnode});
                }
                else if(wt+dis==dist[adjnode])
                    ways[adjnode]= (ways[adjnode]%mod+ ways[node]%mod)%mod;

            }
        }

        return ways[n-1]%mod ;

    }


 int countPaths(int n, vector<vector<int>>& roads)
    {
        long long int mod = (1e9+7);
        vector<long long > ways(n,0);
        vector<long long > dist(n,LONG_MAX);

        dist[0] = 0;
        ways[0] = 1;

        vector<pair<long long ,long long >>adj[n];

        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }


        priority_queue<pair<long long int,long long int>
        ,vector<pair<long long int,long long int>>,
         greater<pair<long long int,long long int>>>pq;

        pq.push({0,0});

        while(pq.size())
        {
            long long int node = pq.top().second;
            long long int dis = pq.top().first;
            pq.pop();

            for(auto it: adj[node])
            {
                long long int wt = it.second;
                long long int adjnode = it.first;

                if(wt+dis<dist[adjnode])
                {
                    dist[adjnode] = wt+dis;

                    ways[adjnode] = ways[node];
                    pq.push({wt+dis,adjnode});
                }
                else if(wt+dis==dist[adjnode])
                    ways[adjnode]= (ways[adjnode]%mod+ ways[node]%mod)%mod;

            }
        }

        return ways[n-1]%mod ;

    }


 long long karyTree(int kd, int m) {

      long long int ans=1,mod=1e9+7,k=kd;

      while(m)
      {
          cout<<ans<<endl;
          if(m&1)
          {
              ans *=k;
              ans %=mod;
              m--;
          }
          else
          {
              k = k*k;
              k %= mod;
              m /= 2;
          }
      }
      return ans%mod;

    }
