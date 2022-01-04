#include "PC.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
    List L;
    parent P;
    infotypeCh C;
    adrParent S, precPr;
    adrChild J, precCh;

    int pilihan, x;
    string yesOrno;

    create_List(L);

    pilihan = selectMenu();

    while (pilihan != 0) {
        switch (pilihan){
            case 1:
                {
                string input;
                cout << "Masukkan Nomor Kartu Keluarga : ";
                cin >> input;
                P.nomor_KK = input;
                newElm_Parent(P, S);
                inserLast_Parent(L, S);
                cout << "===========================" << endl;
                cout << "Kelas Berhasil Ditambah" << endl;
                cout << "===========================" << endl;
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }

            case 2:
                {
                string nama_lengkap, nik, tgl_Lahir, tempat_lahir, status, nomor_kk;
                cout << "Masukkan Nomor Kartu Keluarga baru : ";
                cin >> nomor_kk;
                S = search_Parent(L, nomor_kk);
                if (S != NULL){
                    cout << "Masukkan Data Keluarga baru" << endl;
                    cout << "Nama Lengkap : ";
                    cin >> nama_lengkap;
                    cout << "NIK : ";
                    cin >> nik;
                    cout << "Tanggal Lahir : ";
                    cin >> tgl_Lahir;
                    cout << "Tempat Lahir : ";
                    cin >> tempat_lahir;
                    cout << "Status : ";
                    cin >> status;
                    C.nama_Lengkap = nama_lengkap;
                    C.nik = nik;
                    C.tanggal_Lahir = tgl_Lahir;
                    C.tempat_Lahir = tempat_lahir;
                    C.status = status;

                    newElm_Child(C,J);
                    insertNew_Child(L,S,J);
                    cout << "===============================" << endl;
                    cout << "Anggota keluarga Berhasil Di Tambah" << endl;
                    cout << "===============================" << endl;
                } else if (S == NULL){
                    cout << "===============================" << endl;
                    cout << "Nomor Kartu Keluarga Tidak Ditemukan" << endl;
                    cout << "===============================" << endl;
                }
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }

            case 3:
                {
                showData_Parent(L);
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }

            case 4:
                {
                showData_Child(L);
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }

            case 5:
                {
                string nomor_KK;
                cout << "Masukkan Nomor Kartu Keluarga Yang Ingin Di Hapus : ";
                cin >> nomor_KK;
                adrParent p;
                p = first(L);
                if (p == NULL){
                    cout << "===================================" << endl;
                    cout << "Nomor Kartu Keluarga Tidak Ditemukan" << endl;
                    cout << "===================================" << endl;
                }else if (info(p).nomor_KK == nomor_KK){
                    deleteFirst_Parent(L);
                    cout << "===================================" << endl;
                    cout << "Nomor kartu keluarga:  " << info(p).nomor_KK << " Berhasil DiHapus" << endl;
                    cout << "===================================" << endl;
                }else if (next(p)!=NULL){
                    precPr = searchBefore_Parent(L, nomor_KK);
                    deleteAfter_Parent(precPr, S);
                    cout << "===================================" << endl;
                    cout << "Nomor Kartu Keluarga " << info(p).nomor_KK << " Berhasil DiHapus" << endl;
                    cout << "===================================" << endl;
                }else{
                    cout << "===================================" << endl;
                    cout << "NOMOR KARTU KELUARGA " << nomor_KK << " TIDAK DI TEMUKAN" << endl;
                    cout << "===================================" << endl;
                }
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }

            case 6:
                {
                string nomor_KK, nik;
                cout << "Masukkan nomor kartu keluarga baru: ";
                cin >> nomor_KK;
                cout << "Masukkan NIK Yang Ingin Di Hapus : ";
                cin >> nik;
                adrChild c;
                adrParent P;
                P = first(L);
                if (P == NULL){
                    cout << "======================" << endl;
                    cout << "Nomor Kartu Keluarga Tidak Ada" << endl;
                    cout << "======================" << endl;
                }
                while (P != NULL){
                    adrChild Q = nextChild(P);
                    if (info(P).nomor_KK == nomor_KK){
                        if (info(Q).nik==nik){
                            deleteFirst_Child(L, P, J);
                            cout << "======================" << endl;
                            cout << "Nama : " << info(Q).nama_Lengkap << endl;
                            cout << "NIK  : " << info(Q).nik << endl;
                            cout << "Tanggal Lahir  : " << info(Q).tanggal_Lahir << endl;
                            cout << "Tempat Lahir  : " << info(Q).tempat_Lahir << endl;
                            cout << "Status  : " << info(Q).status << endl;
                            cout << "======================" << endl;
                            cout << "DATA BERHASIL DIHAPUS" << endl;
                            cout << "======================" << endl;
                        }else if (next(Q)!= NULL){
                            precCh = searchBefore_Child(L, nomor_KK, nik);
                            deleteAfter_Child(L, precCh, J);
                            cout << "======================" << endl;
                            cout << "Nama : " << info(Q).nama_Lengkap << endl;
                            cout << "NIK  : " << info(Q).nik << endl;
                            cout << "Tanggal Lahir  : " << info(Q).tanggal_Lahir << endl;
                            cout << "Tempat Lahir  : " << info(Q).tempat_Lahir << endl;
                            cout << "Status  : " << info(Q).status << endl;
                            cout << "======================" << endl;
                            cout << "DATA BERHASIL DIHAPUS" << endl;
                            cout << "======================" << endl;
                        }else{
                            cout << "NIK TIDAK DITEMUKAN" << endl;
                        }
                    }

                    P = next(P);

                }
            }

            case 7:
                {
                string nik;
                cout << "Masukkan Nomor Induk Keluarga Yang Ingin Di Cari: ";
                cin >> nik;
                cari_Child(L, nik);
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }
        }
        pilihan = selectMenu();
    }

    cout << "ANDA TELAH KELUAR DARI PROGRAM KARTU KELUARGA" << endl << endl;
    return 0;
}
