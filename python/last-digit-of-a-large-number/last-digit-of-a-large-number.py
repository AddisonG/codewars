def last_digit(n1, n2):
    if not n2:
        return 1
    result = (n1 % 100)
    for i in range(1, n2 % 100):
        result *= (n1 % 100)
    return result % 10
