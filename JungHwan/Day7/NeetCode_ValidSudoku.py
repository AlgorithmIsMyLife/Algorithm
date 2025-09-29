class Solution:

    #check 3 * 3 grid where left top coor is (x,y)
    def checkGrid(self, board, x, y):
        list = [False] * 10
        for j in range(x,x+3):
            for i in range(y,y+3):
                print(board[j][i])
                if board[j][i] == ".": continue
                elif list[int(board[j][i])] == False:
                    list[int(board[j][i])] = True
                else: return False
        return True


    def checkRow(self, board, y):
        list = [False] * 10
        for i in range(9):
            if board[y][i] == ".": continue
            elif list[int(board[y][i])] == False:
                list[int(board[y][i])] = True
            else: return False
        return True
        
    def checkCol(self, board, x):
        list = [False] * 10
        for i in range(9):
            if board[i][x] == ".": continue
            elif list[int(board[i][x])] == False:
                list[int(board[i][x])] = True
            else: return False
        return True


    def isValidSudoku(self, board: list[list[str]]) -> bool:
        result = True
        for i in range(9):
            result &= Solution.checkCol(Solution, board, i)
            result &= Solution.checkRow(Solution, board, i)
        for i in range(0,9,3):
            for j in range(0,9,3):
                result &= Solution.checkGrid(Solution, board, j, i)
        return result
    
