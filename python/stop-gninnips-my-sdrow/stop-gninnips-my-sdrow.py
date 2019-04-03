def spin_words(sentence):
    result = ''
    words = sentence.split(' ')
    
    for word in words:
        if (len(word) >= 5):
            result += " " + reverse(word)
        else:
            result += " " + word
    
    return result[1::]

def reverse(word):
    reversedWord = ''
    for letter in word:
        reversedWord = letter + reversedWord
    return reversedWord
