class Solution {
public:
    vector<vector<int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor=image[sr][sc];

        if(oldColor==color) return image;

        queue<pair<int,int>>q;
        q.push({sr,sc});

        image[sr][sc] = color;

        while(!q.empty()){
            auto current=q.front();
            q.pop();

            int r=current.first;
            int c=current.second;

            for(auto &dir:directions){
                int new_r=dir[0]+r;
                int new_c=dir[1]+c;

                if(new_r>=0 && new_c>=0 && new_r<image.size() && new_c<image[0].size() && image[new_r][new_c]==oldColor){
                    image[new_r][new_c]=color;
                    q.push({new_r,new_c});
                }
            }
        }
        return image;
    }
};