// welcometozohocorporation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** createMat(char* str, int len) {
    char **mat;
    int i,j,k;
    
    mat = (char**)malloc(sizeof(char*) * len);
    
    for(i=0; i<len; i++) {
        *(mat + i) = (char*)malloc(sizeof(char) * len);
    }
    
    k = 0;
    
    for(i=0; i<len; i++) {
        for(j=0; j<len; j++) {
            
            if(k < strlen(str)) {
                *(*(mat+i)+j) = *(str+(k++));
            } else {
                break;
            }
            
        }
    }
    
    return mat;
}

void printMat(char **mat, int len) {
    int i,j;
    
    for(i=0; i<len; i++) {
        for(j=0; j<len; j++) {
            printf("%c ",*(*(mat+i)+j));
        }
        printf("\n");
    }
}

void checkSugStr(char **mat, int len) {
    
    char x[10] = "TOO";
    int k = 0, i, j;
    
    for(i=0; i<len; i++) {
        for(j=0; j<len-2; j++) {
            
            if(*(*(mat+i)+j) == *(x+k)) {
                
                if( *(*(mat+i)+(j+1)) == *(x+(k+1)) && *(*(mat+i)+(j+2)) == *(x+(k+2))) {
                    printf("<%d,%d>\n<%d,%d>",i,j,i,j+2);
                    return;
                } 
                
                if(i <= 2 && *(*(mat+(i+1))+j) == *(x+(k+1)) && *(*(mat+i+2)+j) == *(x+(k+2)))  {
                    printf("<%d,%d>\n<%d,%d>",i,j,i+2,j);
                    return;
                }
            } 
            
        }
    }
}

int main() {
    char *str,**mat;
    int len, x;
    
    scanf("%s",str); // input = WELCOMETOZOHOCORPORATION
    len = strlen(str);
    x = len % 5;
    len += (5-x);

    
    mat = createMat(str, len/5);
    
    printMat(mat, len/5);
    
    checkSugStr(mat, len/5);
    
    return 0;
}
