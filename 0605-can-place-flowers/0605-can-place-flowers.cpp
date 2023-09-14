class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int pt = 0;
        
        while (pt < flowerbed.size()) {
            if (n == 0) {
                return true;
            }
            
            if (flowerbed[pt] == 1) {
                pt += 2;
            } else {
                if (pt + 1 == flowerbed.size()) {
                    --n;
                    pt += 2;
                } else if (flowerbed[pt+1] == 0) {
                    --n;
                    pt += 2;
                } else {
                    ++pt;
                }
            }
        }
        
        if (n == 0) {
            return true;
        }
        return false;
    }
};