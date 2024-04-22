// NAYLA ZEANLITA PUTRI NUR'AIN
// 2309106052 B1'23
// POSTEST 6 APL
// PROGRAM DATA GAJI KARYAWAN DALAM 1 MINGGU

#include <iostream>
#include <map>

using namespace std;
map <string, string> AkunKaryawan;

// NESTED STRUCT
struct Posisi{
    string Posisi;
    int SisaKontrakbulan;
};
struct Daftar{
    string Nama;
    // NESTED STRUCT
    Posisi Pos;
};
Daftar Karyawan[10][2]{
    {"Octavia", {"Kasir", 6}},
    {"Jasmine", {"Kasir", 8}},
    {"Imro", {"Marketing", 24}},
    {"Ridwan", {"Marketing", 12}},
    {"Rini", {"Manajer Toko", 12}},
    {"Elly", {"Cleaning Service", 3}},
    {"Rio", {"Staff Gudang", 6}},
    {"Randy", {"Staff Gudang", 6}},
    {"Dani", {"Penata Barang", 3}},
    {"Aldi", {"Penata Barang", 4}}
};

// ARRAY OF STRUCT
struct Gaji{
        string Nama;
        int Jamkerja;
        int GajiPerjam;
    };

Gaji DataGaji[10] = {
    {"Octavia", 40, 17000},
    {"Jasmine", 40, 17000},
    {"Imro", 40, 19000},
    {"Ridwan", 40, 19000},
    {"Rini", 40, 28000},
    {"Elly", 40, 10000},
    {"Rio", 40, 16000},
    {"Randy", 40, 16000},
    {"Dani", 40, 15000},
    {"Aldi", 40, 15000}
    };

// PENGGUNAAN DEFERENCE OPERATOR
Gaji *ptr = DataGaji;

// FUNGSI CONTINUE
string Continue(){
    string Jawab;
    string result;
    while (true){
        cout<<"Ingin melanjutkan program (y/n)? ";
        cin>>Jawab;
        // ERROR HANDLING
        if (cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"Cukup jawab y/n saja."<<endl;
            continue;
        } else if (Jawab == "Y" || Jawab == "y"){
            result = "y";
            break;
        } else if (Jawab == "N" || Jawab == "n"){
            result = "n";
            break;
        // ERROR HANDLING
        } else {
            cout<<"Cukup jawab y/n saja."<<endl;
        }
    }
    return result;
}

// FUNGSI LOGIN
map <string, string> Login(){
    // DEKLARASI VARAIBEL 
    string Username;
    string Password;
    map <string,string> result;
    // VARIABEL LOGIN UNTUK MENYIMPAN JUMLAH LOGIN
    int login = 0;
    
    while (true){
        if (login > 3){
            cout<<"Login gagal, pastikan kembali Username dan Password anda sudah terdaftar"<<endl;
            exit (0);
        } else {
            cout<<"\n===LOGIN PAGE==="<<endl;
            cout<<"*Username sesuai dengan nama yang terdaftar di data karyawan"<<endl;
            cout<<"*Password sesuai dengan NIM anda"<<endl;
            cout<<"Masukkan Username Anda : ";
            cin>>Username;
            // ERROR HANDLING
            if (cin.fail()){
                cin.clear();
                cin.ignore();
                cout<<"Input salah."<<endl;
                continue;
            }
            cout<<"Masukkan Password Anda : ";
            cin>>Password;
            // ERROR HANDLING
            if (cin.fail()){
                cin.clear();
                cin.ignore();
                cout<<"Input salah."<<endl;
                continue;
            }
            result[Username] = Password;
            if (AkunKaryawan.find(Username) != AkunKaryawan.end() && AkunKaryawan[Username] == Password){
                cout<<"Login berhasil"<<endl;
                break;
            } else {
                login += 1;
                cout<<"Username atau Password anda salah, silahkan coba lagi"<<endl;
            }
        }
    }
    return result;
}

