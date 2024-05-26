#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string.h>
using namespace std;

struct Karyawan
{
    string nama;
    string password;
    int jabatan;
    int jamKerja;
};

struct Posisi
{
    int id;
    string posisi;
    int gajiPerJam;
};

Karyawan karyawan[100];
int idxKaryawan = 0;
void readKaryawan()
{
    string data, nama, password, jabatan, jamKerja;
    int jabatan_int, jamKerja_int;
    ifstream file;
    file.open("karyawan.csv", ios::in);

    if (file.is_open())
    {
        while (getline(file, data))
        {
            stringstream ss(data);
            getline(ss, nama, ',');
            getline(ss, password, ',');
            getline(ss, jabatan, ',');
            getline(ss, jamKerja, '\n');
            stringstream jabatan_string(jabatan);
            stringstream jamKerja_string(jamKerja);
            jabatan_string >> jabatan_int;
            jamKerja_string >> jamKerja_int;

            // Periksa qpakah nama karyawan sudah ada sebelumnya
            bool karyawanSudahAda = false;
            for (int i = 0; i < idxKaryawan; i++)
            {
                if (karyawan[i].nama == nama)
                {
                    karyawanSudahAda = true;
                    break;
                }
            }

            // Jika nama karyawan belum ada, tambahkan ke dalam array of struct karyawan
            if (!karyawanSudahAda)
            {
                karyawan[idxKaryawan].nama = nama;
                karyawan[idxKaryawan].password = password;
                karyawan[idxKaryawan].jabatan = jabatan_int;
                karyawan[idxKaryawan].jamKerja = jamKerja_int;
                idxKaryawan++;
            }
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
        exit(1);
    }
}

Posisi jabatan[100];
int idxJabatan = 0;
void readJabatan()
{
    string data, id, posisi, gajiPerJam;
    int id_int, gajiPerJam_int;
    ifstream file;
    file.open("jabatan.csv", ios::in);

    if (file.is_open())
    {
        while (getline(file, data))
        {
            stringstream ss(data);
            getline(ss, id, ',');
            getline(ss, posisi, ',');
            getline(ss, gajiPerJam, '\n');
            stringstream id_string(id);
            stringstream gajiPerJam_string(gajiPerJam);
            id_string >> id_int;
            gajiPerJam_string >> gajiPerJam_int;

            // Periksa apakah nama jabatan sudah ada sebelumnya
            bool jabatanSudahAda = false;
            for (int i = 0; i < idxJabatan; i++)
            {
                if (jabatan[i].posisi == posisi)
                {
                    jabatanSudahAda = true;
                    break;
                }
            }

            // Jika nama jabatan belum ada, tambahkan ke dalam array of struct jabatan
            if (!jabatanSudahAda)
            {
                jabatan[idxJabatan].id = id_int;
                jabatan[idxJabatan].posisi = posisi;
                jabatan[idxJabatan].gajiPerJam = gajiPerJam_int;
                idxJabatan++;
            }
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
        exit(1);
    }
}

string loggedInUser;
Karyawan *userData = nullptr;
bool login()
{
    int percobaan = 0;
    string namaInput, passwordInput;

    do
    {
        cout << "======================================================================" << endl;
        cout << "| Anda Harus Login Untuk Menggunakan Aplikasi Penggajian MissCompany |" << endl;
        cout << "======================================================================" << endl;
        cout << "Username : ";
        getline(cin, namaInput);
        cout << "Password : ";
        getline(cin, passwordInput);
        bool loginBerhasil = false;
        for (int i = 0; i < idxKaryawan; i++)
        {
            if (karyawan[i].nama == namaInput && karyawan[i].password == passwordInput)
            {
                cout << "Login berhasil!" << endl;
                loggedInUser = karyawan[i].nama;
                userData = new Karyawan;
                *userData = karyawan[i];
                loginBerhasil = true;
                break;
            }
        }
        if (loginBerhasil)
        {
            return true;
        }
        else
        {
            percobaan++;
            cout << "Username atau password salah!!" << endl;
            if (percobaan < 3)
            {
                cout << "Login gagal. Silakan coba lagi (" << percobaan << "/3)" << endl;
            }
            else
            {
                cout << "Maaf, Anda telah gagal login sebanyak 3 kali." << endl;
                cout << "Program berhenti." << endl;
                return false;
            }
        }
    } while (percobaan < 3);
    return false;
}

// FUNGSI CONTINUE
string Continue(string query)
{
    string Jawab;
    string result;
    while (true)
    {
        if (query == "lanjut")
        {
            cout << "Ingin melanjutkan program (y/n)? ";
        }
        else
        {
            cout << "Yakin ingin keluar dari program (y/n)? ";
        }
        cin >> Jawab;
        // ERROR HANDLING
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Cukup jawab y/n saja." << endl;
            continue;
        }
        else if (Jawab == "Y" || Jawab == "y")
        {
            result = "y";
            break;
        }
        else if (Jawab == "N" || Jawab == "n")
        {
            result = "n";
            break;
            // ERROR HANDLING
        }
        else
        {
            cout << "Cukup jawab y/n saja." << endl;
        }
    }
    return result;
}

void SlipGaji(Karyawan *user)
{
    readJabatan();
    string posisiJabatan;
    int gajiPerJamUser;

    // Menghitung panjang maksimum untuk setiap kolom yang akan ditampilkan dalam tabel slip gaji
    int maxJamKerjaLength = strlen("Jam Kerja");
    int maxPosisiLength = strlen("Posisi Jabatan");
    int maxGajiPerJamLength = strlen("Gaji Per Jam");

    // Mencari posisi jabatan dan gaji per jam user yang sedang login
    for (int j = 0; j < idxJabatan; j++)
    {
        if (user->jabatan == jabatan[j].id)
        {
            posisiJabatan = jabatan[j].posisi;
            gajiPerJamUser = jabatan[j].gajiPerJam;
            // Memperbarui panjang maksimum jika posisi jabatan atau gaji per jam user lebih panjang
            maxPosisiLength = max(maxPosisiLength, (int)posisiJabatan.length());
            maxGajiPerJamLength = max(maxGajiPerJamLength, (int)to_string(gajiPerJamUser).length());
            break;
        }
    }

    cout << "Halo selamat datang " << user->nama << "!" << endl;

    // Menampilkan slip gaji dengan lebar sesuai panjang maksimum kolom yang akan ditampilkan
    cout << "\n+" << string(maxJamKerjaLength + 2, '=') << "+" << string(maxPosisiLength + 2, '=') << "+" << string(maxGajiPerJamLength + 2, '=') << "+" << string(13, '=') << "+" << endl;
    cout << "| " << left << setw(maxJamKerjaLength) << "Jam Kerja"
         << " | " << setw(maxPosisiLength) << "Posisi Jabatan"
         << " | " << setw(maxGajiPerJamLength) << "Gaji Per Jam"
         << " | " << setw(11) << "Total Gaji"
         << " |" << endl;
    cout << "+" << string(maxJamKerjaLength + 2, '-') << "+" << string(maxPosisiLength + 2, '-') << "+" << string(maxGajiPerJamLength + 2, '-') << "+" << string(13, '-') << "+" << endl;
    cout << "| " << left << setw(maxJamKerjaLength) << user->jamKerja << " | " << setw(maxPosisiLength) << posisiJabatan << " | " << setw(maxGajiPerJamLength) << gajiPerJamUser << " | " << setw(11) << (user->jamKerja * gajiPerJamUser) << " |" << endl;
    cout << "+" << string(maxJamKerjaLength + 2, '=') << "+" << string(maxPosisiLength + 2, '=') << "+" << string(maxGajiPerJamLength + 2, '=') << "+" << string(13, '=') << "+" << endl;
}

void showJabatan()
{
    readJabatan();

    int maxNo = 0;
    int maxJabatan = 0;
    int maxGaji = 0;
    int maxNoLength = 0;
    int maxJabatanLength = 0;
    int maxGajiPerJamLength = 0;
    int maxJudulNoLength = 0;
    int maxJudulJabatanLength = 0;
    int maxJudulGajiLength = 0;
    maxJudulNoLength = strlen("No");
    maxJudulJabatanLength = strlen("Jabatan");
    maxJudulGajiLength = strlen("Gaji Per Jam");
    for (int i = 1; i < idxJabatan; i++)
    {
        maxNoLength = max(maxNoLength, (int)to_string(i).length());
        maxJabatanLength = max(maxJabatanLength, (int)jabatan[i].posisi.length());
        maxGajiPerJamLength = max(maxGajiPerJamLength, (int)to_string(jabatan[i].gajiPerJam).length());
    }

    if (maxJudulNoLength > maxNoLength)
    {
        maxNo = maxJudulNoLength;
    }
    else
    {
        maxNo = maxNoLength;
    }

    if (maxJudulJabatanLength > maxJabatanLength)
    {
        maxJabatan = maxJudulJabatanLength;
    }
    else
    {
        maxJabatan = maxJabatanLength;
    }

    if (maxJudulGajiLength > maxGajiPerJamLength)
    {
        maxGaji = maxJudulGajiLength;
    }
    else
    {
        maxGaji = maxGajiPerJamLength;
    }

    cout << "+" << string(maxNo + 2, '=') << "+" << string(maxJabatan + 2, '=') << "+" << string(maxGaji + 2, '=') << "+" << endl;

    // Menampilkan judul tabel dengan lebar sesuai lebar maksimum kolom pada satu baris
    cout << "|" << left << setw(maxNo + 2) << "No"
         << "|" << setw(maxJabatan + 2) << "Jabatan"
         << "|" << setw(maxGaji + 2) << "Gaji Per Jam"
         << "|" << endl;

    // Menampilkan baris pembatas antara judul dan isi tabel
    cout << "+" << string(maxNo + 2, '=') << "+" << string(maxJabatan + 2, '=') << "+" << string(maxGaji + 2, '=') << "+" << endl;

    // Menampilkan isi tabel dengan lebar sesuai lebar maksimum kolom pada satu baris
    for (int i = 1; i < idxJabatan; i++)
    {
        cout << "|" << left << setw(maxNo + 2) << i << "|"
             << setw(maxJabatan + 2) << jabatan[i].posisi << "|"
             << setw(maxGaji + 2) << jabatan[i].gajiPerJam << "|" << endl;
    }

    // Menampilkan garis bawah tabel
    cout << "+" << string(maxNo + 2, '=') << "+" << string(maxJabatan + 2, '=') << "+" << string(maxGaji + 2, '=') << "+" << endl;
}

void createJabatan()
{
    readJabatan();
    ofstream file;
    file.open("jabatan.csv", ios::out | ios::app);

    Posisi newJabatan;
    newJabatan.id = idxJabatan + 1;
    cout << "Masukkan Nama Jabatan: ";
    cin.ignore();
    getline(cin, newJabatan.posisi);

    while (true)
    {
        cout << "Masukkan Gaji per Jam: ";
        cin >> newJabatan.gajiPerJam;

        if (cin.fail() || newJabatan.gajiPerJam < 0)
        {
            cin.clear();
            cin.ignore();
            cout << "Inputan harus berupa angka positif." << endl;
        }
        else
        {
            break;
        }
    }

    file << newJabatan.id << ",";
    file << newJabatan.posisi << ",";
    file << newJabatan.gajiPerJam << "\n";
    file.close();

    cout << "Data jabatan berhasil ditambahkan." << endl;
    showJabatan();
}

void updateJabatan(string theUpdate)
{
    int IdxUpdate = -1;
    if (theUpdate == "nama")
    {
        cout << "UPDATE NAMA JABATAN" << endl;
        cout << "Masukkan nomor data jabatan yang ingin di update : ";
        cin >> IdxUpdate;
    }
    else if (theUpdate == "gaji")
    {
        cout << "UPDATE gaji per Jam" << endl;
        cout << "Masukkan nomor data jabatan yang ingin di update : ";
        cin >> IdxUpdate;
    }
    else
    {
        cout << "Inputan tidak tersedia" << endl;
    }
    if (IdxUpdate >= 1 && IdxUpdate <= idxJabatan)
    {
        if (theUpdate == "nama")
        {
            cout << "Masukkan Nama baru : ";
            cin.ignore();
            getline(cin, jabatan[IdxUpdate].posisi);
        }
        else if (theUpdate == "gaji")
        {
            cout << "Masukkan gaji per Jam baru : ";
            cin >> jabatan[IdxUpdate].gajiPerJam;
        }
        else
        {
            cout << "Inputan tidak tersedia" << endl;
        }

        // Menulis kembali data ke file dengan mode trunc
        ofstream file;
        file.open("jabatan.csv", ios::out | ios::trunc);
        for (int i = 0; i < idxJabatan; i++)
        {
            file << jabatan[i].id << ",";
            file << jabatan[i].posisi << ",";
            file << jabatan[i].gajiPerJam << "\n";
        }
        file.close();

        cout << "Berhasil Update" << endl;
    }
    else
    {
        cout << "Nomor indeks tidak valid." << endl;
    }
}

void deleteJabatan()
{
    int idxDelete = -1;
    cout << "HAPUS DATA jabatan" << endl;
    cout << "Masukkan nomor data jabatan yang ingin dihapus : ";
    cin >> idxDelete;

    if (idxDelete >= 1 && idxDelete < idxJabatan)
    {
        for (int i = idxDelete; i < idxJabatan; i++)
        {
            jabatan[i] = jabatan[i + 1];
        }
        idxJabatan--;

        // Menulis kembali data ke file dengan mode trunc
        ofstream file;
        file.open("jabatan.csv", ios::out | ios::trunc);
        for (int i = 0; i < idxJabatan; i++)
        {
            file << jabatan[i].id << ",";
            file << jabatan[i].posisi << ",";
            file << jabatan[i].gajiPerJam << "\n";
        }
        file.close();

        cout << "Berhasil menghapus data jabatan" << endl;
    }
    else
    {
        cout << "Nomor indeks tidak valid." << endl;
    }
}

void showKaryawan()
{
    readJabatan();
    readKaryawan();

    int maxNo = 0;
    int maxNama = 0;
    int maxJamKerja = 0;
    int maxGaji = 0;
    int maxJabatan = 0;
    int maxTotal = 0;
    int maxNoLength = 0;
    int maxNamaLength = 0;
    int maxJamKerjaLength = 0;
    int maxGajiLength = 0;
    int maxJabatanLength = 0;
    int maxTotalLength = 0;
    int maxJudulNoLength = strlen("No");
    int maxJudulNamaLength = strlen("Nama");
    int maxJudulJamLength = strlen("Jam Kerja");
    int maxJudulGajiLength = strlen("Gaji Per Jam");
    int maxJudulJabatanLength = strlen("Jabatan");
    int maxJudulTotalLength = strlen("Total Gaji");

    for (int i = 1; i < idxKaryawan; i++)
    {
        int jabatanLength = 0;
        int gajiPerJamLength = 0;
        for (int j = 1; j < idxJabatan; j++)
        {
            if (karyawan[i].jabatan == jabatan[j].id)
            {
                jabatanLength = jabatan[j].posisi.length();
                gajiPerJamLength = to_string(jabatan[j].gajiPerJam).length();
                break;
            }
        }
        maxNoLength = max(maxNoLength, (int)to_string(i).length());
        maxNamaLength = max(maxNamaLength, (int)karyawan[i].nama.length());
        maxJamKerjaLength = max(maxJamKerjaLength, (int)to_string(karyawan[i].jamKerja).length());
        maxJabatanLength = max(maxJabatanLength, jabatanLength);
        maxGajiLength = max(maxGajiLength, gajiPerJamLength);
        int totalGajiLength = to_string(karyawan[i].jamKerja * jabatan[i].gajiPerJam).length();
        maxTotalLength = max(maxTotalLength, totalGajiLength);
    }

    if (maxJudulNoLength > maxNoLength)
    {
        maxNo = maxJudulNoLength;
    }
    else
    {
        maxNo = maxNoLength;
    }

    if (maxJudulNamaLength > maxNamaLength)
    {
        maxNama = maxJudulNamaLength;
    }
    else
    {
        maxNama = maxNamaLength;
    }

    if (maxJudulJamLength > maxJamKerjaLength)
    {
        maxJamKerja = maxJudulJamLength;
    }
    else
    {
        maxJamKerja = maxJamKerjaLength;
    }

    if (maxJudulGajiLength > maxGajiLength)
    {
        maxGaji = maxJudulGajiLength;
    }
    else
    {
        maxGaji = maxGajiLength;
    }

    if (maxJudulJabatanLength > maxJabatanLength)
    {
        maxJabatan = maxJudulJabatanLength;
    }
    else
    {
        maxJabatan = maxJabatanLength;
    }

    if (maxJudulTotalLength > maxTotalLength)
    {
        maxTotal = maxJudulTotalLength;
    }
    else
    {
        maxTotal = maxTotalLength;
    }

    // Menampilkan garis atas tabel
    cout << "+" << string(maxNo + 2, '=') << "+" << string(maxNama + 2, '=') << "+" << string(maxJamKerja + 2, '=') << "+" << string(maxJabatan + 2, '=') << "+" << string(maxGaji + 2, '=') << "+" << string(maxTotal + 2, '=') << "+" << endl;

    // Menampilkan judul tabel dengan lebar sesuai lebar maksimum kolom pada satu baris
    cout << "|" << left << setw(maxNo + 2) << "No"
         << "|" << setw(maxNama + 2) << "Nama"
         << "|" << setw(maxJamKerja + 2) << "Jam Kerja"
         << "|" << setw(maxJabatan + 2) << "Jabatan"
         << "|" << setw(maxGaji + 2) << "Gaji Per Jam"
         << "|" << setw(maxTotal + 2) << "Total Gaji"
         << "|" << endl;

    // Menampilkan baris pembatas antara judul dan isi tabel
    cout << "+" << string(maxNo + 2, '=') << "+" << string(maxNama + 2, '=') << "+" << string(maxJamKerja + 2, '=') << "+" << string(maxJabatan + 2, '=') << "+" << string(maxGaji + 2, '=') << "+" << string(maxTotal + 2, '=') << "+" << endl;

    // Menampilkan isi tabel dengan lebar sesuai lebar maksimum kolom pada satu baris
    for (int i = 1; i < idxKaryawan; i++)
    {
        string posisiJabatan;
        int gajiPerJam;
        for (int j = 1; j < idxJabatan; j++)
        {
            if (karyawan[i].jabatan == jabatan[j].id)
            {
                posisiJabatan = jabatan[j].posisi;
                gajiPerJam = jabatan[j].gajiPerJam;
                break;
            }
        }
        int totalGaji = karyawan[i].jamKerja * gajiPerJam;
        cout << "|" << left << setw(maxNo + 2) << i << "|"
             << setw(maxNama + 2) << karyawan[i].nama << "|"
             << setw(maxJamKerja + 2) << karyawan[i].jamKerja << "|"
             << setw(maxJabatan + 2) << posisiJabatan << "|"
             << setw(maxGaji + 2) << gajiPerJam << "|"
             << setw(maxTotal + 2) << totalGaji << "|"
             << endl;
    }

    // Menampilkan garis bawah tabel
    cout << "+" << string(maxNo + 2, '=') << "+" << string(maxNama + 2, '=') << "+" << string(maxJamKerja + 2, '=') << "+" << string(maxJabatan + 2, '=') << "+" << string(maxGaji + 2, '=') << "+" << string(maxTotal + 2, '=') << "+" << endl;
}

void createKaryawan()
{
    int piljabatan;
    ofstream file;
    file.open("karyawan.csv", ios::out | ios::app);

    Karyawan newKaryawan;
    cout << "Masukkan Nama : ";
    cin.ignore();
    getline(cin, newKaryawan.nama);

    cout << "Masukkan Password : ";
    cin >> newKaryawan.password;

    while (true)
    {
        cout << "Masukkan Jam Kerja : ";
        cin >> newKaryawan.jamKerja;

        if (cin.fail() || newKaryawan.jamKerja < 0)
        {
            cin.clear();
            cin.ignore();
            cout << "Inputan harus berupa angka." << endl;
        }
        else
        {
            break;
        }
    }

    showJabatan();
    while (true)
    {
        cout << "Masukkan pilihan jabatan : ";
        cin >> piljabatan;

        if (cin.fail() || piljabatan < 1 || piljabatan > idxJabatan)
        {
            cin.clear();
            cin.ignore();
            cout << "Nomor jabatan tidak valid. Masukkan nomor jabatan yang tersedia." << endl;
        }
        else
        {
            newKaryawan.jabatan = piljabatan + 1;
            break;
        }
    }

    file << newKaryawan.nama << ",";
    file << newKaryawan.password << ",";
    file << newKaryawan.jabatan << ",";
    file << newKaryawan.jamKerja << "\n";
    file.close();

    cout << "Data karyawan berhasil ditambahkan." << endl;
}

void updateKaryawan(string theUpdate)
{
    int IdxUpdateGaji = -1;
    if (theUpdate == "nama")
    {
        cout << "UPDATE NAMA" << endl;
        cout << "Masukkan nomor data karyawan yang ingin di update : ";
        cin >> IdxUpdateGaji;
    }
    else if (theUpdate == "jamKerja")
    {
        cout << "UPDATE Jam Kerja" << endl;
        cout << "Masukkan nomor data karyawan yang ingin di update : ";
        cin >> IdxUpdateGaji;
    }
    else if (theUpdate == "jabatan")
    {
        cout << "UPDATE Jabatan" << endl;
        cout << "Masukkan nomor data karyawan yang ingin di update : ";
        cin >> IdxUpdateGaji;
    }
    else
    {
        cout << "Inputan tidak tersedia" << endl;
    }
    if (IdxUpdateGaji >= 1 && IdxUpdateGaji < idxKaryawan)
    {
        if (theUpdate == "nama")
        {
            cout << "Masukkan Nama baru : ";
            cin.ignore();
            getline(cin, karyawan[IdxUpdateGaji].nama);
        }
        else if (theUpdate == "jamKerja")
        {
            cout << "Masukkan Jam Kerja baru : ";
            cin >> karyawan[IdxUpdateGaji].jamKerja;
        }
        else if (theUpdate == "jabatan")
        {
            int noJab;
            showJabatan();
            cout << "Masukkan Nomor Jabatan baru : ";
            cin >> noJab;
            karyawan[IdxUpdateGaji].jabatan = noJab + 1;
        }
        else
        {
            cout << "Inputan tidak tersedia" << endl;
        }

        // Menulis kembali data ke file dengan mode trunc
        ofstream file;
        file.open("karyawan.csv", ios::out | ios::trunc);
        for (int i = 0; i < idxKaryawan; i++)
        {
            file << karyawan[i].nama << ",";
            file << karyawan[i].password << ",";
            file << karyawan[i].jabatan << ",";
            file << karyawan[i].jamKerja << "\n";
        }
        file.close();
        cout << "Berhasil Update" << endl;
    }
    else
    {
        cout << "Nomor indeks tidak valid." << endl;
    }
}

void deleteKaryawan()
{
    int idxDeleteKaryawan = -1;
    cout << "HAPUS DATA KARYAWAN" << endl;
    cout << "Masukkan nomor data karyawan yang ingin dihapus : ";
    cin >> idxDeleteKaryawan;

    if (idxDeleteKaryawan >= 1 && idxDeleteKaryawan < idxKaryawan)
    {
        for (int i = idxDeleteKaryawan; i < idxKaryawan; i++)
        {
            karyawan[i] = karyawan[i + 1];
        }
        idxKaryawan--;

        // Menulis kembali data ke file dengan mode trunc
        ofstream file;
        file.open("karyawan.csv", ios::out | ios::trunc);
        for (int i = 0; i < idxKaryawan; i++)
        {
            file << karyawan[i].nama << ",";
            file << karyawan[i].password << ",";
            file << karyawan[i].jabatan << ",";
            file << karyawan[i].jamKerja << "\n";
        }
        file.close();
        cout << "Berhasil menghapus data karyawan" << endl;
    }
    else
    {
        cout << "Nomor indeks tidak valid." << endl;
    }
}

void menuCrudKaryawan()
{
    int Menucrud;
    while (true)
    {
        // Menampilkan garis atas tabel
        cout << "+" << string(31, '=') << "+" << endl;

        cout << "|" << setw(31) << "=== MENU MANAJEMEN KARYAWAN ==="
             << "|" << endl;

        // Menampilkan garis pembatas antara judul dan isi menu
        cout << "+" << string(31, '=') << "+" << endl;

        // Menampilkan isi menu
        cout << "| " << left << setw(30) << "1. Tambah data karyawan"
             << "|" << endl;
        cout << "| " << left << setw(30) << "2. Tampilkan data karyawan"
             << "|" << endl;
        cout << "| " << left << setw(30) << "3. Perbarui data karyawan"
             << "|" << endl;
        cout << "| " << left << setw(30) << "4. Hapus data karyawan"
             << "|" << endl;
        cout << "| " << left << setw(30) << "5. Keluar"
             << "|" << endl;

        // Menampilkan garis bawah tabel
        cout << "+" << string(31, '=') << "+" << endl;
        cout << "Pilih menu (Number only) : ";
        cin >> Menucrud;
        // ERROR HANDLING
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Input salah." << endl;
            continue;
            // CREATE
        }
        else if (Menucrud == 1)
        {
            createKaryawan();
            showKaryawan();
            // READ
        }
        else if (Menucrud == 2)
        {
            showKaryawan();
            // UPDATE
        }
        else if (Menucrud == 3)
        {
            int MenuUpdate;
            while (true)
            {
                // Menampilkan garis atas tabel
                cout << "+" << string(21, '=') << "+" << endl;

                cout << "|" << setw(21) << "===  MENU UPDATE  ==="
                     << "|" << endl;

                // Menampilkan garis pembatas antara judul dan isi menu
                cout << "+" << string(21, '=') << "+" << endl;

                // Menampilkan isi menu update
                cout << "| " << left << setw(20) << "1. Update Nama"
                     << "|" << endl;
                cout << "| " << left << setw(20) << "2. Update Jam Kerja"
                     << "|" << endl;
                cout << "| " << left << setw(20) << "3. Update Jabatan"
                     << "|" << endl;
                cout << "| " << left << setw(20) << "4. Keluar"
                     << "|" << endl;

                // Menampilkan garis bawah tabel
                cout << "+" << string(21, '=') << "+" << endl;
                cout << "Pilih menu (Number only) : ";
                cin >> MenuUpdate;
                // ERROR HANDLING
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Input salah." << endl;
                    continue;
                    // UPDATE NAMA
                }
                else if (MenuUpdate == 1)
                {
                    showKaryawan();
                    updateKaryawan("nama");
                    showKaryawan();
                    // UPDATE JAM KERJA
                }
                else if (MenuUpdate == 2)
                {
                    showKaryawan();
                    updateKaryawan("jamKerja");
                    showKaryawan();
                    // UPDATE JABATAN
                }
                else if (MenuUpdate == 3)
                {
                    showKaryawan();
                    updateKaryawan("jabatan");
                    showKaryawan();
                }
                else if (MenuUpdate == 4)
                {
                    string Lanjut = Continue("lanjut");
                    if (Lanjut == "y")
                    {
                        break;
                    }
                    else
                    {
                        cout << "\n===MENUTUP PROGRAM===" << endl;
                        exit(0);
                    }
                    // ERROR HANDLING
                }
                else
                {
                    cout << "Menu tidak ada, pastikan kembali pilihan anda";
                }
            }
            // DELETE
        }
        else if (Menucrud == 4)
        {
            showKaryawan();
            deleteKaryawan();
            showKaryawan();
            // KELUAR
        }
        else if (Menucrud == 5)
        {
            string Lanjut = Continue("lanjut");
            if (Lanjut == "y")
            {
                break;
            }
            else
            {
                cout << "\n===MENUTUP PROGRAM===" << endl;
                exit(0);
            }
            // ERROR HANDLING
        }
        else
        {
            cout << "Menu tidak ada, pastikan kembali pilihan anda" << endl;
        }
    }
}

