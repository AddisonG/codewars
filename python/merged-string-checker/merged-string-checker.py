def is_merge(s, part1, part2):
    if len(part1) + len(part2) != len(s):
        return False
    
    pointer1 = 0
    pointer2 = 0
    for i, c in enumerate(s):
        if pointer1 < len(part1) and pointer2 < len(part2) and part1[pointer1] == c and part2[pointer2] == c:
            return is_merge(s[i + 1::], part1[pointer1 + 1::], part2[pointer2::]) or is_merge(s[i + 1::], part1[pointer1::], part2[pointer2 + 1::])
        elif pointer1 < len(part1) and part1[pointer1] == c:
            pointer1 += 1
        elif pointer2 < len(part2) and part2[pointer2] == c:
            pointer2 += 1
        else:
            return False
    return True
