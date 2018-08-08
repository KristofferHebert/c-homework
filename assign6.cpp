#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const double pi = 3.14159265;
const double grav = 9.8; // Earth gravity (m/s^2)

// Given time, angle, velocity, and gravity
// Update x and y values
void Trajectory(double t, double a, double v,
                double& x, double& y) {
   x = v * t * cos(a);
   y = v * t * sin(a) - 0.5 * grav * t * t;
   return;
}

// convert degree value to radians
double DegToRad(double deg) {
    return ((deg * pi) / 180.0);
}

// print time, x, and y values
void PrintUpdate(double t, double x, double y) {
    cout << "Time " << fixed << setprecision(0)
         << setw(3) << t << "   x = " << setw(3)
         << x << "   y = " << setw(3) << y << endl;
    return;
}
void GetUsrInpt(double swineX, double& fowlAngle, double& fowlVel){
    cout << "\nThe Mean Swine is " << swineX << " meters away.\n";
    cout << "Enter fowl launch angle (deg): ";
    cin >> fowlAngle;
    fowlAngle = DegToRad(fowlAngle); // convert to radians
    cout << "Enter fowl launch velocity (m/s): ";
    cin >> fowlVel;
}
// Print message
void PrintIntro(){
    cout << "Welcome to Upset Fowl!\n";
    cout << "The objective is to hit the Mean Swine by launching an Upset Fowl.\n";
    return;
}

double LaunchFowl(double& fowlAngle, double& fowlVel){
    double fowlY = 0.0; // object's height above ground (m)
    double fowlX = 0.0; // object's horiz. dist. from start (m)
    double t = 1.0; // time (s)
    do {
        PrintUpdate(t, fowlX, fowlY);
        Trajectory(t, fowlAngle, fowlVel, fowlX, fowlY);
        t=t+1.0;
    } while ( fowlY > 0.0 ); // while above ground
    
    PrintUpdate(t, fowlX, fowlY);
    return fowlX;
}

bool DtrmnIfHit(double& fowlLandingX, double& swineX){

    cout << swineX << endl;

    double beforeSwineX = 0.0; 
    beforeSwineX = swineX - 30;
    bool result;
    
    if ((fowlLandingX <= swineX) && (fowlLandingX >= beforeSwineX)) {
        cout << "Hit'em!!!" << endl;
        result = true;
    } else {
        cout << "Missed'em..." << endl;
        result = false;
    }    
    return result;
}

int main() {
    double fowlAngle = 0.0; // angle of launch of fowl (rad)
    double fowlVel = 0.0; // velocity of fowl (m/s)
    double swineX = 0.0; // distance to swine (m)
    double fowlLandingX = 0.0; // fowl’s horiz. dist. from start (m)
    bool didHitSwine = false; // did hit the swine?
    int tries = 4;

    // Select random distance
    srand(time(0));
    swineX = (rand() % 201) + 50;

    PrintIntro();

    // Give use 4 tries to hit swine
    while(tries != 0 && didHitSwine != true){
        GetUsrInpt(swineX, fowlAngle, fowlVel);
        fowlLandingX = LaunchFowl(fowlAngle, fowlVel);
        didHitSwine = DtrmnIfHit(fowlLandingX,swineX);
        tries --;
    }

    return 0;
}
