def snail(array):
    # Boundaries
    top = left = 0
    bot = right = len(array) - 1
    
    # Edge cases
    if len(array[0]) == 0:
        return []
    if len(array[0]) == 1:
        return [array[0][0]]
    
    # X,Y / col,row / horizontal,vertical
    pointer = [0, 0]
    dir = [1, 0]
    output = []
    
    while top <= bot and left <= right:
        output.append(array[pointer[1]][pointer[0]])
        
        if dir[0] == 1 and pointer[0] == right:
            dir = (0, 1) # Go down
            top += 1
        elif dir[1] == 1 and pointer[1] == bot:
            dir = (-1, 0) # Go left
            right -= 1
        elif dir[0] == -1 and pointer[0] == left:
            dir = (0, -1) # Go up
            bot -= 1
        elif dir[1] == -1 and pointer[1] == top:
            dir = (1, 0) # Go right
            left += 1
        
        pointer[0] += dir[0]
        pointer[1] += dir[1]
    
    return output
