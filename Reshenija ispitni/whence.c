#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *in_dat;
    if (argc != 2)
    {
        fprintf(stderr, "Upatstvo: %s <vlezna_datoteka>", argv[0]);
        return -1;
    }
    if ((in_dat = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Ne mozhe da se otvori datotekata %s za chitanje", argv[1]);
        return -1;
    }

    char c;
    char s[81];
    int line = 1, linemax = 1;
    int whence = 0, whence_max = 0;
    int number_letters = 0;
    int max = 0;
    while ((c = fgetc(in_dat)) != EOF)
    {
        if (c != '\n')
        {
            if (isalpha(c) && isupper(c))
            {
                number_letters++;
            }
        }
        else
        {
            if (number_letters > max)
            {
                max = number_letters;
                linemax = line;
                whence_max = whence;
            }
            line++;
            number_letters=0;
            whence = ftell(in_dat);
        }
    }

    fseek(in_dat, whence_max, SEEK_SET);
    fgets(s, 81, in_dat);
    printf("%s%d",s,linemax);

    fclose(in_dat);
    return 0;
}