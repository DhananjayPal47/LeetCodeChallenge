class Solution {
public:
    int digitSum(int number){
        int sum = 0;
        while(number>0){
            int digit = number%10;
            sum += digit;
            number = number/10;
        }
        return sum;
    }
    int largestInteger(int n, int s) {

        if(s==0)
            return 0;
        int start = pow(10,(n-1));
        int end = pow(10,n)-1;
        int maxi = -1;

        for(int i=start;i<=end;i++){
            if(digitSum(i)==s)
                maxi = max(maxi,i);
                
        }
        return maxi;
        
    }
};