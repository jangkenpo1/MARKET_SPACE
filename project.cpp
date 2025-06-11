#include <iostream>
#include <conio.h>

using namespace std;

int pilih = 1, input, AkunYangMasuk = 0;

//Data  untuk semua akun
	struct DataDiri {
	    string nama, username, password;
	    int saldo = 0;
	};
	
	struct Alamat {
		string jalan, desa, kecamatan, kabupaten, kota, provinsi;
		int nomor;
	};
	//Informasi Toko
	struct InfoToko {
		string namaToko;
		string noTelp;
		float luasTanah, luasRuangan;
	    int hargaSewa, jumlahLantai;
		Alamat alamatToko;
	};

struct barangSeller {
    string namaBarang;
    int harga ;
    int stok;
    string kategori;
    string deskripsi;
    string tokoAsal;
    int indeksAkunSeller;//indeks yang punya barang
}BarangSeller[100];
int jumlahBarang = 0;

struct Promo {
    string namaBarang;
    int potongan; // dalam persen
    bool aktif;
};
Promo daftarPromo[100];
int jumlahPromo = 0;

struct Barang{
    string nama;
    string deskripsi;
    string kategori;
    int harga;
    int stok;
};

struct member{
    string namaBarang;
    int harga;
    int jumlah;
	string namaTokoAsal;
};
int jumlahBarangMember = 0;

//Data Member
struct Member {
    DataDiri data;
    string HP, email;
    member BarangMember[100];//barang yang dibeli
    int jumlahBarangMember;
	int indeksBarangMember = 0;
}AkunMember[100];
int jumlahMember = 1;

//SELLER
	//info toko yang disewa, tergantung dia mau jual apa
	struct Toko{
	    string namaToko;
	    string deskripsiToko;
	    string kategoriToko;
	    Barang* daftarBarang;
	    int jumlahBarang;
	    int kapasitasBarang;
	};
	
	//untuk keperluan sewa toko
		struct KategoriTokoSeller{//untuk akses tipe toko sesuai keinginan
			string namaToko[100];
		}kategoriToko[100];
		int jumlahKategori;
		
		struct SewaToko{//semua toko yang bisa di sewa
			string namaPemilik;
			InfoToko toko;
			int harga;
			int idPemilik;
			int indeksToko;//indkes untuk di edit mitra
		}sewaToko[200];
		int jumlahSewaToko = 1;
		
	//Data Seller
	struct Seller {
	    DataDiri data;
	    Toko toko;
		string pesan[500];
		int jumlahPesan = 0;
		member RiwayatMember[100];//list riwayat pembelian  
	    int totalRiwayat = 0;
		int jumlahToko = 0;//bisa nyewa lebih dari 1 toko
	}AkunSeller[100];
	int jumlahSeller = 1;

//MITRA
	struct ListRequestToko{
		string namaPengirim;
		int indeksPengirim;
		int indeksToko;//yang di sewa
		string pesan;
	};
	//DataMitra
	struct Mitra {
		ListRequestToko requestToko[500];
		int jumlahPesan = 0;
		DataDiri data;
		InfoToko TokoMitra[100];
		int jumlahTokoMitra = 0;//jumlah toko yang dimiliki mitra
		int indeksToko[100];//simpan indkesnya untuk edit toko yang di ambil di struct sewaToko
	} AkunMitra[100];
	int jumlahMitra = 1;
 

//Function Prototype
void MenuSign(bool signin);
void MainMenu();
void MenuMember();

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
      
	I N T E G R A T E D    M A R K E T    S Y S T E M
      
)";
    for(int i = 0; i < 72; i++) cout << "=";
    cout << endl;
}

void CetakMid(string teks, bool enter = false, int lebar = 70, int menuPil = 0) {
    cout << "|";
    int panjang = teks.length();
    for (int i = 0; i <= lebar - panjang; i++) {
        if (i == (lebar - panjang)/2) {
            if (pilih == menuPil) cout << "\33[35m" << teks << "\33[0m";
            else cout << teks;
        } else cout << " ";
    }
    cout << "|   ";
    if (enter) cout << endl;
}
 
