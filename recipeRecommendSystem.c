#include <stdio.h>
#include <string.h>

#define MAX_RECIPES 10
#define MAX_INGREDIENTS 10
#define MAX_NAME_LEN 50

// function declaration
void add_recipe();
void recommend_recipe();

struct Recipe {
    char name[MAX_NAME_LEN];
    char ingredients[MAX_INGREDIENTS][MAX_NAME_LEN];
    int ingredients_count;
    char dietary_restriction[MAX_NAME_LEN];
};

// Global variable declaration
struct Recipe recipes[MAX_RECIPES];
int recipe_count = 0;

// function definition
void add_recipe() {
    if ( recipe_count >= MAX_RECIPES) {
        printf("Maximum Recipe limit is reached\n");
        return;
    }
    struct Recipe new_recipe;
    printf("Enter the new recipe name : ");
    scanf(" %[^\n]", new_recipe.name);
    printf("Enter the number of ingredients ( upto 10): ");
    scanf("%d", &new_recipe.ingredients_count);
    for (int i = 0; i < new_recipe.ingredients_count; i++) {
        printf("Enter ingredient %d : ",i + 1);
        scanf(" %[^\n]", new_recipe.ingredients[i]);
    }
    printf("Enter the Dietary Restrictions (if any): ");
    scanf(" %[^\n]", new_recipe.dietary_restriction);
    recipes[recipe_count] = new_recipe;
    recipe_count++;
}
// function definition
void recommend_recipe() {
    char available_ingredients[MAX_INGREDIENTS][MAX_NAME_LEN];
    int available_count;
    printf("Enter the number of ingredients available (upto 10) : ");
    scanf("%d", &available_count);
    printf("The available ingredients are :\n");
    for (int i = 0; i < available_count; i++) {
        printf("Enter the available ingredient %d : ",i + 1);
        scanf(" %[^\n]", available_ingredients[i]);
    }
    for (int i = 0; i < recipe_count; i++) {
        int match_count = 0;
        for(int j = 0; j < recipes[i].ingredients_count; j++) {
            for (int k = 0; k < available_count; k++) {
                if ( strcmp(recipes[i].ingredients[j],available_ingredients[k]) == 0) {
                    match_count++;
                }
            }
        }
        if (match_count == recipes[i].ingredients_count) {
            printf("\nThe Recommended Recipe is : %s\n", recipes[i].name);
        }

    }
}
int main() {
    char choice; 
    int option;
    do {
        printf("\nRECIPE RECOMMENDATION SYSTEM\n");
        printf("1 : Add a Recipe(specify dietary restrictions)\n");
        printf("2 : Recommend a Recipe\n");
        printf("3 : Exit\n");
        printf("Enter your option : ");
        scanf("%d", &option);
        switch(option) {
            case 1:
            add_recipe();     // function call
            break;
            case 2:
            recommend_recipe();     // function call
            break;
            case 3:
            printf("Exiting from the system.......\n");
            break;
            default:
            printf("Invalid choice!!\n");
        }
        printf("\nDo you want to continue (y/n) : ");
        scanf(" %c", &choice);
    }while (choice == 'Y' || choice == 'y');
    return 0;
}
    


