#include <iostream>
#include <conio.h>
using namespace std;

int pilih = 1, input, AkunYangMasuk = 0;

struct DataDiri {
    string nama, username, password;
    int saldo = 0;
};

struct Alamat {
	string jalan, provinsi, kota, kabupaten;
	int nomor;
};

struct mitra {
	string namaToko;
	string noTelp;
	float luasTanah, luasRuangan;
    int hargaSewa, jumlahLantai;
	Alamat alamatToko;
} ;

struct Mitra {
	DataDiri data;
	mitra TokoMitra[100];
	int indeksTokoMitra;
} AkunMitra[100];
int jumlahMitra = 0;

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

struct seller {
    string namaBarang;
    int harga ;
    int stok;
    string kategori;
    string deskripsi;
}BarangSeller[100];
int jumlahBarang = 0;

struct member{
    string namaBarang;
    int harga;
    int jumlah;
} ;
int jumlahBarangMember = 0;

struct Member {
    DataDiri data;
    string HP, email;
    member BarangMember[100];
	int indeksBarangMember = 0;
}AkunMember[100];
int jumlahMember = 0;

void MenuSign(bool signin);

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

void MenuMember(){
    cin.ignore();
    do{
	string Baru;
	string PreviewNamaBarang[100];
	int PreviewHargaBarang[100];
    system("cls");
    Banner();
    CetakMid("Halo " + AkunMember[AkunYangMasuk].data.nama, true, 70);
    for(int i = 0; i < 72; i++) cout << "="; cout << endl;
    CetakMid("Beli Barang", true, 70, 1);
    CetakMid("Saldo", true, 70, 2);
    CetakMid("History", true, 70, 3);
    CetakMid("Profile", true, 70, 4);
    CetakMid("Log Out", true, 70, 5);
    for(int i = 0; i < 72; i++) cout << "=";

        input = getch();
        switch(input) {
            case 72: pilih = (pilih == 1) ? 5 : pilih - 1; break; // Up
            case 80: pilih = (pilih == 5) ? 1 : pilih + 1; break; // Down
            case 13:
            	switch(pilih){
            		case 1 : {
                        system("cls");
                        Banner();
                        CetakMid("BELI BARANG", true, 70);
                        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
                        CetakMid("Barang Yang Tersedia :", true, 70);
                        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
                        if (jumlahBarang == 0) {
                            cout << "Tidak ada barang tersedia." << endl;
                        } else {
							int beliBarang = 0;
							int harga = 0;
							do {
								for(int i = 0; i < jumlahBarang; i++) {
									CetakMid(BarangSeller[i].namaBarang, true, 33, i + 1);
									if (i % 3 == 0) cout << endl;
								}
								for(int i = 0; i < 72; i++) cout << "="; cout << endl;
								CetakMid( "Daftar Keranjang :", true, 3);
								for (int j = 0; j < beliBarang; j++) {
									cout << j + 1 << ". " << PreviewNamaBarang[j] 
										  << " - Rp." << PreviewHargaBarang[j] << endl;
								}
								for(int i = 0; i < 72; i++) cout << "="; cout << endl;
								CetakMid( "BAYAR", true, 3, jumlahBarang );
								for(int i = 0; i < 72; i++) cout << "="; cout << endl;
								CetakMid( "CANCEL", true, 3, jumlahBarang + 1);
								for(int i = 0; i < 72; i++) cout << "="; cout << endl;
								case 72: pilih = (pilih == 1) ? jumlahBarang : pilih - 1; break; // Up
            					case 80: pilih = (pilih == jumlahBarang + 1) ? 1 : pilih + 1; break; // Down
								case 13:
									if(pilih < jumlahBarang){
										system("cls");
										Banner();
										CetakMid("PREVIEW", true, 70);
										for(int i = 0; i < 72; i++) cout << "="; cout << endl;
										if (BarangSeller[pilih - 1].stok == 0) {
											cout << "Stok barang habis." << endl;
										} else {
											cout << "Nama Barang: " << BarangSeller[pilih - 1].namaBarang << endl;
											PreviewNamaBarang[beliBarang] = BarangSeller[pilih - 1].namaBarang;
											cout << "Harga: Rp." << BarangSeller[pilih - 1].harga << endl;
											PreviewHargaBarang[beliBarang] = BarangSeller[pilih - 1].harga;
											harga += BarangSeller[pilih - 1].harga;
											cout << "Stok: " << BarangSeller[pilih - 1].stok << endl;
											cout << "Deskripsi: " << BarangSeller[pilih - 1].deskripsi << endl;
											beliBarang++;
										}
									}
									else if (pilih == jumlahBarang) {
										system("cls");
										Banner();
										CetakMid("CHECKOUT", true, 70);
										for(int i = 0; i < 72; i++) cout << "="; cout << endl;
										if (beliBarang > 0) {
											cout << "Total Harga: Rp." << harga << endl;
											system("pause");
											if (AkunMember[AkunYangMasuk].data.saldo >= harga) {
												AkunMember[AkunYangMasuk].data.saldo -= harga;
												for (int i = 0; i < beliBarang; i++) {
													AkunMember[AkunYangMasuk].BarangMember[i].jumlah = 1; 
												}
												int indeksBarang = AkunMember[AkunYangMasuk].indeksBarangMember ;
												for (int i = 0; i < beliBarang; i++) {
													AkunMember[AkunYangMasuk].BarangMember[indeksBarang].namaBarang = PreviewNamaBarang[i];
													AkunMember[AkunYangMasuk].BarangMember[indeksBarang].harga = PreviewHargaBarang[i];
													indeksBarang++;
												}
												AkunMember[AkunYangMasuk].indeksBarangMember = indeksBarang;
												cout << "Pembelian berhasil! Saldo Anda sekarang: Rp." << AkunMember[AkunYangMasuk].data.saldo << endl;
											} else {
												cout << "Saldo tidak cukup untuk melakukan pembelian." << endl;
											}
										} else {
											system("cls");
											Banner();
											CetakMid("KERANJANG", true, 70);
											for(int i = 0; i < 72; i++) cout << "="; cout << endl;
											if (beliBarang == 0) {
												cout << "Keranjang kosong. Tidak ada barang yang dibeli." << endl;
											}
										}
										break;
									}
									else if (pilih == jumlahBarang + 1){

									}
									system("pause");
							} while (true);

                        }
						system("pause");
                        break;
                    }
            		case 2 : {
                        system("cls");
                        Banner();
                        CetakMid("SALDO " + AkunMember[AkunYangMasuk].data.nama, true, 70);
                        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
                        cout << "Saldo Anda: Rp." << AkunMember[AkunYangMasuk].data.saldo << endl;
                        cout << "Ingin menambah saldo? (y/n): ";
                        char jawab;
                        cin >> jawab;
                        cin.ignore(); 
                        if (jawab == 'y' || jawab == 'Y') {
                            int nominal;
                            cout << "Masukkan nominal yang ingin ditambahkan: ";
                            cin >> nominal;
                            AkunMember[AkunYangMasuk].data.saldo += nominal;
                            cout << "Saldo berhasil ditambahkan!" << endl;
                            system("pause");
                        } 
                        break;
                    }
            		case 3 : {
                        system("cls"); 
                        Banner();
                        CetakMid("HISTORY " + AkunMember[AkunYangMasuk].data.nama, true, 70);
                        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
                        cout << "History pembelian Anda:\n"; 
                        if (jumlahBarang == 0) {
                            cout << "Tidak ada history pembelian." << endl;
                        } else {
                            for(int i = 0; i < jumlahBarangMember; i++) {
                                cout << i + 1 << ". " << AkunMember[AkunYangMasuk].BarangMember[i].namaBarang
                                     << " - Rp." << AkunMember[AkunYangMasuk].BarangMember[i].harga
                                     << " (Jumlah: " << AkunMember[AkunYangMasuk].BarangMember[i].jumlah << ")" << endl;
                            }
                        }
                        system("pause");
                        break;
                    }
            		case 4 : {
                        system("cls");
                        Banner();
                        CetakMid("PROFILE " + AkunMember[AkunYangMasuk].data.nama, true, 70);
                        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
                        cout << "1. Nama: " << AkunMember[AkunYangMasuk].data.nama << endl;
                        cout << "2. Username: " << AkunMember[AkunYangMasuk].data.username << endl;
                        cout << "3. No HP: " << AkunMember[AkunYangMasuk].HP << endl;
                        cout << "4. Email: " << AkunMember[AkunYangMasuk].email << endl;
						cout << "5. Password: " << AkunMember[AkunYangMasuk].data.password << endl;
                        cout << "6. Saldo: " << AkunMember[AkunYangMasuk].data.saldo << endl;
						int pilihan;
						cout << "Ketik 1-5 untuk mengubah data, ketik 0 untuk kembali... "; cin >> pilihan;
						cin.ignore();
						if (pilihan == 1) {
							cout << "Masukkan nama baru: "; getline(cin, Baru);
							cout << "Apakah anda yakin? (y/n): ";
							char jawab;		
							cin >> jawab;
							if (jawab == 'y' || jawab == 'Y') {
								AkunMember[AkunYangMasuk].data.nama = Baru;
								cout << "Data berhasil diubah!\n";
							}
						} else if (pilihan == 2) {
							cout << "Masukkan username baru: "; getline(cin, Baru);
							cout << "Apakah anda yakin? (y/n): ";
							char jawab;
							cin >> jawab;
							if (jawab == 'y' || jawab == 'Y') {
								AkunMember[AkunYangMasuk].data.username = Baru;
								cout << "Data berhasil diubah!\n";
							}
						} else if (pilihan == 3) {
							cout << "Masukkan No HP baru: "; getline(cin, Baru);
							cout << "Apakah anda yakin? (y/n): ";
							char jawab;
							cin >> jawab;
							if (jawab == 'y' || jawab == 'Y') {
								AkunMember[AkunYangMasuk].HP = Baru;
								cout << "Data berhasil diubah!\n";
							}
						} else if (pilihan == 4) {
							cout << "Masukkan Email baru: "; getline(cin, Baru);
							cout << "Apakah anda yakin? (y/n): ";
							char jawab;
							cin >> jawab;
							if (jawab == 'y' || jawab == 'Y') {
								AkunMember[AkunYangMasuk].email = Baru;
								cout << "Data berhasil diubah!\n";
							}
						} else if (pilihan == 5) {
							cout << "Masukkan Password baru: "; getline(cin, Baru);
							cout << "Apakah anda yakin? (y/n): ";
							char jawab;
							cin >> jawab;
							if (jawab == 'y' || jawab == 'Y') {
								AkunMember[AkunYangMasuk].data.password = Baru;
								cout << "Data berhasil diubah!\n";
							}
						} 
                        system("pause");
                        break;
            		case 5 : {
                        MenuSign(1); // ini gimana biar balek ke menu awal? 0/1?
                    }
				}
            }
        }
    } while (true);
}

