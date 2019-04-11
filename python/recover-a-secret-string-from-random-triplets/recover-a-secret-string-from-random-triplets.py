def recoverSecret(triplets):
    before = {}
    for triplet in triplets:
        for i, c in enumerate(triplet):
            if c not in before:
                before[c] = set()
        before[triplet[1]].add(triplet[0])
        before[triplet[2]].update([triplet[0], triplet[1]])
    
    phrase = ""
    for i in range(0, len(before)):
        for key in before:
            if not before[key]:
                phrase += key
                break;
        before.pop(key)
        for other in before:
            before[other].discard(key)
    
    return phrase