// PROSEDUR CRUD YANG HANYA BISA DI AKSES ADMIN
void CRUD(){
    // MENU ADMIN
    // DEKLARASI VARIABEL 
    int MenuAdmin;
    while (true){
        cout<<"\n===MENU CRUD ADMIN==="<<endl;
        cout<<"1. Menampilkan data karyawan"<<endl;
        cout<<"2. Update data karyawan"<<endl;
        cout<<"3. Delete data karyawan"<<endl;
        cout<<"4. Keluar"<<endl;
        cout<<"Pilih menu (Number only) : ";
        cin>>MenuAdmin;
        // ERROR HANDLING
        if (cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"Input salah."<<endl;
            continue;
        // READ
        } else if (MenuAdmin == 1){
            cout<<"\n===MENU ADMIN==="<<endl;
            for (int i = 0; i < 10; i++){
                cout<<"\nNama    : "<<Karyawan[i]->Nama<<endl;
                cout<<"Jabatan : "<<Karyawan[i]->Pos.Posisi<<endl;
                cout<<"Sisa Kontrak : "<<Karyawan[i]->Pos.SisaKontrakbulan<<" bulan"<<endl;
            }

        // UPDATE
        } else if (MenuAdmin == 2){
            // DEKLARASI VARIABEL
            int MenuUpdate;
            int IdxUpdate;
            cout<<"\n===UPDATE DATA==="<<endl;
            cout<<"\n ===DATA KARYAWAN==="<<endl;
            for (int i = 0; i < 10; i++){
                cout<<(i+1)<<". ";
                cout<<"Nama    : "<<Karyawan[i]->Nama<<endl;
                cout<<"  Jabatan : "<<Karyawan[i]->Pos.Posisi<<endl;
                cout<<"Sisa Kontrak : "<<Karyawan[i]->Pos.SisaKontrakbulan<<" bulan"<<endl;
            }
            while (true){
                cout<<"\n===MENU UPDATE==="<<endl;
                cout<<"1. Update Nama"<<endl;
                cout<<"2. Update Jabatan"<<endl;
                cout<<"3. Update Kontrak"<<endl;
                cout<<"4. Keluar"<<endl;
                cout<<"Pilih menu (Number only) : ";
                cin>>MenuUpdate;
                // ERROR HANDLING
                if (cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout<<"Input salah."<<endl;
                    continue;
                // UPDATE NAMA
                } else if (MenuUpdate == 1){
                    string NewName;
                    cout<<"Masukkan nomor data yang ingin di update :";
                    if (IdxUpdate <= 10){
                        cin>>IdxUpdate;
                        // ERROR HANDLING
                        if (cin.fail()){
                            cin.clear();
                            cin.ignore();
                            cout<<"Input salah."<<endl;
                            continue;
                        }
                        cout<<"\nUPDATE NAMA"<<endl;
                        cout<<"Masukkan nama baru : ";
                        cin>>NewName;
                        Karyawan[IdxUpdate-1]->Nama = NewName;   
                        cout<<"Berhasil update data karyawan"<<endl;
                    // ERROR HANDLING
                    } else {
                        cout<<"Masukkan nomor data yang tersedia"<<endl;
                    }
                // UPDATE JABATAN
                } else if (MenuUpdate == 2){
                    string NewPosition;
                    cout<<"Masukkan nomor data yang ingin di update :";
                    if (IdxUpdate <= 10){
                        cin>>IdxUpdate;
                        // ERROR HANDLING
                        if (cin.fail()){
                            cin.clear();
                            cin.ignore();
                            cout<<"Input salah."<<endl;
                            continue;
                        }
                        cout<<"\nUPDATE JABATAN"<<endl;
                        cout<<"Masukkan posisi baru : ";
                        cin>>NewPosition;
                        Karyawan[IdxUpdate-1]->Pos.Posisi = NewPosition; 
                        cout<<"Berhasil update data karyawan"<<endl;  
                    // ERROR HANDLING
                    } else {
                        cout<<"Masukkan nomor data yang tersedia"<<endl;
                    }
                // UPDATE KONTRAK
                } else if (MenuUpdate == 3){
                    int NewKontrak;
                    cout<<"Masukkan nomor data yang ingin di update :";
                    if (IdxUpdate <= 10){
                        cin>>IdxUpdate;
                        cout<<"\nUPDATE KONTRAK"<<endl;
                        cout<<"Masukkan Kontrak baru : ";
                        cin>>NewKontrak;
                        // ERROR HANDLING
                        if (cin.fail()){
                            cin.clear();
                            cin.ignore();
                            cout<<"Input salah."<<endl;
                        }
                        Karyawan[IdxUpdate-1]->Pos.SisaKontrakbulan = NewKontrak; 
                        cout<<"Berhasil update data karyawan"<<endl;  
                    // ERROR HANDLING
                    } else {
                        cout<<"Masukkan nomor data yang tersedia"<<endl;
                        
                    }    
                } else if (MenuUpdate == 4){
                    string Lanjut = Continue();
                    if (Lanjut == "y"){
                        break;
                    } else {
                        cout<<"\n===MENUTUP PROGRAM==="<<endl;
                        exit (0);
                    } 
                // ERROR HANDLING 
                } else {
                    cout<<"Menu tidak ada, pastikan kembali pilihan anda";
                }
            }
        // DELETE
        // FITUR DELETE DISINI TIDAK MENGHAPUS ELEMENNYA TETAPI MENGOSONGKAN NYA
        // SEBAGAI BENTUK BAHWA KEKURANGAN 1 KARYAWAN DAN AGAR DAPAT DITAMBAHKAN DENGAN KARYAWAN BARU
        // DEKLARASI VARIABEL IDXDELETE UNTUK MENAMPUNG INDEX DARI DATA YANG INGIN DIHAPUS
        } else if (MenuAdmin == 3){
            int IdxDelete;
            cout<<"\n===DELETE DATA==="<<endl;
            cout<<"\n ===DATA KARYAWAN==="<<endl;
            for (int i = 0; i < 10; i++){
            cout<<(i+1)<<". ";
                cout<<"Nama    : "<<Karyawan[i]->Nama<<endl;
                cout<<" Jabatan : "<<Karyawan[i]->Pos.Posisi<<endl;
                cout<<"Sisa Kontrak : "<<Karyawan[i]->Pos.SisaKontrakbulan<<" bulan"<<endl;
            }
            cout<<"Masukkan nomor data yang ingin di delete : ";
            if (IdxDelete <= 10){
                cin>>IdxDelete;
                // ERROR HANDLING
                if (cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout<<"Input salah."<<endl;
                    continue;
                }
                Karyawan[IdxDelete-1]->Nama = "-";
                Karyawan[IdxDelete-1]->Pos.Posisi = "-";
                Karyawan[IdxDelete-1]->Pos.SisaKontrakbulan = 0;
            // ERROR HANDLING
            } else {
                cout<<"Masukkan nomor data yang tersedia"<<endl;
            }
        } else if (MenuAdmin == 4){
            string Lanjut = Continue();
            if (Lanjut == "y"){
                break;
            } else {
                cout<<"\n===MENUTUP PROGRAM==="<<endl;
                exit (0);
            }
        // ERROR HANDLING
        } else {
            cout<<"Menu tidak ada, pastikan kembali pilihan anda"<<endl;
        }
    }
}


