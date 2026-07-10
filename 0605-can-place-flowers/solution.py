class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        cnt=0
        for i in range(len(flowerbed)):
           
            left = (i == 0) or flowerbed[i-1] == 0
            right = (i == len(flowerbed)-1) or flowerbed[i+1] == 0
            if flowerbed[i] == 0 and left and right:
                flowerbed[i] = 1
                cnt += 1
        return cnt>=n
