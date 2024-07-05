class Solution:
    def encode(self, strs: list[str]) -> str:
        encodedString = ""
        for string in strs:
            encodedString += str(len(string))
            encodedString += '#'
            encodedString += string
        return encodedString

    def decode(self, s: str) -> list[str]:
        print(s)
        list = []
        i = 0
        while i < len(s):
            start = i
            end = i+1
            while s[end] != "#": end += 1
            tokensize = int(s[start:end])
            token = s[end+1 : end+1+tokensize]
            print(token)
            list.append(token)
            i += (end - start + tokensize + 1)
        return list