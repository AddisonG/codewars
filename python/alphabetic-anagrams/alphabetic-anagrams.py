import math

def listPosition(word):
    if len(word) == 1:
        return 1
    divider = 1
    for letter in set(word):
        divider *= math.factorial(word.count(letter))
    
    return sorted(word).index(word[0]) * math.factorial(len(word) - 1) // divider + listPosition(word[1::])
