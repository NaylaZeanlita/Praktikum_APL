#include <iostream>
#include <map>
#include <string>

using namespace std;
map<string, int> DataUser;

// FUNGSI CONTINUE UNTUK USER MEMILIH UNTUK MELANJUTKAN PROGRAM ATAU TIDAK
string Continue(){
    // DEKLARASI VARIABEL
    string Jawab;
    string result;
    // INPUT JAWABAN
    cout<<"Ingin melanjutkan (y/n) ? ";
    cin>>Jawab;
    // MENYETARAKAN ISI DARI VARIBEL JAWAB
    while (true){
        if (Jawab == "Y" || Jawab == "y"){
            result = "Y";
            break;
        } else if (Jawab == "N" || Jawab == "n"){
            result = "N";
            break;
        } else {
            cout<<"Cukup Jawab y/n saja"<<endl;
        }
    }
    // MENGEMBALIKAN NILAI JAWAB
    return result;
}

void Regist(){
    string Username;
    int Password;
    bool StatusRegist = false;
    while (true){
        cout<<"===REGISTRATION PAGE==="<<endl;
        cout<<"Masukkan Username Baru : ";
        cin>>Username;
        cout<<"Masukkan Password : ";
        cin>>Password;
        // PERIKSA DATA USER BARU
        if (DataUser.find(Username) == DataUser.end()){
            DataUser[Username] = Password;
            cout<<"Registrasi berhasil, silahkan login"<<endl;
            StatusRegist = true;
            break;
        } else {
            cout<<"Username sudah terdaftar, silahkan registrasi ulang"<<endl;
        }
    }
}

void Login(){
    string Username;
    int Password; 
    int inputan = 0;
    while (true){
        inputan += 1;
        if (inputan > 3){
            cout<<"Login gagal, pastikan kembali username dan pasword Anda."<<endl;
            exit (0);
        } else {
            cout<<"\n===LOGIN PAGE==="<<endl;
            cout<<"Masukkan Username Anda : ";
            cin>>Username;
            cout<<"Masukkan Password Anda : ";
            cin>>Password;
            if (DataUser.find(Username) != DataUser.end() && DataUser[Username] == Password){
                cout<<"Login Berhasil"<<endl;
                break;
            } else {
                cout<<"Username atau Password Anda salah, silahkan coba lagi"<<endl;
            }
        }       
    }
}

void Menu(){
    int Pilih;
    float KmPerJam;
    float CmPerDetik;
    float MeterPerDetik;
    float MilPerJam;
    while (true){
        cout<<"\n===MENU KONVERSI==="<<endl;
        cout<<"1. Konversi Km/Jam ke (Cm/Dtk, M/Dtk, Mil/Jam)"<<endl;
        cout<<"2. Konversi Cm/Dtk ke (Km/Jam, M/Dtk, Mil/Jam)"<<endl;
        cout<<"3. Konversi M/Dtk ke (Km/Jam, Cm/Dtk, Mil/Jam)"<<endl;
        cout<<"4. Konversi Mil/Jam ke (Km/Jam, Cm/Dtk, M/Dtk)"<<endl;
        cout<<"Pilihlah Menu Konversi (Number Only) : "<<endl;
        cin>>Pilih;
        if (Pilih == 1){
            cout<<"\n===Konversi Km/Jam ke (Cm/Dtk, M/Dtk, Mil/Jam)==="<<endl;
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Masukkan kecepatan dengan satuan Km/Jam yang ingin di konversi : ";
            cin>>KmPerJam;
            cout<<"Hasil Konversi :"<<endl;
            cout<<(KmPerJam * 1000/36)<<"Cm/Detik"<<endl;
            cout<<(KmPerJam * 10/36)<<"Meter/Detik"<<endl;
            cout<<(KmPerJam * 0.621371)<<"Mil/Jam"<<endl;
            string Lanjut = Continue();
            if (Lanjut == "Y"){
                Menu();
            } else {
                cout<<"\n===Menutup Program===";
                exit (0);
            }
        } else if (Pilih == 2){
            cout<<"\n===Konversi Cm/Dtk ke (Km/Jam, M/Dtk, Mil/Jam)==="<<endl;
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Masukkan kecepatan dengan satuan Cm/Detik yang ingin di konversi : ";
            cin>>CmPerDetik;
            cout<<"Hasil Konversi :"<<endl;
            cout<<(CmPerDetik * 0.036)<<"Km/Jam"<<endl;
            cout<<(CmPerDetik * 0.01)<<"Meter/Detik"<<endl;
            cout<<(CmPerDetik * 0.0223694)<<"Mil/Jam"<<endl;
            string Lanjut = Continue();
            if (Lanjut == "Y"){
                Menu();
            } else {
                cout<<"\n===Menutup Program===";
                exit (0);
            }
        } else if (Pilih == 3){
            cout<<"\n===Konversi Meter/Dtk ke (Km/Jam, Cm/Dtk, Mil/Jam)==="<<endl;
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Masukkan kecepatan dengan satuan Meter/Detik yang ingin di konversi : ";
            cin>>MeterPerDetik;
            cout<<"Hasil Konversi :"<<endl;
            cout<<(MeterPerDetik * 3.6)<<"Km/Jam"<<endl;
            cout<<(MeterPerDetik * 100)<<"Cm/Detik"<<endl;
            cout<<(MeterPerDetik * 3600/1609.344)<<"Mil/Jam"<<endl; 
            string Lanjut = Continue();
            if (Lanjut == "Y"){
                Menu();
            } else {
                cout<<"\n===Menutup Program===";
                exit (0);
            }      
        } else if (Pilih == 4){
            cout<<"\n===Konversi Mil/Jam ke (Km/Jam, Cm/Dtk, M/Dtk)==="<<endl;
            cout<<"-------------------------------------------------"<<endl;
            cout<<"Masukkan kecepatan dengan satuan Mil/Jam yang ingin di konversi : ";
            cin>>MilPerJam;
            cout<<"Hasil Konversi :"<<endl;
            cout<<(MilPerJam * 1.60934)<<"Km/Jam"<<endl;
            cout<<(MilPerJam * 160934/360000)<<"Cm/Detik"<<endl;
            cout<<(MilPerJam * 1609.34/3600)<<"Meter/Detik"<<endl;
            string Lanjut = Continue();
            if (Lanjut == "Y"){
                Menu();
            } else {
                cout<<"\n===Menutup Program===";
                exit (0);
            }       
        } else {
            cout<<"Pillihan tidak ada di menu, tolong pilih ulang sesuai menu";
        }
    }
}

int main(){
    Regist();
    Login();
    Menu();
}