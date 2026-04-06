#include <bits/stdc++.h>
using namespace std;

class Robot {
    int _width, _height;
    int _x, _y;
    vector<string> ans = { "East","North","West","South" };
    int _idx;
public:
    Robot(int width, int height) :_width(width), _height(height) {
        _x = _height - 1, _y = 0;
        _idx = 0;
    }

    void step(int num) {
        num %= (2 * _width + 2 * (_height - 2));    //省去转多圈的时间
        if (!num) {   //当num为0的时候且机器人在拐角的时候需要判断（num为0在此题目中一定是转了图至少一圈）
            if (_x == 0 && _y == 0)  _idx = 2;
            else if (_x == 0 && _y == _width - 1) _idx = 1;
            else if (_x == _height - 1 && _y == _width - 1) _idx = 0;
            else if (_x == _height - 1 && _y == 0) _idx = 3;
        }
        while (num) {
            if (_idx == 0) {
                int len = _width - _y - 1;
                if (num > len) {
                    _y = _width - 1;
                    num -= len;
                    _idx = (_idx + 1) % 4;
                }
                else {
                    _y += num;
                    num = 0;
                }
            }
            else if (_idx == 1) {
                int len = _x;
                if (num > len) {
                    _x = 0;
                    num -= len;
                    _idx = (_idx + 1) % 4;
                }
                else {
                    _x -= num;
                    num = 0;
                }
            }
            else if (_idx == 2) {
                int len = _y;
                if (num > len) {
                    _y = 0;
                    num -= len;
                    _idx = (_idx + 1) % 4;
                }
                else {
                    _y -= num;
                    num = 0;
                }
            }
            else {
                int len = _height - 1 - _x;
                if (num > len) {
                    _x = _height - 1;
                    num -= len;
                    _idx = (_idx + 1) % 4;
                }
                else {
                    _x += num;
                    num = 0;
                }
            }
        }
    }

    vector<int> getPos() {
        return { _y, _height - _x - 1 };
    }

    string getDir() {
        return ans[_idx];
    }
};

int main() {

	return 0;
}