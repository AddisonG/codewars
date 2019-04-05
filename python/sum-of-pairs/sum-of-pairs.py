def sum_pairs(array, target):
    passed = set()
    for i in range(0, len(array)):
        element = array[i]
        if (target - element) in passed:
            return [target - element, element]
        passed.add(element)
