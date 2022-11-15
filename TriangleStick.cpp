#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    // Count the amount of successful triangles made from 100,000 tries
    int successTriangle = 0;
    int totalTriangle = 100000;

    for(int i = 0; i < totalTriangle; ++i)
    {
        // Random values between 0 and 1
        double pointA = (double) rand() / RAND_MAX;
        double pointB = (double) rand() / RAND_MAX;
        vector<double> lineLengths; // Vector containing the 3 line lengths of the triangle

        // Put the three line lengths into a vector
        if(pointA < pointB)
        {
            lineLengths.push_back(pointA);
            lineLengths.push_back(pointB - pointA);
            lineLengths.push_back(1 - pointB);
        }
        else
        {
            lineLengths.push_back(pointB);
            lineLengths.push_back(pointA - pointB);
            lineLengths.push_back(1 - pointA);
        }

        // Sort for order smallest to largest
        sort(lineLengths.begin(), lineLengths.end());
        
        // Check if the two shortest lengths are greater than the longest length, otherwise not a triangle
        if(lineLengths[0] + lineLengths[1] > lineLengths[2])
        {
            successTriangle++;
        }
    }

    cout << "Amount of successful triangles: " << successTriangle << endl;
    cout << "Amount of triangles attempted: " << totalTriangle << endl;
    cout << "Success chance: " << round((double) successTriangle * 1000 / (double) totalTriangle) / 1000 << endl;
    
    return 0;
}