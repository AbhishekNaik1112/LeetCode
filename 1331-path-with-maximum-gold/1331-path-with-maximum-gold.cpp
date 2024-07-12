class Solution {
private:
    int searchGold(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == 0)
            return 0;

            int temp=grid[i][j];
            grid[i][j]=0;

            int top=searchGold(grid,i-1,j);
            int bot=searchGold(grid,i+1,j);
            int lef=searchGold(grid,i,j-1);
            int rig=searchGold(grid,i,j+1);

            grid[i][j]=temp;

            return temp+max({top,bot,lef,rig});
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
               if(grid[i][j]>0){
                maxGold=max(maxGold,searchGold(grid,i,j));
               }
            }
        }
        return maxGold;
    }
};