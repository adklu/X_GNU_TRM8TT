#include "thread2.h"
#include "thread1.h"

#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <signal.h>
#include <getopt.h>
#include <sys/poll.h>
#include <string>
#include <cmath>

#include <cstdio>
#include <ctime>

#include <QDebug>
#include <QTimer>

#include <err.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

//#include <alsa/asoundlib.h>
#include "asoundlib.h"
#include <config.h.in>
#include <version.h>

#include <linux/soundcard.h>


#include <QProcess>



static sig_atomic_t done = 0;

//#include "eca-control-interface.h"

int timestartvalue=0;
int timestopvalue=0;
int systemtime=1;
int stoploop;
int initialc=0;
int tapezero=0;
int tapeduration=0;
int playing=0;
//int ntt=0;

//#include <QThread>

//QTimer* timer2 = new QTimer();
//int ntt2 = 0;



//Thread2::Thread2(QObject *parent) : QObject(parent)
  Thread2::Thread2(QObject *parent, bool b) :
      QThread(parent), Stop(b)
{
      //for midi input
//      timer2->setInterval(300);
//      timer2->setSingleShot(false);
//      timer2->start(300);


}


void Thread2::run()

{

aseqdump();

qDebug() << "_____________________--worker thread 2" << reinterpret_cast<std::uintptr_t>(thread()->currentThreadId());



//    while(! done )
//        {



//       systemtime=systemtime+1;


//        sleep(1);








      //qDebug() << "systemtime" << systemtime;

   //}



//        //qDebug() << timevalue;
//        if (ntt==5)
//        {
//        emit possignal(timevalue);
//         }
//                                             if(ntt>5)
//                                                {
//                                               //add_send_hex_data("B0 29 01");
//                                                 //qDebug() << ntt;
//                                                 //int timevalue=ntt;
//                                                 //emit possignal(timevalue);
//                                                }
//                                                if(ntt>10)
//                                                {
//                                               //add_send_hex_data("B0 29 02");
//                                                   // qDebug() << ntt;
//                                                }
//                                                if(ntt>15)
//                                                {
//                                               //add_send_hex_data("B0 29 03");
//                                                    //qDebug() << ntt;
//                                                }
//                                                if(ntt>20)
//                                                {
//                                               //add_send_hex_data("B0 29 04");
//                                                    //qDebug() << ntt;
//                                                }



    //}


//}

exec();
}








void Thread2::startstoploop(int stoploop)
{

//T1:stop
if (stoploop == 1)
{

    timestopvalue = systemtime;

     emit possignalstop(timestopvalue);

//    clock_t endTime = clock();
//    clock_t endTime;
//     qDebug() << "timeInSeconds" << endTime;


//    clock_t clockTicksTaken = endTime - startTime;
//    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;

//    qDebug() << "timeInSeconds" << timeInSeconds;


}

//T1:play
if (stoploop == 0)
{
//    playing=1;
   timestartvalue = systemtime;

    if(initialc==0)
    {
       tapezero=timestartvalue;
    }

   emit possignalstart(timestartvalue);



//    clock_t startTime = clock();

   qDebug() << "startTime nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn";

//   initialc=initialc+1;

//   timetoLED();


   //










     qDebug() << "systemtime" << systemtime;

  }











}



void Thread2::timetoLED()

{

//    if(systemtime==5)
//    {
//      emit possignalstart(5);
//        qDebug() << "systime ====================================05";
//    }
//    if(systemtime==10)
//    {
//      emit possignalstart(10);
//    }
//    if(systemtime==15)
//    {
//      emit possignalstart(15);
//          qDebug() << "systime ====================================015";
//    }




}




//aseqdump
void Thread2::check_snd(const char *operation, int err)
{
    if (err < 0)
        qDebug() << "Cannot %s - %s" << operation << snd_strerror(err);
        //fatal("Cannot %s - %s", operation, snd_strerror(err));
}


