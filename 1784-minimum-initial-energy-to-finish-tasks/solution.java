import java.util.*;

class Solution {
    public int minimumEffort(int[][] tasks) {
        Arrays.sort(tasks, (a, b) -> {
            int gapA = a[1] - a[0];
            int gapB = b[1] - b[0];
            return gapB - gapA; 
        });

        int energy = 0;
        int current = 0;

        for (int[] task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            if (current < minimum) {
                energy += minimum - current;
                current = minimum;
            }

            current -= actual;
        }

        return energy;
    }
}
