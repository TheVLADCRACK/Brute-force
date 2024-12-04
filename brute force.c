          //Author  : VLADCRACK
          //Contact : t.me/TheVLADCRACK_237
          //License :  Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/> 
          //[Attention] Je ne suis en rien responsable de l'usage de ce programme [Attention]


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define MAX 1000

const char caracteresPossibles[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 &é(-é_çà)=~#{[|\\^@]}$*ù!:;,?./%+\"'€£¥$¢°=©®™✓<>`|•√π÷×§∆₹¥₱←↑↓→∞≠≈‰℅♣♠♪♥♦ΩΠμ¶№—_–·±★†‡„“”«»‚‘’‹›¡¿‽äãåāªàâėęēêeeëÿūúũùûüīįíĩìïîºōøõóòöœôßśšćçčńñæáÄÃÅĀÀÂÆÁĖĘĒÊeeËŪÚŨÙÛÜĪĮÍĨÌÏÎŌØÕÓÒÖŒÔẞŚŠŃÑĆÇČ";

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {

printf("\e[8;23;84t");
    char texteATrouver[MAX];
    char tentativeCourante[MAX];
    char tentativeSuivante[MAX];
    int generation = 0;
    int termine = 0;
    int i;
    
    clear_screen();
    printf("\033[32;4m\033[1m\n\n\t\tCE PROGRAMME EST DESTINE A CRACKER VOTRE MOT DE PASSE\n\t\t\t\033[0m   \033[32;4m\033[1mAVEC UNE FACILITE DECONSERTANTE\n\n\033[0m");

    printf("\n\n\033[39;1mEntre ton mot de passe:\033[0m \033[37");
    fgets(texteATrouver, MAX, stdin);
    texteATrouver[strcspn(texteATrouver, "\n")] = 0;
    printf("\n\n");

    srand(time(NULL));

    for (i = 0; i < strlen(texteATrouver); i++) {
        tentativeCourante[i] = caracteresPossibles[rand() % strlen(caracteresPossibles)];
    }
    tentativeCourante[i] = '\0';

    while (!termine) {
        printf("\r%s", tentativeCourante);
        fflush(stdout);

        termine = 1;
        
        for (i = 0; i < strlen(texteATrouver); i++) {
            if (tentativeCourante[i] != texteATrouver[i]) {
                termine = 0;
                tentativeSuivante[i] = caracteresPossibles[rand() % strlen(caracteresPossibles)];
            } else {
                tentativeSuivante[i] = texteATrouver[i];
            }
        }
        tentativeSuivante[i] = '\0';  
        
        strcpy(tentativeCourante, tentativeSuivante);

        generation++;
        usleep(10000);
    }

    printf("\n\n\n\t\t\t😈Mot de passe cracke😈\n\n");
    printf(" Cela ne m'a demande que %d generation(s)!\n\n", generation);
    printf("Je te conseille d'utiliser un mot de passe plus securise\nSinon...\n\n\n");

    return 0;
}
