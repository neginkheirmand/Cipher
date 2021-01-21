
#include <iostream>
#include <string>

//implementation of the vigenere cipher
//the base of this type of encryption is a chart in which the transformed character by the code char(in row i)  
//and key char(in column j) is char x (with position i+j in the arr)
//please check if the char exists in the arr before using it in the message as input to the program

using namespace std;
char vigenere(char a, char key){
    char arr[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '_', '!', '?', '#', '*'};
    int posA=-1;
    int posKey=-1;
    for(int i=0; i<(sizeof(arr)); i++){
        if(a==arr[i]){
            posA=i;
        }
        if(key==arr[i]){
            posKey=i;
        }
        if(posKey!=-1 && posA!=-1){
            break;
        }
    }
    return arr[(posA+posKey)%(sizeof(arr))];
}

int main()
{
    string key = "";
    cout << "Type your key: ";
    cin >> key;
    string code = "";
    cout << "Type your message: ";
    cin >> code;
    string vigenereCoded="";
    for(int i=0; i<code.length(); i++){
        vigenereCoded+=vigenere(code[i], key[i%(key.length())]);
    }
    cout<<vigenereCoded;


    return 0;
}
