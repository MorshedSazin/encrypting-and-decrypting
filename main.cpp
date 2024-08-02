/*it just for fun*/
#include<bits/stdc++.h>
using namespace std;


int currentTime() {  
    time_t t = time(NULL);
    struct tm date = *localtime(&t);
    return date.tm_hour;
}

void decrypting(string toBeDicy) {    
    string s1, s2;
    cout << "\nThe message was: ";
    int hashCode = currentTime();
    for (int i = 0; i < toBeDicy.size(); ++i) {
        (i%2==0) ? (toBeDicy[i] != ' ' ? s1+= (toBeDicy[i]-hashCode) : s1+=' ') 
        : (toBeDicy[i] != ' ' ? (s2+=toBeDicy[i]+hashCode)   : s2+=' ');
    }
    reverse(s2.begin(),s2.end());
    cout << s1 << s2 << endl;
    cout << "\033[0m\n\n";
}

void encrypting(string toBeEncrypt, int hashCode = currentTime()) {
    printf("\nThe encrypted message is: ");
    for (int i = 0, j = toBeEncrypt.size() - 1; i <= j; ++i, --j) {

        toBeEncrypt[i] = (toBeEncrypt[i] == ' ') ? ' ' : (toBeEncrypt[i] + hashCode);
        toBeEncrypt[j] = (toBeEncrypt[j] == ' ') ? ' ' : (toBeEncrypt[j] - hashCode);

        (i != j) ? printf("%s%c%C", "\033[32m", toBeEncrypt[i],toBeEncrypt[j])
        : printf("%s%c","\033[32m",toBeEncrypt[i]);
    }
    cout << "\033[0m\n\n";
}

int main() {
    printf("\nPress: 1 for Encrypting\nPress: 2 for Decrypting\nPress: 0 to exit\n\n");
    bool check = true;
    int test;

    while (check) {
        printf("Enter a number from (0 to 2): ");
        scanf("%d",&test);

        if (test == 0) return 0;
        if (test == 1) {
            system("clear");
            cin.ignore();
            cout << "Enter your text: ";
            string toBeEncrypt;
            getline(cin, toBeEncrypt);
            encrypting(toBeEncrypt);

        } else if (test == 2) {
            system("clear");
            cin.ignore();
            cout << "Enter the encrypted message: ";
            string toBeDicy;
            getline(cin, toBeDicy);
            decrypting(toBeDicy);
        } else {
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
