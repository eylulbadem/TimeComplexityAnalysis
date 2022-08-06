// CS201 – HW 2
// Name: Eylül Badem
// ID: 22003079
// Section: 01
// Date: 06.04.2022

#include <iostream>
#include <ctime>
using namespace std;

int algo1(int a, int n, int p) {
    int temp = a;
    int result = 1;

    for ( int i = 0; i < n; i++ ) {
        a = temp * a;
        result = a % p;
    }

    return result;
}

int algo2(int a, int n, int p) {
    int temp = a;
    int result = 1;

    for ( int i = 0; i < n; i++ ) {
        a = temp * a;

        if ( 1 == (a % p) ) {
            for ( int j = 0; j < (n % i); j++ )
                a = temp * a;
            return a % p;
        }
        result = a % p;
    }

    return result;
}

int algo3(int a, int n, int p) {
    int result = 1;

    if ( n == 1 )
        return a % p;

    if ( (n % 2) == 0 ) {
        result = algo3( a,n/2, p );
        return ( result * result ) % p;
    }
    else if ( (n % 2) == 0 ) {
        result = algo3( a,(n-1)/2, p);
        return ( a * result * result ) % p;
    }
    return 0;
}

int main() {

    double duration;
    clock_t startTime = clock();
    int a = 2;
    int n = 10*(1000000);
    int p = 10007;

    for ( int i = 0; i < 1000000; i++ )
        algo3(a,n,p);

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration/1000000 << " seconds." << endl;

    return 0;
}
