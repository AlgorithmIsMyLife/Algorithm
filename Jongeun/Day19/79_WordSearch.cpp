class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        bool isFind{false};

        vector<vector<bool>> isPassed;

        for (int i = 0; i < board.size(); i++)
        {
            vector<bool> temp;
            for (int j = 0; j < board[i].size(); j++)
            {
                temp.push_back(false);
            }
            isPassed.push_back(temp);
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                _exist(board, isPassed, word, i, j, 0, isFind);
            }
        }

        return isFind;
    }

    void _exist(vector<vector<char>> &board, vector<vector<bool>> &isPassed, string &word, int i, int j, int step, bool &isFind)
    {
        // bound checking
        if (i < 0 || i >= board.size())
        {
            return;
        }

        if (j < 0 || j >= board[i].size())
        {
            return;
        }

        // safe bound

        // is Already Passed?
        if (isPassed[i][j])
        {
            return;
        }

        // found
        if (word[step] == board[i][j])
        {

            if (step == word.size() - 1)
            {
                // end index
                isFind = true;
                return;
            }

            isPassed[i][j] = true;
            // Not End index -> keep search(E,W,S,N)
            _exist(board, isPassed, word, i - 1, j, step + 1, isFind);
            _exist(board, isPassed, word, i, j - 1, step + 1, isFind);
            _exist(board, isPassed, word, i, j + 1, step + 1, isFind);
            _exist(board, isPassed, word, i + 1, j, step + 1, isFind);

            isPassed[i][j] = false;
        }
    }
};
