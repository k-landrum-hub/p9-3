/*
* Roman numerals
* korbin landrum
* 10/29/26
*/

#include<iostream>
#include<string>
using namespace std;

//function prototypes
int romanCharValue(char r);
int convertRomanToInt(string s);

int main() {
    string input;

    while (true) {
        cout << "Enter Roman number or Q to quit: ";
        cin >> input;

        if (input == "Q" || input == "q") {
            break;
        }

        int result = convertRomanToInt(input);
        cout << input << " = " << result << endl;
    }

    return 0;
}


 // number value of the passed Roman numeral character.
 
//int romanCharValue(char r) {
//    if (r == 'I' || r == 'i') return 1;
//    if (r == 'V' || r == 'v') return 5;
//    if (r == 'X' || r == 'x') return 10;
//    if (r == 'L' || r == 'l') return 50;
//    if (r == 'C' || r == 'c') return 100;
//    if (r == 'D' || r == 'd') return 500;
//    if (r == 'M' || r == 'm') return 1000;
//    return 0;
//}

// Converts a Roman number into intager 
 
int convertRomanToInt(string s) {
    int total = 0;

    // Loop continues while the roman number string is not empty
    while (!s.empty()) {
        // If the string has length 1 OR the first character has a larger or equal value than the second
        if (s.length() == 1 || romanCharValue(s[0]) >= romanCharValue(s[1])) {
            total += romanCharValue(s[0]);
             s.erase(0, 1); // Remove the first character
        } 
        // Else (the second character has a strictly larger value than the first)
        else {
            total += (romanCharValue(s[1]) - romanCharValue(s[0]));
            s.erase(0, 2); // Remove both characters
        }
    }

    return total;
}