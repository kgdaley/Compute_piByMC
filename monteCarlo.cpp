#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <random>

using namespace std;

double where(double x, double y)
{
    double loc = (x*x) + (y*y);
    return loc;
}

int main()
{
    //variables and parameters
    double circleArea, squareArea, pi; 
    int i; // i= number of points in circle, 
    int steps = 1000000; //how many iterations
    double xpos, ypos, location; // location = distance from circle center
    int start, stop;

    // initialize random number
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    // iterate over the square area
    // determine how many randomly generated numbers land in the circle
   
   start = clock();
    for (i=0; (i< steps); i++){

        xpos = dis(gen);
        ypos = dis(gen);
        location = where(xpos, ypos);
        // count how many points land in the circle
        if(location <= 1)
        {
            circleArea++;
        }
        squareArea++;
        pi = double (4*circleArea) / squareArea;
    }

    stop = clock();
    double dblTime = ((double)(stop - start)) / CLOCKS_PER_SEC;
    cout << "The value of pi for " << steps << " steps is " << pi; 
    cout << "\n" << "It took " << dblTime << " seconds to run";
    
}