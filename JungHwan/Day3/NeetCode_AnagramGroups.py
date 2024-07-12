class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s) != len(t)): return False
        for i in s:
            if(s.count(i) != t.count(i)): 
                return False
        return True

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        answers = []
        while(len(strs) != 0):
            print(strs)
            s = strs.pop(0)
            answer = [s]
            newList = strs[:]
            for i in strs:
                if Solution.isAnagram(Solution, s, i):
                    answer.append(i)  
                    newList.remove(i)
            strs = newList
            answers.append(answer)
        return answers        