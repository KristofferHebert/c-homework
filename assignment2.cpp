#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double width = 0.0;
    double height = 0.0;
    double area = 0.0;
    double time = 0.0;
    double gallons = 0.0;
    double buckets = 0.0;
    double cost = 0.0;

    // Get width as user input
    cout << "Enter the width of the wall in feet: ";
    cin >> width;

    // Get height as user input
    cout << "Enter the height of the wall in feet: ";    
    cin >> height; 
    
    // Calculate and output area of wall
    area = height * width;
    cout << "Total area to paint in square feet: "
         << area
         << endl;

    // Calculate number of buckets needed
    buckets = ceil(area / 350);
    cout << "Total number of gallons of paint needed: "
         << buckets
         << endl;

    // Calculate cost of paint
    cost = buckets * 27;
    cout << "Total cost of paint in dollars: "
         << cost
         << endl;
    
    // Calculate time needed to paint
    time = area/100;
    cout << "Total time to paint in hours: "
         << time
         << endl;

    return 0;
}
