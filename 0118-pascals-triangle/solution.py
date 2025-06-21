class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows==1:
            list1=[[1]]
            return list1
        if numRows==2:
            list1=[[1],[1,1]]
            return list1
        list1=[[1],[1,1]]
        for i in range(2,numRows):
            list2=[]
            for j in range(i+1):

                if j==0 or j==i:
                  
                  list2.append(1)
                else:
                    list2.append(list1[i-1][j-1]+list1[i-1][j])
            list1.append(list2)        
        return list1              
