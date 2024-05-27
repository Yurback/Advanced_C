#include <stdio.h>
#include <stdbool.h>

struct onscreen_box
{
    unsigned char : 2;
    unsigned char opaque : 1;
    unsigned char f_color : 3;
    unsigned char : 2;
    unsigned char dysplay : 1;
    unsigned char b_color : 3;
    unsigned char type_border : 4;
};

char *types_colors[8] = {"Black", "Red", "Green", "Yellow", "Blue", "Magenta", "Cyan", "White"};

char *types_borders[3] = {"Solid", "Dotted", "Dashed"};

char *types_opacity[2] = {"Opaque", "Transparent"};

char *types_dysplay[2] = {"Shown", "Hidden"};

int main(void)
{
    struct onscreen_box user_settings = {1, 4, 1, 3, 1};
    printf("Your settings are:\nBox is %s\nThe fill color is %s\nBorder is %s\nThe border color is %s\nThe border style is%s\n",
           types_opacity[user_settings.opaque], types_colors[user_settings.f_color], types_dysplay[user_settings.dysplay], types_colors[user_settings.b_color], types_borders[user_settings.type_border]);

    user_settings.opaque = 1;
    user_settings.f_color = 7;
    // user_settings["dysplay"] = 1; // To implement hash-table needs to visit site https://benhoyt.com/writings/hash-table-in-c/
    user_settings.dysplay = 1;
    user_settings.b_color = 7;
    user_settings.type_border = 2;

    printf("\n\nModified settings are:\nBox is %s\nThe fill color is %s\nBorder is %s\nThe border color is %s\nThe border style is%s\n",
           types_opacity[user_settings.opaque], types_colors[user_settings.f_color], types_dysplay[user_settings.dysplay], types_colors[user_settings.b_color], types_borders[user_settings.type_border]);

    unsigned char num = 0b10000000;
    printf("The size of boolean is %d\n", num);
    printf("The size of boolean is %0x\n", num);

 struct onscreen_box two = user_settings;
	two.type_border = 0;
	
    printf("The size of boolean is %0lx\n", sizeof(struct onscreen_box));
    printf("Size of onscreenbox: %0b\n", user_settings);
    printf("Size of onscreenbox: %0b\n", user_settings.type_border);
    
        printf("Size of onscreenbox: %0b\n", two);
    printf("Size of onscreenbox: %0b\n", two.type_border);
    
    
    return 0;
}
