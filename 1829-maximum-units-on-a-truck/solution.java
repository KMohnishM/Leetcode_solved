class Solution {
  public static void quickSort(int[][] boxTypes, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(boxTypes, low, high);
            quickSort(boxTypes, low, pivotIndex - 1);
            quickSort(boxTypes, pivotIndex + 1, high);
        }
    }

    public static int partition(int[][] boxTypes, int low, int high) {
        int[] pivot = boxTypes[high]; // Choose the last element as the pivot
        int i = low - 1;

        for (int j = low; j < high; j++) {
            // Compare based on units per box
            if (boxTypes[j][1] > pivot[1]) { // Descending order
                i++;
                // Swap boxTypes[i] and boxTypes[j]
                int[] temp = boxTypes[i];
                boxTypes[i] = boxTypes[j];
                boxTypes[j] = temp;
            }
        }
        // Swap pivot with the element at i + 1
        int[] temp = boxTypes[i + 1];
        boxTypes[i + 1] = boxTypes[high];
        boxTypes[high] = temp;

        return i + 1;
    }

    public int maximumUnits(int[][] boxTypes, int truckSize) {
             // Sort the boxTypes array using Quick Sort
        quickSort(boxTypes, 0, boxTypes.length - 1);

        int totalUnits = 0;

        for (int[] boxType : boxTypes) {
            int boxCount = boxType[0];
            int unitsPerBox = boxType[1];

            // Take as many boxes as the truck can carry
            int boxesToTake = Math.min(boxCount, truckSize);
            totalUnits += boxesToTake * unitsPerBox;
            truckSize -= boxesToTake;

            // Stop if the truck is full
            if (truckSize == 0) {
                break;
            }
        }

        return totalUnits;
    }
}
