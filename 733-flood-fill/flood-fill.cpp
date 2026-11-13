
class Solution {
public:
    bool is_valid(int x, int y, vector<vector<int>>& image,
                  vector<vector<bool>>& visited, int oldColor) {

        int n = image.size();
        int m = image[0].size();

        if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] &&
            image[x][y] == oldColor) {

            return true;
        }

        return false;
    }

    void dfs(int x, int y, vector<vector<int>>& image,
             vector<vector<bool>>& visited, int oldColor, int newColor) {

        visited[x][y] = true;

        image[x][y] = newColor;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {

            int newx = x + dx[i];
            int newy = y + dy[i];

            if (is_valid(newx, newy, image, visited, oldColor)) {

                dfs(newx, newy, image, visited, oldColor, newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        int n = image.size();
        int m = image[0].size();

        int oldColor = image[sr][sc];

        // Important edge case
        if (oldColor == color) {
            return image;
        }

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        dfs(sr, sc, image, visited, oldColor, color);

        return image;
    }
};
