#include <stdio.h>

void readfile(char filename[255])
{
    FILE *file;
    file = fopen(filename, "r");

    char str[9999];

    if (file == NULL) perror ("Fajl nyitasi hiba");
    else
    {
        while( fgets(str, 9999, file) != NULL )
        {
            printf("%s\n", str);
        }
        fclose (file);
    }
}

void readfile_rownum(char filename[255])
{
    FILE *file;
    file = fopen(filename, "r");

    char str[9999];

    if (file == NULL) perror ("Fajl nyitasi hiba");
    else
    {
        int row=1;
        while( fgets(str, 9999, file) != NULL )
        {
            printf("%2d. %s\n", row, str);
            row++;
        }
        fclose (file);
    }
    printf("\n");
}

void writefile(char filename[255], char name[50], int age)
{
    FILE *file;
    file = fopen(filename, "w");


    if (file == NULL) perror ("Fajl nyitasi hiba");
    else
    {
        fprintf(file, "%s %d", name, age);
        fclose (file);
    }
}

void fprinfFloat (char filename[255])
{
    FILE *file;
    file = fopen(filename, "w");

    double in;

    if (file == NULL) perror ("Fajl nyitasi hiba");
    else
    {
        int valasz;
        printf("Adj meg valos szamokat 0 vegjelig, amiket majd kiirunk egy file-ba: \n");

        do
        {
            printf("Szeretned a 0-t is kiiratni? (i/n) : ");
            valasz = getchar();
            getchar();
        }
        while ( (valasz != 'i') && (valasz != 'n') );
        valasz -= 'n';

        int i = 1;
        if (valasz)
            do
            {
                printf("%2d : ", i);
                i++;
                scanf("%lf", &in);
                fprintf(file, "%lf ", in);

            }
            while ((int)in != 0);
        else
            // ha nem akarjuk a 0-t is kiirni
            do
            {
                printf("%2d : ", i);
                i++;
                scanf("%lf", &in);
                if ((int)in)
                    fprintf(file, "%lf ", in);

            }
            while ((int)in != 0);

        fclose (file);
    }
}

int main()
{    
    // Készíts programot, ami egy létező szöveges fájl tartalmát úgy írja ki a képernyőre, hogy a sorok elé odaírja a sorszámot is!
    readfile_rownum("file_to_read.txt");

    // Készíts programot, ami a felhasználó nevét és életkorát kiírja egy fájlba!
    writefile("file_user_age", "Fabian Gabor", 32);

    // Ha már létezik a 2. program által létrehozott fájl, olvastassuk vissza egy új programban a korábbi eredményeket!
    readfile("file_user_age");

    // Kérj be 0 végjelig valós számokat, majd írasd ki őket egy fájlba!
    fprinfFloat("valos_szamok.txt");

    return 0;
}
