#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main(){
    // vector<char> arr = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q'};

    // for(int i = 0, j = arr.size()-1; i <= arr.size()/2; ++i,--j){
    //     i!=j? cout << i <<":" <<j <<" " <<arr[i] <<" " << arr[j] <<endl : cout << i <<":" << arr[i] << endl;;
    // }
    // German
    string german = u8"Hallo, Welt!"; // "Hello, World!" in German
    // string english = "hello world";
    // string arabic = u8"مرحبا بالعالم"; // "Hello, World!" in Arabic
    // string bangla ; // "Hello, World!" in Bangla


    // scanf("%s", &bangla);
    // printf("%s\n", bangla);
    /*
    for(int i = 0; i < english.length(); ++i) {
        cout << "Bangla character code at position " << i << ": " << static_cast<int>(static_cast<unsigned char>(bangla[i])) << " : " <<static_cast<unsigned char>(bangla[i]) << endl;
    }
    */
    string s2 = "ABCDEF";
    cout <<s2.length()<<endl;
    
    for (int i=0,j=1; i <= j; ++i, --j) {
        i!=j? cout <<i <<" : " << j << endl :cout <<j <<endl ;
    }
    return 0;
}

// static_cast<unsigned char>
//  "বিজয় থেকে ইউনিকোড";