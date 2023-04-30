#include <stdio.h>
typedef struct pokemon{
    int id;
    char name[20];
    char first_move[20];
    char second_move[20];
    int attack;
    int special_attack;
    int defense;
    int special_defense;
    int Hp;
    int maxHp;
}Pokemon;
int check(Pokemon *A, Pokemon *B);
void recover(Pokemon *P){
    P->Hp = P->maxHp;
}
int check(Pokemon *A, Pokemon *B){
    if(!A->Hp){
        if(!B->Hp){
            printf("Draw.\n");
            return 1;
        }
        printf("%s is the winner! %s died in vain...\n\n",B->name,A->name);
        return 1;
    }
    else if(!B->Hp){
        printf("%s is the winner! %s died in vain...\n\n",A->name,B->name);
        return 1;
    }
    return 0;
}
void battle(Pokemon *A, Pokemon *B){
    if(check(A,B)) return;
    while(1){
        int damage = 2*(A->attack-B->defense);
        if(damage<1) damage=1;
        B->Hp-=damage;
        printf("%s used %s!\n",A->name,A->first_move);
        if(B->Hp<0)B->Hp=0;
        printf("%s now has %d HP.\n",B->name,B->Hp);
        if(check(A,B)) return;
        damage = 2*(B->attack-A->defense);
        if(damage<1) damage=1;
        A->Hp-=damage;
        printf("%s used %s!\n",B->name,B->first_move);
        if(A->Hp<0)A->Hp=0;
        printf("%s now has %d HP.\n",A->name,A->Hp);
        if(check(A,B)) return;
        damage = 2*(A->special_attack-B->special_defense);
        if(damage<1) damage=1;
        B->Hp-=damage;
        printf("%s used %s!\n",A->name,A->second_move);
        if(B->Hp<0)B->Hp=0;
        printf("%s now has %d HP.\n",B->name,B->Hp);
        if(check(A,B)) return;
        damage = 2*(B->special_attack-A->special_defense);
        if(damage<1) damage=1;
        A->Hp-=damage;
        printf("%s used %s!\n",B->name,B->second_move);
        if(A->Hp<0)A->Hp=0;
        printf("%s now has %d HP.\n",A->name,A->Hp);
        if(check(A,B)) return;
    }
}