#include <iostream>
#include "barel.h"

using namespace std;

int main() {
    
    Barel spirt(10, 96);
    Barel water(10, 0);
    double cup = 1;
    int count = 0;

    while(spirt.getAlcohol() > 50) {
        spirt.pourOut(water, cup);
        water.pourOut(spirt, cup);
        count++;
    }

    cout << "Iteration count = " << count << endl;

    return 0;
}