/*
 * Author:  Oleksii Yukhymenko
 * Date:    03-Feb-2018
 *
 *
 * An example of a correct and incorrect reading a file in C
 *
 */

#include <stdio.h>

#define FILE_NAME "file2.txt"
#define FILE_MODE_WRITE "w"
#define FILE_MODE_READ "r"


int main() {
    FILE *f_ = NULL;
    int in_int;
    char in_char;

    f_ = fopen(FILE_NAME, FILE_MODE_WRITE);
    if (!f_) {
        return 1;
    }

    fputc(0x12, f_);
    fputc(0xFF, f_);
    fputc(0x22, f_);

    if (fclose(f_)) {
        return 1;
    }

    // INCORRECT READ FILE
    f_ = fopen(FILE_NAME, FILE_MODE_READ);
    if (!f_) {
        return 1;
    }

    printf("\n========\n");
    while((in_char = fgetc(f_)) != EOF) {
        printf("%X ", in_char);
    }
    printf("\n========\n");

    if (fclose(f_)) {
        return 1;
    }
    // INCORRECT READ FILE [END]




    // CORRECT READ FILE
    f_ = fopen(FILE_NAME, FILE_MODE_READ);
    if (!f_) {
        return 1;
    }

    printf("\n========\n");
    while(!feof(f_)) {
        if((in_int = fgetc(f_)) != EOF) {
            printf("%X ", in_int);
        }
    }
    printf("\n========\n");
    if (fclose(f_)) {
        return 1;
    }
    // CORRECT READ FILE [END]

    return 0;
}