void menuCrudJabatan()
{
    int MenuAdmin;
    while (true)
    {
        // Menampilkan garis atas tabel
        cout << "+" << string(30, '=') << "+" << endl;

        cout << "|" << setw(30) << "=== MENU MANAJEMEN JABATAN ==="
             << "|" << endl;

        // Menampilkan garis pembatas antara judul dan isi menu
        cout << "+" << string(30, '=') << "+" << endl;

        // Menampilkan isi menu
        cout << "| " << left << setw(29) << "1. Tambah data jabatan"
             << "|" << endl;
        cout << "| " << left << setw(29) << "2. Tampilkan data jabatan"
             << "|" << endl;
        cout << "| " << left << setw(29) << "3. Perbarui data jabatan"
             << "|" << endl;
        cout << "| " << left << setw(29) << "4. Hapus data jabatan"
             << "|" << endl;
        cout << "| " << left << setw(29) << "5. Keluar"
             << "|" << endl;

        // Menampilkan garis bawah tabel
        cout << "+" << string(30, '=') << "+" << endl;
        cout << "Pilih menu (Number only) : ";
        cin >> MenuAdmin;
        // ERROR HANDLING
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Input salah." << endl;
            continue;
            // CREATE
        }
        else if (MenuAdmin == 1)
        {
            createJabatan();
            showJabatan();
            // READ
        }
        else if (MenuAdmin == 2)
        {
            showJabatan();
            // UPDATE
        }
        else if (MenuAdmin == 3)
        {
            int MenuUpdate;
            while (true)
            {
                cout << "+" << string(25, '=') << "+" << endl;

                cout << "|" << setw(25) << "===    MENU UPDATE    ==="
                     << "|" << endl;

                // Menampilkan garis pembatas antara judul dan isi menu
                cout << "+" << string(25, '=') << "+" << endl;

                // Menampilkan isi menu update
                cout << "| " << left << setw(24) << "1. Update Jabatan"
                     << "|" << endl;
                cout << "| " << left << setw(24) << "2. Update Gaji Per Jam"
                     << "|" << endl;
                cout << "| " << left << setw(24) << "3. Keluar"
                     << "|" << endl;

                // Menampilkan garis bawah tabel
                cout << "+" << string(25, '=') << "+" << endl;
                cout << "Pilih menu (Number only) : ";
                cin >> MenuUpdate;
                // ERROR HANDLING
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Input salah." << endl;
                    continue;
                    // UPDATE NAMA JABATAN
                }
                else if (MenuUpdate == 1)
                {
                    showJabatan();
                    updateJabatan("nama");
                    showJabatan();
                    // UPDATE GAJI PER JAM
                }
                else if (MenuUpdate == 2)
                {
                    showJabatan();
                    updateJabatan("gaji");
                    showJabatan();
                    // KELUAR
                }
                else if (MenuUpdate == 3)
                {
                    string Lanjut = Continue("lanjut");
                    if (Lanjut == "y")
                    {
                        break;
                    }
                    else
                    {
                        cout << "\n===MENUTUP PROGRAM===" << endl;
                        exit(0);
                    }
                    // ERROR HANDLING
                }
                else
                {
                    cout << "Menu tidak ada, pastikan kembali pilihan anda";
                }
            }
            // DELETE
        }
        else if (MenuAdmin == 4)
        {
            showJabatan();
            deleteJabatan();
            showJabatan();
            // KELUAR
        }
        else if (MenuAdmin == 5)
        {
            string Lanjut = Continue("lanjut");
            if (Lanjut == "y")
            {
                break;
            }
            else
            {
                cout << "\n===MENUTUP PROGRAM===" << endl;
                exit(0);
            }
            // ERROR HANDLING
        }
        else
        {
            cout << "Menu tidak ada, pastikan kembali pilihan anda" << endl;
        }
    }
}

