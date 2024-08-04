/*it just for fun*/
#include <iostream>
#include <ctime>
#include <algorithm> 
#include <string>
using namespace std;


int currentTime() {  
    time_t t = time(NULL);
    struct tm date = *localtime(&t);
    // return date.tm_hour;
    return 3;
}

void encrypting(string toBeEncrypt, int hashCode = currentTime()) {
    printf("\nThe encrypted message is: ");
    for (int i = 0, j = toBeEncrypt.length() - 1; i <= j; ++i, --j) {
        if(i!=j){
            toBeEncrypt[i] = (toBeEncrypt[i] == ' ') ? '~' : (toBeEncrypt[i] + hashCode);
            toBeEncrypt[j] = (toBeEncrypt[j] == ' ') ? '~' : (toBeEncrypt[j] - hashCode);
        }else toBeEncrypt[i] = (toBeEncrypt[i] == ' ') ? '~' : (toBeEncrypt[i] + hashCode);

        (i != j) ? printf("%s%c%C", "\033[32m", toBeEncrypt[i],toBeEncrypt[j])
        : printf("%s%c","\033[32m",toBeEncrypt[i]);
    }
    peintf("\033[0m\n\n");
}

void decrypting(string toBeDicy) {    
    string s1, s2;
    cout << "\nThe message was: ";
    int hashCode = currentTime();
    for (size_t i = 0; i < toBeDicy.length(); ++i) {
        (i%2==0) ? (toBeDicy[i] != '~' ? s1+= (toBeDicy[i]-hashCode) : s1+=' ') 
        : (toBeDicy[i] != '~' ? (s2+=toBeDicy[i]+hashCode) : s2+=' ');
    }
    reverse(s2.begin(),s2.end());
    printf("%s%s\n", s1.c_str(), s2.c_str());
    printf("\033[0m\n\n");
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
            printf("Enter your text: ");
            string toBeEncrypt;
            getline(cin, toBeEncrypt);
            encrypting(toBeEncrypt);

        } else if (test == 2) {
            system("clear");
            cin.ignore();
            printf("Enter the encrypted message: ");
            string toBeDicy;
            getline(cin, toBeDicy);
            decrypting(toBeDicy);
        } else {
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
