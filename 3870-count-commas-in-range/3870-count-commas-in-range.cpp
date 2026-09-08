class Solution {
public:
    int countCommas(int n) {
        int count = 0;
        for(int i=1;i<=n;i++){
            int digits = log10(i)+1;
            count += (digits-1)/3;
        }
        return count;
    }
};