// LOWER HURUF
string lower(string str)
{
    for (char &c : str)
    {
        c = tolower(c);
    }
    return str;
}

// SORTING HURUF ASCENDING
void Selectionsortas()
{
    int i, j, MinIdx;
    for (int i = 0; i < idxKaryawan - 1; i++)
    {
        MinIdx = i;
        for (j = i + 1; j < idxKaryawan; j++)
        {
            if (lower(karyawan[j].nama) < lower(karyawan[MinIdx].nama))
            {
                MinIdx = j;
            }
        }
        if (MinIdx != i)
        {
            swap(karyawan[i], karyawan[MinIdx]);
        }
    }
}

void Selectionsortdes()
{
    int i, j, MinIdx;
    for (int i = 0; i < idxKaryawan - 1; i++)
    {
        MinIdx = i;
        for (j = i + 1; j < idxKaryawan; j++)
        {
            if (lower(karyawan[j].nama) > lower(karyawan[MinIdx].nama))
            {
                MinIdx = j;
            }
        }
        if (MinIdx != i)
        {
            swap(karyawan[i], karyawan[MinIdx]);
        }
    }
}

int gajikaryawan(Karyawan karyawan, Posisi jabatan[])
{
    string posisiJabatan;
    for (int i = 0; i < idxKaryawan; i++)
    {
        for (int j = 0; j < idxJabatan; j++)
        {
            if (karyawan.jabatan == jabatan[j].id)
            {
                posisiJabatan = jabatan[j].posisi;
                break;
            }
        }
    }
    for (int k = 0; k < idxJabatan; k++)
    {
        if (posisiJabatan == jabatan[k].posisi)
        {
            return karyawan.jamKerja * jabatan[k].gajiPerJam;
        }
    }
    return 0;
}

