#include <stdio.h>

int acabou(int* vet, int N) {
    for(int l = 0; l < N; l++) {
        if(vet[l] == 0) {
            return 0;
        }
    }
    return 1;
}

int vivos(int* arrayBool, int N, int posM, int m) {
    int soma = 0;
    if(posM > N - 1) {
        posM -= N;
    }
    for(int l = 0; l < m; l++) {
        if(posM + l + 1 > N - 1) {
            posM -= N;
            if(arrayBool[posM] == 1) {
                soma++;
            }
        }
        if(arrayBool[posM + l + 1] == 1) {
            soma++;
            m++;
            if(m == N - 1) {
                break;
            }
        }
    }
    return soma;
}

int mortos(int* arrayBool, int N, int posM, int m) {
    int soma = 0;
    if(posM < 0) {
        posM += N;
    }
    for(int l = 0; l < m; l++) {
        if(posM - l - 1 < 0) {
            posM += N - l - 1;
            if(arrayBool[posM] == 1) {
                soma++;
            }
        }
        if(arrayBool[posM - l - 1] == 1) {
            soma++;
        }
    }
    return soma;
}

int main(){
    int N, k, m;
    while(scanf("%d %d %d", &N, &k, &m) == 3){
        if((N == 0) && (k == 0) && (m == 0)) break;
        int array[N], arrayBool[N];
        int i, posK = 0, posM = N - 1, flag = 1;
        for(i = 0; i < N; i++){
            array[i] = i+1; arrayBool[i] = 0;
        }
        while(!acabou(arrayBool, N)) {
            int escK = -1, escM = -1;
            while(escK < 0) {
                //printf("\nEntrando no K\n");
                int addin = vivos(arrayBool, N, posK, k);
                //printf("Escolhidos: %d\n", addin);
                posK += k - 1 + addin;
                //printf("%d = %d - 1 + %d", posK, k, addin);
                //printf("Posição: %d\n", posK);
                if(posK > N - 1) {
                    //printf("Posição era maior que %d\n", N - 1);
                    posK -= N - 1;
                    //printf("Posição: %d\n", posK);
                }
                while (arrayBool[posK] == 1) {
                    //printf("Posição ocupada foi escolhida...\n");
                    for(int l = 0; l < 10; l++) {
                        //printf("%d  ", arrayBool[l]);
                    }
                    posK++;
                    //printf("Posição: %d\n", posK);
                    if(posK > N - 1) {
                        posK = posK % N;
                        //printf("Posição era maior que %d\n", N - 1);
                        //printf("Posição: %d\n", posK);
                    }
                } 
                escK = posK;
                //printf("Posição FINAL: %d\n", posK);
            }
            while(escM < 0) {
                //printf("\nEntrando no M\n");
                int noddin = mortos(arrayBool, N, posM, m);
                //printf("Escolhidos: %d\n", noddin);
                posM += -m + flag - noddin;
                //printf("Posição: %d\n", posM);
                if(posM < 0) {
                    //printf("Posição era menor que 0");
                    posM = posM + N;
                    //printf("Posição: %d\n", posM);
                }
                while (arrayBool[posM] == 1) {
                    //printf("Posição ocupada foi escolhida...\n");
                    posM--;
                    for(int l = 0; l < 10; l++) {
                        //printf("%d  ", arrayBool[l]);
                    }
                    if(posM < 0) {
                        posM = N + posM;
                        //printf("Posição era menor que 0");
                        //printf("Posição: %d\n", posM);
                    }
                }
                escM = posM;
            }
            if (escM != escK) {
                arrayBool[escK] = 1;
                arrayBool[escM] = 1;
                if (escK > 8) {
                    printf(" %d", array[escK]);
                }
                else {
                    printf("  %d", array[escK]);
                }
                if (escM > 8) {
                    printf(" %d", array[escM]);
                }
                else {
                    printf("  %d", array[escM]);
                }
            }
            if (escM == escK) {
                arrayBool[escK] = 1;
                if (escK > 8) {
                    printf(" %d", array[escK]);
                }
                else {
                    printf("  %d", array[escK]);
                }
            }
            if(!acabou(arrayBool, N)) {
                printf(",");
            }
            flag = 0;
        }
    }
    return 0;
}
