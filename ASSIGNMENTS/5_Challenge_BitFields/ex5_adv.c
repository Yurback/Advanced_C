#include <stdio.h>

struct onscreen_box
{
    unsigned int : 4;
    unsigned int opaque : 1;
    unsigned int f_color : 3;
    unsigned int : 2;
    unsigned int dysplay : 1;
    unsigned int b_color : 3;
    unsigned int type_border : 2
};

char *types_colors[8] = {"Black", "Red", "Green", "Yellow", "Blue", "Magenta", "Cyan", "White"};

char *types_borders[3] = {"Solid", "Dotted", "Dashed"};

char *types_opacity[2] = {"Opaque", "Transparent"};

char *types_dysplay[2] = {"Shown", "Hidden"};

int main(void)
{

    struct onscreen_box user_settings = {0, +1, +4, 0, +1, +3, 1};
    printf("Your settings are:\nBox is %s\nThe fill color is %s\nBorder is %s\nThe border color is %s\nThe border style is%s\n",
           types_opacity[user_settings.opaque], types_colors[user_settings.f_color], types_dysplay[user_settings.dysplay], types_colors[user_settings.b_color], types_borders[user_settings.type_border]);

    user_settings.opaque = 0;
    user_settings.f_color = 7;
    user_settings.dysplay = 1;
    user_settings.b_color = 7;
    user_settings.type_border = 2;

    printf("\n\nModified settings are:\nBox is %s\nThe fill color is %s\nBorder is %s\nThe border color is %s\nThe border style is%s\n",
           types_opacity[user_settings.opaque], types_colors[user_settings.f_color], types_dysplay[user_settings.dysplay], types_colors[user_settings.b_color], types_borders[user_settings.type_border]);

    return 0;
}