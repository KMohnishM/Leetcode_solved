class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        arr1=[nums[0]]
        arr2=[nums[1]]
        a1=a2=0
        for i in range(2,len(nums)):
            if(arr1[a1]>arr2[a2]):
                arr1.append(nums[i])
                a1+=1
            else:
                arr2.append(nums[i])
                a2+=1
        result=arr1+arr2
        return result            
        
