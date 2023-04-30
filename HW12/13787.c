#include <stdio.h>
#include <string.h>
#define lvup_atk 200
#define lvup_dfn 100
#define lvup_maxHp 20
#define lvup_maxMp 15
#define T 2
typedef struct pokemon {
    int id;
    char name[10];
    int level;
    int attack;
    int defense;
    int Hp;
    int Mp;
    int maxHp;
    int maxMp;
    int costMp;
} Pokemon;
void level_up(Pokemon *P) {
    if (P->level < 5) {
        (P->level)++;
        (P->attack) += lvup_atk;
        (P->defense) += lvup_dfn;
        (P->maxHp) += lvup_maxHp;
        (P->maxMp) += lvup_maxMp;
    }
    P->Hp = P->maxHp;
    P->Mp = P->maxMp;
}

// TODO: simulate and print the process of the battle
void battle(Pokemon *A, Pokemon *B) {
    if(A->Hp==0){
        if(B->Hp==0){
            printf("Draw.\n");
            return;
        }
        printf("%s is the winner! %s died in vain...\n\n",B->name,A->name);
        return;
    }
    if(B->Hp==0){
        printf("%s is the winner! %s died in vain...\n\n",A->name,B->name);
        return;
    }
    while (1) {
        (A->Mp) += T;
        if (A->Mp > A->maxMp) A->Mp = A->maxMp;
        if(A->Mp>=A->costMp){
            A->Mp-=A->costMp;
            int damage = 2*(A->level)* (A->attack-B->defense)/100;
            if(damage>0){
                B->Hp-=damage;
                if(B->Hp<=0) B->Hp=0;
                printf("%s used Headbutt!\n",A->name);
                printf("%s now has %d HP.\n",B->name,B->Hp);
                if(B->Hp==0){
                    printf("%s is the winner! %s died in vain...\n\n",A->name,B->name);
                    break;
                }
            }
        }
        else{
            printf("%s used Rest!\n",A->name);
            (A->Mp) += T;
            printf("%s now has %d MP.\n",A->name,A->Mp);
        }
        (B->Mp) += T;
        if (B->Mp > B->maxMp) B->Mp = B->maxMp;
        if(B->Mp>=B->costMp){
            B->Mp-=B->costMp;
            int damage = 2*(B->level)* (B->attack-A->defense)/100;
            if(damage>0){
                A->Hp-=damage;
                if(A->Hp<=0) A->Hp=0;
                printf("%s used Headbutt!\n",B->name);
                printf("%s now has %d HP.\n",A->name,A->Hp);
                if(A->Hp==0){
                    printf("%s is the winner! %s died in vain...\n\n",B->name,A->name);
                    break;
                }
            }
        }
        else{
            printf("%s used Rest!\n",B->name);
            (B->Mp) += T;
            printf("%s now has %d MP.\n",B->name,B->Mp);
        }
    }
}