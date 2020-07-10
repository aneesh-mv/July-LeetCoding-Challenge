/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16
*/
class Solution {
public:
    int dfs(int i,int j, vector<vector<int>> &grid)
    {
        if(i<0||i>grid.size()-1||j>grid[0].size()-1||j<0||grid[i][j]==0)
        {
            return 1;
        }
        if(grid[i][j]==2)
        {
            return 0;
        }
        grid[i][j] = 2;
        int left = dfs(i,j-1,grid);
        int right = dfs(i,j+1,grid);
        int up = dfs(i-1,j,grid);
        int down = dfs(i+1,j,grid);
        
        return up+down+left+right;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        if(n==0||m==0)
        {
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    count = dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};
