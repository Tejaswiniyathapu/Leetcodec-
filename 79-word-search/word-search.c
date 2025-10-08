bool dfs(char** board, int i, int j, int m, int n, char* word, int index) {
    if (word[index] == '\0') return true;
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index])
        return false;

    char temp = board[i][j];
    board[i][j] = '#';

    bool found = dfs(board, i + 1, j, m, n, word, index + 1) ||
                 dfs(board, i - 1, j, m, n, word, index + 1) ||
                 dfs(board, i, j + 1, m, n, word, index + 1) ||
                 dfs(board, i, j - 1, m, n, word, index + 1);

    board[i][j] = temp;
    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int m = boardSize;
    int n = boardColSize[0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(board, i, j, m, n, word, 0))
                return true;
        }
    }
    return false;
}
