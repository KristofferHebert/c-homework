#include <iostream>
using namespace std;

int main()
{
    int trunkHeight;
    int trunkWidth;
    int leavesWidth;

    // Gather User input
    cout << "Enter trunk height: ";
    cin >> trunkHeight;
    cout << "Enter trunk width: ";
    cin >> trunkWidth;
    cout << "Enter leaves width: ";
    cin >> leavesWidth;

    // Draw leaves
    for (int i = 0; i <= leavesWidth; i++) {
        if (i % 2 != 0) {
            
            // Render leaves
            string leaves;
            string padding;
            for (int ii = i; ii != 0; ii--) {
                leaves.append("*");
            }
            
            // Center leaves
            int space = (leavesWidth - leaves.length()) / 2;
            while (space != 0) {
                padding.append(" ");
                space--;
            }
            cout << padding << leaves << padding << endl;
        }
    }

    // Draw trunk based on height
    for (int i = 0; i < trunkHeight; i++) {

        // Render Trunk
        string trunk;
        string padding;
        
        // Center trunk
        for (int ii = 0; ii < trunkWidth; ii++) {
            trunk.append("*");
        }

        // Center text
        int space = (leavesWidth - trunk.length()) / 2;

        while (space != 0) {
            padding.append(" ");
            space--;
        }
        cout << padding << trunk << padding << endl;
    }

    return 0;
}