class Solution {
public:
    bool dfs(vector<int>& arr, int i, vector<int>& visited) {
        int n = arr.size();

        
        if (i < 0 || i >= n || visited[i]) {
            return false;
        }

        
        if (arr[i] == 0) {
            return true;
        }

        visited[i] = 1;

        return dfs(arr, i + arr[i], visited) || dfs(arr, i - arr[i], visited);
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n, 0);

        return dfs(arr, start, visited);
    }
};
