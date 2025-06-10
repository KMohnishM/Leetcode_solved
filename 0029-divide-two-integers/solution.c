int divide(int dividend, int divisor) {
   long int d1=dividend,d2=divisor;
   if(d1/d2>INT_MAX||d1/d2<INT_MIN){return INT_MAX;}
    return dividend/divisor;
}
