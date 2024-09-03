#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void xoaxuongdong(char x[]){
    if(x[strlen(x)-1]=='\n'){
        x[strlen(x)-1] = '\0';	
    }	
}

int main(){
    FILE *f;
    char n[100];
    char x[100];
    printf("nhap gia tri n(0<n<=100):");
    fflush(stdin);
    fgets(n,sizeof(n),stdin);
    xoaxuongdong(n);

    printf("\n nhap chuoi su kien 13<ms>: ");
    fflush(stdin);
    fgets(x,sizeof(x),stdin);
    xoaxuongdong(x);

    f=fopen("file_mush_ghost","w");
    fprintf(f,"%s\n%s\n",n,x);
    fclose(f);

    // Chuy?n file t? CRLF sang LF
    FILE *fp1, *fp2;
    fp1 = fopen("file_mush_ghost", "r");
    fp2 = fopen("file_mush_ghost_lf", "w");

    int c;
    while ((c = fgetc(fp1)) != EOF) {
        if (c == '\r') {
            continue;
        }
        fputc(c, fp2);
    }

    fclose(fp1);
    fclose(fp2);
    remove("file_mush_ghost");
    rename("file_mush_ghost_lf", "file_mush_ghost");

    return 0;
}
