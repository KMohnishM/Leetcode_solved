class Solution(object):
    def isRectangleOverlap(self, rec1, rec2):
        """
        :type rec1: List[int]
        :type rec2: List[int]
        :rtype: bool
        """
        
        if rec1[2] <= rec2[0] or rec2[2] <= rec1[0]:
            return False
        
        
        if rec1[1] >= rec2[3] or rec2[1] >= rec1[3]:
            return False

        return True

