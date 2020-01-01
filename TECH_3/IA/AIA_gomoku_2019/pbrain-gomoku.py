#!/usr/bin/python3
from random import randint, choice, shuffle
from copy import deepcopy
from math import inf
import time

other_color_g = 2
ia_color_g = 1
depth_g = 3

# usual function
def splitCommand(string):
    return string.replace(',', ' ').split()

def takeSecond(elem):
    return elem[1]

# class Board
class Board:
    def __init__(self, width, height):
        empty = 0
        self.width = width
        self.height = height
        self.board = [x[:] for x in [[empty] * width] * height]
        self.t_end = time.time() + 4.8

    def resetTime(self):
        self.t_end = time.time() + 4.8

    def getCurrentBoard(self):
        return self.board

    def displayBoard(self, board):
        for line in board:
            for char in line:
                print(char, end='')
            print()

    def reset(self):
        empty = 0
        self.board = [x[:] for x in [[empty] * self.width] * self.height]

    def isSourrounded(self, x, y, board):
        if x - 1 >= 0 and board[y][x - 1] != 0:
            return True
        if x + 1 < self.width - 1 and board[y][x + 1] != 0:
            return True
        if y - 1 >= 0 and board[y - 1][x] != 0:
            return True
        if y + 1 < self.height - 1 and board[y + 1][x] != 0:
            return True
        return False

    def getBestScoreNow(self, valid_moves, color):
        valid_move_score = []
        board_cpy = deepcopy(self.board)
        for valid_move in valid_moves:
            board_cpy[valid_move[1]][valid_move[0]] = color 
            valid_move_score.append((valid_move, self.getScore(board_cpy, color)))
            board_cpy[valid_move[1]][valid_move[0]] = 0
        valid_move_score.sort(key=takeSecond, reverse=True)
        return [x[0] for x in valid_move_score]

    def getValidMovesCoord(self, board, sourrounded):
        valid_moves = []
        for y, line in enumerate(board, 0):
            for x, box in enumerate(line, 0):
                if sourrounded:
                    if box == 0  and self.isSourrounded(x, y, board):
                        valid_moves.append((x, y))
                else:
                    if box == 0:
                        valid_moves.append((x, y))
        return self.getBestScoreNow(valid_moves, ia_color_g)

    def putOnCoord(self, x, y, color):
        self.board[y][x] = color

    def isEndGame(self, board, player):
        # vertical 
        for x in range(self.width):
            line = [row[x] for row in board]
            for i in range(self.height - 4):
                pattern = line[i:i+5]
                if pattern.count(1) == 5 or pattern.count(2) == 5:
                    return True
        # horizontal
        for line in board:
            for i in range(self.width - 4):
                pattern = line[i:i+5]
                if pattern.count(1) == 5 or pattern.count(1) == 2: 
                    return True
        return False

    def getWidth(self):
        return self.width - 1

    def getHeight(self):
        return self.height - 1

    def getShapeScore(self, consecutive_num, open_num, color):
        if open_num == 0 and consecutive_num:
            return 0
        if consecutive_num == 4:
            if open_num == 1:
                return 100000000
            if open_num == 2:
                return 100000000
        elif consecutive_num == 3:
            if open_num == 1:
                return 7
            if open_num == 2:
                return 100000000
        elif consecutive_num == 2:
            if open_num == 1:
                return 2
            if open_num == 2:
                return 5
        elif consecutive_num == 3:
            if open_num == 1:
                return 0.5
            if open_num == 2:
                return 1
        else:
            return 10000000000

    def getScore(self, board, color):
        score = 0
        # horizontal
        for line in board:
            for i in range(self.width - 4):
                pattern = line[i:i+5]
                score += self.getShapeScore(pattern.count(color), pattern.count(0), color)
        # vertical
        for x in range(self.width):
            line = [row[x] for row in board]
            for i in range(self.height - 4):
                pattern = line[i:i+5]
                score += self.getShapeScore(pattern.count(color), pattern.count(0), color)
        return score

    def isLastNode(self, board):
        return self.isEndGame(board, None) or len(self.getValidMovesCoord(board, True)) == 0

    def miniMax(self, board, depth, alpha, beta, maximizing_player):
        valid_moves = self.getValidMovesCoord(board, True)
        terminal_node = self.isLastNode(board)
        if depth == 0 or terminal_node:
            if terminal_node:
                if self.isEndGame(board, ia_color_g):
                    return (None, 10000000000)
                elif self.isEndGame(board, other_color_g):
                    return (None, -10000000000)
                else:
                    return (None, 0)
            else:
                return (None, self.getScore(board, ia_color_g))
        if maximizing_player:
            val = -inf
            coo = choice(valid_moves)
            for coord in valid_moves:
                if time.time() > self.t_end:
                    break
                board_copy = deepcopy(self.board)
                board_copy[coord[1]][coord[0]] = ia_color_g
                new_score = self.miniMax(board_copy, depth - 1, alpha, beta, False)[1]
                if new_score > val:
                    val = new_score
                    coo = coord
                alpha = max(alpha, val)
                if alpha >= beta:
                    break
            return coo, val
        else:
            val = inf
            coo = choice(valid_moves)
            for coord in valid_moves:
                if time.time() > self.t_end:
                    break
                board_copy = deepcopy(self.board)
                board_copy[coord[1]][coord[0]] =other_color_g
                new_score = self.miniMax(board_copy, depth - 1, alpha, beta, True)[1]
                if new_score < val:
                    val = new_score
                    coo = coord
                beta = min(beta, val)
                if alpha >= beta:
                    break
            return coo, val