//mod of aseqdump.c
void Thread2::aseqdump()
{

qDebug() << "_____________________--aseq  " << reinterpret_cast<std::uintptr_t>(thread()->currentThreadId());
    static snd_seq_t *seq;
    static int port_count;
    static snd_seq_addr_t *ports;

    int do_list = 0;
        struct pollfd *pfds;
        int npfds;
        int c;



    //parse_ports
    char *buf, *s, *port_name;
    int err;

    /* open sequencer */
        err = snd_seq_open(&seq, "default", SND_SEQ_OPEN_DUPLEX, 0);
        check_snd("open sequencer", err);

        /* set our client's name */
        err = snd_seq_set_client_name(seq, "aseqdump");
    check_snd("set client name", err);

    port_name = "X-TOUCH COMPACT";

    /* make a copy of the string because we're going to modify it */
    buf = strdup(port_name);
    //check_mem(buf);

    for (port_name = s = buf; s; port_name = s + 1)
    {
        /* Assume that ports are separated by commas.  We don't use
         * spaces because those are valid in client names. */
        s = strchr(port_name, ',');
        if (s)
            *s = '\0';

        ++port_count;
       // ports = realloc(ports, port_count * sizeof(snd_seq_addr_t));
        ports = static_cast<snd_seq_addr_t*>(realloc(ports, port_count * sizeof(snd_seq_addr_t)));
        //check_mem(ports);

        err = snd_seq_parse_address(seq, &ports[port_count - 1], port_name);
        if (err < 0)
           // fatal("Invalid port %s - %s", port_name, snd_strerror(err));
        qDebug() << "Invalid port";
    }

    free(buf);
    //parse_ports end

    //create_port
        //int err;

        err = snd_seq_create_simple_port(seq, "aseqdump",
                         SND_SEQ_PORT_CAP_WRITE |
                         SND_SEQ_PORT_CAP_SUBS_WRITE,
                         SND_SEQ_PORT_TYPE_MIDI_GENERIC |
                         SND_SEQ_PORT_TYPE_APPLICATION);
    check_snd("create port", err);


    //create_port end

    //connect_ports

        int i;

        for (i = 0; i < port_count; ++i)
        {
            err = snd_seq_connect_from(seq, 0, ports[i].client, ports[i].port);
            if (err < 0)
                qDebug() << "Cannot connect from port %d:%d - %s";
                      //ports[i].client, ports[i].port, snd_strerror(err));
         }
     //connect_ports

        //main

        err = snd_seq_nonblock(seq, 1);
            check_snd("set nonblock mode", err);

            if (port_count > 0)
                printf("Waiting for data.");
            else
                printf("Waiting for data at port %d:0.",
        snd_seq_client_id(seq));


            npfds = snd_seq_poll_descriptors_count(seq, POLLIN);
                pfds = static_cast<pollfd*>(alloca(sizeof(*pfds) * npfds));



                for (;;)
                          {
                               usleep(300000);

                              snd_seq_poll_descriptors(seq, pfds, npfds, POLLIN);
                              if (poll(pfds, npfds, -1) < 0)
                              {
                             // qDebug() << " if (poll(pfds, npfds, -1) < 0)";
                              }
                              do {
                                  snd_seq_event_t *event;
                                  err = snd_seq_event_input(seq, &event);

                                if (err < 0)
                                {
                                    // qDebug() << "err" << err;
                                }

                                  if (event)
                                      dump_event(event);
                              } while (err > 0);

                              fflush(stdout);
                           }



//main end
//timer----------------------------------------------------------------

   qDebug() << "before TIMER++++++++++++++++++++++++++++++++++++++++++++";





//   connect(timer2, &QTimer::timeout, this, [=]() mutable
//   {
//       {


//           snd_seq_poll_descriptors(seq, pfds, npfds, POLLIN);
//           if (poll(pfds, npfds, -1) < 0)
//           {
//               // qDebug() << " if (poll(pfds, npfds, -1) < 0)";
//               // timer2->stop();
//           }

//           do {
//               snd_seq_event_t *event;
//               //

//               err = snd_seq_event_input(seq, &event);

//               if (err < 0)
//               {
//                   // qDebug() << "err" << err;
//               }

//               if (event)
//                   dump_event(event);

//           } while (err > 0);

//           fflush(stdout);

//           ntt2 = ntt2 +1;
//           //qDebug() <<  "this is the timer2 loop:" << ntt2;


//       }


//   });





//timer end------------------------------------------------------------
}


