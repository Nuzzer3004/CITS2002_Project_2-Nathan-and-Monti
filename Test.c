#include "eyebot.h"
/*Compiling
  1:  gccarm –o <filename>, -Werror, -Wall, -pedantic
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count =  0;
int v_des = 5030;
/*
  10,000 ticks/s = 50%
  Max Speed = 10060 ticks/s
  50% = 5300 ticks/s
*/

void file_writer(FILE *fp,int v_act) {
    fprintf(fp, "%i, ", v_act);
}

void onoff_controller(FILE *fp) {
    int enc_new, v_act, r_mot;
    static int enc_old;
    enc_new = ENCODERRead(1);
    v_act = (enc_new-enc_old) * 100;

    if (count < 1000) {
        file_writer(v_act);
        count++;
    }

    // As 100 ticks/s
    if (v_act < v_des) {
        r_mot = 100;
        // 50% speed
    } else {
        r_mot = 0;
    }
    MOTORDrive(1, r_mot);
    enc_old = enc_new;
}

int main(void) {
    TimerHandle t1;
    t1 = OSAttachTimer(10, onoff_controller);
    /*
      1000 --> 1 sec --> 1 Hz
      10 --> 1/100 sec --> 100 Hz
    */
    FILE *fp;
    fp = fopen("/home/pi/usr/software/output.csv", "a");

    while (KEYRead() != KEY4) {
        /* do other tasks, e.g. set speeds */
    }

    OSDetachTimer(t1);
    fclose(fp);

    return 0;
}
