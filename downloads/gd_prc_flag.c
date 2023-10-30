#include <stdio.h>
#include <gd.h>

int main() {
    int width = 300; // 中国国旗的宽度
    int height = 200; // 中国国旗的高度

    gdImagePtr img = gdImageCreateTrueColor(width, height);

    // 分配红色
    int red = gdImageColorAllocate(img, 255, 0, 0);
    gdImageFill(img, 0, 0, red);

    // 分配黄色
    int yellow = gdImageColorAllocate(img, 255, 255, 0);

    // 绘制大黄色五角星
    int star_size = height / 2;
    int star_x = width / 6;
    int star_y = height / 4;
    gdImageFilledEllipse(img, star_x, star_y, star_size, star_size, yellow);

    // 绘制小黄色五角星
    int small_star_size = star_size / 4;
    int small_star_x = star_x + star_size * 0.7;
    int small_star_y = star_y + star_size * 0.7;
    for (int i = 0; i < 4; i++) {
        gdImageFilledEllipse(img, small_star_x, small_star_y, small_star_size, small_star_size, yellow);
        small_star_x += star_size * 0.3;
    }

    FILE *outputFile = fopen("china_flag.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }

    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);

    return 0;
}