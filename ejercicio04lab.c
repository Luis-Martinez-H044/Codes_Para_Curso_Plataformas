#include<stdio.h>
int main(){
int entero, residuo, i;
char binario[32];
printf("Por favor ingrese un numero entero positivo: ");
scanf("%d", &entero);

	for(i = 0; i < 32; i++) {
		residuo= entero & 1;
		binario[i]=(residuo==1) ? '1' : '0';
		entero=entero>> 1;
}
binario[32] = '\0';
printf("La representación binaria del entero es: ");

int Uno = -1;
for(i = 32; i > 0; i--) {
    if (binario[i - 1] == '1') {
        Uno = i - 1;
        break;
    }
}

if (Uno == -1) {
    printf("0");
} else {
    for(i = Uno + 1; i > 0; i--) {
        printf("%c", binario[i - 1]);
    }
}
    printf("\n");
    return 0;
}
