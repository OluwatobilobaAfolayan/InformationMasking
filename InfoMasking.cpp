#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*Function removes leading characters such as "E: " or "P: " */
string removeLeadingCharacters(string data){
    data.erase(0, 2);
    if(data[0] == ' ')
        data.erase(0, 1); //remove whitespace if any
    return data;
}

/*Function removes specialcharacters within string*/
string removeSpecialCharacters(string data) {
    for(int i = 0; i < data.length(); i++) {
        if(!isdigit(data[i]))
            data.erase(i, 1);
    }
    return data;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string initialData;
    string maskedData;
    string tempData;
    string asterisks = "*****";
    string genericAsterisk = "***-***-";
    int phoneNoWithoutAC = 10;  //phone number is 10 digits without area code

    while(getline(cin, initialData)) {  //read input email string
        maskedData = "";
        tempData = "";
        if(initialData.at(0) == 'E') {
            initialData = removeLeadingCharacters(initialData);
            maskedData += initialData[0];  //appends first character to new email
            maskedData.append(asterisks);

            for(int i = 0; i < initialData.length(); i++) {
                if (initialData[i+1] == '@'){
                     maskedData.append(initialData.substr(i, initialData.length() - i));  //appends masked email with -
                    //last character and domain name
                     break;
                }
            }

            cout << "E:" << maskedData << endl;
        }
        else if (initialData.at(0) == 'P')
        {
            initialData = removeLeadingCharacters(initialData);
            initialData.erase(remove(initialData.begin(),initialData.end(), ' '), initialData.end()); //remove extra white space

            if(initialData[0] == '+') {
                maskedData += '+';
                initialData = removeSpecialCharacters(initialData);

                for(int i = 0; i < initialData.length(); i++) {  //append asterisks based on length of area code
                    if(i + phoneNoWithoutAC < initialData.length())
                        maskedData += '*';
                    else
                        break;
                }

                maskedData += '-';
            }
            else
            {
                initialData = removeSpecialCharacters(initialData);
            }

            maskedData += genericAsterisk;
            maskedData.append(initialData.substr((initialData.length() - 4), 4)); //append last four digits to masked phone number
            cout << "P:" << maskedData << endl;
        }
    }
    return 0;
}
