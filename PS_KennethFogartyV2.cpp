// PS_KennethFogartyV2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    int a, d;

    cout << "Choose an a: ";
    cin >> a;

    cout << "Choose an d: ";
    cin >> d;

    unsigned long long int left = 0;
    unsigned long long int right = 0;

    int split = 1;
    int start = 0;
    bool cont = true;

    //auto clockStart = high_resolution_clock::now();

    do {

        int i = start;
        left = left + (a + (d * i));
        right = a + (d * (i + 1));

        for (i; i < split; i++) {

            int y = i;
            while (left > right) {

                right = right + (a + (d * (y + 2)));
                y++;
            }

            if (left == right) {

                /*
                auto clockStop = high_resolution_clock::now();

                auto clockDuration = duration_cast<microseconds>(clockStop - clockStart);

                cout << "\nPASS at: " << i << "   " << "Time taken to find: " << clockDuration.count() << " microseconds" << endl << endl;
                */

                //cout << "\nPASS at: " << i << endl << endl;

                cout << endl << "FIRST SUM:  0 -> " << i << "   SECOND SUM:  " << (i + 1) << " -> " << (y + 1) << endl << endl;

                if (split < 500) {
                    for (int z = 0; z < i; z++) {

                        int element = a + (d * z);
                        cout << element << " + ";
                    }
                    cout << a + (d * i) << " = " << left << "   |   ";

                    for (int l = (i + 1); l <= y; l++) {

                        int element = a + (d * l);
                        cout << element << " + ";
                    }
                    cout << a + (d * (y + 1)) << " = " << right << endl << endl;
                }
                else {
                    cout << "Split is to big to display." << endl << endl;
                }

                cout << "Do you want to find the next split?  1 or 0: ";
                cin >> cont;
                
                switch (cont) {
                case '1' :
                    cont = true;
                    break;
                case '0' :
                    cont = false;
                    break;
                }
                break;
            }    
        }
        split++;
        start++;

    } while (cont != false);
}
