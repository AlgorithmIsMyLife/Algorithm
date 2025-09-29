class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {

    for (int i = 0; i < 9; i++) {
      string temp = "0123456789";
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          int idx = board[i][j] - '0';
          if (temp[idx] == '0') {
            return false;
          } else {
            temp[idx] = '0';
          }
        }
      }
    }

    for (int j = 0; j < 9; j++) {
      string temp = "0123456789";
      for (int i = 0; i < 9; i++) {

        if (board[i][j] != '.') {
          int idx = board[i][j] - '0';
          if (temp[idx] == '0') {
            return false;
          } else {
            temp[idx] = '0';
          }
        }
      }
    }

    vector<string> verify(9);

    for (int i = 0; i < 9; i++) {
      verify[i] = "0123456789";
    }

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          int idx = (i / 3) * 3 + (j / 3);
          int idx2 = board[i][j] - '0';

          if (verify[idx][idx2] == '0') {
            return false;

          } else {
            verify[idx][idx2] = '0';
          }
        }
      }
    }

    return true;
  };
};
