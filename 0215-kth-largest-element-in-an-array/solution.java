class Solution {
    public int findKthLargest(int[] nums, int k) {
        int size = nums.length;
        int pivotIndex = (int)(Math.random() * size);
        int pivotValue = nums[pivotIndex];
        
        
        int[] left = new int[size];
        int[] equal = new int[size];
        int[] right = new int[size];
        int leftSize = 0, equalSize = 0, rightSize = 0;
        
        
        for (int num : nums) {
            if (num < pivotValue) {
                left[leftSize++] = num;
            } else if (num > pivotValue) {
                right[rightSize++] = num;
            } else {
                equal[equalSize++] = num;
            }
        }
        
        
        if (k <= rightSize) {
            int[] rightExact = new int[rightSize];
            System.arraycopy(right, 0, rightExact, 0, rightSize);
            return findKthLargest(rightExact, k);
        } else if (k > rightSize + equalSize) {
            int[] leftExact = new int[leftSize];
            System.arraycopy(left, 0, leftExact, 0, leftSize);
            return findKthLargest(leftExact, k - rightSize - equalSize);
        } else {
            return pivotValue;
        }
    }
}
