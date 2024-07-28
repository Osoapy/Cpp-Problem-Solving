#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N; 
    int resultados[N];
    for(int aux, K, aux2 = N; aux2 != 0; aux2--) {
        std::cin >> aux >> K;
        int a[K], contador = 0, maiorN = 0;
        for(; K != 0; K--) {
            cin >> a[K];
            if (a[K] == 1) {contador++;}
            else {contador += a[K] * 2 - 1;}
            if (a[K] > maiorN) {maiorN = a[K];}
        }
        if (maiorN != 1) {
            resultados[aux2 - 1] = contador - (maiorN * 2 - 1);
        }
        else {
            resultados[aux2 - 1] = contador - 1;
        }
    }
    for(; N != 0; N--) {
        std::cout << resultados[N - 1] <<  std::endl;
    }
    return 0;
}
