def pig_it(text):
    pigged = ""
    for word in text.split(" "):
        if word.isalpha():
            pigged += " " + word[1::] + word[0] + "ay"
        else:
            pigged += " " + word
    return pigged[1::]