// FUNGSI REKURSIF TOTAL GAJI KARYAWAN
// PENERAPAN PARAMETER & DAN *
int TotalGaji(Gaji *ptr, int Idx, int &TotalGajiKeseluruhan){
    if (Idx < 10){
        int Gaji = (ptr + Idx)->Jamkerja * (ptr + Idx)->GajiPerjam;
        TotalGaji(ptr, Idx + 1, TotalGajiKeseluruhan);
        TotalGajiKeseluruhan += Gaji;
    }
    return TotalGajiKeseluruhan;
}

// PROSEDUR DATA GAJI
void gaji(){
    int MenuGaji;
    while (true){
        cout<<"\n===MENU DATA GAJI KARYAWAN==="<<endl;
        cout<<"1. Tampilkan data gaji karyawan"<<endl;
        cout<<"2. Update data gaji karyawan"<<endl;
        cout<<"3. Total Gaji Karyawan"<<endl;
        cout<<"4. Keluar"<<endl;
        cout<<"Pilih menu data gaji karyawan : ";
        cin>>MenuGaji;
        // ERROR HANDLING
        if (cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"Input salah."<<endl;
            continue;
        }
        if (MenuGaji == 1){
            cout<<"DATA GAJI KARYAWAN"<<endl;
            for (int i = 0; i < 10; i++){
                cout<<"\nNama        : "<<(ptr + i)->Nama<<endl;
                cout<<"Jam Kerja   : "<<(ptr + i)->Jamkerja<<endl;
                cout<<"GajiPerJam  : "<<(ptr + i)->GajiPerjam<<endl;
                cout<<"Total Gaji  : "<<(ptr + i)->Jamkerja * (ptr + i)->GajiPerjam<<endl;
                // PENERAPAN ADDRESS OF OPERATOR
                cout<<"Alamat Nama : "<<&((ptr + i))->Nama<<endl;
            }
        } else if (MenuGaji == 2){
            int MenuUpdateGaji;
            int IdxUpdateGaji;
            string NewNameGaji;
            int NewHour;
            int NewPay;
            for (int i = 0; i < 10; i++){
                cout<<"\n"<<(i+1)<<". ";
                cout<<"Nama        : "<<(ptr + i)->Nama<<endl;
                cout<<"   Jam Kerja   : "<<(ptr + i)->Jamkerja<<endl;
                cout<<"   GajiPerJam  : "<<(ptr + i)->GajiPerjam<<endl;
                cout<<"   Total Gaji  : "<<(ptr + i)->Jamkerja * (ptr + i)->GajiPerjam<<endl;
                // PENERAPAN ADDRESS OF OPERATOR
                cout<<"   Alamat Nama : "<<&((ptr + i))->Nama<<endl;
            }
            while (true){
                cout<<"UPDATE DATA GAJI KARYAWAN"<<endl;
                cout<<"1. Update Nama"<<endl;
                cout<<"2. Update Jam Kerja"<<endl;
                cout<<"3. Update Gaji Per Jam"<<endl;
                cout<<"4. Keluar "<<endl;
                cout<<"Pilih data gaji yang ingin di update : ";
                cin>>MenuUpdateGaji;
                // ERROR HANDLING
                if (cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout<<"Input salah."<<endl;
                    continue;
                // UPDDATE NAMA
                } else if (MenuUpdateGaji == 1){
                    cout<<"UPDATE NAMA"<<endl;
                    cout<<"Masukkan nomor data gaji yang ingin di update : ";
                    if (IdxUpdateGaji <= 10){
                        cin>>IdxUpdateGaji;
                        // ERROR HANDLING
                        if (cin.fail()){
                            cin.clear();
                            cin.ignore();
                            cout<<"Input salah."<<endl;
                            continue;
                        }
                        cout<<"Masukkan Nama baru : ";
                        cin>>NewNameGaji;
                        // ERROR HANDLING
                        if (cin.fail()){
                            cin.clear();
                            cin.ignore();
                            cout<<"Input salah."<<endl;
                            continue;
                        }
                        (ptr + IdxUpdateGaji)->Nama = NewNameGaji;
                        cout<<"Berhasil Update"<<endl;
                    // ERROR HANDLING
                    } else {
                        cout<<"Masukkan nomor data yang tersedia";
                        
                    }
                } else if (MenuUpdateGaji == 2){
                    cout<<"UPDATE JAM KERJA"<<endl;
                    cout<<"Masukkan nomor data gaji yang ingin di update : ";
                    if (IdxUpdateGaji <= 10){
                        cin>>IdxUpdateGaji;
                        // ERROR HANDLING
                        if (cin.fail()){
                            cin.clear();
                            cin.ignore();
                            cout<<"Input salah."<<endl;
                            continue;
                        }
                        if (0 < NewHour <= 112){
                            cout<<"Masukkan Jam Kerja baru : ";
                            cin>>NewHour;
                            // ERROR HANDLING
                            if (cin.fail()){
                                cin.clear();
                                cin.ignore();
                                cout<<"Input salah."<<endl;
                                continue;
                            }
                            (ptr + IdxUpdateGaji)->Jamkerja = NewHour;
                            cout<<"Berhasil Update"<<endl;
                        }
                    // ERROR HANDLING
                    } else {
                        cout<<"Masukkan nomor data yang tersedia";
                        
                    }
                } else if (MenuUpdateGaji == 3){
                    cout<<"UPDATE GAJI PERJAM"<<endl;
                    cout<<"Masukkan nomor data gaji yang ingin di update : ";
                    if (IdxUpdateGaji <= 10){
                        cin>>IdxUpdateGaji;
                        // ERROR HANDLING
                        if (cin.fail()){
                            cin.clear();
                            cin.ignore();
                            cout<<"Input salah."<<endl;
                            continue;
                        }
                        cout<<"Masukkan Gaji perjam baru : ";
                        cin>>NewPay;
                        // ERROR HANDLING
                        if (cin.fail()){
                            cin.clear();
                            cin.ignore();
                            cout<<"Input salah."<<endl;
                            continue;
                        }
                        (ptr + IdxUpdateGaji)->GajiPerjam = NewPay;
                        cout<<"Berhasil Update"<<endl;
                    // ERROR HANDLING
                    } else {
                        cout<<"Masukkan nomor data yang tersedia";
                        
                    }
                } else if (MenuUpdateGaji == 4){
                    string Lanjut = Continue();
                    if (Lanjut == "y"){
                        break;
                    } else {
                        cout<<"\n===MENUTUP PROGRAM==="<<endl;
                        exit (0);
                    }    
                } else {
                    cout<<"Menu tidak ada, pastikan kembali pilihan anda";
                }
            }
        } else if (MenuGaji == 3){
            int TotalGajiKeseluruhan = 0;
            TotalGaji(DataGaji, 0, TotalGajiKeseluruhan);
            cout<<"Total seluruh gaji karyawan adalah "<<TotalGajiKeseluruhan<<endl;
        }else if (MenuGaji == 4){
            string Lanjut = Continue();
            if (Lanjut == "y"){
                break;
            } else {
                cout<<"\n===MENUTUP PROGRAM==="<<endl;
                exit (0);
            }  
        // ERROR HANDLING  
        } else {
            cout<<"Menu tidak ada, pastikan kembali pilihan anda"<<endl;
            
        }
    }
}

