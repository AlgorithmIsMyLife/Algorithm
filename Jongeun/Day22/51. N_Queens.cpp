class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<string> board;
        for (int i = 0; i < n; i++)
        {
            string temp = "";
            for (int j = 0; j < n; j++)
            {
                temp.push_back('.');
            }
            board.push_back(temp);
        }
        vector<int> col(n + 1);
        _solveNQueens(result, col, board, 0, n);

        return result;
    }

    void _solveNQueens(vector<vector<string>> &result, vector<int> &col, vector<string> &board, int step, int n)
    {
        if (isPromising(col, step))
        {
            if (step == n)
            {
                // push the col
                for (int i = 1; i < n + 1; i++)
                {
                    board[i - 1][col[i] - 1] = 'Q';
                }
                result.push_back(board);

                // restore
                for (int i = 1; i < n + 1; i++)
                {
                    board[i - 1][col[i] - 1] = '.';
                }

                return;
            }
            else
            {
                for (int j = 1; j < n + 1; j++)
                {
                    col[step + 1] = j;
                    _solveNQueens(result, col, board, step + 1, n);
                }
            }
        }
    }

    bool isPromising(vector<int> &col, int step)
    {
        if (step == 0)
        {
            return true;
        }

        int j = 1;
        while (j < step)
        {
            if (col[step] == col[j] || abs(col[step] - col[j]) == (step - j))
            {
                return false;
            }
            j++;
        }

        return true;
    }
};
