class Solution:
    def totalNumbers(self, digits: List[int]) -> int:

        n=len(digits)
        st = set()

        for i in range(n):
            for j in range(n):
                for k in range(n):
                    if i==j or j==k or i==k:
                        continue
                        
                    num=100*digits[i]+10*digits[j]+digits[k]
                    if num>=100 and num%2==0:
                        st.add(num)

        return len(st)
