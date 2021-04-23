
#* 1832. Check if the Sentence Is Pangram

def checkIfPangram(sentence: str) -> bool:
    """ if sentence contains at least one of every letter of the English alphabet,    return true. """
    alphabet_set = "abcdefghijklmnopqrstuvwxyz"
    for char in alphabet_set:
        if char not in sentence:
            return False
    return True



sentence = "thequickbrownfoxjumpsoverthelazydog"
print(checkIfPangram(sentence))