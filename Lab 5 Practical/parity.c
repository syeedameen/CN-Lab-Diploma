/**
 * author: Syeed Mohd ameen                                         Dated: 24-02-2025
 * email: syeedmohdameen@zhcet.ac.in 
 * webpage : https://syeedameen.github.io/
 */


#include <stdio.h>
#include <stdlib.h>

/* print the number of one's and zero's in the string */
void print_string(char *string){

    /* check the string until we found null */
    while (*string != '\0'){
        printf("%c = ", *string);

        for (int i=0; i<8; i++){
            _Bool flag = (0x80 >> i) & (*string);
            printf("%d", flag ? 1 : 0);
        }
        string += 1;
        printf("\n");
    }
}   

/* count the number of one's in the string */
int count_parity(char *string){
    
    int count = 0;
    
    while (*string != '\0'){
        for (int i=0; i<8; i++){
            _Bool flag = (0x80 >> i) & (*string);
            if (flag == 1){
                count += 1;
            }
        }
        string += 1;
    }
    return count;
}


int main(){
    char *msg = "Hello Syeed Ameen";
    print_string(msg);

    printf("Number of one's in %s = %d \nparity of the above message = %s", 
        msg, count_parity(msg), (count_parity(msg) % 2 == 0)? "even" : "Odd");
    
    return 0;
}