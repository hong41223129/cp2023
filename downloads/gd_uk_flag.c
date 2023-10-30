#include <stdio.h>
#include <gd.h>

int main() {
    int width = 300; // 英国国旗的宽度
    int height = 150; // 英国国旗的高度

    gdImagePtr img = gdImageCreateTrueColor(width, height);

    // 分配白色
    int white = gdImageColorAllocate(img, 255, 255, 255);
    gdImageFill(img, 0, 0, white);

    // 分配红色
    int red = gdImageColorAllocate(img, 204, 0, 0);

    // 分配蓝色
    int blue = gdImageColorAllocate(img, 0, 0, 102);

    // 绘制红色十字
    int cross_width = width / 5;
    int cross_height = height / 5;

    // 绘制红色横条
    gdImageFilledRectangle(img, 0, height / 3, width, height / 3 + cross_height, red);

    // 绘制红色竖条
    gdImageFilledRectangle(img, width / 3, 0, width / 3 + cross_width, height, red);

    // 绘制蓝色背景
    gdImageFilledRectangle(img, 0, 0, width / 3, height / 3, blue);

    FILE *outputFile = fopen("uk_flag.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }

    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);

    return 0;
}