void insertionsortas(Karyawan karyawan[], Posisi jabatan[])
{
    for (int i = 1; i < idxKaryawan; i++)
    {
        Karyawan key = karyawan[i];
        int j = i - 1;
        int keytotalgaji = gajikaryawan(key, jabatan);
        while (j >= 0 && gajikaryawan(karyawan[j], jabatan) > keytotalgaji)
        {
            karyawan[j + 1] = karyawan[j];
            j = j - 1;
        }
        karyawan[j + 1] = key;
    }
}

void insertionsortdes(Karyawan karyawan[], Posisi jabatan[])
{
    for (int i = 1; i < idxKaryawan; i++)
    {
        Karyawan key = karyawan[i];
        int j = i - 1;
        int keytotalgaji = gajikaryawan(key, jabatan);
        while (j >= 0 && gajikaryawan(karyawan[j], jabatan) < keytotalgaji)
        {
            karyawan[j + 1] = karyawan[j];
            j = j - 1;
        }
        karyawan[j + 1] = key;
    }
}

void Sorting()
{
    while (true)
    {
        int menusort;
        cout << "\n===MENU SORTING===" << endl;
        cout << "1. Sorting nama ascending" << endl;
        cout << "2. Sorting nama descending" << endl;
        cout << "3. Sorting gaji ascending" << endl;
        cout << "4. Sorting gaji descending" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu sorting : ";
        cin >> menusort;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Input salah." << endl;
            continue;
        }
        else if (menusort == 1)
        {
            Selectionsortas();
            cout << "=DATA GAJI KARYAWAN NAMA TERURUT ASCENDING=" << endl;
            cout << "---------------------------------------" << endl;
            showKaryawan();
        }
        else if (menusort == 2)
        {
            Selectionsortdes();
            cout << "=DATA GAJI KARYAWAN NAMA TERURUT DESCENDING=" << endl;
            cout << "---------------------------------------" << endl;
            showKaryawan();
        }
        else if (menusort == 3)
        {
            insertionsortas(karyawan, jabatan);
            cout << "=DATA GAJI KARYAWAN GAJI TERURUT ASCENDING=" << endl;
            cout << "---------------------------------------" << endl;
            showKaryawan();
        }
        else if (menusort == 4)
        {
            insertionsortdes(karyawan, jabatan);
            cout << "=DATA GAJI KARYAWAN GAJI TERURUT DESCENDING=" << endl;
            cout << "---------------------------------------" << endl;
            showKaryawan();
        }
        else if (menusort == 5)
        {
            string Lanjut = Continue("lanjut");
            if (Lanjut == "y")
            {
                break;
            }
            else
            {
                cout << "\n===MENUTUP PROGRAM===" << endl;
                exit(0);
            }
        }
        else
        {
            cout << "silahkan pilih menu yang tersedia" << endl;
        }
    }
}

