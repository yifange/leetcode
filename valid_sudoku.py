class Solution:
    # @param board, a 9x9 2D array
    # @return a boolean
    def isValidSudoku(self, board):
        checklist = [False] * 9
        for i in range(9):
            for j in range(9):
                if board[i][j] != ".":
                    number = int(board[i][j]) - 1
                    if checklist[number]:
                        return False
                    else:
                        checklist[number] = True
            checklist = [False] * 9

        for i in range(9):
            for j in range(9):
                if board[j][i] != ".":
                    number = int(board[j][i]) - 1
                    if checklist[number]:
                        return False
                    else:
                        checklist[number] = True
            checklist = [False] * 9
        for x, y in [(0, 0), (0, 3), (0, 6), (3, 0), (3, 3), (3, 6), (6, 0), (6, 3), (6, 6)]:
            checklist = [False] * 9
            for i in range(3):
                for j in range(3):
                    if board[x + i][y + j] != ".":
                        number = int(board[x + i][y + j]) - 1
                        if checklist[number]:
                            return False
                        else:
                            checklist[number] = True
        return True

sol = Solution()
board = [
    ['5', '3', '.', '.', '7', '.', '.', '.', '.'],
    ['6', '.', '.', '1', '9', '5', '.', '.', '.'],
    ['.', '9', '8', '.', '.', '.', '.', '6', '.'],
    ['8', '.', '.', '.', '6', '.', '.', '.', '3'],
    ['4', '.', '.', '8', '.', '3', '.', '.', '1'],
    ['7', '.', '.', '.', '2', '.', '.', '.', '6'],
    ['.', '6', '.', '.', '.', '.', '2', '8', '.'],
    ['.', '.', '.', '4', '1', '9', '.', '.', '5'],
    ['.', '.', '.', '.', '8', '.', '.', '7', '9']
]
print sol.isValidSudoku(board)
