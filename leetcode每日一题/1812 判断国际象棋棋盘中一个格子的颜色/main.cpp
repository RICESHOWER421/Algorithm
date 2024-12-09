#include <iostream>
using namespace std;

bool squareIsWhite(char* coordinates)
{
    if (coordinates[0] == 'a' || coordinates[0] == 'c' || coordinates[0] == 'e' || coordinates[0] == 'g')
    {
        if (coordinates[1] == '2' || coordinates[1] == '4' || coordinates[1] == '6' || coordinates[1] == '8')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (coordinates[1] == '2' || coordinates[1] == '4' || coordinates[1] == '6' || coordinates[1] == '8')
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

int main() {

	return 0;
}