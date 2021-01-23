#include <iostream>
#include <string> 
#include <conio.h>
using namespace std;

void Encrypt(){

    int k=3;
    string Message;
    string Encrypted_msg;
    
    
    cout<<"Enter The Message You Want To Encrypt"<<endl;
    cin.ignore();
    getline(cin, Message);
    for (int  i = 0; i < Message.size(); i++)
    {
            if (Message[i]==32) // For Space " "
            {   
                Encrypted_msg=Encrypted_msg+Message[i];
                continue;
            }
            else
            {
                if (Message[i]+k>122)  // For Small Letters Special Case & Special Character '[' to "`".
                {
                    Message[i]=Message[i]+k-122;
                    Message[i]=96+Message[i];    // 96 + the extra value left after 122. To Start From "a".
                    Encrypted_msg=Encrypted_msg+Message[i];
                }
                else if (Message[i]+k>90 && Message[i]+k<=93) // For Capital Letters Special Cases & Special Character '[' to "`".
                {
                    Message[i]=Message[i]+k-90;  
                    Message[i]=64+Message[i];       //26 + the extra value of key left after 90.To Strat From "A"
                    Encrypted_msg=Encrypted_msg+Message[i];

                }
                else
                {
                    Message[i]=Message[i]+k; // For Normal Cases
                     Encrypted_msg=Encrypted_msg+Message[i];
                }
                
                
            }
            
            
        }
        cout<<"Your Encrypted Message Is : "<<Encrypted_msg;

   
   
    
    
    
}



void Decrypt(){
    char c;
    int k=3;   // <--- Key
    string Message;
    string Decrypted_msg;

        cout<<"Enter The Message You Want To Decrypt"<<endl;
        cin.ignore();
        getline(cin,Message);

        
        for (int  i = 0; i < Message.size(); i++)
        {
            if (Message[i]==32)         //32 IN ASCII = SPACE " "
            {
                Decrypted_msg=Decrypted_msg+Message[i];
                continue;
            }
            else
            {
                if (Message[i]-k<97&&Message[i]-k>=94) // For Small Letters Special Case & Special Character '[' to "`".
                {
                    Message[i]=Message[i]-k;
                    Message[i]=Message[i]+26;
                    Decrypted_msg=Decrypted_msg+Message[i];
                }
                else if (Message[i]-k>61 && Message[i]-k<65)   
                {
                    Message[i]=Message[i]-k;  
                    Message[i]=Message[i] + 26;   
                    Decrypted_msg=Decrypted_msg+Message[i];

                }
                else
                {   
                    Message[i]=Message[i]-k;           // Normal Case.
                     Decrypted_msg=Decrypted_msg+Message[i];
                }
                
                
            }
            
            
        }
        cout<<"Your Decrypted Message Is :"<<Decrypted_msg;
    
}

int main(){
    char a;
    cout<<"<-----WELCOME TO CAESAR CIPHER ENCRYPT/DECRYPT PROGRAM----->"<<endl;
    cout<<"\n";
    cout<<"Enter 1 For Encryption"<<endl;
    cout<<"Enter 0 For Decryption"<<endl;
    cin>>a;

        if(a=='1'){
            Encrypt();
        }
        else if(a=='0'){
             Decrypt();
        }
        else{
           cout<<"Enter Correct Choice"<<endl;
        }

    getch();

    return 0;

}