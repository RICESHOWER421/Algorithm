#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

//������룬ֻ��˵˼·���뵽�˵��Ǵ����Ż����⻹�ö࿼��
//֮ǰ����ŷ��ɸ+����д������ʱ�临�Ӷ�ΪO(N)Ҳ�ǳ���
//������Ҫʹ�������Ԥ����+O(1)���𰸵�˼·
//�����wa��11�Σ�˼·��ȫû�����⣬����Ϳ��ڰ����ܹ��ύȴ���ܹ�
//�����ϰ���ŷ������Լ�O(N)���ˣ�ֻ��˵������
const int MX = 31622;
int pi[MX + 1];

auto init = [] {
    for (int i = 2; i <= MX; i++) {
        if (pi[i] == 0) { 
            pi[i] = pi[i - 1] + 1;
            for (int j = i * i; j <= MX; j += i) { 
                pi[j] = -1; 
            }
        }
        else {
            pi[i] = pi[i - 1];
        }
    }
    return 0;
}();

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        return r - l + 1 - (pi[(int)sqrt(r)] - pi[(int)sqrt(l - 1)]);
    }
};

int main() {
    cout << Solution().nonSpecialCount(10, 11) << "\n";
	return 0;
}