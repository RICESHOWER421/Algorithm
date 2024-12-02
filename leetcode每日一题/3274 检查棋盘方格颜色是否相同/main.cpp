#include <string>
#include <iostream>
#include <string>
using namespace std;
bool checkTwoChessboards(string coordinate1, string coordinate2) {
	return (coordinate1[0] - 'a') % 2 == (coordinate2[0] - 'a') % 2 ? ((coordinate1[1] - '0') % 2 == (coordinate2[1] - '0') % 2 ? true : false) : ((coordinate1[1] - '0') % 2 != (coordinate2[1] - '0') % 2 ? true : false);
}

int main() {

	return 0;
}