// PROSEDUR SLIP GAJI KARYAWAN
void SlipGaji(){
    cout<<"\n===SLIP GAJI==="<<endl;
    for (int i = 0; i < 10; i++){
        cout<<"\nNama      : "<<(ptr + i)->Nama<<endl;
        cout<<"Jam Kerja   : "<<(ptr + i)->Jamkerja<<endl;
        cout<<"GajiPerJam  : "<<(ptr + i)->GajiPerjam<<endl;
        cout<<"Total Gaji  : "<<(ptr + i)->Jamkerja * (ptr + i)->GajiPerjam<<endl;
        // PENERAPAN ADDRESS OF OPERATOR
        cout<<"Alamat Nama : "<<&((ptr + i))->Nama<<endl;
        cout<<"\n----------------------"<<endl;
    }
}

// SELECTION SORT (DESCENDING)
// SORTING HURUF DESCENDNG
void Selectionsortdes(Gaji DataGaji[], int n){
    int i, j, MinIdx;
    for (int i = 0; i < n - 1; i++){
        MinIdx = i;
        for (j = i + 1; j < n; j++){
            if (DataGaji[j].Nama > DataGaji[MinIdx].Nama){
                MinIdx = j;
            }
        }
        if (MinIdx != i){
            swap(DataGaji[i], DataGaji[MinIdx]);
        }
    }
}

