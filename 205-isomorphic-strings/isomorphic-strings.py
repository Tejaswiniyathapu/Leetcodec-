class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        map1={}
        map2={}
        for i in range(len(s)):
            ch1= s[i]
            ch2 = t[i]
            if ch1 in map1 and map1[ch1]!=ch2:
                return False
            if ch2 in map2 and map2[ch2]!=ch1:
                return False
            map1[ch1]= ch2
            map2[ch2]=ch1
        return True        