void MenuMitra(){
	cin.ignore();
    do{
    system("cls");
    Banner();
    CetakMid("Halo " + AkunMitra[AkunYangMasuk].data.nama, true, 70);
    for(int i = 0; i < 72; i++) cout << "="; cout << endl;
	CetakMid("Tambah Toko", true, 70, 1);
    CetakMid("Daftar Toko", true, 70, 2);
    CetakMid("Saldo", true, 70, 3);
    CetakMid("Profile", true, 70, 4);
    CetakMid("Log Out", true, 70, 5);
    for(int i = 0; i < 72; i++) cout << "=";

        input = getch();
        switch(input) {
            case 72: pilih = (pilih == 1) ? 5 : pilih - 1; break; // Up
            case 80: pilih = (pilih == 5) ? 1 : pilih + 1; break; // Down
            case 13:
			switch(pilih) {
				case 1: {
					system("cls");
					Banner();
					int indeksToko = AkunMitra[AkunYangMasuk].indeksTokoMitra;
					CetakMid("TAMBAH RUKO " + AkunMitra[AkunYangMasuk].data.nama, true, 70);
					for(int i = 0; i < 72; i++) cout << "="; cout << endl;
					cout << "Masukkan Nama Toko: ";	cin.ignore(); getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].namaToko);
					cout << "Masukkan Alamat : ";	cin.ignore();getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.jalan);
					cout << "Masukkan Kabupaten: ";	cin.ignore(); getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.kabupaten);
					cout << "Masukkan Kota: ";	cin.ignore(); getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.kota);
					cout << "Masukkan Provinsi: ";	cin.ignore(); getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.provinsi);
					cout << "Masukkan Nomor Toko : ";	cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.nomor;
					cout << "Masukkan No Telepon : ";	cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].noTelp;
					cout << "Masukkan Luas Tanah (m2): ";	cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].luasTanah;
					cout << "Masukkan Luas Ruangan (m2): ";	cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].luasRuangan;
					cout << "Masukkan Harga Sewa (per tahun): Rp.";	cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].hargaSewa;
					cout << "Masukkan Jumlah Lantai: ";	cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].jumlahLantai;
					indeksToko++;
					AkunMitra[AkunYangMasuk].indeksTokoMitra++;
					cout << "Toko berhasil ditambahkan!\n";
					system("pause");
					break;
				}
				case 2: {
					system("cls");
					Banner();
					CetakMid("DAFTAR TOKO " + AkunMitra[AkunYangMasuk].data.nama, true, 70);
					for(int i = 0; i < 72; i++) cout << "="; cout << endl;
					for (int i = 0; i < AkunMitra[AkunYangMasuk].indeksTokoMitra; i++) {
						cout << i + 1 << ". " << AkunMitra[AkunYangMasuk].TokoMitra[i].namaToko << endl;
						cout << "   Alamat: " << AkunMitra[AkunYangMasuk].TokoMitra[i].alamatToko.jalan << ", "
						     << AkunMitra[AkunYangMasuk].TokoMitra[i].alamatToko.kabupaten << ", "
						     << AkunMitra[AkunYangMasuk].TokoMitra[i].alamatToko.kota << ", "
						     << AkunMitra[AkunYangMasuk].TokoMitra[i].alamatToko.provinsi << endl;
						cout << "   No Telepon: " << AkunMitra[AkunYangMasuk].TokoMitra[i].noTelp << endl;
						cout << "   Luas Tanah: " << AkunMitra[AkunYangMasuk].TokoMitra[i].luasTanah << " m2" << endl;
						cout << "   Luas Ruangan: " << AkunMitra[AkunYangMasuk].TokoMitra[i].luasRuangan << " m2" << endl;
						cout << "   Harga Sewa: Rp." << AkunMitra[AkunYangMasuk].TokoMitra[i].hargaSewa << endl;
						cout << "   Jumlah Lantai: " << AkunMitra[AkunYangMasuk].TokoMitra[i].jumlahLantai << endl;
						for(int i = 0; i < 72; i++) cout << "="; cout << endl;
					}
					cout << "Apakah anda ingin mengedit informasi toko? (y/n): ";
					char jawab;
					cin >> jawab;
					if(jawab == 'y' || jawab == 'Y') {
						cout << "pilih nomor toko yang ingin diedit (0 untuk batal): ";
						int nomorToko;
						cin >> nomorToko;
						if(nomorToko > 0 && nomorToko <= AkunMitra[AkunYangMasuk].indeksTokoMitra) {
							int indeks = nomorToko - 1;
							cout << "Masukkan Nama Toko Baru: "; cin.ignore(); getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeks].namaToko);
							cout << "Masukkan Alamat Baru: "; cin.ignore(); getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeks].alamatToko.jalan);
							cout << "Masukkan Kabupaten Baru: "; cin.ignore(); getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeks].alamatToko.kabupaten);
							cout << "Masukkan Kota Baru: "; cin.ignore(); getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeks].alamatToko.kota);
							cout << "Masukkan Provinsi Baru: "; cin.ignore(); getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeks].alamatToko.provinsi);
							cout << "Masukkan Nomor Toko Baru: "; cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeks].alamatToko.nomor;
							cout << "Masukkan No Telepon Baru: "; cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeks].noTelp;
							cout << "Masukkan Luas Tanah Baru (m2): "; cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeks].luasTanah;
							cout << "Masukkan Luas Ruangan Baru (m2): "; cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeks].luasRuangan;
							cout << "Masukkan Harga Sewa Baru (per tahun): Rp."; cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeks].hargaSewa;
							cout << "Masukkan Jumlah Lantai Baru: "; cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeks].jumlahLantai;
							cout << "Informasi toko berhasil diubah!\n";
						} else {
							cout << "Batal mengedit informasi toko.\n";
						}
					}
					system("pause");
					break;
				}
				case 3: {
					system("cls");
					Banner();
					CetakMid("SALDO " + AkunMitra[AkunYangMasuk].data.nama, true, 70);
					for(int i = 0; i < 72; i++) cout << "="; cout << endl;
					cout << "Saldo Anda: Rp." << AkunMitra[AkunYangMasuk].data.saldo << endl;
					system("pause");
					break;
				}
				case 4: {
					system("cls");
					Banner();
					CetakMid("PROFILE " + AkunMitra[AkunYangMasuk].data.nama, true, 70);
					for(int i = 0; i < 72; i++) cout << "="; cout << endl;
					cout << "1. Nama: " << AkunMitra[AkunYangMasuk].data.nama << endl;
					cout << "2. Username: " << AkunMitra[AkunYangMasuk].data.username << endl;
					cout << "3. Password: " << AkunMitra[AkunYangMasuk].data.password << endl;
					int pilihan;
					cout << "Ketik 1-3 untuk mengubah data, ketik 0 untuk kembali... "; cin >> pilihan;
					cin.ignore();
					switch(pilihan) {
						case 1:
							cout << "Masukkan Nama Baru: ";
							getline(cin, AkunMitra[AkunYangMasuk].data.nama);
							break;
						case 2:
							cout << "Masukkan Username Baru: ";
							getline(cin, AkunMitra[AkunYangMasuk].data.username);
							break;
						case 3:
							cout << "Masukkan Password Baru: ";
							getline(cin, AkunMitra[AkunYangMasuk].data.password);
							break;
						case 0:
							break;
						default:
							cout << "Pilihan tidak valid!" << endl;
					}
					cout << "Data berhasil diubah!\n";
					system("pause");
					break;
				}
				case 5: {
					MenuSign(1); // kembali ke menu sign
					break;
				}
			}
		}
	} while(true);
}

