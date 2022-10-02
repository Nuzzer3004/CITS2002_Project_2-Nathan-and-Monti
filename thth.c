#include "eyebot.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int v_des = 5030;
int count = 0;
int x_count = 0;

double Kp, Ki, Kd;

FILE *fp;


// void lcd_print(int v_act) {
//     int y = 240-(v_act/42)
//     int LCDPixel(x_count, y, COLOR BLACK);
// }

void pid_controller () {
    fp = fopen("/home/pi/usr/pid.csv", "a");
    /* Proportional controller control */
    int enc_new, v_act, r_mot, e_func;
    static int r_old=0, e_old=0, e_old2=0, enc_old=0;
    enc_new = ENCODERRead(1);

    // Proportional, Integral and Differential Components
    v_act = (enc_new-enc_old) * 100;
    e_func = v_des - v_act;
    r_mot = r_old + Kp*(e_func-e_old) + Ki*(e_func+e_old)/2 + Kd*(e_func - 2 * e_old + e_old2);
    // r_mot = min(r_mot, +100);  /* limit output to 50% */
    // r_mot = max(r_mot, -100); /* limit output */

    if(count < 1000) {
        fprintf(fp, "%i, ", v_act);
        count++;
    }

//    if(x_count < 320) {
//         lcd_print(v_act);
//         x_count++;
//    } else {
//         x_count = 0;
//         LCDClear();
//     }

    MOTORDrive(1, r_mot);
    e_old2 = e_old;
    e_old = e_func;
    r_old = r_mot;
    enc_old = enc_new;

    fclose(fp);

}

int main(int argc, char *argv[]) {
    Kp = atof(argv[1]);
    Ki = atof(argv[2]);
    Kd = atof(argv[3]);

    // LCDInit();
    // usleep(1000);
    // LCDclear();

    TIMER t1;
    t1 = OSAttachTimer(10, &pid_controller);

    while (1)
    {
        usleep(10);
    }

    OSDetachTimer(t1);

    return 0;


}