def sort_array(source_array):
    odds = [x for x in source_array if x % 2]
    odds.sort(reverse=True)

    return [odds.pop() if x % 2 else x for x in source_array]
