
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MEM_ALLOC_ERR -1
struct Person {
    char* name;
    char* surname;
    char* role;
    size_t importance;
    
};
typedef struct Person Person;

void show_person_info(Person* person) {
    printf("name: %20s\nsurname: %30s\nrole: %15s\nimportance: %zu", 
        person->name, person->surname, person->role, person->importance);
    
}

size_t name_size = 20;
size_t surname_size = 30;
size_t role_size = 15;

int mem_alloc_person(Person* person, size_t name_sz,
    size_t surname_sz, size_t role_sz) {
    person->name = malloc(name_sz * sizeof(char));
    if (person->name == NULL) {
        return MEM_ALLOC_ERR;
    }
    person->surname = malloc(name_sz * sizeof(char));
    if (person->surname == NULL) {
        return MEM_ALLOC_ERR;
    }
    person->role = malloc(role_sz * sizeof(char));
    if (person->surname == NULL) {
        return MEM_ALLOC_ERR;
    }
    return 0;
}

int mem_free_person(Person* person) {
    free(person->name);
    free(person->surname);
    free(person->role);
}

void show_surnames(Person* people, size_t n, char* surname) {
    for (size_t i = 0; i < n; i++) {
        if (!strcmp(people[i].surname, surname)) {
            show_person_info(&people[i]);
            printf("\n");
        }
    }
}

void show_names(Person* people, size_t n, char* name) {
    for (size_t i = 0; i < n; i++) {
        if (!strcmp(people[i].name, name)) {
            show_person_info(&people[i]);
            printf("\n");
        }
    }
}

void show_roles(Person* people, size_t n, char* role) {
    for (size_t i = 0; i < n; i++) {
        if (!strcmp(people[i].role, role)) {
            show_person_info(&people[i]);
            printf("\n");
        }
    }
}

int main()
{
    int n = 1;
    printf("Enter count of project participants: ");
    scanf("%d", &n);
    Person* people = malloc(n * sizeof(Person));
    for (int i = 0; i < n; i++) {
        mem_alloc_person(&people[i], name_size, surname_size, role_size);
        if (1) {
            printf("Enter name: ");
            scanf("%20s", people[i].name);
            printf("Enter surname: ");
            scanf("%30s", people[i].surname);
            printf("Enter role: ");
            scanf("%15s", people[i].role);
            printf("Enter importance level");
            scanf("%zu", &people[i].importance);
        } else {
            printf("Mem alloc error, check your pc");
        }
    }
    size_t cmd_line_size = 10;
    char* command_line = malloc(cmd_line_size * sizeof(char));
    printf("Command list is: EXIT - quit from program, SURNAME | NAME | ROLE <text> - output\n");
    printf("Enter a command: ");
    while (scanf("%10s", command_line)) {
        if (!strcmp(command_line, "SURNAME")) {
            printf("Enter surname: ");
            char surname[surname_size];
            scanf("%30s", surname);
            show_surnames(people, n, surname );
        } else if (!strcmp(command_line, "NAME")) {
            printf("Enter name: ");
            char name[name_size];
            scanf("%20s", name);
            show_names(people, n, name );
        } else if (!strcmp(command_line, "ROLE")) {
            printf("Enter role: ");
            char role[role_size];
            scanf("%15s", role);
            show_roles(people, n, role );
        } else if (!strcmp(command_line, "EXIT")) {
            printf("Exiting from program");
            for (size_t i = 0; i < n; i++) {
                mem_free_person(&people[i]);
            }
            free(people);
            return 0;
        } else {
            printf("There is no such command as %10s", command_line);
        }
        printf("Enter a command: ");
    }
    return 0;
}
