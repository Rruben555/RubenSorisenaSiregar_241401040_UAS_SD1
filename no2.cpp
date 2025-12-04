#include <iostream>
#include <algorithm> // untuk sort()
#include <math.h>    // untuk floor()
#include <ctime>

using namespace std;

int main(){
    int N;
    bool status[200];
    bool called[200];
    int random;
    srand(time(0));
    for (int i = 0; i < 200; i++) {
        status[i]=1;
    }

    cout << "Masukkan jumlah tersedia: ";
    cin >> N;

    int tersedia[N];
    for (int i = 0; i < N; i++) {
        tersedia[i]=rand() % 201;
    }

    // Urutkan tersedia ascending agar bisa digunakan untuk Interpolation Search
    sort(tersedia, tersedia + N);

    cout << "\nKursu setelah diurutkan: ";
    for (int i = 0; i < N; i++) {
        cout << tersedia[i] << " ";
    }
    cout << endl;

    int cari;
    cout << "\nMasukkan kursi yang ingin dicari: ";
    cin >> cari;

    int low = 0, high = N - 1, flag = 0;
    int posisi;
    float posisi1;

    // Proses Interpolation Search
    while(low<=high && cari>=tersedia[low] && cari<=tersedia[high]){
        posisi1=(float)(cari-tersedia[low])/(tersedia[high]-tersedia[low]) *(high-low) + low;
        posisi=floor(posisi1);
        if(tersedia[posisi]==cari){
            flag=1;
            break;
        }

        if(tersedia[posisi]>cari) high=posisi-1;
        if(tersedia[posisi]<cari) low=posisi+1;

    }
    

    cout << "Pencari kursi no-" << posisi << endl;
    if (flag == 1) cout<<"STATUS: TERSEDIA";
    else{
        if (status[posisi]==0){
            cout<<"Status: TIDAK TERSEDIA\n";
            int dekat=abs(tersedia[0]-posisi);
            int terdekat=tersedia[0];

            for (int i=1; i<N; i++){
                int tesdekat=abs(tersedia[i]-posisi);
                if(tesdekat<dekat) terdekat=tersedia[i];
            }
            cout<<"Kursi terdekat: "<<terdekat;
        }
    }
    return 0;
}