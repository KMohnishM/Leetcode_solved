int mySqrt(int x) {
    int i;
    if(x==0){return 0;}
    if(x==1){return 1;}
    for( i=0;i<=x/2;i++){
        if(pow(i,2)>x){
            break;
        }
        // if(pow(i,2)==x){i++;}
    }
    return i-1;
}
