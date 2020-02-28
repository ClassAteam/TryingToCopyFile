/* Глава 1. Программа 1.1.Базовая программа копирования файлов cp. Реализация, использующая библиотеку С. */

/* cp файл1 файл2: Копировать файл1 в файл2. */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <errno.h>

#define BUF_SIZE 256


int main() {

    FILE* in_file, * out_file;

    char rec[BUF_SIZE];

    size_t bytes_in, bytes_out;

   

    in_file = fopen("CopySource.txt", "rb");

   

    out_file = fopen("CopyReciever.txt", "wb");

   

    /* Обработать входной файл по одной записи за один раз. */

    
    while ((bytes_in = fread(rec, 1, BUF_SIZE, in_file)) > 0) {   //zapisal znachenie iz fayla v "rec"

        bytes_out = fwrite(rec, 1, bytes_in, out_file);           //  iz "rec" zapisivaetsa v structuru FILE* out_file

        if (bytes_out != bytes_in) {

            perror("2");

            return 4;

        }
        for (size_t i = 0; i < 100; i++)
        {
            fputc('\n', out_file);
            fwrite(rec, 1, bytes_in, out_file);
        }

    }

    fclose(in_file);

    fclose(out_file);

    return 0;

}