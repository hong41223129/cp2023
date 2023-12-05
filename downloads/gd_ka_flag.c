#include <stdio.h>
#include <gd.h>
#include <math.h>

int main() {
    // 初始化繪圖窗口
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // 繪製白色背景
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, getmaxx(), getmaxy());

    // 繪製藍色部分
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(100, 100, 500, 400);
    floodfill(300, 250, WHITE);

    // 繪製紅色和黑色圓圈
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    circle(300, 250, 50);
    floodfill(300, 250, RED);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(300, 250, 10);
    floodfill(300, 250, BLACK);

    // 關閉繪圖窗口
    delay(5000);
    closegraph();

    return 0;
}