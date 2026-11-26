class Solution:
    def canAliceWin(self, n: int) -> bool:
        stones = n
        remove = 10
        alice = True

        while stones >= remove:
            stones -= remove
            remove -= 1
            alice = not alice

        return not alice
        