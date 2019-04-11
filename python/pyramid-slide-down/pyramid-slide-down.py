def longest_slide_down(pyramid):
    previous = pyramid[0]
    for row in pyramid[1::]:
        for i, cell in enumerate(row):
            if i == 0:
                row[0] += previous[0]
            elif i == len(row) - 1:
                row[i] += previous[i - 1]
            else:
                row[i] += max(previous[i], previous[i - 1])
        previous = row
    return max(previous)