# class Gomoku
class Gomoku:
    def __init__(self):
        self.commands = {
            "TURN"      : self.cmdTurn,
            "BEGIN"     : self.cmdBegin,
            "BOARD"     : self.cmdBoard,
            "INFO"      : self.cmdInfo,
            "END"       : self.cmdEnd,
            "ABOUT"     : self.cmdAbout,
            "RESTART"   : self.cmdRestart
        }
        self.status = False

    def cmdRestart(self, command):
        self.board.reset()
        print('OK')

    def cmdAbout(self, command):
        print("OC Team [William, Moussa] gomoku AI ft. MiniMax")

    def cmdEnd(self, command):
        exit(0) # exit normaly

    def cmdInfo(self, command):
        return # do nothing with this

    def start(self, command):
        if len(command) == 2 and command[0] == "START" and int(command[1]) != 0:
            self.status = True
            self.board = Board(int(command[1]), int(command[1]))
            print("OK")
        elif len(command) == 3 and command[0] == "RECTSTART" and int(command[1]) != 0 and int(command[1]) != 0:
            self.status = True
            self.board = Board(int(command[1]), int(command[2]))
            print("OK")
        if self.status == False:
            print("ERROR wrong command")
            exit(84)

    def cmdTurn(self, command):
        if len(command) == 3:
            self.board.putOnCoord(int(command[1]), int(command[2]), other_color_g) # other turn
            self.board.resetTime()
            coord, _ = self.board.miniMax(self.board.getCurrentBoard(), depth_g, -inf, inf, True)
            if coord == None:
                coords = self.board.getValidMovesCoord(self.board.getCurrentBoard(), True)
                if len(coords) == 0:
                    exit(0)
                coord = coords[0]
            self.board.putOnCoord(int(coord[0]), int(coord[1]),  ia_color_g) #IA turn
            print(f"{coord[0]},{coord[1]}")
        else:
            print("ERROR coordinate are invalid")

    def cmdBegin(self, command):
        if len(command) == 1:
            self.begin = True
            x = randint( 0, self.board.getWidth() - 1)
            y = randint(0, self.board.getHeight() - 1)
            self.board.putOnCoord(x, y, ia_color_g)
            print(f"{x},{y}")

    def cmdBoard(self, command):
        self.board.reset()
        while True:
            sub_cmd = splitCommand(input())
            if sub_cmd[0] == "DONE":
                break
            self.board.putOnCoord(int(sub_cmd[0]), int(sub_cmd[1]), ia_color_g if sub_cmd[2] == '1' else other_color_g)
        self.board.resetTime()
        coord, _ = self.board.miniMax(self.board.getCurrentBoard(), depth_g, -inf, inf, True)
        if coord == None:
            coords = self.board.getValidMovesCoord(self.board.getCurrentBoard(), True)
            if len(coords) == 0:
                exit(0)
            coord = coords[0]
        self.board.putOnCoord(int(coord[0]), int(coord[1]), ia_color_g)
        print(f"{int(coord[0])},{int(coord[1])}")


    def run(self):
        while True:
            command = splitCommand(input())

            if len(command) == 0:
                pass
            self.start(command)
            if self.status == True and command[0] in self.commands:
                self.commands[command[0]](command)
# class Gomoku


test = Gomoku()
test.run()