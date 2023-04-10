//
// Created by sidtr on 10/04/2023.
//

#ifndef PLAYGROUND_TABLE_H
#define PLAYGROUND_TABLE_H

#endif //PLAYGROUND_TABLE_H
#define WIDTH 100

enum styles {
    Minimalist, Default, Default_Colour, Basic, Basic_Colour
};

void printTable(char *header[], int rows, int cols, char arr[rows][cols][100], enum styles style);

void printHeader(char *header[], int cols, enum styles style, unsigned long int maxWidthPerCol[]);

void printHeader(char *header[], int cols, enum styles style, unsigned long int maxWidthPerCol[]) {

    switch (style) {
        case Basic:
            for (int i = 0; i < cols; i++) {
                if (maxWidthPerCol[i] < WIDTH)
                    printf("%-*s", (int) maxWidthPerCol[i] + 2, header[i]);
                else
                    // We'll try our best
                    printf(" %s ", header[i]);
            }
            break;
        case Basic_Colour:
            for (int i = 0; i < cols; i++) {
                if (maxWidthPerCol[i] < WIDTH)
                    printf(COLOUR_BOLD "%-*s" COLOUR_OFF, (int) maxWidthPerCol[i] + 2, header[i]);
                else
                // We'll try our best
                printf(COLOUR_BOLD " %s " COLOUR_OFF, header[i]);
            }
            break;
        case Default:
            printf("+");
            for (int j = 0; j < (WIDTH - 1); j++) {
                printf("-");
            }
            printf("+\n|");

            for (int i = 0; i < cols; i++) {
                int len = strlen(header[i]);
                int widthPerHeader = WIDTH / cols;
                int padding = (widthPerHeader - len) / 2;

                for (int j = 0; j < padding; j++) {
                    printf(" ");
                }
                printf("%s", header[i]);  // print each string on a new line
                for (int j = 0; j < padding; j++) {
                    printf(" ");
                }
                printf("|");
            }

            printf("\n+");
            for (int j = 0; j < (WIDTH - 1); j++) {
                printf("-");
            }
            printf("+");
            break;
        case Default_Colour:
            printf("+");
            for (int j = 0; j < (WIDTH - 1); j++) {
                printf("-");
            }
            printf("+\n|");

            for (int i = 0; i < cols; i++) {
                int len = strlen(header[i]);
                int widthPerHeader = WIDTH / cols;
                int padding = (widthPerHeader - len) / 2;

                for (int j = 0; j < padding; j++) {
                    printf(" ");
                }
                printf(COLOUR_BOLD "%s" COLOUR_OFF, header[i]);  // print each string on a new line
                for (int j = 0; j < padding; j++) {
                    printf(" ");
                }
                printf("|");
            }

            printf("\n+");
            for (int j = 0; j < (WIDTH - 1); j++) {
                printf("-");
            }
            printf("+");
            break;
        case Minimalist:
            for (int i = 0; i < cols; i++) {
                int len = strlen(header[i]);
                int widthPerHeader = WIDTH / cols;
                int padding = (widthPerHeader - len) / 2;

                printf(COLOUR_UNDERLINE "|");
                for (int j = 0; j < padding; j++) {
                    printf(COLOUR_UNDERLINE " ");
                }
                printf(COLOUR_BOLD "%s" COLOUR_OFF COLOUR_UNDERLINE, header[i]);
                for (int j = 0; j < padding; j++) {
                    printf(" ");
                }
            }
            printf("|");
            break;
        default:
            printf("other");
            break;
    }
    printf("\n" COLOUR_OFF);
}

void printTable(char *header[], int rows, int cols, char arr[rows][cols][100], enum styles style) {
    unsigned long int maxWidth[cols];
    for (int i = 0; i < cols; i++) {
        maxWidth[i] = 0;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            if (strcmp(arr[i][j], "\0") != 0) {
                if ((strlen(arr[i][j]) > maxWidth[j]) && strlen(arr[i][j]) < WIDTH)
                    maxWidth[j] = strlen(arr[i][j]);
                if ((strlen(header[j]) > maxWidth[j]) && strlen(header[j]) < WIDTH)
                    maxWidth[j] = strlen(header[j]);
            }
    }

    printHeader(header, cols, style, maxWidth);

    int widthPerHeader = WIDTH / cols;

    for (int i = 0; i < rows; i++) {
        if (style != Basic && style != Basic_Colour) {
            printf("|");
        }
        for (int j = 0; j < cols; j++) {
            int len = strlen(arr[i][j]);
            int padding = (int) ((style == Basic || style == Basic_Colour) ? maxWidth[j] + 2 : (widthPerHeader - len) /
                                                                                               2);
            if (style == Default || style == Default_Colour || style == Minimalist) {
                for (int k = 0; k < padding; k++) {
                    printf(" ");
                }
            }
            printf("%s", arr[i][j]);
            if (style == Default || style == Default_Colour || style == Minimalist) {
                for (int k = (widthPerHeader == len + (padding * 2) ? 1 : 0); k < padding; k++) {
                    printf(" ");
                }
                printf("|");
            } else {
                // TODO: use padding
                for (int k = 0; k < (padding - len); k++) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    switch (style) {
        case Minimalist:
            break;
        case Basic:
            break;
        case Basic_Colour:
            break;
        case Default:
            printf("+");
            for (int j = 0; j < (WIDTH - 1); j++) {
                printf("-");
            }
            printf("+\n");
            break;
        case Default_Colour:
            printf("+");
            for (int j = 0; j < (WIDTH - 1); j++) {
                printf("-");
            }
            printf("+\n");
            break;
        default:
            break;
    }
    printf(COLOUR_OFF);
}