// INSERTION SORT (ASCENDING)
// SORTING ANGKA ASCENDING
void insertionsortas(Gaji DataGaji[], int n){
    int i, j, key;
    for (int i = 1; i < n; i++){
        Gaji key = DataGaji[i];
        j = i - 1;
        while (j >= 0 && (DataGaji[j].GajiPerjam * DataGaji[j].Jamkerja) > (key.GajiPerjam * key.Jamkerja)){
            DataGaji[j + 1] = DataGaji[j];
            j = j - 1;
        }
        DataGaji[j + 1] = key;
    }
}

// BUBBLE SORT (DESCENDING)
// SORTING ANGKA DESCENDING
void bubblesortgajides(Gaji DataGaji[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n -1; j++){
            if ((DataGaji[j].GajiPerjam * DataGaji[j].Jamkerja) < (DataGaji[j+1].GajiPerjam * DataGaji[j+1].Jamkerja)){
                swap(DataGaji[j], DataGaji[j+1]);
            }
        }
    }
}

// SELECTION SORT (ASCENDING)
// SORTING HURUF ASCENDING
void Selectionsortas(Gaji DataGaji[], int n){
    int i, j, MinIdx;
    for (int i = 0; i < n - 1; i++){
        MinIdx = i;
        for (j = i + 1; j < n; j++){
            if (DataGaji[j].Nama < DataGaji[MinIdx].Nama){
                MinIdx = j;
            }
        }
        if (MinIdx != i){
            swap(DataGaji[i], DataGaji[MinIdx]);
        }
    }
}

