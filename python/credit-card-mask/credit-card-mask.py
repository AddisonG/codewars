# return masked string
def maskify(string):
    if len(string) <= 4:
        return string
    return max(0, len(string) - 4) * "#" + string[-4:]
