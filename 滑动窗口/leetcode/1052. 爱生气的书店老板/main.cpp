#include <iostream>
#include <vector>
using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
	int sum = 0;
	for (int i = 0; i < customers.size(); i++) 
		if (!grumpy[i]) sum += customers[i];
	
	int more = 0;
	for (int i = 0; i < minutes; i++)
		if (grumpy[i]) more += customers[i];

	int max_more = more;
	for (int i = minutes; i < customers.size(); i++) {
		if (grumpy[i]) more += customers[i];
		if (grumpy[i - minutes]) more -= customers[i - minutes];
		max_more = max(max_more, more);
	}
	return sum + max_more;
}

int main() {
	vector<int> customers = { 4,10,10 };
	vector<int> grumpy = { 1,1,0 };
	cout << maxSatisfied(customers, grumpy, 2) << endl;
	return 0;
}