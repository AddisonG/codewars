def permutations(string):
    if len(string) == 1:
        return [string]
    perms = []
    for c in set(string):
        for suffix in permutations(string.replace(c, '', 1)):
            perms.append(c + suffix)
    return perms
