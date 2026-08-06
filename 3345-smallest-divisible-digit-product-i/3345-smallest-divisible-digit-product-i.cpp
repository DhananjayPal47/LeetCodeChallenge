class Solution {
public:
    int digitProduct(int number){
        int product = 1;

        while(number>0){
            int digit = number%10;
            product *= digit;
            number = number/10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(digitProduct(n)%t==0)
                return n;
            n++;
        }
    }
};