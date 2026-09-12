class Solution {
public:
    vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>&image,int r,int c,int oldColor,int color){
        image[r][c]=color;

        for(auto &dir:directions){
            int newr=dir[0]+r;
            int newc=dir[1]+c;

            if(newr>=0 && newc>=0 && newr<image.size() && newc<image[0].size() && image[newr][newc]==oldColor){
                dfs(image,newr,newc,oldColor,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor=image[sr][sc];

        if(oldColor==color) return image;

        dfs(image,sr,sc,oldColor,color);

        return image;
    }
};