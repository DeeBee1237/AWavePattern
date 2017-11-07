#include <stdio.h>

void makeThePattern (int patternNumber) {
    // create a new 2d array and determine the width and height:
    int height = patternNumber;
    // if the number is 3 (say) then we will do 3 up + 2 down + 1 up, etc
    // therefore our width is 1 + 2 + 3 + .. + p = p(p+1)/2
    int width = (patternNumber*(patternNumber + 1))/2;
    char arr [height][width];
    // start loading it up from the bottom left corner here:
    int row = height - 1;
    int col = 0;
    for (int i = 0; i < height; i++) {

        if (i%2 == 0 || i == 0) {
            // upDiagonally
            for (int j = 0; j < height-i; j++) {
                arr[row][col] = '/';

                if (j == height - i - 1)
                    col++;
                else {
                    row--;
                    col++;
                }
            }
        }
        else {
            //	downDiagonally
            for (int j = 0; j < height-i; j++) {
                arr[row][col] = '\\';

                if (j == height - i - 1)
                    col++;
                else {
                    row++;
                    col++;
                }
            }
        }
    }
    // now print it's contents out:
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            char currentChar = arr[row][col];
            if (currentChar != '\\' && currentChar != '/')
                printf("%c",' ');
            else
                printf("%c",arr[row][col]);
        }
        printf("%c",'\n');
    }
}


int main() {

    // pass in the pattern number you would like generated here:
    makeThePattern(4);

    return 0;
}
