#include <stdio.h>
#include <gd.h>
#include <math.h>

int main() {
    int rows = 15; // 國旗的行數
    int cols = 30; // 國旗的列數

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i < rows / 3) {
                printf("\033[47m  "); // 白色部分
            } else if (i < 2 * rows / 3) {
                printf("\033[41m  "); // 紅色部分
            } else {
                printf("\033[34m  "); // 藍色部分
            }
        }
        printf("\033[0m\n"); // 重置顏色
    }

    return 0;
}