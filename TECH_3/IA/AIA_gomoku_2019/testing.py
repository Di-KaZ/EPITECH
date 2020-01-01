
board = [
    [1, 0, 0, 1, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]

def getScore(board, color):
        for line in board:
            for i in range(10 - 4):
                pattern = line[i:i+5]
                print(f"color = {pattern.count(color)}, empty = {pattern.count(0)}")

def getScoreVertical(board, color):
    for x in range(10):
        line = [row[x] for row in board]
        for i in range(10 - 4):
                pattern = line[i:i+5]
                print(f"color = {pattern.count(color)}, empty = {pattern.count(0)}")
