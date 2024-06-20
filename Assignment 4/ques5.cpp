#include <string>
#include <iostream>
#include <vector>
using namespace std;

string findSmallestRotation(string original) {
    string doubledString = original + original;
    int stringLength = original.length();
    
    vector<int> failureFunction(2 * stringLength, -1);
    
    int bestRotationStart = 0;
    
    for (int current = 1; current < 2 * stringLength; current++) {
        int matchLength = failureFunction[current - bestRotationStart - 1];
        
        while (matchLength != -1 && doubledString[current] != doubledString[bestRotationStart + matchLength + 1]) {
            if (doubledString[current] < doubledString[bestRotationStart + matchLength + 1]) {
                bestRotationStart = current - matchLength - 1;
            }
            matchLength = failureFunction[matchLength];
        }
        
        if (matchLength == -1 && doubledString[current] != doubledString[bestRotationStart + matchLength + 1]) {
            if (doubledString[current] < doubledString[bestRotationStart + matchLength + 1]) {
                bestRotationStart = current;
            }
            failureFunction[current - bestRotationStart] = -1;
        } else {
            failureFunction[current - bestRotationStart] = matchLength + 1;
        }
    }
    
    return doubledString.substr(bestRotationStart, stringLength);
}