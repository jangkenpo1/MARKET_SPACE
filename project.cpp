#include <iostream>
#include <conio.h>
using namespace std;

int pilih = 1, input;

struct DataDiri {
    string nama, username, password;
    int saldo = 0;
};

struct Seller {
    DataDiri data;
    string namaToko;
    float luasTanah, luasRuangan;
    int hargaSewa, jumlahLantai;
    struct Alamat {
        string jalan, provinsi, kota, kabupaten;
        int nomor;
    } alamat;
}AkunSeller[100];
int jumlahSeller = 0;

struct Member {
    DataDiri data;
    string HP, email;
}AkunMember[100];
int jumlahMember = 0;

struct Mitra {
    DataDiri data;
}AkunMitra[100];
int jumlahMitra = 0;

// Cetak banner
void Banner() {
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

// Cetak teks tengah
void CetakMid(string teks, bool enter = false, int lebar = 70, int menuPil = 0) {
    cout << "|";
    int panjang = teks.length();
    for (int i = 0; i <= lebar - panjang; i++) {
        if (i == (lebar - panjang)/2) {
            if (pilih == menuPil) cout << "\33[35m" << teks << "\33[0m";
            else cout << teks;
        } else cout << " ";
    }
    cout << "|";
    if (enter) cout << endl;
}

void SignIn(int jenis){//1 member, 2 seller, 3 mitra
	cin.ignore();
	string username, password;
	bool valid = false;
	switch(jenis){//1 member, 2 seller, 3 mitra
		case 1:
			do {
				Banner();
				CetakMid("SIGN IN MEMBER", true, 70);
				for(int i = 0; i < 72; i++) cout << "="; cout << endl;
			    valid = true;
			    bool usernameDitemukan = false;
    			bool loginBerhasil = false;
			    cout << "Masukkan Username: ";
			    getline(cin, username);
			    cout << "Masukkan Password: ";
			    getline(cin, password);
				for (int i = 0; i < jumlahMember; i++) {
			        if (AkunMember[i].data.username == username) {
			            usernameDitemukan = true;
			            if (AkunMember[i].data.password == password) {
			                loginBerhasil = true;
			                break;  // username & password cocok, keluar loop
			            } break; // username cocok, tapi password salah — tidak perlu lanjut
			        }
			    }
			    if (loginBerhasil) {
			        cout << "\033[34mLogin sebagai member berhasil!\033[0m\n";
			        system("pause");
					return; //ganti pake fungsi memanggil menu member nanti
			    } else if (usernameDitemukan) {
			        cout << "\033[31mPassword salah!\033[0m\n";
			    } else {
			        cout << "\033[31mUsername tidak ditemukan!\033[0m\n";
			    }
			    cout << "Ingin coba lagi? (y/n): ";
		        char jawab;
		        cin >> jawab;
		        cin.ignore(); // buang enter
		        if (jawab == 'y' || jawab == 'Y') valid = false;
		        else {
		        	system("pause");
					return; // keluar dari fungsi SignIn
				}
			} while (!valid);
		case 2:
			do {
				Banner();
				CetakMid("SIGN IN SELLER", true, 70);
				for(int i = 0; i < 72; i++) cout << "="; cout << endl;
			    valid = true;
			    bool usernameDitemukan = false;
   	 			bool loginBerhasil = false;
			    cout << "Masukkan Username: ";
			    getline(cin, username);
			    cout << "Masukkan Password: ";
			    getline(cin, password);
				for (int i = 0; i < jumlahMember; i++) {
			        if (AkunSeller[i].data.username == username) {
			            usernameDitemukan = true;
			            if (AkunSeller[i].data.password == password) {
			                loginBerhasil = true;
			                break;  // username & password cocok, keluar loop
			            } break; // username cocok, tapi password salah — tidak perlu lanjut
			        }
			    }
			    if (loginBerhasil) {
			        cout << "\033[34mLogin sebagai seller berhasil!\033[0m\n";
			        system("pause");
					return; //ganti pake fungsi memanggil menu seller nanti
			    } else if (usernameDitemukan) {
			        cout << "\033[31mPassword salah!\033[0m\n";
			    } else {
			        cout << "\033[31mUsername tidak ditemukan!\033[0m\n";
			    }
			    cout << "Ingin coba lagi? (y/n): ";
		        char jawab;
		        cin >> jawab;
		        cin.ignore(); // buang enter
		        if (jawab == 'y' || jawab == 'Y') valid = false;
		        else {
		        	system("pause");
					return; // keluar dari fungsi SignIn
				}
			} while (!valid);
		case 3:
			do {
				Banner();
				CetakMid("SIGN IN MITRA", true, 70);
				for(int i = 0; i < 72; i++) cout << "="; cout << endl;
			    valid = true;
			    bool usernameDitemukan = false;
    			bool loginBerhasil = false;
			    cout << "Masukkan Username: ";
			    getline(cin, username);
			    cout << "Masukkan Password: ";
			    getline(cin, password);
				for (int i = 0; i < jumlahMember; i++) {
			        if (AkunMitra[i].data.username == username) {
			            usernameDitemukan = true;
			            if (AkunMitra[i].data.password == password) {
			                loginBerhasil = true;
			                break;  // username & password cocok, keluar loop
			            } break; // username cocok, tapi password salah — tidak perlu lanjut
			        }
			    }
			    if (loginBerhasil) {
			        cout << "\033[34mLogin sebagai mitra berhasil!\033[0m\n";
			        system("pause");
					return; //ganti pake fungsi memanggil menu mitra nanti
			    } else if (usernameDitemukan) {
			        cout << "\033[31mPassword salah!\033[0m\n";
			    } else {
			        cout << "\033[31mUsername tidak ditemukan!\033[0m\n";
			    }
			    cout << "Ingin coba lagi? (y/n): ";
		        char jawab;
		        cin >> jawab;
		        cin.ignore(); // buang enter
		        if (jawab == 'y' || jawab == 'Y') valid = false;
		        else {
		        	system("pause");
					return; // keluar dari fungsi SignIn
				}
			} while (!valid);
	}
}

void SignUp(int jenis) {//1 member, 2 seller, 3 mitra
	cin.ignore();
    Banner();
    string nama, username, password, hp, email;
    bool valid = false;
    switch(jenis){//1 member, 2 seller, 3, mitra
    	case 1:
    		CetakMid("SIGN UP MEMBER", true, 70);
	        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
	        cout << "Masukkan Nama: ";
	        getline(cin, nama);
	        do {
			    valid = true;
			    cout << "Masukkan Username: ";
			    getline(cin, username);
				for (int i = 0; i < jumlahMember; i++) {
			        if (AkunMember[i].data.username == username){
			        	cout << "Username sudah digunakan!\n";
				        cout << "Ingin coba lagi? (y/n): ";
				        char jawab;
				        cin >> jawab;
				        cin.ignore(); // buang enter
				        if (jawab == 'y' || jawab == 'Y') valid = false;
				        else {
				        	system("pause");
							return; // keluar dari fungsi SignUp
						}
			        }
				}
			} while (!valid);
	        cout << "Masukkan No HP: ";
	        getline(cin, hp);
	        cout << "Masukkan Email: ";
	        getline(cin, email);
	        cout << "Masukkan Password: ";
	        getline(cin, password);
	
	        AkunMember[jumlahMember].data.nama = nama;
	        AkunMember[jumlahMember].data.username = username;
	        AkunMember[jumlahMember].data.password = password;
	        AkunMember[jumlahMember].HP = hp;
	        AkunMember[jumlahMember].email = email;
	        jumlahMember++;
	
	        cout << "Pendaftaran member berhasil!\n";
	        break;
	    case 2:
    		CetakMid("SIGN UP SELLER", true, 70);
	        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
	        cout << "Masukkan Nama: ";
	        getline(cin, nama);
			do {
			    valid = true;
			    cout << "Masukkan Username: ";
			    getline(cin, username);
				for (int i = 0; i < jumlahSeller; i++) {
			        if (AkunSeller[i].data.username == username){
			        	cout << "Username sudah digunakan!\n";
				        cout << "Ingin coba lagi? (y/n): ";
				        char jawab;
				        cin >> jawab;
				        cin.ignore(); // buang enter
				        if (jawab == 'y' || jawab == 'Y') valid = false;
				        else {
				        	system("pause");
							return; // keluar dari fungsi SignUp
						}
			        }
			    }
			} while (!valid);
	        cout << "Masukkan Password: ";
	        getline(cin, password);
	
	        // Simpan data seller
	        AkunSeller[jumlahSeller].data.nama = nama;
	        AkunSeller[jumlahSeller].data.username = username;
	        AkunSeller[jumlahSeller].data.password = password;
	        jumlahSeller++;
	
	        cout << "Pendaftaran seller berhasil!\n";
	        break;
	    case 3:
	    	CetakMid("SIGN UP MITRA", true, 70);
	        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
	        cout << "Masukkan Nama Mitra: ";
	        getline(cin, nama);
	        do {
			    valid = true;
			    cout << "Masukkan Username: ";
			    getline(cin, username);
				for (int i = 0; i < jumlahMitra; i++) {
			        if (AkunMitra[i].data.username == username){
			        	cout << "Username sudah digunakan!\n";
				        cout << "Ingin coba lagi? (y/n): ";
				        char jawab;
				        cin >> jawab;
				        cin.ignore(); // buang enter
				        if (jawab == 'y' || jawab == 'Y') valid = false;
				        else {
				        	system("pause");
							return; // keluar dari fungsi SignUp
						}
			        }
			    }
			} while (!valid);
	        cout << "Masukkan Password: ";
	        getline(cin, password);
	        
			AkunMitra[jumlahMitra].data.nama = nama;
	        AkunMitra[jumlahMitra].data.username = username;
	        AkunMitra[jumlahMitra].data.password = password;
	        jumlahMitra++;
	        cout << "Pendaftaran mitra berhasil!\n";
	}
	system("pause");
}
// Menu Sign
void MenuSign(bool signin) {// kalok true dia sign, kalok false dia signup
    pilih = 1;
    do {
        Banner();
        CetakMid((signin == true)? "SIGN IN" : "SIGN UP", true, 70);
        for(int i = 0; i < 72; i++) cout << "="; cout << endl;

        CetakMid("Member", true, 70, 1);
        CetakMid("Seller", true, 70, 2);
        CetakMid("Mitra", true, 70, 3);
        CetakMid("Back", true, 70, 4);
        for(int i = 0; i < 72; i++) cout << "=";

        input = getch();
        switch(input) {
            case 72: pilih = (pilih == 1) ? 4 : pilih - 1; break; // Up
            case 80: pilih = (pilih == 4) ? 1 : pilih + 1; break; // Down
            case 13:
            	switch(pilih){
            		case 1:
            			(signin == true)? SignIn(1): SignUp(1);
            			break;
            		case 2:
            			(signin == true)? SignIn(2): SignUp(2);
            			break;
            		case 3:
            			(signin == true)? SignIn(3): SignUp(3);
            			break;
            		case 4:
            			pilih = 1;
            			return;
				}
        }
    } while (true);
}

// Main Menu
void MainMenu() {
    pilih = 1;
    do {
        Banner();
        CetakMid("WELCOME TO MARKETPLACE", true, 70);
        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
		CetakMid("Sign In", true, 70, 1);
        CetakMid("Sign Up", true, 70, 2);
        CetakMid("Exit", true, 70, 3);
        for(int i = 0; i < 72; i++) cout << "=";

        input = getch();
        switch (input) {
            case 72: pilih = (pilih == 1) ? 3 : pilih - 1; break;
            case 80: pilih = (pilih == 3) ? 1 : pilih + 1; break;
            case 13:
            	switch(pilih){
            		case 1:
            			MenuSign(true);//untuk ke menu sign(signIn)
            			break;
            		case 2:
            			MenuSign(false);//untuk ke menu sign(signUp)
            			break;
            		case 3:
            			return;
				}
        }
    } while (true);
}

int main() {
    MainMenu();
    return 0;
}
