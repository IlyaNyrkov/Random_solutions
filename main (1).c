
#include <stdio.h>
//Создать структуру для хранения информации о заинтересованных сторонах проекта:
//их роли (заказчик, покупатель, разработчик и пр.), наименовании или имени,
// степени влияния и т.д. Составить с ее использованием программу 
//вывода информации обо всех заинтересованных
enum roles {
    developer = 0,
    client,
    product_owner,
    product_manager
};
typedef enum roles roles;
struct participants {
    roles role;
    char name[15];
    char surname[30];
    size_t importance; // 1 ... 10
};
typedef struct participants participants;

//requests
//SHOW <role>
void help() {
    printf("COMMAND LIST: \n\tHELP - command info, ");
    printf("\n\tSHOW [-all] [-name <participant_name>] [-surname <participant_name>]");
    printf("\n\t[-importance < LESS || MORE > <number>] - show info depending on keys");
    printf("\nOPTIONS:");
    printf("\n\t-surname, -importance, -name, -role can be used at the same time");
    printf("\n\t-all\n\t\tshow all project participants");
    printf("\n\t-surname <participant_name>\n\t\tshow participants with <participant_name>");
    printf("\n\t-importance <LESS || MORE > <number>\n\t\tshow participants with importance level");
    printf("\n\t\tMORE or LESS to written <number>, if there is no <MORE or LESS> prints participants");
    printf("\n\t\twith equal to <number> importance level");
}

void print_particip_info(const participants* participant) {
    printf("%s, %s,\nrole: %s,\nimportance level: %d", 
    participant->name, participant->surname, participant->importance, participant->role);
}

int main()
{
    
    help();

    return 0;
}
