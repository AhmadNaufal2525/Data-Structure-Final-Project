#ifndef PC_H_INCLUDED
#define PC_H_INCLUDED
#include <iostream>

#include <iostream>
using namespace std;

#define info(Q) (Q)->info
#define next(Q) (Q)->next
#define first(L) (L).first
#define nextChild(J) (J)->nextChild

struct child{
    string nama_Lengkap;
    string nik;
    string tanggal_Lahir;
    string tempat_Lahir;
    string status;
};

typedef child infotypeCh;

typedef struct elmParent *adrParent;
typedef struct elmChild *adrChild;

struct parent{
    string nomor_KK;
};

struct elmParent{
    parent info;
    adrParent next;
    adrChild nextChild;
};

struct elmChild{
    infotypeCh info;
    adrChild next;
};

struct List{
    adrParent first;
};

void create_List(List &ListChild);
void newElm_Parent(parent info, adrParent &S);
void newElm_Child(infotypeCh info, adrChild &J);

void insertNew_Child(List &ListParent, adrParent S, adrChild J);
void inserLast_Parent(List &ListParent, adrParent S);

void deleteFirst_Child(List &ListParent, adrParent &S, adrChild &J);
void deleteLast_Child(List &ListChild, adrParent &S, adrChild &J);
void deleteAfter_Child(List &ListChild, adrChild Prec, adrChild &J);

adrChild searchBefore_Child(List ListParent, string kelas, string nim);

void deleteFirst_Parent(List &ListParent);
void deleteAfter_Parent(adrParent Prec, adrParent P);

adrParent searchBefore_Parent(List ListParent, string nomor_KK);

void showData_Parent(List ListParent);
void showData_Child(List ListParent);
adrParent search_Parent(List ListChild, string nomor_KK);


void cari_Child(List ListParent, string nik);
adrChild search_Child(List ListParent, string nik);

int selectMenu();

#endif // PC_H_INCLUDED
