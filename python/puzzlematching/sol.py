def matrix_compare(m1,m2) :
    for i in range(6) :
        for j in range(6):
            if m1[i][j] != m2[i][j] :
                return False
    return True
def rotate_blocks(blocks):
    size = 6
    new_blocks = []
    for block in blocks:
        y,x = block
        new_blocks.append((x,size-1-y))
    return normalize(new_blocks)

def normalize(blocks) :
    new_blocks = []
    y = min([b[0] for b in blocks])
    x = min([b[1] for b in blocks])
    for b in blocks :
        p,q = b
        new_blocks.append((p-y,q-x))
    
    return new_blocks

def blocks_to_matrix(blocks) :
    matrix = [[0] * 6 for _ in range(6)]
    for b in blocks :
        p,q = b
        matrix[p][q] = 1
    return matrix

def scan(point,board) :
    size = len(board)
    blocks = [point]
    board[point[0]][point[1]] = 1
    y,x = point
    if 0 <= y-1 and board[y-1][x] == 0 :
        blocks = blocks + scan((y-1,x),board)
    if 0 <= x-1 and board[y][x-1] == 0 :
        blocks = blocks + scan((y,x-1),board)
    if y+1 < size and board[y+1][x] == 0 :
        blocks = blocks + scan((y+1,x),board)
    if x+1 < size and board[y][x+1] == 0 :
        blocks = blocks + scan((y,x+1),board)
    return blocks
    


def solution(game_board, table):
    size = len(game_board)
    #scan board to 4 matrix
    board_info = [] #list of len of each blocks
    board_matrix = []
    for i in range(size) :
        for j in range(size) :
            if game_board[i][j] == 0 :
                blocks = scan((i,j),game_board)
                board_info.append(len(blocks))
                board_matrix.append(blocks_to_matrix(normalize(blocks)))
    
    #scan table to 4 matrix
    
    #flip
    for i in range(size) :
        for j in range(size) :
            if table[i][j] == 0:
                table[i][j] = 1
            else :
                table[i][j] = 0
    
    table_info = [] #size of each blocks. -1 when already used
    table_matrix = [] # each unit is made of 4 matrix
    for i in range(size) :
        for j in range(size) :
            if table[i][j] == 0 :
                blocks = scan((i,j),table)
                table_info.append(len(blocks))
                unit = []
                blocks = normalize(blocks)
                unit.append(blocks_to_matrix(blocks))
                for t in range(3) :
                    blocks = rotate_blocks(blocks)
                    unit.append(blocks_to_matrix(normalize(blocks)))
                table_matrix.append(unit)
    
    answer = 0
    # find matching blocks
    for i in range(len(board_info)) :
        l = board_info[i]
        matrix = board_matrix[i]
        for j in range(len(table_info)) :
            if table_info[j] != l:
                continue
            flag = False
            for m in table_matrix[j] :
                if matrix_compare(matrix,m) : #found
                    flag = True
                    break
            if flag :
                table_info[j] = -1
                answer += l
                break
        

    return answer