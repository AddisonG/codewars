# Really sad I can't just do this with regex
# return re.sub(r"(.)\1+", r"\1", sequence)

def unique_in_order(sequence):
    result = []
    if not sequence:
        return result
    
    result.append(sequence[0])
    for item in sequence:
        if result[-1] != item:
            result.append(item)
    return result
