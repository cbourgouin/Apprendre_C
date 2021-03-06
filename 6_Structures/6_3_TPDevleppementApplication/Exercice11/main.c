
/* 
 * File:   main.c
 * Author: cbourgouin
 *
 * Created on 6 décembre 2019, 15:03
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"

int main() {
    typeAdherent * ad[NBMAXADHE];
    int compteurAdherent = 0;
    int i;
    int leAd;
    char reponse;

    do {
        afficherMenu(compteurAdherent);
        scanf(" %c", &reponse);
        
        switch (reponse) {
            case 'A': compteurAdherent = ajouterUnAdherent(ad, compteurAdherent);
                break;
            case 'S': printf("Adherents a supprimer : ");
                scanf("%d", &leAd);
                compteurAdherent = supprimerUnAdherent(ad, leAd-1, compteurAdherent);
                break;
            case 'M': printf("Adherents a modifier : ");
                scanf("%d", &leAd);
                modifierUnAdherents(ad, leAd - 1);
                break;
            case 'V':printf("Adherents a voir : ");
                scanf("%d", &leAd);
                afficherUnAdherent(ad[leAd - 1]);
                break;
            case 'L': afficherLesAdherents(ad, compteurAdherent);
                break;
            case 'E': supprimerLesAdherents(ad, compteurAdherent);
                break;
        }
    } while (reponse != 'Q');

    return (0);
}