// BINARY SEARCH
// SEARCHING DATA TERURUT
int BinarySearch(Gaji DataGaji[], int p, int q, string x){
    while (p <= q){
        int mid = p + (q - p) / 2;
        if (DataGaji[mid].Nama == x){
            return mid;
        }
        if (DataGaji[mid].Nama < x){
            p = mid + 1;
        } else {
            q = mid - 1;
        }
    }
    return -1;
}

// SEQUENTIAL SEARCH
// SEARCHING DATA TERURUT DESCENDING
int SequentialSearch(Gaji DataGaji[], int n, string x){
    for (int i = 0; i < n; i++){
        if (DataGaji[i].Nama == x){
            return i;
        } 
    }
    return -1;
}

// FUNGSI SORTING
void Sorting(){
    while (true){
        int menusort;
        cout<<"\n===MENU SORTING==="<<endl;
        cout<<"1. Sorting nama ascending"<<endl;
        cout<<"2. Sorting nama descending"<<endl;
        cout<<"3. Sorting gaji ascending"<<endl;
        cout<<"4. Sorting gaji descending"<<endl;
        cout<<"5. Keluar"<<endl;
        cout<<"Pilih menu sorting : ";
        cin>>menusort;
        if (cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"Input salah."<<endl;
            continue;
        } else if (menusort == 1){
            Selectionsortas(DataGaji, 10);
            cout<<"=DATA GAJI KARYAWAN NAMA TERURUT DESCENDING="<<endl;
            cout<<"---------------------------------------"<<endl;
            for (int i = 0; i < 10; i++){
                cout<<"\n"<<i+1<<". Nama        :"<<DataGaji[i].Nama<<endl;
                cout<<"   Jam Kerja   : "<<DataGaji[i].Jamkerja<<endl;
                cout<<"   Gaji Perjam : "<<DataGaji[i].GajiPerjam<<endl;
                cout<<"   Total Gaji  : "<<DataGaji[i].GajiPerjam * DataGaji[i].Jamkerja<<endl;
            }
        } else if (menusort == 2){
            Selectionsortdes(DataGaji, 10);
            cout<<"=DATA GAJI KARYAWAN NAMA TERURUT ASCENDING="<<endl;
            cout<<"---------------------------------------"<<endl;
            for (int i = 0; i < 10; i++){
                cout<<"\n"<<i+1<<". Nama        :"<<DataGaji[i].Nama<<endl;
                cout<<"   Jam Kerja   : "<<DataGaji[i].Jamkerja<<endl;
                cout<<"   Gaji Perjam : "<<DataGaji[i].GajiPerjam<<endl;
                cout<<"   Total Gaji  : "<<DataGaji[i].GajiPerjam * DataGaji[i].Jamkerja<<endl;
            }
        } else if (menusort == 3){
            insertionsortas(DataGaji, 10);
            cout<<"=DATA GAJI KARYAWAN GAJI TERURUT ASCENDING="<<endl;
            cout<<"---------------------------------------"<<endl;
            for (int i = 0; i < 10; i++){
                cout<<"\n"<<i+1<<". Nama        :"<<DataGaji[i].Nama<<endl;
                cout<<"   Jam Kerja   : "<<DataGaji[i].Jamkerja<<endl;
                cout<<"   Gaji Perjam : "<<DataGaji[i].GajiPerjam<<endl;
                cout<<"   Total Gaji  : "<<DataGaji[i].GajiPerjam * DataGaji[i].Jamkerja<<endl;
            }
        } else if (menusort == 4){
            bubblesortgajides(DataGaji, 10);
            cout<<"=DATA GAJI KARYAWAN GAJI TERURUT DESCENDING="<<endl;
            cout<<"---------------------------------------"<<endl;
            for (int i = 0; i < 10; i++){
                cout<<"\n"<<i+1<<". Nama        :"<<DataGaji[i].Nama<<endl;
                cout<<"   Jam Kerja   : "<<DataGaji[i].Jamkerja<<endl;
                cout<<"   Gaji Perjam : "<<DataGaji[i].GajiPerjam<<endl;
                cout<<"   Total Gaji  : "<<DataGaji[i].GajiPerjam * DataGaji[i].Jamkerja<<endl;
            }
        } else if (menusort == 5){
            string Lanjut = Continue();
            if (Lanjut == "y"){
                break;
            } else {
                cout<<"\n===MENUTUP PROGRAM==="<<endl;
                exit (0);
            }    
        } else {
            cout<<"silahkan pilih menu yang tersedia"<<endl;
        }
    }
}

