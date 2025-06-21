class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n=len(matrix)
        m=len(matrix[0])
        listi=[]
        listj=[]
        # print(m)
        for i in range(n):
            for j in range(m):
                if matrix[i][j]==0 :
                    listi.append(i)
                    listj.append(j)
                
        for i in range(n):
            for j in range(m):
                if i in listi or j in listj :
                    matrix[i][j]=0
        return matrix            
