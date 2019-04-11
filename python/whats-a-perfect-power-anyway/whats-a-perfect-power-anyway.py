def isPP(n):
    base = 2
    while base ** 2 <= n:
        exp = 2
        while base ** exp < n:
            exp += 1
        if base ** exp == n:
            return [base, exp]
        base += 1
    return None
