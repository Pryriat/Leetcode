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
Explanation: The perimeter is the 16 yellow stripes in the image below:
![](https://assets.leetcode.com/uploads/2018/10/12/island.png)
*/

class Solution1 /*Initialise a vector which has 2 extra rows and 2 extra columns,cost more time and memory,easy codinig*/
{
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        vector<vector<int>> new_grid(grid.size()+2,vector<int>(grid[0].size()+2));
        int result=0;
        for(int i=1;i<grid.size()+1;i++)
            for(int j=1;j<grid[0].size()+1;j++)
                new_grid[i][j]=grid[i-1][j-1];
        for(int i=1;i<grid.size()+1;i++)
            for(int j=1;j<grid[0].size()+1;j++)
                if(new_grid[i][j])
                    result+=4-new_grid[i+1][j]-new_grid[i-1][j]-new_grid[i][j+1]-new_grid[i][j-1];
        return result;
    }
};
        
class Solution /*Burp force*/
{
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int result=0;
        int tmp=0;
        if(grid.size()==1&&grid[0].size()==1)
            return 4;
        else if(grid.size()==1 || grid[0].size()==1)
        {
            for(auto x:grid)
                for(auto y:x)
                    result+=y;
            return 2+result*2;
        }
        else
        {
            for(int x=0;x<grid.size();x++)
            {
                for(int y=0;y<grid[0].size();y++)
                {
                    if(grid[x][y])
                    {
                        if(x==0&&y==0)
                            result+=(4-grid[x+1][y]-grid[x][y+1]);
                        else if(x==0&&y==grid[0].size()-1)
                            result+=(4-grid[x+1][y]-grid[x][y-1]);
                        else if(x==grid.size()-1&&y==0)
                            result+=(4-grid[x-1][y]-grid[x][y+1]);
                        else if(x==grid.size()-1&&y==grid[0].size()-1)
                            result+=(4-grid[x-1][y]-grid[x][y-1]);
                        else if(x==0)
                            result +=(4-grid[x][y-1]-grid[x+1][y]-grid[x][y+1]);
                        else if(x==grid.size()-1)
                            result +=(4-grid[x][y-1]-grid[x-1][y]-grid[x][y+1]);
                        else if(y==0)
                            result+=(4-grid[x-1][y]-grid[x][y+1]-grid[x+1][y]);
                        else if(y==grid[0].size()-1)
                            result+=(4-grid[x-1][y]-grid[x][y-1]-grid[x+1][y]);
                        else
                            result+=(4-grid[x-1][y]-grid[x][y-1]-grid[x+1][y]-grid[x][y+1]); 
                    }   
                }    
            }    
        }    
        return result;
    }
};

