#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Создать структуру для хранения информации о заинтересованных сторонах проекта:
//их роли (заказчик, покупатель, разработчик и пр.), наименовании или имени,
// степени влияния и т.д. Составить с ее использованием программу 
//вывода информации обо всех заинтересованных


struct participants {
    char* role; //developer client product_owner product_manager
    char* name;
    char* surname;
    size_t importance; // 1 ... 10
};
typedef struct participants participants;

//requests
//SHOW <role>
void help() {
    printf("COMMAND LIST: \n    HELP - show command info,\n    EXIT - exit from program,");
    printf("\n    SHOW [-all] [-name <participant_name>] [-surname <participant_name>]");
    printf("\n    [-importance < LESS || MORE > <number>] - show info depending on keys");
    printf("\nOPTIONS for SHOW:");
    printf("\n    -surname, -importance, -name, -role\n        can be used at the same time");
    printf("\n    -all\n        show all project participants");
    printf("\n    -surname <participant_name>\n        show participants with <participant_name>");
    printf("\n    -importance <LESS || MORE > <number>\n        show participants with importance level");
    printf("\n        MORE or LESS to written <number>, if there is no\n        <MORE or LESS> prints participants");
    printf("\n        with equal to <number> importance level\n");
}

int print_particip_info(const participants* participant) {
    printf("%s %s\nrole: %s\nimportance level: %zu\n",
        participant->name, participant->surname, participant->role, participant->importance);
}

int fill_participant (char* buffer, participants* participant) {
    char* data =  strsep(&buffer, " ");
    participant->role = data;
    data =  strsep(&buffer, " ");
    participant->name = data;
    data =  strsep(&buffer, " ");
    participant->surname = data;
    data =  strsep(&buffer, " ");
    participant->importance = strtol(data, NULL, 10);
    return 0;
}

int make_participants (int particip_count, participants* particips, char* buffer[]) {
    particips = (participants*)malloc(sizeof(participants) * particip_count);
    if (particips == NULL) {
        printf("Can't allocate memory for participants");
        return 0;
    }
    for (size_t i = 0; i < particip_count; i++) {
        getline(&buffer[i], &strlen(buffer[i]), stdin);
        fill_participant(buffer[i], &particips[i]);
    }
    return 0;
}

int enter_participant (char *argv[]) {
    int size = 0;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        getline(&argv[i], 120, stdin);
    }
    return 0;
}

int main(int argc, char *argv[]) //int argc, char *argv[]
{
    participants* particips = NULL;
    char *particip_data[] = NULL;
    size_t particip_count = 0;
    if (argc > 0) {
        particip_data = argv;
    } else {
        
    }
    make_participants(argc, particips, particip_data);
    
    char* command_buffer = NULL;
    size_t cmd_buffer_size = 80;
    size_t char_cnt = 0;
    command_buffer = (char*)malloc(cmd_buffer_size * sizeof(char));
    printf("Enter participant: ");
    char_cnt = getline(&command_buffer, &cmd_buffer_size, stdin);
    participants particip1;
    enter_participant(command_buffer, &particip1);
    print_particip_info(&particip1);
    help();
    
    
    printf("Please, enter a command:\n");
    do {
        char_cnt = getline(&command_buffer, &cmd_buffer_size, stdin);
        printf("Please, enter a command:\n");
    } while (char_cnt > 0);
    return 0;
}
