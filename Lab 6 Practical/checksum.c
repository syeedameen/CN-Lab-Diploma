#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// function to calculate the checksum 
unsigned char calculateChecksum(unsigned char *data, int len){
    unsigned int sum = 0;
    for (int i=0; i<len; i++){
        sum += data[i];
    }

    // add carry into 8-bit character 
    while (sum >> 8){
        sum = (sum & 0xFF) + (sum >> 8);
    }
    // calculate first complement of sum 
    sum = ~sum;
    return (unsigned char) (sum);
}

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
        printf(" (%d)", *string);
        printf("\n");
    }
} 

int main(){
    unsigned char *data = "Hey, Ameen";
    int len = strlen(data);

    unsigned char checksum = calculateChecksum(data, len);
    print_string(data);
    printf("Checksum of\n%s : 0x%02X\n", data, checksum);

    return 0;
}