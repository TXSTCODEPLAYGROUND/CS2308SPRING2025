// This code shows how facebook validation and authentication works
// We will have two option either login or register
// If you have id already registered you can login with that id, if not you need to register 
#include <iostream>
#include <vector>

using namespace std;

struct  FaceBook
{
    
    private:
        string user_name;
        string password;
    
    public:
        string profile_name;
        FaceBook(string user_name,string password, string profile_name){
            this-> user_name = user_name;
            this-> password = password;
            this -> profile_name = profile_name;
        }
};

void loadUrl(){
    cout<<"--------------------www.facebook.com---------------------------------"<<endl;
    cout<<"--------------------This is the landing page-------------------------"<<endl;

    char log_id;
    
    while(true){
        cout<<"Login(Enter 1): "<<endl;
        cout<<"Register(Enter 2: ";
        cin>>log_id;

        if(log_id == '1' || log_id == '2')
            break;      
    }

}

int main(){
    // loadUrl();
    vector <string> users;
    FaceBook user1("suman10","messi","pyscho");
    return 0;
}

