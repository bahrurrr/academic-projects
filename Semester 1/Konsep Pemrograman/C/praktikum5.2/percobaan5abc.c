#include <stdio.h>

float konversi(float, char, char);
int main(){
    float suhu, hasil;
    char asal, tujuan;
    printf ("masukkan suhu sumber : ");
    scanf ("%f", &suhu);
    printf ("masukkan satuan asal(C, F, R) : ");
    scanf (" %c", &asal);
    printf ("masukkan satuan tujuan(C, F, R) : ");
    scanf (" %c", &tujuan);
    
    hasil = konversi (suhu, asal, tujuan);
    if (hasil == -9999)
    puts ("input error");
    else
    printf ("hasil konversi suhu %.2f %c = %.2f %c", suhu, asal, hasil, tujuan);
}
float konversi(float suhu, char asal, char tujuan){
    float hasil;
    if ((asal == 'C' || asal == 'c') && (tujuan == 'F' || tujuan == 'f')){
        hasil = (9.0 / 5) * suhu + 32;
        return hasil;
    }
    else if ((asal == 'C' || asal == 'c') && (tujuan == 'R' || tujuan == 'r')){
        hasil = (4.0 / 5) * suhu;
        return hasil;
    }
    else if ((asal == 'F' || asal == 'f') && (tujuan == 'C' || tujuan == 'c')){
        hasil = (5.0 / 9) * (suhu - 32);
        return hasil;
    }
    else if ((asal == 'F' || asal == 'f') && (tujuan == 'R' || tujuan == 'r')){
        hasil = (4.0 / 9) * (suhu - 32);
        return hasil;
    }
    else if ((asal == 'R' || asal == 'r') && (tujuan == 'C' || tujuan == 'c')){
        hasil = (5.0 / 4) * suhu;
        return hasil;
    }
    else if ((asal == 'R' || asal == 'r') && (tujuan == 'F' || tujuan == 'f')){
        hasil = (9.0 / 4) * suhu + 32;
        return hasil;
    }
    else
    return -9999;
}