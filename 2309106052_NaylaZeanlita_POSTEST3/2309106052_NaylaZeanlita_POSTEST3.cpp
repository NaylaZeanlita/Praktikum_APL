// NAYLA ZEANLITA PUTRI NUR'AIN
// 2309106052 B1'23
// POSTEST 3 APL
// PROGRAM DATA GAJI KARYAWAN DALAM 1 MINGGU

#include <iostream>
#include <map>

using namespace std;
map <string, string> AkunKaryawan;

string Karyawan[10][2] = {
        {"Octavia", "Kasir"},
        {"Jasmine", "Kasir"},
        {"Imro Atul", "Marketing"},
        {"Ridwan", "Marketing"},
        {"Rini", "Manajer Toko"},
        {"Elly", "Cleaning Service"},
        {"Rio", "Staff Gudang"},
        {"Randy", "Staff Gudang"},
        {"Dani", "Penata Barang"},
        {"Aldi", "Penata Barang"}
    };

struct Gaji{
        string Nama;
        int Jamkerja;
        int GajiPerjam;
    };
struct Gaji DataGaji[10][3] = {
    {"Octavia", 40, 17000},
    {"Jasmine", 40, 17000},
    {"Imro Atul", 40, 19000},
    {"Ridwan", 40, 19000},
    {"Rini", 40, 28000},
    {"Elly", 40, 10000},
    {"Rio", 40, 16000},
    {"Randy", 40, 16000},
    {"Dani", 40, 15000},
    {"Aldi", 40, 15000}
};

// FUNGSI CONTINUE
string Continue(){
    string Jawab;
    string result;
    cout<<"Ingin melanjutkan program (y/n)? ";
    cin>>Jawab;
    while (true){
        if (Jawab == "Y" || Jawab == "y"){
            result = "y";
            break;
        } else if (Jawab == "N" || Jawab == "n"){
            result = "n";
            break;
        } else {
            cout<<"Cukup jawab y/n saja."<<endl;
        }
    }
    return result;
}

// PROSEDUR REGISTRASI
void Regist(){
    // DEKLARASI VARIABEL
    string Username;
    string Password;
    bool StatusRegist = false;
    while (true){
        // INPUT USERNAME DAN PASSWORD REGISTRASI
        cout<<"\n===REGISTRATION PAGE==="<<endl;
        cout<<"Masukkan Username : ";
        cin>>Username;
        cout<<"Masukkan Password : ";
        cin>>Password;
        // PERIKSA AKUN KARYAWAN
        if (AkunKaryawan.find(Username) == AkunKaryawan.end()){
            AkunKaryawan[Username] = Password;
            cout<<"Registrasi berhasil, silahkan login"<<endl;
            StatusRegist = true;
            break;
        } else {
            cout<<"Username sudah terdaftar, silahkan registrasi ulang"<<endl;
        }
    }
}

