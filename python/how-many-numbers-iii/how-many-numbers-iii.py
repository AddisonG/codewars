def find_all(sum_digits, len_digits):
    result = seeker(sum_digits, 1, len_digits)
    return result if result else []

def seeker(sum_digits, min_digit, len_digits):
    if len_digits * min_digit > sum_digits or sum_digits > len_digits * 9:
        return
    if len_digits == 1:
        return [1, sum_digits, sum_digits]
    count = 0
    min = None
    max = 0
    for i in range(min_digit, 10):
        result = seeker(sum_digits - i, i, len_digits - 1)
        if not result:
            continue
        count += result[0]
        if not min and result[1]:
            min = i * 10 ** (len_digits - 1) + result[1]
        max = i * 10 ** (len_digits - 1) + result[2]
    return [count, min, max]
