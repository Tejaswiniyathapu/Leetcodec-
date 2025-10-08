bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    
    
 int m = boardSize;
    int n = boardColSize[0];
    int len = strlen(word);

   
    bool dfs(int i, int j, int index) {
        if (index == len) return true;
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (board[i][j] != word[index]) return false;

        char temp = board[i][j];
        board[i][j] = '#';  

        bool found = dfs(i + 1, j, index + 1) ||
                     dfs(i - 1, j, index + 1) ||
                     dfs(i, j + 1, index + 1) ||
                     dfs(i, j - 1, index + 1);

        board[i][j] = temp;  
        return found;
    }

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(i, j, 0)) return true;
        }
    }

    return false;
}   




