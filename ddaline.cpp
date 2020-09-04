#include <stdio.h>
  #include <conio.h>
  #include <graphics.h>
  #include <math.h>
  #include <dos.h>

  int main() {
        /* request auto detection */
        int gdriver = DETECT, gmode, err;
        int key, graphics = 0, detect;
        int i, x1, y1, x2, y2, dx, dy, steps;
        float x, y, xincr, yincr;

        /* initialize graphic mode */
     initgraph(&graphics, &detect, " ");
 /*       err = graphresult();

        if (err != grOk) {
                //error occurred
                printf("Graphic Error: %s\n",
                                grapherrormsg(err));
                getch();
                return 0;
        }
  */


        //draw line from (0, 0) to x-axis & y-axis maximum */
        x1 = y1 = 0;
        x2 = getmaxx(), y2 = getmaxy();

        dx = x2 - x1;
        dy = y2 - y1;

        x = x1, y = y1;

        steps = abs(dx) > abs(dy) ? dx : dy;

        xincr = (1.0 * dx) / steps;
        yincr = (1.0 * dy) / steps;

        putpixel((int) x, (int) y, WHITE);

        /* find the x and y successors and plot the pixels */
        for (i = 0; i < steps; i++) {
                x = x + xincr;
                y = y + yincr;

                /* put a pixel at the given postion(x, y) */
                putpixel((int) x, (int) y, WHITE);

                /* sleep for 50 milliseconds */
                delay(50);
        }

        /* deallocate memory allocated fro graphic screen */
        closegraph();
        return 0;
  }
