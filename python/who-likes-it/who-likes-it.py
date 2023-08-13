def likes(names):
    if len(names) == 0:
        return "no one likes this"
    if len(names) == 1:
        return names[0] + " likes this"
    if len(names) == 2:
        return " and ".join(names[:2]) + " like this"
    start = ", ".join(names[:2])
    if len(names) == 3:
        end = " and " + names[2]
    else:
        end = f" and {len(names) - 2} others"
    return start + end + " like this"