void MenuMember(int idxAkunLogin){
	do{
		string Baru;
		string PreviewNamaBarang[100];
		int PreviewHargaBarang[100];
	    Banner();
	    CetakMid("Halo " + AkunMember[AkunYangMasuk].data.nama, true, 70);
	    for(int i = 0; i < 72; i++) cout << "="; cout << endl;
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
	    CetakMid("Beli Barang", true, 70, 1);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
	    CetakMid("Saldo", true, 70, 2);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
	    CetakMid("History", true, 70, 3);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
	    CetakMid("Profile", true, 70, 4);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
	    CetakMid("Log Out", true, 70, 5);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
	    for(int i = 0; i < 72; i++) cout << "=";
	        input = getch();
	        switch(input) {
	            case 72: pilih = (pilih == 1) ? 5 : pilih - 1; break; // Up
	            case 80: pilih = (pilih == 5) ? 1 : pilih + 1; break; // Down
	            case 13:
	            	switch(pilih){
	            		case 1 :{//Beli Barang
	            			bool jalan = true;
	            			int beli;
	            			char ans;
		            		do{
		            			Banner();
		                        CetakMid("BELI BARANG", true, 70);
		                        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
		                        CetakMid("Barang Yang Tersedia :", true, 70);
		                        for(int i = 0; i < 70; i++) cout << "=";
		                        cout << endl;
		                        if (jumlahBarang == 0){
									cout << "Tidak ada barang tersedia." << endl;
		                        	jalan = false;
		                        	system("pause");
								} 
		                        else {
									int harga = 0;
									for(int i = 0; i < jumlahBarang; i++) {
										if (i % 3 == 0) {
											cout << endl;
											for(int i = 0; i < 71; i++) cout << "-";
											cout << endl;
										}
										CetakMid(BarangSeller[i].namaBarang, false, 20, i + 1);
									}
									cout << endl;
									for(int i = 0; i < 72; i++) cout << "="; cout << endl;
									CetakMid( "CANCEL", true, 70, jumlahBarang + 1);
									for(int i = 0; i < 72; i++) cout << "="; cout << endl;
									
									input = getch();
									switch (input) {
										case 72:{//up
											if(pilih <= 3) pilih = jumlahBarang + 1;
											else pilih -= 3;
										}break;
										case 80: {//down
											if(pilih == jumlahBarang + 1) pilih = 1;
											else if(pilih >= jumlahBarang - 3) pilih = jumlahBarang + 1;
											else pilih += 3;
										}break;
										case 77: pilih = (pilih == jumlahBarang + 1) ? 1: pilih + 1; break; // Kanan
										case 75: pilih = (pilih == 1) ? jumlahBarang + 1: pilih - 1; break; // Kiri
										case 13:{
											if(pilih == jumlahBarang + 1) jalan = false;
											else{
												cout << "Anda akan membeli " << BarangSeller[pilih - 1].namaBarang << endl;
												cout << "Stok: " << BarangSeller[pilih - 1].stok << endl;
												cout << "Deskripsi: " << BarangSeller[pilih - 1].deskripsi << endl;
												cout <<"Apakah anda yakin ingin membeli barang?(y/Y): ";
												cin >> ans;
												if(ans == 'y' || ans == 'Y'){
													do{
														cout << "Masukan jumlah barang yang akan di beli: ";
														cin >> beli;
														if(beli > BarangSeller[pilih - 1].stok){
															cout << "Jumlah melebihi stok..\n";
															system("pause");
														}else{
															if(BarangSeller[pilih - 1].harga * pilih > AkunMember[idxAkunLogin].data.saldo){
																cout << "Saldo anda tidak cukup...";
															}else{
																int totalHarga = BarangSeller[pilih - 1].harga * beli;
																AkunMember[idxAkunLogin].data.saldo -= totalHarga;
																cout << "Pembelian anda berhasil di proses\n";
																
																//Simpan di riwayat Member
																int& indeksBarang = AkunMember[idxAkunLogin].jumlahBarangMember;
																AkunMember[idxAkunLogin].BarangMember[indeksBarang].namaBarang = BarangSeller[pilih - 1].namaBarang;
																AkunMember[idxAkunLogin].BarangMember[indeksBarang].harga = BarangSeller[pilih - 1].harga;
																AkunMember[idxAkunLogin].BarangMember[indeksBarang].jumlah = beli;
																AkunMember[idxAkunLogin].BarangMember[indeksBarang].namaTokoAsal = BarangSeller[pilih - 1].tokoAsal;
																AkunMember[idxAkunLogin].BarangMember[indeksBarang].namaBarang = BarangSeller[pilih - 1].namaBarang;
																indeksBarang++;
																
																//Simpan di riwayat Seller
																int indeksAkunSeller = BarangSeller[pilih - 1].indeksAkunSeller;
																int& indeksRiwayat = AkunSeller[indeksAkunSeller].totalRiwayat;
																AkunSeller[indeksAkunSeller].RiwayatMember[indeksRiwayat].namaBarang = BarangSeller[pilih - 1].namaBarang;
																AkunSeller[indeksAkunSeller].RiwayatMember[indeksRiwayat].jumlah = beli;
																AkunSeller[indeksAkunSeller].RiwayatMember[indeksRiwayat].harga = BarangSeller[pilih - 1].harga * beli;
																AkunSeller[indeksAkunSeller].RiwayatMember[indeksRiwayat].namaTokoAsal = AkunSeller[idxAkunLogin].data.username;
																indeksRiwayat++;
																system("pause");
																break;
															}
															system("pause");
														}
													}while(beli > BarangSeller[pilih - 1].stok);
													pilih = 1;
												}else jalan = false;
											}
										}
									}
								}
							}while(jalan == true);
							pilih = 1;
							break;
						}
						case 2:{//Saldo
							Banner();
	                        CetakMid("SALDO " + AkunMember[AkunYangMasuk].data.nama, true, 70);
	                        for(int i = 0; i < 72; i++) cout << "=";
	                        cout << "\nSaldo Anda: Rp." << AkunMember[AkunYangMasuk].data.saldo << endl;
	                        cout << "Ingin menambah saldo? (y): ";
	                        char jawab;
	                        cin >> jawab;
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
						case 3:{//History
							 system("cls"); 
	                        Banner();
	                        CetakMid("HISTORY " + AkunMember[AkunYangMasuk].data.nama, true, 70);
	                        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
	                        cout << "History pembelian Anda:\n"; 
	                        if (AkunMember[idxAkunLogin].jumlahBarangMember == 0) {
	                            cout << "Tidak ada history pembelian." << endl;
	                        } else {
	                            for(int i = 0; i < AkunMember[idxAkunLogin].jumlahBarangMember; i++) {
	                                cout << i + 1 << ". " << AkunMember[AkunYangMasuk].BarangMember[i].namaBarang
	                                     << " - Rp." << AkunMember[AkunYangMasuk].BarangMember[i].harga
	                                     << " (Jumlah: " << AkunMember[AkunYangMasuk].BarangMember[i].jumlah << ")" << endl;
	                            }
	                        }
	                        system("pause");
	                        break;
						}
						case 4:{//Profile
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
						}
						case 5:{//Back
							cin.ignore();
							pilih = 1;
							return;
						}
					}
			}
	}while(true);
}
void MenuSeller(int idxAkunLogin){
	Toko& toko = AkunSeller[idxAkunLogin].toko;
	char ans;
	pilih = 1;
    do {
		Banner();
        CetakMid("MENU SELLER", true, 70);
        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("Sewa Toko", true, 70, 1);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
        CetakMid("Profil Toko", true, 70, 2);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
        CetakMid("Kelola Barang", true, 70, 3);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
        CetakMid("Riwayat Penjualan", true, 70, 4);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
        CetakMid("Kelola Promo", true, 70, 5);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
        CetakMid("Saldo", true, 70, 6);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
        CetakMid("Kotak Pesan", true, 70, 7);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
        CetakMid("Back", true, 70, 8);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
        for(int i = 0; i < 72; i++) cout << "=";
        input = getch();
        switch (input) {
            case 72: pilih = (pilih == 1) ? 8 : pilih - 1; break;
            case 80: pilih = (pilih == 8) ? 1 : pilih + 1; break;
            case 13:{
            	switch(pilih){
					case 1:{//sewa Toko
            			do{
							Banner();
	            			CetakMid("LIST TOKO YANG BISA DI SEWA", true, 70);
        					for(int i = 0; i < 72; i++) cout << "=";
							cout << endl;
							for(int i = 0; i < 71; i++) cout << "-";
							cout << endl;
							for(int i = 1; i <= jumlahSewaToko; i++){
								CetakMid(sewaToko[i - 1].toko.namaToko, false, 20, i);
								if(i % 3 == 0){
									cout << endl;
									for(int i = 0; i < 71; i++) cout << "-";
									cout << endl;
								}
							}
							cout << endl;
							for(int i = 0; i < 70; i++) cout << "=";				
							cout << endl;
							CetakMid("|      [ BACK ]      |", true, 70, jumlahSewaToko + 1);
							for(int i = 0; i < 70; i++) cout << "=";				
							cout << endl;
							input = getch();
							switch(input){
					            case 72: pilih = (pilih == 1) ? jumlahSewaToko + 1 : pilih - 1; break;
					            case 80: pilih = (pilih == jumlahSewaToko + 1) ? 1 : pilih + 1; break;
					            case 13:
									if(pilih != jumlahSewaToko + 1){
										Banner();
										cout << "\t\t\t\t\t\tSaldo Anda: " << AkunSeller[idxAkunLogin].data.saldo << endl;
										cout << "berikut adalah detail toko " << sewaToko[pilih - 1].toko.namaToko << ":" << endl;	
										cout << "Nama Pemilik toko : " << sewaToko[pilih - 1].namaPemilik;		
										cout << "\nNo Hp " << sewaToko[pilih - 1].toko.noTelp;	
										cout << "\nAlamat toko :";
										cout << "\n   Jalan " << sewaToko[pilih - 1].toko.alamatToko.jalan;
										cout << "\n   Desa " << sewaToko[pilih - 1].toko.alamatToko.desa;
										cout << "\n   Kecamatan " << sewaToko[pilih - 1].toko.alamatToko.kecamatan;	
										cout << "\n   Kabupaten " << sewaToko[pilih - 1].toko.alamatToko.kabupaten;	
										cout << "\n   Kota " << sewaToko[pilih - 1].toko.alamatToko.kota;	
										cout << "\n   Provinsi " << sewaToko[pilih - 1].toko.alamatToko.provinsi;
										cout << "\nDetail sewa toko : " << sewaToko[pilih - 1].namaPemilik;	
										cout << "\n   Harga Rp." << sewaToko[pilih - 1].toko.hargaSewa;	
										cout << "\n   Luas Tanah " << sewaToko[pilih - 1].toko.luasTanah;	
										cout << "\n   Luas Ruangan " << sewaToko[pilih - 1].toko.luasRuangan;	
										cout << "\n   Jumlah Lantai " << sewaToko[pilih - 1].toko.jumlahLantai;		
										cout << "\nApakah anda berminat untuk menyewanya?(y/Y): ";
										cin >> ans;
										if(ans == 'y' || ans == 'Y')
										{
											if(AkunSeller[idxAkunLogin].data.saldo >= sewaToko[pilih - 1].toko.hargaSewa){
												int idPemilik = sewaToko[pilih - 1].idPemilik;
												bool sudahMinta = false;
												for(int j = 0; j < AkunMitra[idPemilik].jumlahPesan; j++){
												    if(AkunMitra[idPemilik].requestToko[j].indeksPengirim == idxAkunLogin &&
												       AkunMitra[idPemilik].requestToko[j].indeksToko == pilih - 1){
												       sudahMinta = true;
												       break;
												    }
												}
												if(sudahMinta){
												    cout << "Anda sudah pernah mengirim permintaan untuk toko ini!\n";
												} else {
												    // Buat request ke mitra
													AkunMitra[idPemilik].requestToko[AkunMitra[idPemilik].jumlahPesan].namaPengirim = AkunSeller[idxAkunLogin].data.nama;
													AkunMitra[idPemilik].requestToko[AkunMitra[idPemilik].jumlahPesan].indeksToko = pilih - 1; // index toko dari daftar sewaToko
													AkunMitra[idPemilik].requestToko[AkunMitra[idPemilik].jumlahPesan].pesan = "Saya tertarik menyewa toko anda.";
											
													AkunMitra[idPemilik].jumlahPesan++;
													
													//Potong Saldo Sementara
													AkunSeller[idxAkunLogin].data.saldo -= sewaToko[pilih - 1].toko.hargaSewa;
													cout << "Permintaan sewa telah dikirim ke pemilik toko.\nSaldo anda sementara ini di potong sebesar " 
													<< sewaToko[pilih - 1].toko.hargaSewa << endl;
													system("pause");
												}
												
											}
											else{
												cout << "Saldo anda tidak cukup.....\n";
												system("pause");
											}
										}	
									} else pilih = -1;
							}
						}while(pilih >= 0);
						pilih = 1;
						break;
					}
					case 2:{//Profile Toko
						Banner();
            			CetakMid("PROFIL TOKO", true, 70);
            			for(int i = 0; i < 72; i++) cout << "="; cout << endl;
            			if (AkunSeller[idxAkunLogin].jumlahToko == 0) {
                            cout << "\nAnda belum memiliki toko. Silakan isi data toko terlebih dahulu.\n";

                            cout << "Nama Toko       : ";
                            getline(cin >> ws, toko.namaToko);
                            cout << "Deskripsi Toko  : ";
                            getline(cin, toko.deskripsiToko);
                            cout << "Kategori Toko   : ";
                            getline(cin, toko.kategoriToko);

                            toko.jumlahBarang = 0;
                            toko.kapasitasBarang = 10;
                            toko.daftarBarang = new Barang[toko.kapasitasBarang];
                            AkunSeller[idxAkunLogin].jumlahToko += 1;

                            cout << "\nToko berhasil dibuat!\n";
                        } else {
                            cout << "Nama Toko     : " << toko.namaToko << "\n";
                            cout << "Deskripsi     : " << toko.deskripsiToko << "\n";
                            cout << "Kategori      : " << toko.kategoriToko << "\n";

                            char pilihanEdit;
                            cout << "\nIngin mengedit profil toko? (y/n): ";
                            cin >> pilihanEdit;
                            cin.ignore();

                            if (pilihanEdit == 'y' || pilihanEdit == 'Y') {
                                cout << "Edit Nama Toko     : ";
                                getline(cin, toko.namaToko);
                                cout << "Edit Deskripsi     : ";
                                getline(cin, toko.deskripsiToko);
                                cout << "Edit Kategori      : ";
                                getline(cin, toko.kategoriToko);

                                cout << "Profil toko berhasil diperbarui.\n";
                            }
                        }
						system ("pause");
                        break;
					}
					case 3:{//Kelola Barang
						Banner();
            			CetakMid("KELOLA BARANG", true, 70);
            			for(int i = 0; i < 72; i++) cout << "="; cout << endl;
            			if(AkunSeller[idxAkunLogin].jumlahToko == 0){//udah punya toko?
							cout << "\nAnda belum memiliki toko, silahkan mengisi data toko terlebih dahulu\n";//sewa dulu sono
            				system("pause");
						}else{
	            			pilih = 1;
	            			int ulang = 0;
						    do {
						        system ("cls"); Banner();
						        CetakMid("KELOLA BARANG", true, 70);
						        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
								CetakMid("Lihat Daftar Barang", true, 70, 1);
						        CetakMid("Tambah Barang", true, 70, 2);
						        CetakMid("Edit Barang", true, 70, 3);
						        CetakMid("Hapus Barang", true, 70, 4);
						        CetakMid("Back", true, 70, 5);
						        for(int i = 0; i < 72; i++) cout << "=";
						
						        input = getch();
						        switch (input) {
						            case 72: pilih = (pilih == 1) ? 5 : pilih - 1; break;
						            case 80: pilih = (pilih == 5) ? 1 : pilih + 1; break;
						            case 13:
						            	switch(pilih){
						            		case 1:{
						            			system ("cls"); Banner();
										        CetakMid("Lihat Daftar Barang", true, 70);
										        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
								            	if (toko.jumlahBarang == 0) {
											        cout << "Belum ada barang di toko.\n";
											        system ("pause"); continue;
											    }
											    for (int i = 0; i < toko.jumlahBarang - 1; i++) {
											        for (int j = i + 1; j < toko.jumlahBarang; j++) {
											            if (toko.daftarBarang[i].kategori > toko.daftarBarang[j].kategori || (toko.daftarBarang[i].kategori == toko.daftarBarang[j].kategori && toko.daftarBarang[i].nama > toko.daftarBarang[j].nama)) {
											                Barang temp = toko.daftarBarang[i];
												            toko.daftarBarang[i] = toko.daftarBarang[j];
												            toko.daftarBarang[j] = temp;
											            }
											        }
											    }
											    string currentKategori = "";
											    for (int i = 0; i < toko.jumlahBarang; i++) {
											        if (toko.daftarBarang[i].kategori != currentKategori) {
											            currentKategori = toko.daftarBarang[i].kategori;
											            cout << "\n================================= " << currentKategori << " =================================\n";
											        }
											        cout << " | Nama Barang : " << toko.daftarBarang[i].nama << "\n"
											             << " | Harga       : Rp." << toko.daftarBarang[i].harga << "\n"
											             << " | Stok        : " << toko.daftarBarang[i].stok << "\n"
											             << " | Deskripsi   : " << toko.daftarBarang[i].deskripsi << "\n";
											        cout << "---------------------------------------------------------------------------------------------------------\n";
											    } system("pause");
												break;
											}
						            		case 2:{
						            			cin.ignore();
						            			system ("cls"); Banner();
										        CetakMid("Tambah Barang", true, 70);
										        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
								            	if (toko.jumlahBarang >= toko.kapasitasBarang) {
											        int kapasitasBaru = toko.kapasitasBarang + 10;
											        Barang* temp = new Barang[kapasitasBaru];
											        for (int i = 0; i < toko.jumlahBarang; i++) {
											            temp[i] = toko.daftarBarang[i];
											        }
											        delete[] toko.daftarBarang;
											        toko.daftarBarang = temp;
											        toko.kapasitasBarang = kapasitasBaru;
											    }
											    Barang baru;
											    cout << "Nama barang: "; getline(cin, baru.nama);
											    cout << "Kategori: "; getline(cin, baru.kategori);
											    cout << "Deskripsi: "; getline(cin, baru.deskripsi);
											    cout << "Harga: "; cin >> baru.harga;
											    cout << "Stok: "; cin >> baru.stok;
											
											    BarangSeller[jumlahBarang].namaBarang = baru.nama;
											    BarangSeller[jumlahBarang].kategori = baru.kategori;
											    BarangSeller[jumlahBarang].deskripsi = baru.deskripsi;
											    BarangSeller[jumlahBarang].harga = baru.harga;
											    BarangSeller[jumlahBarang].stok = baru.stok;
											    BarangSeller[jumlahBarang].tokoAsal = AkunSeller[idxAkunLogin].toko.namaToko;
											    BarangSeller[jumlahBarang].indeksAkunSeller = idxAkunLogin;
											    jumlahBarang++;
											    
											    toko.daftarBarang[toko.jumlahBarang++] = baru;
											    cout << "Barang berhasil ditambahkan.\n";
											    system("pause");
												break;
											}
						            		case 3:{
						            			system ("cls"); Banner();
										        CetakMid("Edit Barang", true, 70);
										        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
										        if (toko.jumlahBarang == 0) {
											        cout << "Tidak ada barang untuk di edit.\n";
											        system ("pause"); continue;
											    }
												if (toko.jumlahBarang == 0) {
											        cout << "Tidak ada barang untuk diedit.\n";
											        continue;
											    }
											
											    for (int i = 0; i < toko.jumlahBarang; i++) {
											        cout << i + 1 << ". " << toko.daftarBarang[i].nama << "\n";
											    } for(int i = 0; i < 72; i++) cout << "=";
											    int idx;
											    cout << "Pilih nomor barang yang ingin diedit: ";
											    cin >> idx;
											    if (idx < 1 || idx > toko.jumlahBarang) {
											        cout << "Pilihan tidak valid.\n";
											        continue;
											    } idx--;
											    cout << "Edit nama (" << toko.daftarBarang[idx].nama << "): ";
											    cin.ignore();
											    getline(cin, toko.daftarBarang[idx].nama);
											    cout << "Edit kategori (" << toko.daftarBarang[idx].kategori << "): ";
											    getline(cin, toko.daftarBarang[idx].kategori);
											    cout << "Edit deskripsi (" << toko.daftarBarang[idx].deskripsi << "): ";
											    cin.ignore();
												getline(cin, toko.daftarBarang[idx].deskripsi);
											    cout << "Edit harga (" << toko.daftarBarang[idx].harga << "): ";
											    cin >> toko.daftarBarang[idx].harga;
											    cout << "Edit stok (" << toko.daftarBarang[idx].stok << "): ";
											    cin >> toko.daftarBarang[idx].stok;
											
											    cout << "Barang berhasil diedit.\n";
											    system("pause");
												break;
											}
											case 4:{
												system ("cls"); Banner();
										        CetakMid("Hapus Barang", true, 70);
										        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
								            	if (toko.jumlahBarang == 0) {
											        cout << "Tidak ada barang untuk dihapus.\n";
											        system ("pause"); continue;
											    }
											
											    for (int i = 0; i < toko.jumlahBarang; i++) {
											        cout << i + 1 << ". " << toko.daftarBarang[i].nama << "\n";
											    }
												int idx;
											    cout << "Pilih nomor barang yang ingin dihapus: ";
											    cin >> idx;
											    if (idx < 1 || idx > toko.jumlahBarang) {
											        cout << "Pilihan tidak valid.\n";
											        continue;
											    }
											    idx--;
											    for (int i = idx; i < toko.jumlahBarang - 1; i++) {
											        toko.daftarBarang[i] = toko.daftarBarang[i + 1];
											    }
											    toko.jumlahBarang--;
											    cout << "Barang berhasil dihapus.\n";
											    system("pause");
												break;
											}
						            		case 5:
						            			ulang = 1; break;
										} 
						        } if (ulang == 1) break; 
						    } while (true);
						    break;
						}
						break;
					}
					case 4:{//Riwayat Penjualan
						system ("cls"); Banner();
					    CetakMid("RIWAYAT PENJUALAN", true, 70);
					    for(int i = 0; i < 72; i++) cout << "="; cout << endl;
            			string tokoSaya = AkunSeller[idxAkunLogin].toko.namaToko;
					    bool ada = false;
					    for (int i = 0; i < jumlahMember; i++) {
					        for (int j = 0; j < AkunSeller[idxAkunLogin].totalRiwayat; j++) {
					            if (AkunMember[i].BarangMember[j].namaTokoAsal == tokoSaya) {
					                ada = true;
					                cout << "Pembeli: " << AkunSeller[idxAkunLogin].RiwayatMember[j].namaTokoAsal
					                     << " | Barang: " << AkunSeller[idxAkunLogin].RiwayatMember[j].namaBarang
					                     << " | Jumlah: " << AkunSeller[idxAkunLogin].RiwayatMember[j].jumlah
					                     << " | Total: Rp." << AkunSeller[idxAkunLogin].RiwayatMember[j].harga
					                     << endl;
					            }
					        }
					    }
					    if (!ada) cout << "Belum ada barang Anda yang dibeli.\n";
					    system("pause");
						break;
					}
					case 5:{//Kelola Promo
						pilih = 1;
            			int ulang = 0;
					    do {
					        system("cls");
					        Banner();
					        CetakMid("KELOLA PROMO", true, 70);
					        for (int i = 0; i < 72; i++) cout << "="; cout << endl;
							CetakMid("Lihat Promo", true, 70, 1);
							CetakMid("Tambah Promo", true, 70, 2);
							CetakMid("Hapus Promo", true, 70, 3);
							CetakMid("Back", true, 70, 4);
					        for (int i = 0; i < 72; i++) cout << "="; cout << endl;
					
					        input = getch();
					        switch (input) {
					            case 72: pilih = (pilih == 1) ? 4 : pilih - 1; break;
					            case 80: pilih = (pilih == 4) ? 1 : pilih + 1; break;
					            case 13:
					            	switch(pilih){
					            		case 1:{
							                Banner();
							                CetakMid("PROMO SAYA", true, 70);
							                for (int i = 0; i < 72; i++) cout << "="; cout << endl;
							
							                bool ada = false;
							                for (int i = 0; i < jumlahPromo; i++) {
							                    if (daftarPromo[i].aktif) {
							                        for (int j = 0; j < AkunSeller[idxAkunLogin].toko.jumlahBarang; j++) {
							                            if (daftarPromo[i].namaBarang == AkunSeller[idxAkunLogin].toko.daftarBarang[j].nama) {
							                                cout << "- " << daftarPromo[i].namaBarang
							                                     << " | Potongan: " << daftarPromo[i].potongan << "%\n";
							                                ada = true;
							                            }
							                        }
							                    }
							                }
							                if (!ada) cout << "Tidak ada promo aktif.\n";
							                system("pause");
											break;
										}
					            		case 2:{
					            			string namaBarang;
							                int potongan;
							                bool ditemukan = false;
							                Banner();
							                CetakMid("TAMBAH PROMO", true, 70);
							                for (int i = 0; i < 72; i++) cout << "="; cout << endl;
							                cout << "Masukkan nama barang Anda: ";
							                getline(cin, namaBarang);
							                cout << "Potongan (%): ";
							                cin >> potongan;
							
							                for (int i = 0; i < AkunSeller[idxAkunLogin].toko.jumlahBarang; i++) {
							                    if (AkunSeller[idxAkunLogin].toko.daftarBarang[i].nama == namaBarang) {
							                        // Cek apakah promo sudah ada
							                        bool duplikat = false;
							                        for (int j = 0; j < jumlahPromo; j++) {
							                            if (daftarPromo[j].namaBarang == namaBarang && daftarPromo[j].aktif) {
							                                cout << "Promo sudah ada untuk barang tersebut.\n";
							                                duplikat = true;
							                                break;
							                            }
							                        }
							                        if (duplikat) break;
							
							                        daftarPromo[jumlahPromo].namaBarang = namaBarang;
							                        daftarPromo[jumlahPromo].potongan = potongan;
							                        daftarPromo[jumlahPromo].aktif = true;
							                        jumlahPromo++;
							
							                        cout << "Promo berhasil ditambahkan!\n";
							                        ditemukan = true;
							                        break;
							                    }
							                }
							                if (!ditemukan) {
							                    cout << "Barang tidak ditemukan di toko Anda.\n";
							                }
							                system("pause");
											break;
										}
					            		case 3:{
					            			string namaBarang;
							                bool ditemukan = false;
							                
							                Banner();
							                CetakMid("HAPUS PROMO", true, 70);
							                for (int i = 0; i < 72; i++) cout << "="; cout << endl;
							
							                cin.ignore();
							                cout << "Masukkan nama barang yang ingin dihapus promonya: ";
							                getline(cin, namaBarang);
							
							                for (int i = 0; i < jumlahPromo; i++) {
							                    if (daftarPromo[i].namaBarang == namaBarang && daftarPromo[i].aktif) {
							                        for (int j = 0; j < AkunSeller[idxAkunLogin].toko.jumlahBarang; j++) {
							                            if (AkunSeller[idxAkunLogin].toko.daftarBarang[j].nama == namaBarang) {
							                                daftarPromo[i].aktif = false;
							                                cout << "Promo berhasil dihapus.\n";
							                                ditemukan = true;
							                                break;
							                            }
							                        }
							                    }
							                    if (ditemukan) break;
							                }
							                if (!ditemukan) cout << "Promo tidak ditemukan atau bukan barang Anda.\n";
							                system("pause");
											break;
										}
					            		case 4:
					            			ulang = 1; break;
									} 
					        } if (ulang == 1) break;
					    } while (true);
					    break;
					}
					case 6:{//Saldo
						Banner();
						CetakMid("SALDO " + AkunMitra[AkunYangMasuk].data.nama, true, 70);
						for(int i = 0; i < 72; i++) cout << "="; cout << endl;
						cout << "Saldo Anda: Rp." << AkunSeller[idxAkunLogin].data.saldo << endl;
						cout << "Ingin menambah saldo? (y): ";
                        char jawab;
                        cin >> jawab;
                        if (jawab == 'y' || jawab == 'Y') {
                            int nominal;
                            cout << "Masukkan nominal yang ingin ditambahkan: ";
                            cin >> nominal;
                            AkunSeller[AkunYangMasuk].data.saldo += nominal;
                            cout << "Saldo berhasil ditambahkan!" << endl;
                            system("pause");
                        } 
                        break;
					}
					case 7:{//Kotak Pesan
						Banner();
						if(AkunSeller[idxAkunLogin].jumlahPesan == 0){
							cout << "Anda belum memiliki Pesan Masuk....\n";
						}
						else{
							for(int i = 0; i < AkunSeller[idxAkunLogin].jumlahPesan; i++){
								cout << AkunSeller[idxAkunLogin].pesan;
								
							}
						}
						system("pause");
						break;
					}
					case 8:{//Back
						cin.ignore();
						pilih = 1;
						return;
					}
				}
        	}
		}
	}while(true);
}
void MenuMitra(){
	pilih = 1;
	do{
		Banner();
		CetakMid("Halo " + AkunMitra[AkunYangMasuk].data.nama, true, 70);
	    for(int i = 0; i < 72; i++) cout << "="; cout << endl;
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("Tambah Ruko", true, 70, 1);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
	    CetakMid("Edit Toko", true, 70, 2);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
	    CetakMid("Saldo", true, 70, 3);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
	    CetakMid("Profile", true, 70, 4);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
	    CetakMid("Kotak Pesan", true, 70, 5);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
	    CetakMid("Log Out", true, 70, 6);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
	    for(int i = 0; i < 72; i++) cout << "=";
	    input = getch();
	    switch(input){
		    case 72: pilih = (pilih == 1) ? 6 : pilih - 1; break; // Up
	        case 80: pilih = (pilih == 6) ? 1 : pilih + 1; break; // Down
	        case 13:
	        	switch(pilih){
			       	case 1:{//tambah toko
						Banner();
						int indeksToko = AkunMitra[AkunYangMasuk].jumlahTokoMitra;
						CetakMid("TAMBAH RUKO " + AkunMitra[AkunYangMasuk].data.nama, true, 70);
						for(int i = 0; i < 72; i++) cout << "="; cout << endl;
						cout << "Masukkan Nama Ruko: ";
						if(cin.peek() == '\n') cin.ignore();	 getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].namaToko);
						cout << "Masukkan jalan : ";	getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.jalan);
						cout << "  Masukkan desa: "; getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.desa);
						cout << "  Masukkan Kecamatan: ";	getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.kecamatan);
						cout << "  Masukkan Kabupaten: ";	getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.kabupaten);
						cout << "  Masukkan Kota : ";	getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.kota);
						cout << "  Masukkan Provinsi: ";	getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.provinsi);
						cout << "Masukkan Nomor Ruko : ";	cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.nomor;
						cout << "Masukkan No Telepon : ";	cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].noTelp;
						cout << "Masukkan Luas Tanah (m2): ";	cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].luasTanah;
						cout << "Masukkan Luas Ruangan (m2): ";	cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].luasRuangan;
						cout << "Masukkan Harga Sewa (per tahun): Rp.";	cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].hargaSewa;
						cout << "Masukkan Jumlah Lantai: ";	cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].jumlahLantai;
						
						//Menambahkan Toko Ke daftar toko yang bisa di Sewa
						sewaToko[jumlahSewaToko].toko.namaToko = AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].namaToko;
						sewaToko[jumlahSewaToko].namaPemilik = AkunMitra[AkunYangMasuk].data.nama;
							//alamat
						sewaToko[jumlahSewaToko].toko.alamatToko.jalan = AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.jalan;
						sewaToko[jumlahSewaToko].toko.alamatToko.desa = AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.desa;
						sewaToko[jumlahSewaToko].toko.alamatToko.kecamatan = AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.kecamatan;
						sewaToko[jumlahSewaToko].toko.alamatToko.kabupaten = AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.kabupaten;
						sewaToko[jumlahSewaToko].toko.alamatToko.kota = AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.kota;
						sewaToko[jumlahSewaToko].toko.alamatToko.provinsi = AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.provinsi;
							//detail Toko
						sewaToko[jumlahSewaToko].toko.alamatToko.nomor = AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].alamatToko.nomor;
						sewaToko[jumlahSewaToko].toko.noTelp = AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].noTelp;
						sewaToko[jumlahSewaToko].toko.luasTanah = AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].luasTanah;
						sewaToko[jumlahSewaToko].toko.luasRuangan = AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].luasRuangan;
						sewaToko[jumlahSewaToko].toko.hargaSewa = AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].hargaSewa;
						sewaToko[jumlahSewaToko].toko.jumlahLantai = AkunMitra[AkunYangMasuk].TokoMitra[indeksToko].jumlahLantai;
						sewaToko[jumlahSewaToko].indeksToko = jumlahSewaToko;//indeks di semua toko, guna untuk di ambil mitra yang punya toko
						AkunMitra[AkunYangMasuk].indeksToko[AkunMitra[AkunYangMasuk].jumlahTokoMitra]++;
						AkunMitra[AkunYangMasuk].jumlahTokoMitra++;
						jumlahSewaToko++;
						
						cout << "Toko berhasil ditambahkan!\n";
						system("pause");
						break;
					   }
			    	case 2:{//Edit toko
						Banner();
						CetakMid("DAFTAR TOKO " + AkunMitra[AkunYangMasuk].data.nama, true, 70);
						for(int i = 0; i < 72; i++) cout << "="; cout << endl;
						if(AkunMitra[AkunYangMasuk].jumlahTokoMitra == 0) {
							cout << "Anda belum mendaftarkan toko...\n";
							system("pause");
							continue;
						}
						for (int i = 0; i < AkunMitra[AkunYangMasuk].jumlahTokoMitra; i++) {
							cout << i + 1 << ". " << AkunMitra[AkunYangMasuk].TokoMitra[i].namaToko << endl;
							cout << "   Alamat:\n";
							cout << "   	Jalan " << AkunMitra[AkunYangMasuk].TokoMitra[i].alamatToko.jalan << endl;
							cout << "   	Desa " << AkunMitra[AkunYangMasuk].TokoMitra[i].alamatToko.desa << endl;
							cout << "   	Kecamatan " << AkunMitra[AkunYangMasuk].TokoMitra[i].alamatToko.kecamatan << endl;
							cout << "   	Kabupaten "<< AkunMitra[AkunYangMasuk].TokoMitra[i].alamatToko.kabupaten << endl;
							cout << "   	Kota " << AkunMitra[AkunYangMasuk].TokoMitra[i].alamatToko.kota << endl;
							cout << "   	Provinsi "<< AkunMitra[AkunYangMasuk].TokoMitra[i].alamatToko.provinsi << endl;
							cout << "   Detail Toko:\n";
							cout << "   	No Telepon: " << AkunMitra[AkunYangMasuk].TokoMitra[i].noTelp << endl;
							cout << "   	Luas Tanah: " << AkunMitra[AkunYangMasuk].TokoMitra[i].luasTanah << " m2" << endl;
							cout << "   	Luas Ruangan: " << AkunMitra[AkunYangMasuk].TokoMitra[i].luasRuangan << " m2" << endl;
							cout << "   	Harga Sewa: Rp." << AkunMitra[AkunYangMasuk].TokoMitra[i].hargaSewa << endl;
							cout << "   	Jumlah Lantai: " << AkunMitra[AkunYangMasuk].TokoMitra[i].jumlahLantai << endl;
							for(int i = 0; i < 72; i++) cout << "="; cout << endl;
						}
						cout << "Apakah anda ingin mengedit informasi toko(y/Y)?: ";
						char jawab;
						cin >> jawab;
						if(jawab == 'y' || jawab == 'Y') {
							int nomorToko;
							
							cout << "Pilih nomor toko yang ingin anda edit: ";
							cin >> nomorToko;
							if(nomorToko > 0 && nomorToko <= AkunMitra[AkunYangMasuk].jumlahTokoMitra) {
								int indeks = nomorToko - 1;
									cout << "Anda akan mengedit toko : " << AkunMitra[AkunYangMasuk].TokoMitra[indeks].namaToko << endl;
									cout << "1. Nama Toko\n2. Alamat Toko\n3. Detail Toko";
									do{
										cout << "\npilih Menu Edit (0 untuk batal): ";
										cin >> pilih;
										if(pilih < 0 || pilih > 3){
											cout << "Input salah....\n";
											system("pause");
										}
									}while(pilih < 0 || pilih > 3);
									cin.ignore();
									switch(pilih){
										case 1: 
											cout << "Masukkan Nama Toko Baru: "; getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeks].namaToko); 
											break;
										case 2:{//Alamat Toko
											cout << "1. Jalan \n2. Desa \n3. Kecamatan\n4. Kabupaten\n5. Kota\n6. Provinsi";
											do{
												cout << "\npilih Menu Edit (0 untuk batal): ";
												cin >> pilih; cin.ignore();
												if(pilih < 0 || pilih > 6){
													cout << "Input salah....\n";
													system("pause");
												}
											}while(pilih < 0 || pilih > 6);
											switch(pilih){
												case 1:
													cout << "Masukkan Jalan Baru: "; getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeks].alamatToko.jalan);
													break;
												case 2:
													cout << "Masukkan Desa Baru: "; getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeks].alamatToko.desa); 
													break;
												case 3:
													cout << "Masukkan Kecamatan Baru: "; getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeks].alamatToko.kecamatan); 
													break;
												case 4:
													cout << "Masukkan Kabupaten Baru: "; getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeks].alamatToko.kabupaten); 
													break;
												case 5:
													cout << "Masukkan Kota Baru: "; getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeks].alamatToko.kota); 
													break;
												case 6:
													cout << "Masukkan Provinsi Baru: "; getline(cin, AkunMitra[AkunYangMasuk].TokoMitra[indeks].alamatToko.provinsi); 
													break;
											}break;
										}
										case 3:{//Detail Toko
											cout << "1. No Hp \n2. Luas Tanah (m2)\n3. Luas Ruangan (m2)\n4. Harga Sewa\n5. Jumlah Lantai";
											do{
												cout << "\npilih Menu Edit (0 untuk batal): ";
												cin >> pilih;
												if(pilih < 0 || pilih > 5){
													cout << "Input salah....\n";
													system("pause");
												}
											}while(pilih < 0 || pilih > 5);
											switch(pilih){
												case 1:
													cout << "Masukkan No Telepon Baru: "; cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeks].noTelp; 
													break;
												case 2:
													cout << "Masukkan Luas Tanah Baru (m2): "; cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeks].luasTanah;
													break;
												case 3:
													cout << "Masukkan Luas Ruangan Baru (m2): "; cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeks].luasRuangan;
													break;
												case 4:
													cout << "Masukkan Harga Sewa Baru (per tahun): Rp."; cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeks].hargaSewa;
													break;
												case 5:
													cout << "Masukkan Jumlah Lantai Baru: "; cin >> AkunMitra[AkunYangMasuk].TokoMitra[indeks].jumlahLantai;
											}break;
										}	
									cin.ignore();
									} 
							}
						} 
						else	cout << "Batal mengedit informasi toko.\n";
					
					cin.ignore();
					system("pause");
					break;
					}
			    	case 3:{//Saldo
						Banner();
						CetakMid("SALDO " + AkunMitra[AkunYangMasuk].data.nama, true, 70);
						for(int i = 0; i < 72; i++) cout << "="; cout << endl;
						cout << "Saldo Anda: Rp." << AkunMitra[AkunYangMasuk].data.saldo << endl;
						system("pause");
						break;
					}
			    	case 4:{//Profile
			    		Banner();
						CetakMid("PROFILE " + AkunMitra[AkunYangMasuk].data.nama, true, 70);
						for(int i = 0; i < 72; i++) cout << "=";
						cout << "\n Nama: " << AkunMitra[AkunYangMasuk].data.nama;
						cout << "\n Username: " << AkunMitra[AkunYangMasuk].data.username;
						cout << "\n Password: " << AkunMitra[AkunYangMasuk].data.password;
						cout << "\nKetik 1-3 untuk mengubah data(0 untuk kembali): "; cin >> pilih;
			    		cin.ignore();
						switch(pilih) {
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
								pilih = 1;
								break;
							default:
								cout << "Pilihan tidak valid!" << endl;
						}
						pilih = 1;
						system("pause");
						break;
					}
			    	case 5:{//Kotak Pesan
						Banner();
						if(AkunMitra[AkunYangMasuk].jumlahPesan == 0){
							cout << "Anda belum memiliki Pesan Masuk....\n";
							system("pause");
						}
						else{
							CetakMid("Hallo " + AkunMitra[AkunYangMasuk].data.nama, true);
							for(int i = 0; i < AkunMitra[AkunYangMasuk].jumlahPesan; i++){
								cout << i + 1 << ". ";
								cout << AkunMitra[AkunYangMasuk].requestToko[i].namaPengirim << " ingin menyewa toko "
								     << sewaToko[AkunMitra[AkunYangMasuk].requestToko[i].indeksToko].toko.namaToko << endl;
								cout << "Apakah anda ingin menerima sewa ini? (y/n): ";
								char jawab;
								cin >> jawab;
								int idxToko = AkunMitra[AkunYangMasuk].requestToko[i].indeksToko;
							    int idxSeller = AkunMitra[AkunYangMasuk].requestToko[i].indeksPengirim;
							    int harga = sewaToko[idxToko].toko.hargaSewa;
								if(jawab == 'y' || jawab == 'Y'){
									AkunSeller[idxSeller].pesan[AkunSeller[idxSeller].jumlahPesan] = "Permintaan disetujui";
									AkunSeller[idxSeller].jumlahToko++;
									AkunSeller[idxSeller].jumlahPesan++;
									cout << "harga " << harga << endl;
								    // Tambahkan saldo ke mitra (uang hasil sewa masuk)
								    AkunMitra[AkunYangMasuk].data.saldo += harga;			
								    cout << "Permintaan disetujui. Saldo anda sekarang: Rp" << AkunMitra[AkunYangMasuk].data.saldo << endl;
								    //hapus dari list sewa
								    for(int i = idxToko; i < jumlahSewaToko; i++){
								    	sewaToko[i].toko.namaToko = sewaToko[i + 1].toko.namaToko;
										sewaToko[i].namaPemilik = sewaToko[i + 1].namaPemilik ;
										sewaToko[i].toko.alamatToko.jalan = sewaToko[i + 1].toko.alamatToko.jalan;
										sewaToko[i].toko.alamatToko.desa = sewaToko[i + 1].toko.alamatToko.desa;
										sewaToko[i].toko.alamatToko.kecamatan = sewaToko[i + 1].toko.alamatToko.kecamatan;
										sewaToko[i].toko.alamatToko.kabupaten = sewaToko[i + 1].toko.alamatToko.kabupaten;
										sewaToko[i].toko.alamatToko.kota = sewaToko[i + 1].toko.alamatToko.kota;
										sewaToko[i].toko.alamatToko.provinsi = sewaToko[i + 1].toko.alamatToko.provinsi;
										sewaToko[i].toko.hargaSewa = sewaToko[i + 1].toko.hargaSewa;
										sewaToko[i].toko.jumlahLantai = sewaToko[i + 1].toko.jumlahLantai;
										sewaToko[i].toko.luasRuangan = sewaToko[i + 1].toko.luasRuangan;
										sewaToko[i].toko.luasTanah = sewaToko[i + 1].toko.luasTanah;
										sewaToko[i].toko.noTelp = sewaToko[i + 1].toko.noTelp;
									}
								    jumlahSewaToko--;
								}
								else{
									AkunSeller[idxSeller].pesan[AkunSeller[idxSeller].jumlahPesan] = "Permintaan Ditolak";
									AkunSeller[idxSeller].jumlahToko++;
									AkunSeller[idxSeller].jumlahPesan++;
								    AkunSeller[idxSeller].data.saldo += harga;//Kembalikan Saldo
								
								    cout << "Permintaan ditolak. Uang telah dikembalikan ke seller." << endl;
								}
								AkunMitra[AkunYangMasuk].jumlahPesan--;
							}
							system("pause");
						}
						break;
					}
					case 6:{//Log Out
						pilih = 1;
						cin.ignore();
			    		return;
					}
				}
				pilih = 1;
		}
	}while(true);
}

