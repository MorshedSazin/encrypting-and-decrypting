/*it just for fun*/


#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int generateRandomHash() {
    //  Random time generator.
    int x = time(0);
    srand(x);
    return 1 + rand() % 100; 
}

int writeHashToFile() {
    int hashCode = generateRandomHash();

    // writing in the txt file.
    ofstream fileIn("randomTime.txt");
    if (fileIn.is_open()) {
        fileIn << hashCode << "\n";
        fileIn.close();
        return 0;
    } else {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }
}

int readHashFromFile() {
    int lastHashCode;

    ifstream fileOut("randomTime.txt");
    if (fileOut.is_open()) {
        fileOut >> lastHashCode;
        fileOut.close();
        return lastHashCode;
    } else {
        cerr << "Unable to open file for reading." << endl;
        return 1;
    }
}

int encrypting(string &toBeEncrypt) {

    const int hashCode = readHashFromFile();
    int i;
    for (i = 0; i < toBeEncrypt.size(); i++) {
        toBeEncrypt[i] += hashCode;
    }
    for (int i = 0; i < toBeEncrypt.size(); i++) {
        cout << static_cast<int>(toBeEncrypt[i]) << " ";
    }
    printf("\n");
    printf("lENGTH OF THE CODE: %zu\n",toBeEncrypt.size());
    return toBeEncrypt.size();
}


void decrypting(int toBeDicy[], int size, int hashCode) {

    printf("\n");
    printf("The message is: ");
    for (int i = 0; i < size; i++) {
        toBeDicy[i] -= hashCode;
        printf("%c", static_cast<char>(toBeDicy[i]));
    }
    printf("\n");
}

int main() {

    printf("Do you want to Encrypt or Decrypt?\npress: 1 for Encrypting\npress: 2 for Decrypting\npress: 0 to exit\n");

    unsigned length = 0;

    while (true) {
        printf("Enter a number from (0 to 2): ");
        int test;
        cin >> test;

        if (test == 0) return 0;

        if (test == 1) {
            const int hashCode = writeHashToFile();
            
            cin.ignore();
            printf("Enter your text: ");

            string toBeEncrypt;
            getline(cin, toBeEncrypt);

            length = encrypting(toBeEncrypt);
            cout << endl;

        } else if (test == 2) {

            const int hashCode = readHashFromFile();

            (length == 0) ? cout << "Enter the 'LENGTH' of the number: ", cin >> length, 0 : 0;

            int toBeDicy[length];
            printf("Enter the encrypted numbers: ");
            for (int i = 0; i < length; i++) cin >> toBeDicy[i];

            decrypting(toBeDicy, length, hashCode);
            printf("\n");

        } else {
            printf("Invalid choice. Please enter a valid option.\n"); 
        }
    }

    return 0;
}