// FUNGSI SEARCHING
void Searching(){
    while (true){
        int menusearch;
        cout<<"\n===MENU SEARCHING==="<<endl;
        cout<<"1. Searching terurut ascending"<<endl;
        cout<<"2. Searching terurut descending"<<endl;
        cout<<"3. Keluar"<<endl;
        cout<<"Pilih menu pencarian : ";
        cin>>menusearch;
        if (cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"Input salah."<<endl;
            continue;
        } else if (menusearch == 1){
            string search;
            int pos;
            cout<<"\n=SEARCHING TERURUT ASCENDING="<<endl;
            cout<<"-----------------------------"<<endl;
            Selectionsortas(DataGaji, 10);
            cout<<"Cari Nama : ";
            cin>>search;
            if (cin.fail()){
                cin.clear();
                cin.ignore();
                cout<<"Input salah."<<endl;
                continue;
            }
            pos = BinarySearch(DataGaji, 0, 9, search);
            if (pos != -1){
                cout<<"\n"<<pos + 1<<". Nama         : "<<DataGaji[pos].Nama<<endl;
                cout<<"   Jam Kerja    : "<<DataGaji[pos].Jamkerja<<endl;
                cout<<"   Gaji Per jam : "<<DataGaji[pos].GajiPerjam<<endl;
                cout<<"   Total Gaji   : "<<DataGaji[pos].GajiPerjam * DataGaji[pos].Jamkerja<<endl;
                cout<<"   Berada di posisi data ke "<<pos + 1<<endl;
            } else {
                cout<<"\nKaryawan bernama "<<search<<" tidak ditemukan"<<endl;
                }
        } else if (menusearch == 2){
            string search;
            int pos;
            cout<<"\n=SEARCHING TERURUT DESCENDING="<<endl;
            cout<<"------------------------------"<<endl;
            Selectionsortdes(DataGaji, 10);
            cout<<"Cari Nama : ";
            cin>>search;
            if (cin.fail()){
                cin.clear();
                cin.ignore();
                cout<<"Input salah."<<endl;
                continue;
            }
            pos = SequentialSearch(DataGaji, 10, search);
            if (pos != -1){
                cout<<"\n"<<pos + 1<<". Nama         : "<<DataGaji[pos].Nama<<endl;
                cout<<"   Jam Kerja    : "<<DataGaji[pos].Jamkerja<<endl;
                cout<<"   Gaji Per jam : "<<DataGaji[pos].GajiPerjam<<endl;
                cout<<"   Total Gaji   : "<<DataGaji[pos].GajiPerjam * DataGaji[pos].Jamkerja<<endl;
                cout<<"   Berada di posisi data ke "<<pos + 1<<endl;
            } else {
                cout<<"\nKaryawan bernama "<<search<<" tidak ditemukan"<<endl;
            }
        } else if (menusearch == 3){
            string Lanjut = Continue();
            if (Lanjut == "y"){
                break;
            } else {
                cout<<"\n===MENUTUP PROGRAM==="<<endl;
                exit (0);
            }    
        } else {
            cout<<"silahkan pilih menu yang tersedia"<<endl;
        }
    }
}