//UNTUK PROSES SIGN AWAL
void SignIn(int jenis){//1 member, 2 seller, 3 mitra
	string username, password;
	bool valid = false;
	switch(jenis){
		case 1:{//Member
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
					MenuMember(AkunYangMasuk); 
					return;
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
			return;
		}
		case 2:{//Seller
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
			            } 
						break; 
			        }
			    }
			    if (loginBerhasil) {
			        cout << "\033[34mLogin sebagai seller berhasil!\033[0m\n";
			        system("pause");
			        MenuSeller(AkunYangMasuk);
					return; 
			    } else if (usernameDitemukan) {
			        cout << "\033[31mPassword salah!\033[0m\n";
			    } else {
			        cout << "\033[31mUsername tidak ditemukan!\033[0m\n";
			    }
			    cout << "Ingin coba lagi? (y): ";
		        char jawab;
		        cin >> jawab;
		        cin.ignore(); // buang enter
		        if (jawab == 'y' || jawab == 'Y') valid = false;
		        else {
		        	system("pause");
					return; // keluar dari fungsi SignIn
				}
			} while (!valid);
			return;
		}
		case 3:{//mitra
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
					return;
			    } else if (usernameDitemukan) cout << "\033[31mPassword salah!\033[0m\n";
			    else cout << "\033[31mUsername tidak ditemukan!\033[0m\n";
			    cout << "Ingin coba lagi? (y/n): ";
		        char jawab;
		        cin >> jawab;
		        cin.ignore();
		        if (jawab == 'y' || jawab == 'Y') valid = false;
		        else {
		        	system("pause");
					return; // keluar dari fungsi SignIn
				}
			} while (!valid);
			return;
		}
	}
}
void SignUp(int jenis) {//1 member, 2 seller, 3 mitra 
    Banner();
    string nama, username, password, hp, email;
    bool valid = false;
    switch(jenis){
    	case 1:{
			CetakMid("SIGN UP MEMBER", true, 70);
	        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
	        cout << "Masukkan Nama: ";
	        if(cin.peek() == '\n') cin.ignore();
	        getline(cin, nama);
	        do {
			    valid = true;
			    cout << "Masukkan Username: ";
			    getline(cin, username);
				for (int i = 0; i < jumlahMember; i++) {
			        if (AkunMember[i].data.username == username){
			        	cout << "Username sudah digunakan!\n";
				        cout << "Ingin coba lagi(y)?: ";
				        char jawab;
				        cin >> jawab;
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
	        break;
		}
	    case 2:{
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
	        break;
		}
	    case 3:{
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
		}
	}
	cout << "Akun berhasil di buat...\n";
	system("pause");
}
void MenuSign(bool signin) {// kalok true dia signin, kalok false dia signup
    pilih = 1;
    do {
        Banner();
        CetakMid((signin == true)? "SIGN IN" : "SIGN UP", true, 70);
        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
        CetakMid("Member", true, 70, 1);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
        CetakMid("Seller", true, 70, 2);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
        CetakMid("Mitra", true, 70, 3);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
        CetakMid("Back", true, 70, 4);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
        for(int i = 0; i < 72; i++) cout << "=";

        input = getch();
        switch(input) {
            case 72: pilih = (pilih == 1) ? 4 : pilih - 1; break; // Up
            case 80: pilih = (pilih == 4) ? 1 : pilih + 1; break; // Down
            case 13:
            	switch(pilih){
            		case 1:
            			(signin == true)? SignIn(1): SignUp(1);
            			return;
            		case 2:
            			(signin == true)? SignIn(2): SignUp(2);
            			return;
            		case 3:
            			(signin == true)? SignIn(3): SignUp(3);
            			return;
            		case 4:
            			pilih = 1;
            			return;
				}
        }
    } while (true);
}
void MainMenu() {
    pilih = 1;
    do {
        Banner();
        CetakMid("WELCOME TO MARKETPLACE", true, 70);
        for(int i = 0; i < 72; i++) cout << "="; cout << endl;
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("Sign In", true, 70, 1);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
        CetakMid("Sign Up", true, 70, 2);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
        CetakMid("Exit", true, 70, 3);
		CetakMid("~~~~~~~~~~~~~~~~~~~~~~", true);
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

int main(){
	//Inisialisasi awal
	AkunMember[0].data.nama = "member1";
	AkunMember[0].data.password = "member1";
	AkunMember[0].data.username = "member1";
	AkunMember[0].data.saldo = 50000000;
	
	AkunSeller[0].data.nama = "seller1";
	AkunSeller[0].data.password = "seller1";
	AkunSeller[0].data.username = "seller1";
	AkunSeller[0].data.saldo = 50000000;
	
	AkunMitra[0].data.nama = "mitra1";
	AkunMitra[0].data.password = "mitra1";
	AkunMitra[0].data.username = "mitra1";
	AkunMitra[0].data.saldo = 50000000;
	
	sewaToko[0].toko.namaToko = "Gasos";
	sewaToko[0].namaPemilik = "Sagos";
	sewaToko[0].toko.alamatToko.jalan = "Agatis";
	sewaToko[0].toko.alamatToko.desa = "Srimulyo";
	sewaToko[0].toko.alamatToko.kecamatan = "Sekolaq Darat";
	sewaToko[0].toko.alamatToko.kabupaten = "Kutai Barat";
	sewaToko[0].toko.alamatToko.kota = "Sendawar";
	sewaToko[0].toko.alamatToko.provinsi = "Kalimantan Timur";
	sewaToko[0].toko.hargaSewa = 10000000;
	sewaToko[0].toko.jumlahLantai = 1;
	sewaToko[0].toko.luasRuangan = 15;
	sewaToko[0].toko.luasTanah = 30;
	sewaToko[0].toko.noTelp = "085215568459";
	
    BarangSeller[jumlahBarang].namaBarang = "Sabun Shinzui";
    BarangSeller[jumlahBarang].kategori = "Sabun";
    BarangSeller[jumlahBarang].deskripsi = "Sabun Kece";
    BarangSeller[jumlahBarang].harga = 5000;
    BarangSeller[jumlahBarang].stok = 5;
    BarangSeller[jumlahBarang].tokoAsal = "Gasos";
	jumlahBarang++;
	BarangSeller[jumlahBarang].namaBarang = "Sabun Citra";
    BarangSeller[jumlahBarang].kategori = "Sabun";
    BarangSeller[jumlahBarang].deskripsi = "Sabun Kece";
    BarangSeller[jumlahBarang].harga = 5000;
    BarangSeller[jumlahBarang].stok = 5;
    BarangSeller[jumlahBarang].tokoAsal = "Gasos";
	jumlahBarang++;
	BarangSeller[jumlahBarang].namaBarang = "Sabun Lifeboy";
    BarangSeller[jumlahBarang].kategori = "Sabun";
    BarangSeller[jumlahBarang].deskripsi = "Sabun Kece";
    BarangSeller[jumlahBarang].harga = 5000;
    BarangSeller[jumlahBarang].stok = 5;
    BarangSeller[jumlahBarang].tokoAsal = "Gasos";
	jumlahBarang++;
	BarangSeller[jumlahBarang].namaBarang = "Sabun Baygon";
    BarangSeller[jumlahBarang].kategori = "Sabun";
    BarangSeller[jumlahBarang].deskripsi = "Sabun Kece";
    BarangSeller[jumlahBarang].harga = 5000;
    BarangSeller[jumlahBarang].stok = 5;
    BarangSeller[jumlahBarang].tokoAsal = "Gasos";
	jumlahBarang++;
	BarangSeller[jumlahBarang].namaBarang = "Sabun Zio";
    BarangSeller[jumlahBarang].kategori = "Sabun";
    BarangSeller[jumlahBarang].deskripsi = "Sabun Kece";
    BarangSeller[jumlahBarang].harga = 5000;
    BarangSeller[jumlahBarang].stok = 5;
    BarangSeller[jumlahBarang].tokoAsal = "Gasos";
	jumlahBarang++;
    MainMenu();
    
    return 0;
}