// FUNGSI LOGIN
map <string, string> Login(){
    // DEKLARASI VARAIBEL 
    string Username;
    string Password;
    map <string,string> result;
    // VARIABEL LOGIN UNTUK MENYIMPAN JUMLAH LOGIN
    int login = 0;
    // PERULANGAN UNTUK JUMLAH LOGIN MAKSIMAL 3 KALI
    while (true){
        login += 1;
        if (login > 3){
            cout<<"Login gagal, pastikan kembali Username dan Password anda sudah terdaftar"<<endl;
            exit (0);
        } else {
            cout<<"\n===LOGIN PAGE==="<<endl;
            cout<<"Masukkan Username Anda : ";
            cin>>Username;
            cout<<"Masukkan Password Anda : ";
            cin>>Password;
            result[Username] = Password;
            if (AkunKaryawan.find(Username) != AkunKaryawan.end() && AkunKaryawan[Username] == Password){
                cout<<"Login berhasil"<<endl;
                break;
            } else {
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

        // READ
        if (MenuAdmin == 1){
            cout<<"\n===MENU ADMIN==="<<endl;
            for (int i = 0; i < 10; i++){
                cout<<"\nNama    : "<<Karyawan[i][0]<<endl;
                cout<<"Jabatan : "<<Karyawan[i][1]<<endl;
            }

        // UPDATE
        } else if (MenuAdmin == 2){
            // DEKLARASI VARIABEL
            int MenuUpdate;
            int IdxUpdate;
            while (true){
                cout<<"\n===MENU UPDATE==="<<endl;
                cout<<"1. Update Nama"<<endl;
                cout<<"2. Update Jabatan"<<endl;
                cout<<"3. Keluar"<<endl;
                cout<<"Pilih menu (Number only) : ";
                cin>>MenuUpdate;
                //UPDATE NAMA
                if (MenuUpdate == 1){
                    string NewName;
                    cout<<"\n===UPDATE DATA==="<<endl;
                    cout<<"\n ===DATA KARYAWAN==="<<endl;
                    for (int i = 0; i < 10; i++){
                        cout<<(i+1)<<". ";
                        cout<<"Nama    : "<<Karyawan[i][0]<<endl;
                        cout<<"  Jabatan : "<<Karyawan[i][1]<<endl;
                    }
                    cout<<"Masukkan nomor data yang ingin di update :";
                    cin>>IdxUpdate;
                    cout<<"\nUPDATE NAMA"<<endl;
                    cout<<"Masukkan nama baru : ";
                    cin>>NewName;
                    Karyawan[IdxUpdate-1][0] = NewName;   
                    cout<<"Berhasil update data karyawan"<<endl;
                // UPDATE JABATAN
                } else if (MenuUpdate == 2){
                    string NewPosition;
                    cout<<"\n===UPDATE DATA==="<<endl;
                    cout<<"\n ===DATA KARYAWAN==="<<endl;
                    for (int i = 0; i < 10; i++){
                        cout<<(i+1)<<". ";
                        cout<<"Nama    : "<<Karyawan[i][0]<<endl;
                        cout<<"  Jabatan : "<<Karyawan[i][1]<<endl;
                    }
                    cout<<"Masukkan nomor data yang ingin di update :";
                    cin>>IdxUpdate;
                    cout<<"\nUPDATE JABATAN"<<endl;
                    cout<<"Masukkan posisi baru : ";
                    cin>>NewPosition;
                    Karyawan[IdxUpdate-1][1] = NewPosition; 
                    cout<<"Berhasil update data karyawan"<<endl;  
                } else if (MenuUpdate == 3){
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
                cout<<"Nama    : "<<Karyawan[i][0]<<endl;
                cout<<" Jabatan : "<<Karyawan[i][1]<<endl;
            }
            cout<<"Masukkan nomor data yang ingin di delete : ";
            cin>>IdxDelete;
            Karyawan[IdxDelete-1][0] = "-";
            Karyawan[IdxDelete-1][1] = "-";
        } else if (MenuAdmin == 4){
            string Lanjut = Continue();
            if (Lanjut == "y"){
                break;
            } else {
                cout<<"\n===MENUTUP PROGRAM==="<<endl;
                exit (0);
            }
        } else {
            cout<<"Menu tidak ada, pastikan kembali pilihan anda"<<endl;
        }
    }
}


// FUNGSI REKURSIF TOTAL GAJI KARYAWAN
int TotalGaji(int Idx, int TotalGajiKaryawan = 0){
    if (Idx < 10){
        int Gaji = DataGaji[Idx]->Jamkerja * DataGaji[Idx]->GajiPerjam;
        return TotalGaji(Idx + 1, TotalGajiKaryawan + Gaji);
    } else {
    return TotalGajiKaryawan;
    }
}

// PROSEDUR DATA GAJI
void Gaji(){
    int MenuGaji;
    while (true){
        cout<<"\n===MENU DATA GAJI KARYAWAN==="<<endl;
        cout<<"1. Tampilkan data gaji karyawan"<<endl;
        cout<<"2. Update data gaji karyawan"<<endl;
        cout<<"3. Total Gaji Karyawan"<<endl;
        cout<<"4. Keluar"<<endl;
        cout<<"Pilih menu data gaji karyawan : ";
        cin>>MenuGaji;
        if (MenuGaji == 1){
            cout<<"DATA GAJI KARYAWAN"<<endl;
            for (int i = 0; i < 10; i++){
                cout<<"\nNama        : "<<DataGaji[i]->Nama<<endl;
                cout<<"Jam Kerja   : "<<DataGaji[i]->Jamkerja<<endl;
                cout<<"GajiPerJam  : "<<DataGaji[i]->GajiPerjam<<endl;
                cout<<"Total Gaji  : "<<DataGaji[i]->Jamkerja * DataGaji[i]->GajiPerjam<<endl;
            }
        } else if (MenuGaji == 2){
            int MenuUpdateGaji;
            int IdxUpdateGaji;
            string NewNameGaji;
            int NewHour;
            int NewPay;
            while (true){
                cout<<"UPDATE DATA GAJI KARYAWAN"<<endl;
                cout<<"1. Update Nama"<<endl;
                cout<<"2. Update Jam Kerja"<<endl;
                cout<<"3. Update Gaji Per Jam"<<endl;
                cout<<"4. Keluar "<<endl;
                cout<<"Pilih data gaji yang ingin di update : ";
                cin>>MenuUpdateGaji;
                // UPDATE NAMA
                if (MenuUpdateGaji == 1){
                    cout<<"UPDATE NAMA"<<endl;
                    for (int i = 0; i < 10; i++){
                        cout<<"\n"<<(i+1)<<". ";
                        cout<<"Nama        : "<<DataGaji[i]->Nama<<endl;
                        cout<<"   Jam Kerja   : "<<DataGaji[i]->Jamkerja<<endl;
                        cout<<"   GajiPerJam  : "<<DataGaji[i]->GajiPerjam<<endl;
                        cout<<"   Total Gaji  : "<<DataGaji[i]->Jamkerja * DataGaji[i]->GajiPerjam<<endl;
                    }
                    cout<<"Masukkan nomor data gaji yang ingin di update : ";
                    cin>>IdxUpdateGaji;
                    cout<<"Masukkan Nama baru : ";
                    cin>>NewNameGaji;
                    DataGaji[IdxUpdateGaji-1]->Nama = NewNameGaji;
                    cout<<"Berhasil Update"<<endl;
                } else if (MenuUpdateGaji == 2){
                    cout<<"UPDATE JAM KERJA"<<endl;
                    for (int i = 0; i < 10; i++){
                        cout<<"\n"<<(i+1)<<". ";
                        cout<<"Nama        : "<<DataGaji[i]->Nama<<endl;
                        cout<<"   Jam Kerja   : "<<DataGaji[i]->Jamkerja<<endl;
                        cout<<"   GajiPerJam  : "<<DataGaji[i]->GajiPerjam<<endl;
                        cout<<"   Total Gaji  : "<<DataGaji[i]->Jamkerja * DataGaji[i]->GajiPerjam<<endl;
                    }
                    cout<<"Masukkan nomor data gaji yang ingin di update : ";
                    cin>>IdxUpdateGaji;
                    cout<<"Masukkan Jam Kerja baru : ";
                    cin>>NewHour;
                    DataGaji[IdxUpdateGaji-1]->Jamkerja = NewHour;
                    cout<<"Berhasil Update"<<endl;
                } else if (MenuUpdateGaji == 3){
                    cout<<"UPDATE GAJI PERJAM"<<endl;
                    for (int i = 0; i < 10; i++){
                        cout<<"\n"<<(i+1)<<". ";
                        cout<<"Nama        : "<<DataGaji[i]->Nama<<endl;
                        cout<<"   Jam Kerja   : "<<DataGaji[i]->Jamkerja<<endl;
                        cout<<"   GajiPerJam  : "<<DataGaji[i]->GajiPerjam<<endl;
                        cout<<"   Total Gaji  : "<<DataGaji[i]->Jamkerja * DataGaji[i]->GajiPerjam<<endl;
                    }
                    cout<<"Masukkan nomor data gaji yang ingin di update : ";
                    cin>>IdxUpdateGaji;
                    cout<<"Masukkan Gaji perjam baru : ";
                    cin>>NewPay;
                    DataGaji[IdxUpdateGaji-1]->GajiPerjam = NewPay;
                    cout<<"Berhasil Update"<<endl;
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
            int TotalGajiKeseluruhan;
            TotalGajiKeseluruhan = TotalGaji(0);
            cout<<"Total seluruh gaji karyawan adalah "<<TotalGajiKeseluruhan<<endl;
        }else if (MenuGaji == 4){
            string Lanjut = Continue();
            if (Lanjut == "y"){
                break;
            } else {
                cout<<"\n===MENUTUP PROGRAM==="<<endl;
                exit (0);
            }    
        } else {
            cout<<"Menu tidak ada, pastikan kembali pilihan anda"<<endl;
        }
    }
}

// PROSEDUR SLIP GAJI KARYAWAN
void SlipGaji(){
    cout<<"\n===SLIP GAJI==="<<endl;
    for (int i = 0; i < 10; i++){
        cout<<"\nNama        : "<<DataGaji[i]->Nama<<endl;
        cout<<"Jam Kerja   : "<<DataGaji[i]->Jamkerja<<endl;
        cout<<"GajiPerJam  : "<<DataGaji[i]->GajiPerjam<<endl;
        cout<<"Total Gaji  : "<<DataGaji[i]->Jamkerja * DataGaji[i]->GajiPerjam<<endl;
        cout<<"\n----------------------"<<endl;
    }
}

int main(){
    AkunKaryawan["ADMIN"] = "2309106052";
    int InPage;
    int MenuAdmin;
    map <string, string> Akun;
    while (true){
        cout<<"\n===HOME PAGE==="<<endl;
        cout<<"1. Registrasi"<<endl;
        cout<<"2. Login"<<endl;
        cout<<"3. Keluar"<<endl;
        cout<<"Pilih menu masuk (Number only) : ";
        cin>>InPage;
        if (InPage == 1){
            Regist();
        } else if (InPage == 2){
            Akun = Login();
            if (Akun["ADMIN"] == "2309106052"){
                while (true){
                    cout<<"\n===MENU ADMIN==="<<endl;
                    cout<<"1. CRUD data karyawan"<<endl;
                    cout<<"2. Data Gaji karyawan"<<endl;
                    cout<<"3. Keluar"<<endl;
                    cout<<"Pilih menu admin (Number only) : ";
                    cin>>MenuAdmin;
                    if (MenuAdmin == 1){
                        CRUD();
                    } else if (MenuAdmin == 2){
                        Gaji();
                    } else if (MenuAdmin == 3){
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
        } else if (InPage == 3){
            cout<<"\n===MENUTUP PROGRAM==="<<endl;
            exit (0);   
        } else {
            cout<<"Silahkan pilih menu yang tersedia"<<endl;
        }
    }
}