#include "ui.h"
#include <stdio.h>
#include <stdlib.h>

void ui_clear_screen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void ui_pause_screen(void)
{
    printf("\nPress ENTER to continue...");
    getchar();
}

void ui_display_menu(void)
{

    printf("============================================\n");
    printf("      LINKED LIST - POINTS IN THE PLANE     \n");
    printf("--------------------------------------------\n");
    printf("[1] - Add at the start\n");
    printf("[2] - Add at the ending\n");
    printf("[3] - Add in an orderly fashion\n");
    printf("[4] - Display the points\n");
    printf("[5] - Delete point\n");
    printf("[0] - Exit the program\n");
}

void ui_display_submenu(int total_nodes)
{
    // ui_clear_screen();
    printf("============================================\n");
    printf("    SHOW THE NODES       TOTAL: %d          \n", total_nodes);
    printf("--------------------------------------------\n");
    printf("[1] - Original List\n");
    printf("[2] - Ascending List\n");
    printf("[3] - Descending List\n");
    printf("[0] - Back\n");
}

void ui_display_header(const char *title)
{
    printf("============================================\n");
    printf("            %s\n", title);
    printf("--------------------------------------------\n");
}

void ui_display_notification(const char *notification)
{
    ui_clear_screen();
    printf("-------------------------------------------\n");
    printf("    %s      \n", notification);
    printf("-------------------------------------------\n");
}

int ui_get_valid_option(int min_option, int max_option)
{
    int input = 0;

    printf("(Select an option between [%d - %d]): ", min_option, max_option);
    while (scanf("%d", &input) != 1 || input < min_option || input > max_option)
    {
        int character;
        while ((character = getchar()) != '\n' && character != EOF)
            continue;

        printf("(Select an option between [%d - %d]): ", min_option, max_option);
    }

    while (getchar() != '\n')
        continue;

    return input;
}