void SignIn(int jenis){//1 member, 2 seller, 3 mitra
	cin.ignore();
	string username, password;
	bool valid = false;
	switch(jenis){
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
							AkunYangMasuk = i; // Simpan indeks akun yang masuk
			                break;  
			            } break; 
			        }
			    }
			    if (loginBerhasil) {
			        cout << "\033[34mLogin sebagai member berhasil!\033[0m\n";
			        system("pause");
					MenuMember(); 
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
				for (int i = 0; i < jumlahSeller; i++) {
			        if (AkunSeller[i].data.username == username) {
			            usernameDitemukan = true;
			            if (AkunSeller[i].data.password == password) {
			                loginBerhasil = true;
							AkunYangMasuk = i; // Simpan indeks akun yang masuk
			                break;  
			            } break; 
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
				for (int i = 0; i < jumlahMitra; i++) {
			        if (AkunMitra[i].data.username == username) {
			            usernameDitemukan = true;
			            if (AkunMitra[i].data.password == password) {
			                loginBerhasil = true;
							AkunYangMasuk = i; // Simpan indeks akun yang masuk
			                break;  
			            } break; 
			        }
			    }
			    if (loginBerhasil) {
			        cout << "\033[34mLogin sebagai mitra berhasil!\033[0m\n";
			        system("pause");
					MenuMitra();
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
	        cout << "Masukkan Password: "; getline(cin, password);

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
