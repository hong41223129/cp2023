#include <stdio.h>
#include <gd.h>
#include <math.h>

void drawFrenchFlag() {
    // 使用ASCII字符表示颜色
    char blue = '#';   // 用#表示蓝色
    char white = ' ';  // 用空格表示白色
    char red = '*';    // 用*表示红色

    // 法国国旗的比例为 2:3
    int height = 2;
    int width = 3;

    // 绘制法国国旗
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // 第一条垂直纹是蓝色
            if (j == 0) {
                printf("%c", blue);
            }
            // 第二条垂直纹是白色
            else if (j == 1) {
                printf("%c", white);
            }
            // 第三条垂直纹是红色
            else if (j == 2) {
                printf("%c", red);
            }
        }
        printf("\n");
    }
}

int main() {
    drawFrenchFlag();

    return 0;
}