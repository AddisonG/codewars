def josephus_survivor(n, k):
    people = list(range(1, n + 1))
    index = 0
    while len(people) > 1:
        start = index
        index = (start + k - 1) % len(people)
        del people[index]
    return people[0]