int BinarySearch(Karyawan karyawan[], int p, int q, string x)
{
    while (p <= q)
    {
        int mid = p + (q - p) / 2;
        if (karyawan[mid].nama == x)
        {
            return mid;
        }
        if (karyawan[mid].nama < x)
        {
            p = mid + 1;
        }
        else
        {
            q = mid - 1;
        }
    }
    return -1;
}

void Searching()
{
    while (true)
    {
        int menusearch;
        cout << "\n===MENU SEARCHING===" << endl;
        cout << "1. Searching Karyawan" << endl;
        cout << "2. Keluar" << endl;
        cout << "Pilih menu pencarian : ";
        cin >> menusearch;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Input salah." << endl;
            continue;
        }
        else if (menusearch == 1)
        {
            string search;
            int pos;
            cout << "\n=SEARCHING KARYAWAN=" << endl;
            cout << "-----------------------------" << endl;
            Selectionsortas();
            cout << "Cari Nama : ";
            cin >> search;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Input salah." << endl;
                continue;
            }
            pos = BinarySearch(karyawan, 0, idxKaryawan, search);
            if (pos != -1)
            {
                string posisiJabatan;
                int gajiPerJam = 0;
                for (int j = 0; j < idxJabatan; j++)
                {
                    if (karyawan[pos].jabatan == jabatan[j].id)
                    {
                        posisiJabatan = jabatan[j].posisi;
                        gajiPerJam = jabatan[j].gajiPerJam;
                        break;
                    }
                }
                int totalGaji = karyawan[pos].jamKerja * gajiPerJam;

                // Menentukan lebar kolom yang diperlukan
                int maxNo = max((int)to_string(pos).length(), (int)strlen("No"));
                int maxNama = max((int)karyawan[pos].nama.length(), (int)strlen("Nama"));
                int maxJamKerja = max((int)to_string(karyawan[pos].jamKerja).length(), (int)strlen("Jam Kerja"));
                int maxJabatan = max((int)posisiJabatan.length(), (int)strlen("Jabatan"));
                int maxGaji = max((int)to_string(gajiPerJam).length(), (int)strlen("Gaji Per Jam"));
                int maxTotal = max((int)to_string(totalGaji).length(), (int)strlen("Total Gaji"));

                // Menampilkan tabel
                cout << "+" << string(maxNo + 2, '=') << "+" << string(maxNama + 2, '=') << "+" << string(maxJamKerja + 2, '=') << "+" << string(maxJabatan + 2, '=') << "+" << string(maxGaji + 2, '=') << "+" << string(maxTotal + 2, '=') << "+" << endl;
                cout << "|" << left << setw(maxNo + 2) << "No"
                     << "|" << setw(maxNama + 2) << "Nama"
                     << "|" << setw(maxJamKerja + 2) << "Jam Kerja"
                     << "|" << setw(maxJabatan + 2) << "Jabatan"
                     << "|" << setw(maxGaji + 2) << "Gaji Per Jam"
                     << "|" << setw(maxTotal + 2) << "Total Gaji"
                     << "|" << endl;
                cout << "+" << string(maxNo + 2, '=') << "+" << string(maxNama + 2, '=') << "+" << string(maxJamKerja + 2, '=') << "+" << string(maxJabatan + 2, '=') << "+" << string(maxGaji + 2, '=') << "+" << string(maxTotal + 2, '=') << "+" << endl;
                cout << "|" << left << setw(maxNo + 2) << pos
                     << "|" << setw(maxNama + 2) << karyawan[pos].nama
                     << "|" << setw(maxJamKerja + 2) << karyawan[pos].jamKerja
                     << "|" << setw(maxJabatan + 2) << posisiJabatan
                     << "|" << setw(maxGaji + 2) << gajiPerJam
                     << "|" << setw(maxTotal + 2) << totalGaji << "|" << endl;
                cout << "+" << string(maxNo + 2, '=') << "+" << string(maxNama + 2, '=') << "+" << string(maxJamKerja + 2, '=') << "+" << string(maxJabatan + 2, '=') << "+" << string(maxGaji + 2, '=') << "+" << string(maxTotal + 2, '=') << "+" << endl;
            }
            else
            {
                cout << "\nKaryawan bernama " << search << " tidak ditemukan" << endl;
            }
        }
        else if (menusearch == 2)
        {
            string Lanjut = Continue("lanjut");
            if (Lanjut == "y")
            {
                break;
            }
            else
            {
                cout << "\n===MENUTUP PROGRAM===" << endl;
                exit(0);
            }
        }
        else
        {
            cout << "silahkan pilih menu yang tersedia" << endl;
        }
    }
}

