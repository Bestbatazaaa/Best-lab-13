#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double Arithmetic = 0, StandardDev = 0, Geometric = 1 , Areverse = 0, Max = A[0], Min = A[0];
    for(int i = 0; i < N ; i++){
        Arithmetic = Arithmetic + A[i];
        Geometric = Geometric * A[i];
        Areverse = Areverse + (1/A[i]);
    }
    for(int i = 0; i < N ; i++){
        if(Max < A[i]){
            Max = A[i];
        }
        if(Min > A[i]){
            Min = A[i];
        }
    }
    for(int i = 0; i < N ; i++){
        StandardDev = StandardDev + pow(A[i]-(Arithmetic/N),2);
    }
    B[0] = Arithmetic/N;
    B[1] = sqrt(StandardDev/N);
    B[2] = pow(Geometric,1.0/N);
    B[3] = 1/(Areverse/N);
    B[4] = Max;
    B[5] = Min;
}
