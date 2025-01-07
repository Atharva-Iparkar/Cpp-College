#include <iostream>
#include <graphics.h>

void drawCircle(int xc, int yc, int x, int y) {
putpixel(xc + x, yc + y, WHITE);
putpixel(xc - x, yc + y, WHITE);
putpixel(xc + x, yc - y, WHITE);
putpixel(xc - x, yc - y, WHITE);
putpixel(xc + y, yc + x, WHITE);
putpixel(xc - y, yc + x, WHITE);
putpixel(xc + y, yc - x, WHITE);
putpixel(xc - y, yc - x, WHITE);
}

void bresenhamCircle(int xc, int yc, int r) {
int x = 0, y = r;
int d = 3 - 2 * r;
drawCircle(xc, yc, x, y);
while (y >= x) {
x++;
if (d > 0) {
y--;
d = d + 4 * (x - y) + 10;
} else {
d = d + 4 * x + 6;
}

drawCircle(xc, yc, x, y);
}
}

int main() {
int gd = DETECT, gm;
initgraph(&gd, &gm, NULL);
int xc = 250, yc = 250, r = 150;
bresenhamCircle(xc, yc, r);
getch();
closegraph();
delay(4000);

return 0;
}

d_comp_pl_ii_12@d-comp-pl-ii-12:~/S211045_Atharva$ gedit Bresehnem.cpp
d_comp_pl_ii_12@d-comp-pl-ii-12:~/S211045_Atharva$ g++ Bresehnem.cpp -o b -lgraph
d_comp_pl_ii_12@d-comp-pl-ii-12:~/S211045_Atharva$ ./b
[xcb] Unknown sequence number while processing queue
[xcb] Most likely this is a multi-threaded client and XInitThreads has not been called
[xcb] Aborting, sorry about that.
b: ../../src/xcb_io.c:260: poll_for_event: Assertion `!xcb_xlib_threads_sequence_lost' failed.

