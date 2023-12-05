#include <stdio.h>
#include <gd.h>

int main() {
    int width = 250; // 日本国旗的宽度
    int height = 150; // 日本国旗的高度

    gdImagePtr img = gdImageCreateTrueColor(width, height);

    // 分配白色
    int white = gdImageColorAllocate(img, 255, 255, 255);
    gdImageFill(img, 0, 0, white);

    // 分配红色
    int red = gdImageColorAllocate(img, 255, 0, 0);

    // 启用抗锯齿
    gdImageSetAntiAliased(img, red);

    // 绘制红色圆圈
    int circle_radius = 80; // 减小半径以使边缘更圆润
    int circle_x = width / 2;
    int circle_y = height / 2;
    gdImageFilledEllipse(img, circle_x, circle_y, circle_radius, circle_radius, red);

    FILE *outputFile = fopen("japan_flag_smooth.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }

    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);

    return 0;
}