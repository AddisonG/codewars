def diamond(n):
    print(n)
    if n == None or n < 1 or n % 2 == 0:
        return None
    return recursive(n % 2, (n + 1) / 2 - 1)

def recursive(stars, spaces):
    if spaces <= 0:
        return '*' * stars + '\n'
    return "{}{}\n{}{}{}\n".format(' ' * spaces, '*' * stars, recursive(stars + 2, spaces - 1), ' ' * spaces, '*' * stars)
