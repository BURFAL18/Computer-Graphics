 #include <stdio.h>
  #include <conio.h>
  #include <graphics.h>
  #include <dos.h>

  int main() {
        /* request auto detection */
        int gdriver = DETECT, gmode, err;
        int i = 0, x = 0, y = 0, flag = 0;

        /* initialize graphic mode */
        initwindow(600 ,500," ");
        err = graphresult();

        if (err != grOk) {
                /* error happened */
                printf("Graphics Error: %s\n",
                                grapherrormsg(err));
                return 0;
        }

        /* ball movement */
        while (x <= getmaxx() && !kbhit()) {

                /* set the current drawing color */
                setcolor(LIGHTRED);
                /* fill the ball with given pattern & color */
                setfillstyle(SOLID_FILL, LIGHTRED);

                /* ball with light red color */
                pieslice(x, y, 0, 360, 12);

                /* ball movement towards x-axis */
                if (i % 5 == 0) {
                        /* left to right */
                        x = x + 3;
                        i = 0;
                }


                /* ball movement towards y-axis */
                if (flag) {
                        /* bottom to top */
                        y = y - 10;
                } else {
                        /* top to bottom */
                        y = y + 10;
                }

                /* check whether ball reached y-axis maximum */
                if (y >= getmaxy()) {
                        flag = 1;
                } else if (y <= 0) {
                        flag = 0;
                }

                /* sleeps for 50 milliseconds */
                delay(50);
                /* clear the graphic screen */
                cleardevice();
                i++;
        }

        getch();

        /* deallocate memory allocated for graphic system */
        closegraph();

        return 0;
  }