int main(){
    AkunKaryawan["ADMIN"] = "2309106052";
    AkunKaryawan["Octavia"] = "2309106001";
    AkunKaryawan["Jasmine"] = "2309106002";
    AkunKaryawan["Imro"] = "2309106003";
    AkunKaryawan["Ridwan"] = "2309106004";
    AkunKaryawan["Rini"] = "2309106005";
    AkunKaryawan["Elly"] = "2309106006";
    AkunKaryawan["Rio"] = "2309106007";
    AkunKaryawan["Randy"] = "2309106008";
    AkunKaryawan["Dani"] = "2309106009";
    AkunKaryawan["Aldi"] = "2309106010";
    int InPage;
    int MenuAdmin;
    map <string, string> Akun;
    while (true){
        cout<<"\n===HOME PAGE==="<<endl;
        cout<<"1. Login"<<endl;
        cout<<"2. Keluar"<<endl;
        cout<<"Pilih menu masuk (Number only) : ";
        cin>>InPage;
        // ERROR HANDLING
        if (cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"Input salah."<<endl;
            continue;
        } else if (InPage == 1){
            Akun = Login();
            if (Akun["ADMIN"] == "2309106052"){
                while (true){
                    cout<<"\n===MENU ADMIN==="<<endl;
                    cout<<"1. CRUD data karyawan"<<endl;
                    cout<<"2. Data Gaji karyawan"<<endl;
                    cout<<"3. Tampilan sorting data gaji karyawan"<<endl;
                    cout<<"4. Searching Data Gaji karyawan"<<endl;
                    cout<<"5. Keluar"<<endl;
                    cout<<"Pilih menu admin (Number only) : ";
                    cin>>MenuAdmin;
                    // ERROR HANDLING
                    if (cin.fail()){
                        cin.clear();
                        cin.ignore();
                        cout<<"Input salah."<<endl;
                        continue;
                    } else if (MenuAdmin == 1){
                        CRUD();
                    } else if (MenuAdmin == 2){
                        gaji();
                    } else if (MenuAdmin == 3){
                        Sorting();
                    } else if (MenuAdmin == 4){
                        Searching();
                    } else if (MenuAdmin == 5){
                        string Lanjut = Continue();
                        if (Lanjut == "y"){
                            break;
                        } else {
                            cout<<"\n===MENUTUP PROGRAM==="<<endl;
                            exit (0);
                        }    
                    } else {
                        cout<<"silahkan pilih menu yang tersedia"<<endl;
                    }
                }
            } else {
                SlipGaji();
            }
        } else if (InPage == 2){
            cout<<"\n===MENUTUP PROGRAM==="<<endl;
            exit (0);   
        } else {
            cout<<"Silahkan pilih menu yang tersedia"<<endl;
        }
    }
}