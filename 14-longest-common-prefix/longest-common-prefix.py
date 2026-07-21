class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        result = ""
        base = strs[0]

        if len(strs) == 0 : 
            return  ""

        for i in range(len(base)) :
            for words in strs[1:] : 
                if i == len(words) or words[i] != base[i] : 
                    return result 
            result = result + base[i] 

        return result              

        