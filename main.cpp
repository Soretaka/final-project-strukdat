#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mpair make_pair
using namespace std;

void cmdLogn(const char *msg)
{
    cout << msg << endl;
}

void cmdLog(const char *msg)
{
    cout << msg;
}

void welcomeMsg()
{
    cmdLogn("Selamat datang di mesin pengelola nomor NIP pegawai!");
} 

void printTableLine()
{
     cmdLogn("--------------------------------------------------------");
}

void Menu()
{
    cmdLogn("Berikut adalah hal yang dapat anda lakukan:");
    cmdLogn("1. Lihat daftar data pegawai");
    cmdLogn("2. Tambahkan daftar data pegawai");
    cmdLogn("3. Hapus data pegawai");
    cmdLogn("4. Sunting data pegawai");
    cmdLogn("5. Akhiri program");
}

void printVector(vector<pair<string,string>> data)
{
    for (int i = 0 ; i <data.size(); i++){
        cout << '|' << setw(30) << left << data[i].first << setfill(' ') << "|"<< setw(23) << left << data[i].second << '|' <<endl;
        printTableLine();
    }
}

bool sortbyseca(const pair<string,string> &a,const pair<string,string> &b)
{
    return (a.second < b.second);
}

bool sortbysecd(const pair<string,string> &a,const pair<string,string> &b)
{
    return (a.second > b.second);
}

bool sortbyfia(const pair<string,string> &a,const pair<string,string> &b)
{
    return (a.first < b.first);
}

bool sortbyfid(const pair<string,string> &a,const pair<string,string> &b)
{
    return (a.first >b.first);
}

void printDaftar(vector<pair<string,string>> data)
{
    system("cls");
    cmdLogn("Ingin diurut berdasarkan nama atau NIP? (pilih 1 untuk nama, pilih 2 untuk NIP)");
    cmdLog("Pilihan: ");
    int mode;
    cin >> mode;
    cmdLogn("");
    int ascdesc;
    if(mode == 1){
        cmdLog("masukan 1 untuk ascending, masukan 2 untuk descending: ");
        cin >> ascdesc;
        cmdLogn("");
        printTableLine();
        cmdLogn("|           N A M A            |          NIP          |");
        printTableLine();
        if(ascdesc == 1){
            sort(data.begin(),data.end(),sortbyfia);
            printVector(data);
        }else if (ascdesc == 2){
            sort(data.begin(),data.end(),sortbyfid);
            printVector(data);
        }
    }else if (mode == 2){
        cmdLog("masukan 1 untuk ascending, masukan 2 untuk descending: ");
        cin >> ascdesc;
        cmdLogn("");
        printTableLine();
        cmdLogn("|           N A M A            |          NIP          |");
        printTableLine();
        if(ascdesc == 1){
            sort(data.begin(),data.end(),sortbyseca);
            printVector(data);
        }else if (ascdesc==2){
            sort(data.begin(),data.end(),sortbysecd);
            printVector(data);
        }
    }
     system("pause");
}

void tambahDaftar(vector<pair<string,string>> &data){
    string name,nip;
    vector<pair<string,string>>::iterator checkData;
    bool flag = 1;
    while(flag){
        cmdLog("Masukkan nama: ");
        cin >> name;
        cmdLog("Masukkan NIP: ");
        cin >> nip;
        checkData = find(data.begin(),data.end(),make_pair(name,nip));
        if(checkData != data.end()){
            cmdLogn("data sudah ada");
            cmdLogn("Apakah ingin membatalkan? (1 untuk iya, 2 untuk tidak)");
            cmdLog("pilihan: ");
            int choice;
            cin >> choice;
            choice--;
            if(choice == 1){
                continue;
            }else if(choice == 0){
                system("pause");
                return;
            }else{
                cmdLog("ERROR");
                system("pause");
                return;
            }
        }else{
            flag = 0;
        }
    }
    cmdLog("Memasukan data ");
    cout << name;
    cmdLog(" dengan NIP ");
    cout << nip;
    cmdLogn("");
    data.pb(make_pair(name,nip));
    ofstream file;
    file.open("nip.txt",std::ios_base::app);
    if(file.is_open()){
        file << name << endl;
        file << nip << endl;
        file.close();
    }else{
        cmdLogn("File tidak ditemukan");
    }
    system("pause");
}

