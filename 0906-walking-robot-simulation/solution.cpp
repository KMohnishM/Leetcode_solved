class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        set<pair<int,int>> st;
        for(auto &obs : obstacles){
            st.insert({obs[0], obs[1]});
        }

        int x = 0, y = 0;
        int dir = 0; // 0=N,1=E,2=S,3=W

        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};

        int maxdist = 0;

        for(int i = 0; i < commands.size(); i++){

            if(commands[i] == -1){
                dir = (dir + 1) % 4;
            }
            else if(commands[i] == -2){
                dir = (dir + 3) % 4;
            }
            else{
                int steps = commands[i];

                for(int j = 0; j < steps; j++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if(st.count({nx, ny})) break;

                    x = nx;
                    y = ny;

                    maxdist = max(maxdist, x*x + y*y);
                }
            }
        }

        return maxdist;
    }
};
