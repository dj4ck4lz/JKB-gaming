#include<stdio.h>
#include<stdlib.h>

//simple ass program to document the first steps to my greatness as the greatest game dev ever

//structure for player duh basic ass shit
struct Player{
    char PlayerName[50];
    char PlayerClass[50];
    double PlayerHealth;
    double PlayerMana;
    double PlayerAtk;
};

int main()
{
    struct Player player1;
    strcpy(player1.PlayerName, "Zack");
    strcpy(player1.PlayerClass, "Mage");
    player1.PlayerHealth = 100.0;
    player1.PlayerMana = 100.0;
    player1.PlayerAtk = 25.0;

    struct Player player2;
    strcpy(player2.PlayerName, "Dick");
    strcpy(player2.PlayerClass, "Barbarian");
    player2.PlayerHealth = 100.0;
    player2.PlayerMana = 100.0;

    int damage_scope = 25, my_health = 100, health_regen = 25, damage_buff = 20, round = 0;
    char affirm_kill;

    printf("Kill %s by entering \"y\"\n", player1.PlayerName);
    printf("Heal by entering \"h\"\n");
    printf("Increase damage by entering \"d\"\n");
    printf("Every even round, %s will heal by 25 health points\n", player1.PlayerName);

    do
    {
        printf("Round %d\n", round);
        printf("Choose your action: ");
        scanf(" %c", &affirm_kill);

        if (affirm_kill=='y')
        {
            double damage = player1.PlayerHealth-damage_scope;
            player1.PlayerHealth = damage;

            double damage_received = my_health-player1.PlayerAtk;
            my_health = damage_received;

            printf("You dealt %f damage to %s\n", damage_scope, player1.PlayerName);
            printf("Remaining health:\nYou: %d\n%s: %f\n", my_health, player1.PlayerName,player1.PlayerHealth);
        }

        else if (affirm_kill=='h')
        {
            my_health = my_health+health_regen;

            printf("You healed by 25 health points!\n");
        }

        else if (affirm_kill=='d');
        {
            damage_scope = damage_scope+damage_buff;

            printf("You got an increase of %d to your damage output!\n", damage_buff);
        }

        round++;

        if (round%2==0)
        {
            player1.PlayerHealth = player1.PlayerHealth+25;

            printf("%s healed by 25 health points!", player1.PlayerName);

        }
    } while(player1.PlayerHealth>0 && my_health>0);

    if (player1.PlayerHealth<=0)
        printf("You killed %s you stupid ni--\n", player1.PlayerName);
    else if (my_health<=0)
        printf("You lost you stupid bitch!\n");

    return 0;

}
