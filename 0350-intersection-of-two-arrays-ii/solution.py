class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        common=[]
        visited=set()
        for i in range(len(nums1)):
            for j in range(len(nums2)):
                if(nums1[i]==nums2[j] and j not in visited):
                    common.append(nums1[i])
                    visited.add(j)
                    break
        return common        
        