int main()
{
    readKaryawan();
    int MenuAdmin;
    if (login())
    {
        if (loggedInUser == "Admin")
        {
            while (true)
            {
                cout << "+" << string(46, '=') << "+" << endl;

                cout << "|" << setw(46) << "==========        MENU ADMIN        =========="
                     << "|" << endl;

                // Menampilkan garis pembatas antara judul dan isi menu
                cout << "+" << string(46, '=') << "+" << endl;

                // Menampilkan isi menu admin
                cout << "| " << left << setw(45) << "1. Manajemen Data Karyawan"
                     << "|" << endl;
                cout << "| " << left << setw(45) << "2. Manajemen Data Gaji Jabatan"
                     << "|" << endl;
                cout << "| " << left << setw(45) << "3. Tampilan sorting data gaji karyawan"
                     << "|" << endl;
                cout << "| " << left << setw(45) << "4. Searching Data Gaji karyawan"
                     << "|" << endl;
                cout << "| " << left << setw(45) << "5. Keluar"
                     << "|" << endl;

                // Menampilkan garis bawah tabel
                cout << "+" << string(46, '=') << "+" << endl;
                cout << "Pilih menu admin (Number only) : ";
                cin >> MenuAdmin;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Input salah." << endl;
                    continue;
                }
                else if (MenuAdmin == 1)
                {
                    menuCrudKaryawan();
                }
                else if (MenuAdmin == 2)
                {
                    menuCrudJabatan();
                }
                else if (MenuAdmin == 3)
                {
                    Sorting();
                }
                else if (MenuAdmin == 4)
                {
                    Searching();
                }
                else if (MenuAdmin == 5)
                {
                    string Lanjut = Continue("stop");
                    if (Lanjut == "y")
                    {
                        cout << "\n===MENUTUP PROGRAM===" << endl;
                        exit(0);
                    }
                    else
                    {
                        true;
                    }
                }
                else
                {
                    cout << "silahkan pilih menu yang tersedia" << endl;
                }
            }
        }
        else
        {
            SlipGaji(userData);
            // break;
        }
    }
    delete userData;
    return 0;
}