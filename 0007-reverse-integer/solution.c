int reverse(int x) {
    long r = 0; // Reversed number (use long to handle intermediate calculations)
    
    // Reverse the digits
    while (x != 0) {
        // Extract the last digit
        int rem = x % 10;
        // Check for overflow before updating r
        // if (r > INT_MAX / 10 || r < INT_MIN / 10) {
        //     return 0;
        // }
        // Update reversed number
        r = r * 10 + rem;
        // Remove the last digit from x
        x = x / 10;
    }
    
    // Check if the final result is within 32-bit signed integer range
    if (r > INT_MAX || r < INT_MIN) {
        return 0;
    }
    
    return (int)r;
}