void Thread2::dump_event(const snd_seq_event_t *ev)
{
   // printf("%3d:%-3d ", ev->source.client, ev->source.port);
    switch (ev->type)
    {
    case SND_SEQ_EVENT_NOTEON:
        if (ev->data.note.velocity)
//            printf("Note on                %2d, note %d, velocity %d\n",
//                   ev->data.note.channel, ev->data.note.note, ev->data.note.velocity);

       qDebug() << ev->data.note.note;

        int bytex = ev->data.note.note;







        //activetape buttons of balance knobs
        if (bytex == 0)
                   {
                 qDebug() << "activetape 0 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(0);
                  }
        if (bytex == 1)
                   {
                 qDebug() << "activetape 1 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(1);
                  }
        if (bytex == 2)
                   {
                 qDebug() << "activetape 2 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(2);
                  }
        if (bytex == 3)
                   {
                 qDebug() << "activetape 3 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(3);
                  }
        if (bytex == 4)
                   {
                 qDebug() << "activetape 4 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(4);
                  }
        if (bytex == 5)
                   {
                 qDebug() << "activetape 5 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(5);
                  }
        if (bytex == 6)
                   {
                 qDebug() << "activetape 6 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(6);
                  }
        if (bytex == 7)
                   {
                 qDebug() << "activetape 7 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(7);
                  }

         //buttons of knobs

        if (bytex == 8)
                   {
                 qDebug() << "8 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(8);
                  }

        if (bytex == 9)
                   {
                 qDebug() << "9 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(9);
                  }
        if (bytex == 10)
                   {
                 qDebug() << "10 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(10);
                  }
        if (bytex == 11)
                   {
                 qDebug() << "11 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(11);
                  }
        if (bytex == 12)
                   {
                 qDebug() << "12 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(12);
                  }
        if (bytex == 13)
                   {
                 qDebug() << "13 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(13);
                  }


        if (bytex == 14)
                   {
                 qDebug() << "T2_14 reset searchvalue to 5 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(14);
                  }
        if (bytex == 15)
                   {
                 qDebug() << "T2_14 searchvalue + 10 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(15);
                  }

        //first row
        if (bytex == 16)
                   {
                 qDebug() << "16 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(16);
                  }
        if (bytex == 17)
                   {
                 qDebug() << "17 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(17);
                  }
        if (bytex == 18)
                   {
                 qDebug() << "18  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(18);
                  }
        if (bytex == 19)
                   {
                 qDebug() << "19  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(19);
                  }
        //
        if (bytex == 20)
                   {
                 qDebug() << "20  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(20);
                  }
        if (bytex == 21)
                   {
                 qDebug() << "21 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(21);
                  }
        if (bytex == 22)
                   {
                 qDebug() << "22  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(22);
                  }
        if (bytex == 23)
                   {
                 qDebug() << "23  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(23);
                  }





        //rec enable
        if (bytex == 40)
                   {
                 qDebug() << "40 rec enable 1 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(40);
                  }
        if (bytex == 41)
                   {
                 qDebug() << "41 rec enable 2 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(41);
                  }
        if (bytex == 42)
                   {
                 qDebug() << "42 rec enable 3 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(42);
                  }
        if (bytex == 43)
                   {
                 qDebug() << "43 rec enable 4 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(43);
                  }
        if (bytex == 44)
                   {
                 qDebug() << "44 rec enable 5 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(44);
                  }
        if (bytex == 45)
                   {
                 qDebug() << "45 rec enable 6 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(45);
                  }
        if (bytex == 46)
                   {
                 qDebug() << "46 rec enable 7 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(46);
                  }
        if (bytex == 47)
                   {
                 qDebug() << "47 rec enable 8 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(47);
                  }

        if (bytex == 48)
                   {
                 qDebug() << "48 main button vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

                 emit aseqsignal2(48);
                  }




        //transport

        if (bytex == 49)
                   {
                 qDebug() << "T2_49 RRvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";
                 //rewind(10);
                 emit aseqsignal2(49);
                  }

        if (bytex == 50)
                   {
                 qDebug() << "T2_50 FFvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";
                 //forward(10);
                 emit aseqsignal2(50);
                  }
        if (bytex == 51)
                   {
                 qDebug() << "T2_51 loopvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";
                 //reset();
                 emit aseqsignal2(51);
                  }
        if (bytex == 52)
                   {
                 qDebug() << "T2_52 main recvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";
                 //reset();
                 emit aseqsignal2(52);
                  }
        if (bytex == 53)
                   {
                 qDebug() << "T2_53 STOPvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";
                // pstop();
                 emit aseqsignal2(53);
                  }
        if (bytex == 54)
                   {
                 qDebug() << "T2_54 PLAYvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";
                 //csgetpos();
                 //play();
                 //emit possignalstop(0);
                 emit aseqsignal2(54);
                  }
        //
        if (bytex == 55)
                   {
                 qDebug() << "55 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";
                 //csgetpos();
                 //play();
                 //emit possignalstop(0);
                 emit aseqsignal2(55);
                  }







//        else
//            printf("Note off               %2d, note %d\n",
//                   ev->data.note.channel, ev->data.note.note);
break;

        //

//    case SND_SEQ_EVENT_CONTROLLER:
//            printf("Control change         %2d, controller %d, value %d\n",
//                   ev->data.control.channel, ev->data.control.param, ev->data.control.value);
//    break;

    }

}


//aseqdump end




Thread2::~Thread2()
{

    //ecas.command("engine-halt");
    //jack_client_close(client);
    //sleep(1);

//  quit();

//#if QT_VERSION >= QT_VERSION_CHECK(5,2,0)
//requestInterruption();
//#endif

//wait();
//sleep(1);

}
