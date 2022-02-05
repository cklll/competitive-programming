# https://leetcode.com/problems/design-add-and-search-words-data-structure/

class Node:
    def __init__(self):
        self.children = {}
        self.isWord = False


class WordDictionary:
    def __init__(self):
        self.root = Node()


    def addWord(self, word: str) -> None:
        root = self.root
        for char in word:
            if char in root.children:
                root = root.children[char]
            else:
                node = Node()
                root.children[char] = node
                root = node
        root.isWord = True

    def search(self, word: str) -> bool:
        return self.dfs(word, self.root)

    def dfs(self, word, root):
        if len(word) == 1:
            if word[0] == '.':
                for _, node in root.children.items():
                    if node.isWord:
                        return True
                return False
            else:
                if word[0] in root.children:
                    return root.children[word[0]].isWord
                return False

        if word[0] == '.':
            for _, node in root.children.items():
                tmp_result = self.dfs(word[1:], node)
                if tmp_result:
                    return True
            return False

        if word[0] in root.children:
            return self.dfs(word[1:], root.children[word[0]])

        return False






# Your WordDictionary object will be instantiated and called as such:
obj = WordDictionary()

obj.addWord("bad")
obj.addWord("dad")
obj.addWord("mad")
print(obj.search("pad"))
print(obj.search("bad"))
print(obj.search(".ad"))
print(obj.search("b.."))
