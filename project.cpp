#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int pilih = 1;
int input ;

struct member{
    string nama;
    string username;
    string HP;
    string email;
    string password;
} AkunMember;

struct seller{
    string nama;
    string username;
    string password;
    string namaToko;
    struct attributinformasiToko{
        int luasTanah;
        int luasRuangan;
        int hargaSewa;
        int JlmhLantai;
        struct attributalamatToko{
            string Jln;
            int NomorAddress;
            string Provinsi;
            string Kota;
            string Kabupaten;
        } alamat;
    } infoToko;
} AkunSeller;

void Banner(){
    system("cls");
    cout << R"(

.___  ___.      ___      .______       __  ___  _______ .___________.
|   \/   |     /   \     |   _  \     |  |/  / |   ____||           |
|  \  /  |    /  ^  \    |  |_)  |    |  '  /  |  |__   `---|  |----`
|  |\/|  |   /  /_\  \   |      /     |    <   |   __|      |  |     
|  |  |  |  /  _____  \  |  |\  \----.|  .  \  |  |____     |  |     
|__|  |__| /__/     \__\ | _| `._____||__|\__\ |_______|    |__|     
                                                                     

           _______..______      ___       ______  _______ 
          /       ||   _  \    /   \     /      ||   ____|
         |   (----`|  |_)  |  /  ^  \   |  ,----'|  |__   
          \   \    |   ___/  /  /_\  \  |  |     |   __|  
      .----)   |   |  |     /  _____  \ |  `----.|  |____ 
      |_______/    | _|    /__/     \__\ \______||_______|
                                                          
                                             
                                                   
)";
for(int i = 0; i < 72; i++) cout << "=";
cout << endl;
}

void CetakMid(string teks,  bool enter = false, int lebar = 70, int menuPil = 0){
    cout << "|";
    int panjang = teks.length();
    for (int i = 0; i <= lebar - panjang; i++) {
        if (i == (lebar - panjang)/2){
            if(pilih == menuPil) cout << "\33[35m" << teks << "\33[0m";
            else cout << teks;
        } else cout << " ";
    }
    cout << "|";
    if(enter) cout << endl;
}

void MainMenu();

int main(){
    MainMenu();
    return 0;
}

void SignUpMember(){
    string nama, username, email;
    system("cls");
    Banner();
    CetakMid("~~~~~~~~~~~~~~~", true, 70);
    CetakMid("Sign Up Member", true, 70);
    CetakMid("~~~~~~~~~~~~~~~", true, 70);
    cout << "Masukkan nama: "; cin >> nama;
    cout << "Masukkan username: "; cin >> username;
    cout << "Masukkan email: "; cin >> email;

    cout << "Pendaftaran berhasil untuk " << nama << " dengan email " << email << endl;
    getch();
}

void MenuSignIn(){
    pilih = 1;
    do{
        Banner();
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("Mitra", true, 70, 1);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("Member", true, 70, 2);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("Seller", true, 70, 3);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("Back", true, 70, 4);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        for(int i = 0; i < 72; i++) cout << "="; 
        input = getch();
        
        switch(input){
            case 72: pilih = (pilih == 1) ? 4 : pilih - 1; break;
            case 80: pilih = (pilih == 4) ? 1 : pilih + 1; break;
            case 13: 
                switch(pilih){
                    case 1: 
                        break;
                    case 2: 
                        break;
                    case 3: 
                        break;
                    case 4: 
                        pilih = 1;
                        return; 
                }
        }
    }while(true);
}


void MenuSignUp(){
    pilih = 1;
    system("cls");
    do{
        Banner();
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("Mitra", true, 70, 1);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("Member", true, 70, 2);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("Seller", true, 70, 3);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("Back", true, 70, 4);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        for(int i = 0; i < 72; i++) cout << "=";
        input = getch();
        
        switch(input){
            case 72: pilih = (pilih == 1) ? 4 : pilih - 1; break;
            case 80: pilih = (pilih == 4) ? 1 : pilih + 1; break;
            case 13: 
                switch(pilih){
                    case 1:    
                        //MenuMitra();
                        break;
                    case 2:
                        //// MenuSeller();
                        break;
                    case 3: 
                        //MenuMember();
                        break;
                    case 4:
                        pilih = 1;
                        return;   
                    }  
        }
    } while(true);
}

void MainMenu(){
    pilih = 1;
    do{
        Banner();
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("Sign-In", true, 70, 1);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("Sign-Up", true, 70, 2);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        CetakMid("Exit", true, 70, 3);
        CetakMid("~~~~~~~~~~~~~~~", true, 70);
        for(int i = 0; i < 72; i++) cout << "=";
        input = getch();

        switch(input){
            case 72: pilih = (pilih == 1) ? 3 : pilih - 1; break;
            case 80: pilih = (pilih == 3) ? 1 : pilih + 1; break;
            case 13: 
                switch(pilih){
                    case 1: 
                        MenuSignIn();
                        break;
                    case 2: 
                        MenuSignUp();
                        break;
                    case 3: 
                        return;
                }

        }
    }while(true);
}


