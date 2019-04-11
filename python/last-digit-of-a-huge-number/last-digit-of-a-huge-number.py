def last_digit(lst):
    if not lst:
        return 1
    if len(lst) == 1:
        return lst[0] % 10
    lst = lst[::-1]
    result = power(lst[1], lst[0])
    for num in lst[2::]:
        if result % 10 == 0:
            result %= 924 # Magic number. 11 * 21 * 4. I can't remember how I found this
        result = power(num, result)
    if result and not lst[-1]:
        return 1
    return result % 10

def power(base, exp):
    if not exp:
        return 1
    result = (base % 1000)
    for i in range(1, exp % 1000):
        result *= (base % 1000)
    return result