void hapusDaftar(vector<pair<string,string>> &data){
    string name,nip;
    bool flag = 1;
    vector<pair<string,string>>::iterator checkData;
    while(flag){
        cmdLog("Masukkan nama: ");
        cin >> name;
        cmdLog("Masukkan NIP: ");
        cin >> nip;
        checkData = find(data.begin(),data.end(),make_pair(name,nip));
        if(checkData == data.end()){
            cmdLogn("data tidak ada");
            cmdLogn("Apakah ingin membatalkan? (1 untuk iya, 2 untuk tidak)");
            cmdLog("pilihan: ");
            int choice;
            cin >> choice;
            choice--;
            if(choice == 1){
                continue;
            }else if(choice == 0){
                system("pause");
                return;
            }else{
                cmdLog("ERROR");
                system("pause");
                return;
            }
        }else{
            flag = 0;
        }
    }
    cmdLog("Menghapus data ");
    cout << name;
    cmdLog(" dengan NIP ");
    cout << nip;
    cmdLogn("");
    data.erase(checkData);
    ofstream file;
    file.open("nip.txt");
    if(file.is_open()){
        for(int i = 0 ; i < data.size();i++){
            file << data[i].first << endl;
            file << data[i].second << endl;
        }
        file.close();
    }else{
        cmdLogn("File tidak ditemukan");
    }
    system("pause");
}

void sunting(vector<pair<string,string>> &data){
    string name,nip;
    bool flag = 1;
    vector<pair<string,string>>::iterator checkData;
    while(flag){
        cmdLog("Masukkan nama: ");
        cin >> name;
        cmdLog("Masukkan NIP: ");
        cin >> nip;
        checkData = find(data.begin(),data.end(),make_pair(name,nip));
        if(checkData == data.end()){
            cmdLogn("data tidak ada");
            cmdLogn("Apakah ingin membatalkan? (1 untuk iya, 2 untuk tidak)");
            cmdLog("pilihan: ");
            int choice;
            cin >> choice;
            choice--;
            if(choice == 1){
                continue;
            }else if(choice == 0){
                system("pause");
                return;
            }else{
                cmdLog("ERROR");
                system("pause");
                return;
            }
        }else{
            flag = 0;
        }
    }
    string nametmp,niptmp;
    flag = 1;
    while(flag){
    cmdLog("Masukkan nama pengganti: ");
    cin >> nametmp;
    cmdLog("Masukkan NIP pengganti: ");
    cin >> niptmp;
    vector<pair<string,string>>::iterator checkDataGanti;
    checkDataGanti = find(data.begin(),data.end(),make_pair(nametmp,niptmp));
    if(checkDataGanti != data.end()){
            cmdLogn("data sudah ada");
            cmdLogn("Apakah ingin membatalkan? (1 untuk iya, 2 untuk tidak)");
            cmdLog("pilihan: ");
            int choice;
            cin >> choice;
            choice--;
            if(choice == 1){
                continue;
            }else if(choice == 0){
                system("pause");
                return;
            }else{
                cmdLog("ERROR");
                system("pause");
                return;
            }
        }else{
            flag = 0;
        }
    }
    data.erase(checkData);
    data.insert(checkData,make_pair(nametmp,niptmp));
    ofstream file;
    file.open("nip.txt");
    if(file.is_open()){
        for(int i = 0 ; i < data.size();i++){
            file << data[i].first << endl;
            file << data[i].second << endl;
        }
        file.close();
    }else{
        cmdLogn("File tidak ditemukan");
    }
    cmdLogn ("Data berhasil diganti");
    system("pause");
}

int main()
{
    ifstream file;
    file.open("nip.txt");
    vector <pair<string,string>> data;
    if(file.is_open()){
        string name;
        string nip;
        string tmp;
        int counter = 0;
        while(getline(file,tmp)){
            if(counter%2 == 0){
                name = tmp;
            }else{
                nip = tmp;
                data.pb(mpair(name,nip));
            }
            counter++;
        }
        file.close();
    }else{
        cmdLogn("File tidak ditemukan");
        return 0;
    }
    welcomeMsg();
    system("pause");
    bool run = 1;
    while(run){
        system("cls");
        Menu();
        int com;
        cin >> com;
        switch (com){
        case 1:
            printDaftar(data);
            break;

        case 2:
            tambahDaftar(data);
            break;

        case 3:
            hapusDaftar(data);
            break;

        case 4:
            sunting(data);
            break;

        case 5:
            run = 0;
            cmdLogn("Mengakhiri program");
            break;

        default:
            cmdLogn("Terjadi suatu kesalahan");
            run = 0;
            break;
        }
    }
}