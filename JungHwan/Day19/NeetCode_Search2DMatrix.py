class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        

        #first search
        colstart, colend = 0, len(matrix) - 1
        while colstart < colend:
            half = int((colstart + colend) / 2)
            print(matrix[half][0] , target)
            if matrix[half][0] < target:
                colstart = half + 1
            elif matrix[half][0] > target:
                colend = half - 1
            else:
                return True
        if matrix[colstart][0] == matrix[colend][0] == target:
            return True
        if matrix[colstart][0] > target:
            colstart -= 1
    
        #second search
        rowstart, rowend = 0, len(matrix[0]) - 1
        while rowstart < rowend:
            half = int((rowstart + rowend) / 2)
            print(matrix[colstart][half] , target)
            if matrix[colstart][half] < target:
                rowstart = half + 1
            elif matrix[colstart][half] > target:
                rowend = half - 1
            else:
                return True
        if matrix[colstart][rowstart] == matrix[colstart][rowend] == target:
            return True
        return False