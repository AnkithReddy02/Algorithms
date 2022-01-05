#define N 1005
    int sizex[N];
    int parent[N];
    // lets change again
    int findset(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        
        return parent[x] = findset(parent[x]);
    }
    void unionset(int a,int b)
    {
        int x = findset(a);
        int y = findset(b);
        
        if(x!=y)
        {
            if(sizex[y] > sizex[x])
            {
                swap(x,y);
            }
            sizex[x] += sizex[y];
            parent[y] = x;
        }
    }

    int main()
    {

    }
