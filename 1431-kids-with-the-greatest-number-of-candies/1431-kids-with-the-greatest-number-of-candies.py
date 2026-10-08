class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
       MaxCandies = max(candies)
       result =[]
       for i in candies:
           if i+extraCandies >= MaxCandies:
               result.append(True)
           else : 
               result.append(False)
       return result