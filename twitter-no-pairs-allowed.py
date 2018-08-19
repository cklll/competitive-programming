# Complete the minimalOperations function below.
def minimalOperations(words):
    results = []
    for word in words:
        word_length = len(word)
        word_list = list(word)
        count = 0

        i = 0
        while i < word_length - 1:
            if word_list[i] == word_list[i + 1]:
                count += 1
                word_list[i+1] = '.'  # just change to something which won't exist in original word

            i += 1

        results.append(count)
    
    return results
