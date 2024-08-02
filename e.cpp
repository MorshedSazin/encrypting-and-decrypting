#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int generateRandomHash() {
    int seed = time(0);
    srand(seed);
    return 1 + rand() % 100;
}

int writeHashToFile() {
    int hashCode = generateRandomHash();

    ofstream fileOut("randomTime.txt", ios::binary);
    if (fileOut.is_open()) {
        fileOut.write(reinterpret_cast<char*>(&hashCode), sizeof(hashCode));
        fileOut.close();
        return 0;
    } else {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }
}

int readHashFromFile() {
    int lastHashCode;

    ifstream fileIn("randomTime.txt", ios::binary);
    if (fileIn.is_open()) {
        fileIn.read(reinterpret_cast<char*>(&lastHashCode), sizeof(lastHashCode));
        fileIn.close();
        return lastHashCode;
    } else {
        cerr << "Unable to open file for reading." << endl;
        return 1;
    }
}

void encrypt(string& toBeEncrypted, int hashCode) {
    for (char& c : toBeEncrypted) {
        c += hashCode;
    }
    cout << "Encrypted message: " << toBeEncrypted << endl;
}

void decrypt(const int* encryptedData, int size, int hashCode) {
    cout << "Decrypted message: ";
    for (int i = 0; i < size; i++) {
        cout << static_cast<char>(encryptedData[i] - hashCode);
    }
    cout << endl;
}

int main() {
    cout << "Press 1 to Encrypt\nPress 2 to Decrypt\nPress 0 to exit\n";

    int length = 0;

    while (true) {
        cout << "Enter a number (0 to 2): ";
        int choice;
        cin >> choice;

        if (choice == 0) {
            return 0;
        } else if (choice == 1) {
            writeHashToFile();

            cin.ignore();
            cout << "Enter your text: ";
            string toBeEncrypted;
            getline(cin, toBeEncrypted);

            encrypt(toBeEncrypted, readHashFromFile());
        } else if (choice == 2) {
            if (length == 0) {
                cout << "Enter the 'LENGTH' of the number: ";
                cin >> length;
            }

            int* encryptedData = new int[length];

            cout << "Enter the encrypted numbers: ";
            for (int i = 0; i < length; i++) {
                cin >> encryptedData[i];
            }

            decrypt(encryptedData, length, readHashFromFile());
            delete[] encryptedData;
        } else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
