#include <iostream>
#include <string>
using namespace std;

//方法一：模拟
//class Solution {
//public:
//    int countCollisions(string directions) {
//        int begin = -1, end = -1;
//        int ans = 0;
//        for (int i = 0; i < directions.size(); i++) {
//            if (directions[i] == 'S') {
//                if (begin == -1) begin = end = i;
//                else end = i;
//            }
//            if (i && directions[i] == 'L' && directions[i - 1] == 'R') {
//                if (begin == -1) {
//                    begin = i - 1;
//                    end = i
//                }
//                else end = i;
//                directions[i] = directions[i - 1] = 'S';
//                ans += 2;
//            }
//        }
//
//        if (begin == -1 && end == -1) return 0;
//        for (int i = 0; i < begin; i++) {
//            if (directions[i] == 'R') ++ans;
//        }
//        for (int i = begin; i < end; i++) {
//            if (directions[i] != 'S') ++ans;
//        }
//        for (int i = end; i < directions.size(); i++) {
//            if (directions[i] == 'L') ++ans;
//        }
//        return ans;
//    }
//};

//方法二：结论，除了最左边连续L和最右边连续R不会相撞，剩下的全部会撞车
class Solution {
public:
    int countCollisions(string directions) {
        int left = 0, right = directions.size() - 1;
        while (directions[left] == 'L') ++left;
        while (directions[right] == 'R') --right;
        
        int ans = 0;
        for (int i = left; i <= right; i++) {
            if (i != right && directions[i] == 'R' && directions[i + 1] == 'L') {
                ans += 2;
                ++i;
            }
            else if (directions[i] != 'S') ++ans; 
        }
        return ans;
    }
};
int main() {

    return 0;
}