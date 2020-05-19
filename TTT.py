from random import randint, choice
from os import system as bash
from time import time


def intInput(stringToDisplay='', min_value=1, max_value=9):
    while True:
        try:
            input_value = int(input(stringToDisplay))
            if (input_value >= min_value and input_value <= max_value):
                return input_value
            else:
                raise ValueError
        except ValueError:
            print('Input an integer number between {0} and {1}, please'.format(min_value, max_value))
        except Exception:
            print('Unexpected error or keyboard interrupt')

def defBoard():
    print('\
 ╔═══╦═══╦═══╗\t\n\
 ║ 1 ║ 2 ║ 3 ║\t\n\
 ╠═══╬═══╬═══╣\t\n\
 ║ 4 ║ 5 ║ 6 ║\t\n\
 ╠═══╬═══╬═══╣\t\n\
 ║ 7 ║ 8 ║ 9 ║\t\n\
 ╚═══╩═══╩═══╝ \t')

def drawBoard():
    print('\
 ╔═══╦═══╦═══╗\n\
 ║ {0} ║ {1} ║ {2} ║\n\
 ╠═══╬═══╬═══╣\n\
 ║ {3} ║ {4} ║ {5} ║\n\
 ╠═══╬═══╬═══╣\n\
 ║ {6} ║ {7} ║ {8} ║\n\
 ╚═══╩═══╩═══╝ '.format(
               board_status[1], board_status[2], board_status[3],
               board_status[4], board_status[5], board_status[6],     
               board_status[7], board_status[8], board_status[9]))


def askPlayerLetter():
    allowed_letters = ['X', 'O']
    letter = input('Do you want to be X or O? ').upper()
    while letter not in allowed_letters:
        letter = input('Please choose between {} and {}: '.format(
            *allowed_letters)).upper()
    if letter == 'X':
        return allowed_letters
    if letter == 'Q':
        return allowed_letters
    else:
        return allowed_letters[::-1]


def whoGoesFirst():
    # Timer used to count 0.75 seconds while displaying who goes first
    if randint(0, 1) == 0:
        CurrentTime, Timer = time(), time() + 0.75
        print('You go first')
        while Timer > CurrentTime:
            CurrentTime = time()
        return 'player'
    else:
        CurrentTime, Timer = time(), time() + 0.75
        print('Computer goes first')
        while Timer > CurrentTime:
            CurrentTime = time()
        return 'computer'


def makeMove(Board, Move, Letter):
    Board[Move] = Letter


def isSpaceFree(Board, Move):
    return Board[Move] == ' '


def playerMove():
    Move = 0
    while not (0 < Move < 10) or not (isSpaceFree(board_status, int(Move))):
        Move = intInput('It\'s your move:\nType Ctrl + C to exit\nWhere would you like to move (1-9)?: ')
    return int(Move)


def isWinner(brd, lttr):
    # Returns a boolean value. brd (board) and lttr (letter) used to make
    # code block compact.
    return ((brd[7] == lttr and brd[8] == lttr and brd[9] == lttr) or
            (brd[4] == lttr and brd[5] == lttr and brd[6] == lttr) or
            (brd[1] == lttr and brd[2] == lttr and brd[3] == lttr) or
            (brd[7] == lttr and brd[5] == lttr and brd[3] == lttr) or
            (brd[9] == lttr and brd[5] == lttr and brd[1] == lttr) or
            (brd[7] == lttr and brd[4] == lttr and brd[1] == lttr) or
            (brd[8] == lttr and brd[5] == lttr and brd[2] == lttr) or
            (brd[9] == lttr and brd[6] == lttr and brd[3] == lttr))


def computerMove():
    '''
    Simple AI that checks
    1)Can computer win in the next move
    2)Can player win in the next move
    3)Is there any free corner
    4)Is center is free
    5)Is there any free side
    And returns a move digit

    '''


    for i in range(1, 10):
        Copy = board_status.copy()
        if isSpaceFree(Copy, i):
            makeMove(Copy, i, ComputerLetter)
            if isWinner(Copy, ComputerLetter):
                return i

    for i in range(1, 10):
        Copy = board_status.copy()
        if isSpaceFree(Copy, i):
            makeMove(Copy, i, PlayerLetter)
            if isWinner(Copy, PlayerLetter):
                return i

    move = randomMoveFromList([7, 9, 1, 3])
    if move is not None:
        return move

    if isSpaceFree(board_status, 5):
        return 5

    move = randomMoveFromList([8, 4, 2, 6])
    if move is not None:
        return move


def randomMoveFromList(MovesList):
    PossibleMoves = []
    for i in MovesList:
        if isSpaceFree(board_status, i):
            PossibleMoves.append(i)
    if len(PossibleMoves) != 0:
        return choice(PossibleMoves)
    else:
        return None


def isBoardFull():
    for i in range(1, 10):
        if isSpaceFree(board_status, i):
            return False
    return True


def playAgain():
    print('Do you want to play again? [y/N] ')
    PlayAgainInput = input().lower()
    return (PlayAgainInput.startswith('y') or PlayAgainInput == '')

# "bash('clear')" function simply clears the screen of the terminal.
# If you want run this script on system that uses other shell then
# substitute "clear" with a command that your shell uses to clear the screen
# P.S. for windows it is "cls".

bash('clear')
print('Welcome to Tic Tac Toe')
PlayAgainWish = True
print('To win, you have to place 3 X-s or O-s in a row.\n\
Use NumPad to enter your move. Here is the key map.')
board_status = ['', 1, 2, 3, 4, 5, 6, 7, 8, 9]
drawBoard()
print('You have to be sure that you are making move to a free cell.\n\n')
PlayerLetter, ComputerLetter = askPlayerLetter()
while PlayAgainWish:
    bash('clear')
    board_status = 10 * [' ']
    turn = whoGoesFirst()
    while True:
        if turn == 'player':
            bash('clear')
            print('   YOUR MOVE')
            defBoard()
            drawBoard()
            move = playerMove()
            makeMove(board_status, move, PlayerLetter)
            turn = 'computer'
            if isWinner(board_status, PlayerLetter):
                bash('clear')
                print('Hooray, you have won the game!')
                defBoard()
                drawBoard()
                PlayAgainWish = playAgain()
                break
            elif isBoardFull():
                bash('clear')
                print("It's a tie!")
                defBoard()
                drawBoard()
                PlayAgainWish = playAgain()
                break
        else:
            # All this dots and timers are used to make animation of
            # computer moving. You will understand if you will run the script.
            for i in ['', '.', '..', '...']:
                bash('clear')
                print(' Computer is making move' + i)
                defBoard()
                drawBoard()
                CurrentTime, Timer = time(), time() + 0.15
                while Timer > CurrentTime:
                    CurrentTime = time()
                if i == '..':
                    move = computerMove()
                    makeMove(board_status, move, ComputerLetter)
                    turn = 'player'
            if isWinner(board_status, ComputerLetter):
                bash('clear')
                print('Oops, you lose!')
                defBoard()
                drawBoard()
                PlayAgainWish = playAgain()
                break
            elif isBoardFull():
                bash('clear')
                print("It's a tie!")
                drawBoard()
                PlayAgainWish = playAgain()
                break