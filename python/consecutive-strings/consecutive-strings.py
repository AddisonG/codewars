def longest_consec(strarr, k):
    if (len(strarr) == 0) or (k > len(strarr)) or (k <= 0):
        return ""
    listy = []
    longest = ""
    for i, string in enumerate(strarr):
        listy.append(0)
        # Store length in list
        for j in range(max(0, i - k + 1), i + 1):
            listy[j] += len(string)
            # Record new longest value
            if (listy[j] > len(longest)) and ((i + 1 >= j + k) or (i + 1 == len(strarr))):
                longest = strarr[j]
                for element in strarr[j+1:i+1]:
                    longest += str(element)
    return longest
