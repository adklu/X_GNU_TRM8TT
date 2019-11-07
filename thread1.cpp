int activetapeNR=1;

//alsa midi input/output system contains modifications of
//aseqdump.c and amidi.c (original files by Clemens Ladisch published under the GNU General Public License 2 or later, see originalfiles folder)
//modifications by A.D.Klumpp published under the GNU General Public License 2 or later
//see comments

//required libs
//jack dev libs
//libjack-dev
//or
//libjack-jackd2-dev

//alsa dev libs
//libasound2-dev

//list jack ports: jack_lsp -c

//midi input: valueGotStart(int timestartvalue)

//delete a track
//1) enter tape with track, which should be removed
//2) press the buttons of knobs 9 and 10
//3) select the track to delete via the top button row (below pan knobs)

//restartmodes()
//press main button + balance knob 1-8 to set the active tape for restart
//pressing the knobs 1-8 will set restart1 to 1, which will restart the progam:
//1) when pressing main into playback mode by setting maincounter to 1
//2) when pressing rec 1 into mono recording mode by setting rec1counter to 1
//3) stereo rec mode when pressing rec 2

//button of knob 11 can reset all faders, when fader controll crashed/frozen


//full text here
//sh replaced
//#kill -9 $(ps -ef | grep "GNU_TRM8TT" | grep -v grep | awk '{print $2}')
//by
//if pgrep GNU_TRM8TT; then pkill GNU_TRM8TT; fi



//for standalone headless OS:
//- sh to close ecasound (and turn off system (qprocess sh script))
//alias sudo='sudo password'
//alias turnoff='shutdown -h now'
//shutdown -h now




//known bugs
//fader cops can crash, if used when transport is stopped (button of knob 11 can reset all faders), could be a bug in ecasound

//removed
// effecttrack(4);
//compressor/limiter
//[- hardware/software monitor switch]





int recmode=0;
int recmode2counter=0;
int deletepre1=0;
int deletepre2=0;
int deletepre3=0;

int trackNRRecLED1=0;
int trackNRRecLED2=0;

int RecLED1counter=0;
int RecLED2counter=0;

int timerLEDsOK=0;


//midi main switch: 1360
//1606: alsadump!!!! off to test vu meter, turn back on later!!

//from const char
//std::string qecasv_bar_buffer= (char*)ecasv_bar_buffer;
//QString T4= QString::fromStdString(qecasv_bar_buffer);

#include <QDateTime>
#include "thread1.h"
#include <QDebug>
#include <QString>
//#include <QMutex>
#include <eca-control-interface.h>
#include "mainwindow.h"

#include <QApplication>
#include <QProcess>

//#include <QStandardPaths>
#include <QDir>

#include <QMessageBox>

#include <QTimer>

#include <QFile>

#include <QByteArray>


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

#include <jack/statistics.h>


#include <jack/jack.h>
#include <jack/transport.h>
//#include <jack/metadata.h>
//#include <jack/session.h>

//>>signal
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include <cassert>
#include <cmath>
#include <cstdio>

#include <ctime>

#include <signal.h>
#include <unistd.h>


#include <sys/time.h>     /* POSIX: select() */
#include <sys/select.h>   /* POSIX: timeval struct */

#include "kvu_numtostr.h"

#include "eca-control-interface.h"

#include "ecicpp_helpers.h"


#include <cstring>


//ALSA
//install libasound2 and libasound2-dev

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


//#include <QProcess>

#include <cstdio>
#include <ctime>
#include <cmath>

#include <vector>

//#include <thread>
//#include <mutex>
//#include <condition_variable>

QString activetape=NULL;
QString HomePathT = QDir::homePath();
//QString TapesPath = HomePathT + "/" + "TRM8TT_Tape";



//QString activetape = HomePathT + "/" + "TRM8TT_Tapes" + "/" + "TRM8TT_Tape_1";

//int track1_rec = 0;
//int track2_rec = 0;
//int track3_rec = 0;
//int track4_rec = 0;
//int track5_rec = 0;
//int track6_rec = 0;
//int track7_rec = 0;
//int track8_rec = 0;



std::vector<int> emptytracksar;

int emptytracks = 0;


int oneemptytrack=0;

int track_rec[] = {0, 0, 0, 0, 0, 0, 0, 0};
int maxrectracks = 0;
int mainrec = 0;
int twotracks = 0;
int reconly1track = 0;
int only1 = 0;

int togglerec = 0;
int toggleeffect1 = 0;
int toggleeffect2 = 0;
int toggleeffect3 = 0;
int toggleeffect4 = 0;
int toggleeffect5 = 0;
int toggleeffect6 = 0;
int toggleeffect7 = 0;
int toggleeffect8 = 0;

int toggleeffect11 = 0;
int toggleeffect22 = 0;
int toggleeffect33 = 0;
int toggleeffect44 = 0;
int toggleeffect55 = 0;
int toggleeffect66 = 0;
int toggleeffect77 = 0;
int toggleeffect88 = 0;

int toggleeffect111 = 0;
int toggleeffect222 = 0;
int toggleeffect333 = 0;
int toggleeffect444 = 0;
int toggleeffect555 = 0;
int toggleeffect666 = 0;
int toggleeffect777 = 0;
int toggleeffect888 = 0;


int toggleeffect9 = 0;


int rec1counter = 0;
int rec2counter = 0;
int rec3counter = 0;
int rec4counter = 0;
int rec5counter = 0;
int rec6counter = 0;
int rec7counter = 0;
int rec8counter = 0;

int maincounter = 0;

int restart1 = 0;
int restart2 = 0;
int restart3 = 0;
int restart4 = 0;
int restart5 = 0;
int restart6 = 0;
int restart7 = 0;
int restart8 = 0;


 snd_seq_t *seq;

int searchvalueN = 3;

char resultport[100];
const char *  rxconnect;

static char *send_hex;
static char *send_data;
static int send_data_length;

static snd_rawmidi_t *input, **inputp;
static snd_rawmidi_t *output, **outputp;

//end ALSA

using namespace std;

//set channel number
static int ecasv_chcount = 8;
//signalmeter
static sig_atomic_t done = 0;



  jack_port_t*  ecaMasterIN_1;
   jack_port_t*  ecaMasterIN_2;
    jack_port_t*  ecaMasterOUT_1;
     jack_port_t*  ecaMasterOUT_2;



QProcess process1;
QProcess process2;


ECA_CONTROL_INTERFACE ecas;


jack_port_t *input_port;
jack_port_t *output_port;
jack_client_t *client;
jack_client_t *mclient;

    const char **ports;
    const char *client_name;
    const char *mclient_name;

    jack_options_t options = JackNullOption;
    jack_options_t moptions = JackNullOption;
    jack_status_t status;
      jack_status_t mstatus;


    QString qserver_name = "default";
    std::string qtserver_name = qserver_name.toStdString();
    const char * server_name = qtserver_name.c_str();

    QString mqserver_name = "mdefault";
    std::string mqtserver_name = mqserver_name.toStdString();
    const char * mserver_name = mqtserver_name.c_str();



int quitnumber = 0;

int timepointer = 0;


//clock
QTimer* timer = new QTimer();
int ntt = 0;

//QTimer* timer2 = new QTimer();
//int ntt2 = 0;

//QTimer* timer3 = new QTimer();
//int ntt3 = 0;


//


Thread1::Thread1(QObject *parent, bool b) :
    QThread(parent), Stop(b)
{

    readtapeslottxt();


    tThread = new Thread2(this);

     //tThread->start();

    connect(tThread,SIGNAL(possignalstart(int)), this, SLOT(valueGotStart(int)));
    connect(tThread,SIGNAL(possignalstop(int)), this, SLOT(valueGotStop(int)));
    connect(this,SIGNAL(stopsignal(int)), tThread, SLOT(startstoploop(int)));

    connect(tThread,SIGNAL(aseqsignal2(int)), this, SLOT(valueGotAseq(int)));







//    //for midi input
//    timer2->setInterval(300);
//    timer2->setSingleShot(false);
//    timer2->start(300);






    //for vu meter
//    timer3->setInterval(80);
//    timer3->setSingleShot(false);
//    timer3->start(80);

   // for clock
    timer->setInterval(1000); //milliseconds
    timer->setSingleShot(false);
    connect(timer, &QTimer::timeout, this, [=]() mutable
    {
int  rcsposimin;
int rcsposisec;

//        ecas.command("cs-get-position");
//                      double cspos = ecas._float();
                            ntt = ntt +1;
                      int rcsposi = ntt;
                      sleep(1);


                      //int rcsposi = std::round(cspos);
                       if(rcsposi>60)
                       {
                           rcsposimin = (std::round(rcsposi/60));
                           rcsposisec = rcsposi - (rcsposimin * 60);
                       }
                       if(rcsposi<=60)
                       {
                           rcsposimin = 0;
                           rcsposisec = rcsposi;
                       }


              qDebug() << rcsposimin << ":" << rcsposisec;



if(timerLEDsOK==1)
        {


                add_send_hex_data("B0 19 05");
                add_send_hex_data("B0 18 05");




      //sec

              if(rcsposisec>5)
              {
             add_send_hex_data("B0 29 01");
              }
              if(rcsposisec>10)
              {
             add_send_hex_data("B0 29 02");
              }
              if(rcsposisec>15)
              {
             add_send_hex_data("B0 29 03");
              }
              if(rcsposisec>20)
              {
             add_send_hex_data("B0 29 04");
              }
              //
              if(rcsposisec>25)
              {
             add_send_hex_data("B0 29 05");
              }
              if(rcsposisec>30)
              {
             add_send_hex_data("B0 29 06");
              }
              if(rcsposisec>35)
              {
             add_send_hex_data("B0 29 07");
              }
              if(rcsposisec>40)
              {
             add_send_hex_data("B0 29 08");
              }
              //
              if(rcsposisec>45)
              {
             add_send_hex_data("B0 29 09");
              }
              if(rcsposisec>50)
              {
             add_send_hex_data("B0 29 0A");
              }
              if(rcsposisec>55)
              {
             add_send_hex_data("B0 29 0B");
              }
              if(rcsposisec>58)
              {
             add_send_hex_data("B0 29 0C");
              }

//min
                                         if(rcsposimin>0)
                                         {
                                        add_send_hex_data("B0 28 01");
                                         }
                                         if(rcsposimin>1)
                                         {
                                        add_send_hex_data("B0 28 02");
                                         }
                                         if(rcsposimin>2)
                                         {
                                        add_send_hex_data("B0 28 03");
                                         }
                                         if(rcsposimin>3)
                                         {
                                        add_send_hex_data("B0 28 04");
                                         }
                                         //
                                         if(rcsposimin>4)
                                         {
                                        add_send_hex_data("B0 28 05");
                                         }
                                         if(rcsposimin>5)
                                         {
                                        add_send_hex_data("B0 28 06");
                                         }
                                         if(rcsposimin>6)
                                         {
                                        add_send_hex_data("B0 28 07");
                                         }
                                         if(rcsposimin>7)
                                         {
                                        add_send_hex_data("B0 28 08");
                                         }
                                         //
                                         if(rcsposimin>8)
                                         {
                                        add_send_hex_data("B0 28 09");
                                         }
                                         if(rcsposimin>9)
                                         {
                                        add_send_hex_data("B0 28 0A");
                                         }
                                         if(rcsposimin>10)
                                         {
                                        add_send_hex_data("B0 28 0B");
                                         }
                                         if(rcsposimin>11)
                                         {
                                        add_send_hex_data("B0 28 0C");
                                         }



 }

    });



    //++++++connect to Jack+++++

//    if (m_pJackClient)
//            stopJack();
//        else
//    startJack();
//++++++++++++++++++++
//   QString acommand = "gnome-terminal -x bash -c \"jackd -R -d alsa -d hw:Audio -r 44100 -p 512";
//   qDebug() << acommand;
//   process2.start(acommand);


sleep(1);

    QString qclient_name = "ecasound";
    std::string qtclient_name = qclient_name.toStdString();
    const char * client_name = qtclient_name.c_str();



    client = jack_client_open (client_name, options, &status, server_name);
       qDebug() << "client";
       qDebug() << client;
       qDebug() << client_name;


       //

//       QString mqclient_name = "ecaMaster";
//       std::string mqtclient_name = mqclient_name.toStdString();
//       const char * mclient_name = mqtclient_name.c_str();



//       mclient = jack_client_open (mclient_name, moptions, &mstatus, mserver_name);
//          qDebug() << "mclient";
//          qDebug() << mclient;
//          qDebug() << mclient_name;



//        ecaMasterIN_1 = jack_port_register 	(mclient,"ecaMasterIN_1",JACK_DEFAULT_AUDIO_TYPE,JackPortIsInput,2);
//          ecaMasterIN_2 = jack_port_register 	(mclient,"ecaMasterIN_2",JACK_DEFAULT_AUDIO_TYPE,JackPortIsInput,2);

//            ecaMasterOUT_1 = jack_port_register 	(mclient,"ecaMasterOUT_1",JACK_DEFAULT_AUDIO_TYPE,JackPortIsOutput,2);
//              ecaMasterOUT_2 = jack_port_register 	(mclient,"ecaMasterOUT_2",JACK_DEFAULT_AUDIO_TYPE,JackPortIsOutput,2);


//              if (jack_activate (mclient)) {
//                      qDebug() << "---------------------------------------cannot activate client";

//                  }



//              if (jack_activate (client)) {
//                      qDebug() << "---------------------------------------cannot activate client";

//                  }


       //

        if (client == NULL)
        {
               qDebug() << "client == NULL";
        }

        if (status & JackServerStarted)
        {
             qDebug() << "JACK server started";
        }

        if (status & JackNameNotUnique)
        {
           client_name = jack_get_client_name(client);
            qDebug() << "TRM8TT/ecasound engine already running. Please close TRM8TT/ecasound and kill all running instances of ecasound before restarting.";
            qDebug() << client_name;

         quitnumber = quitnumber +1;



//            QMessageBox msgBox;
//               msgBox.setText("TRM8TT/ecasound engine already running. Please close TRM8TT/ecasound and kill all running instances of ecasound before restarting.");
//               msgBox.exec();

         }


        qDebug() << "client_name3";
        qDebug() << client_name;



   sleep(1);

//alsaconnect();





}

void Thread1::valueGotStart(int timestartvalue)
{

// effecttrack(4);
    //                //turn off all fan lights
                   // add_send_hex_data("B0 28 00");
                   //  add_send_hex_data("B0 29 00");
    qDebug() << "timestartvalue" << timestartvalue;

    //timepointer = timevalue;

    //add_send_hex_data("B0 29 01");

    if (timestartvalue > 5)
    {
   add_send_hex_data("B0 29 01");
    }

    if (timestartvalue > 10)
    {
   add_send_hex_data("B0 29 02");
    }

    if (timestartvalue > 15)
    {
   add_send_hex_data("B0 29 03");
   qDebug() << "signal received..................................";
    }

    //


}


//  connect(tThread,SIGNAL(aseqsignal2(int)), this, SLOT(valueGotAseq(int)));
void Thread1::valueGotAseq(int aseqsignal2value)
{


    if (aseqsignal2value == 8)
    {
     qDebug() << "cccccccccccccccccccccccccccccc 8 received";
     deletepre1=1;
    }

    if (aseqsignal2value == 9)
    {
     qDebug() << "cccccccccccccccccccccccccccccc 9 received";
     deletepre2=1;
    }
    if (aseqsignal2value == 10)
    {
     qDebug() << "cccccccccccccccccccccccccccccc 10 received";
     if(timerLEDsOK==1)
     {
         ecas.command("c-select chainMaster");
         ecas.command("cop-set ’1,1,0’");
         sleep(1);
         ecas.command("c-select chain1");
         ecas.command("cop-set ’3,1,0’");
         sleep(1);
         ecas.command("c-select chain2");
         ecas.command("cop-set ’3,1,0’");
         sleep(1);
         ecas.command("c-select chain3");
         ecas.command("cop-set ’3,1,0’");
         sleep(1);
         ecas.command("c-select chain4");
         ecas.command("cop-set ’3,1,0’");
         sleep(1);
         ecas.command("c-select chain5");
         ecas.command("cop-set ’3,1,0’");
         sleep(1);
         ecas.command("c-select chain6");
         ecas.command("cop-set ’3,1,0’");
         sleep(1);
         ecas.command("c-select chain7");
         ecas.command("cop-set ’3,1,0’");
         sleep(1);
         ecas.command("c-select chain8");
         ecas.command("cop-set ’3,1,0’");

         add_send_hex_data("B0 24 1C");

         sleep(2);

          add_send_hex_data("B0 24 00");



          qDebug() << "ea reset";
     }

    }



//     if (toggleeffect9==0)
//      {
//      //effectmainlim();
//      //toggleeffect9=toggleeffect9+1;
//     }
//      else
//     {
//      //effectoff(4);
//     }






//top row, delete track
    if (aseqsignal2value == 16)
    {
     qDebug() << "11cccccccccccccccccccccccccccccccccccccccc 16 received";
     recmode=11;
     deletepre3=1;
     restartmodes();


    }
    if (aseqsignal2value == 17)
    {
     qDebug() << "12cccccccccccccccccccccccccccccccccccccccc 17 received";


    recmode=12;
     deletepre3=1;
     restartmodes();

    }
    if (aseqsignal2value == 18)
    {
     qDebug() << "13ccccccccccccccccccccccccccccccccccccccccr 18 received";
         recmode=13;
          deletepre3=1;
          restartmodes();

    }
    if (aseqsignal2value == 19)
    {
     qDebug() << "14ccccccc444cccccccccccccccccccccccccccccccccr 19 received";
         recmode=14;
          deletepre3=1;
          restartmodes();



    }
    //
    if (aseqsignal2value == 20)
    {
     qDebug() << "15ccccccc444cccccccccccccccccccccccccccccccccr 20 received";
         recmode=15;
          deletepre3=1;
          restartmodes();


    }
    //
    if (aseqsignal2value == 21)
    {
     qDebug() << "16ccccccc444cccccccccccccccccccccccccccccccccr 21 received";
         recmode=16;
          deletepre3=1;
          restartmodes();



    }
    //
    if (aseqsignal2value == 22)
    {
     qDebug() << "17ccccccc444cccccccccccccccccccccccccccccccccr 22 received";
         recmode=17;
          deletepre3=1;
          restartmodes();



    }
    //

    //

    if (aseqsignal2value == 23)
    {
     qDebug() << "18ccccccc444cccccccccccccccccccccccccccccccccr 23 received";
         recmode=18;
          deletepre3=1;
          restartmodes();


    }







    if (aseqsignal2value == 54)
    {
    play();

    if((recmode==1)||(recmode==2))
    {
        rectrackled();
        add_send_hex_data("90 24 02");

    }
    }

    if (aseqsignal2value == 53)
    {
    pstop();
    mainrec = 0;
    }

    if (aseqsignal2value == 49)
    {
    //rewind(10);
    rewind(searchvalueN);
    }

    if (aseqsignal2value == 50)
    {
    //forward(10);
    forward(searchvalueN);
    }

    if (aseqsignal2value == 51)
    {
    reset();
    }

    if (aseqsignal2value == 14)
    {
searchvalueN=3;
qDebug() << "searchvalueN=3" << searchvalueN;
    }

    if (aseqsignal2value == 15)
    {
searchvalueN=searchvalueN+10;
qDebug() << "searchvalueN=searchvalueN+10" << searchvalueN;
    }

    //main rec
    if (aseqsignal2value == 52)
    {
        if(togglerec==0)
        {

              if(recmode==0)
              {
                  activetapeLED();
                  recreadyled();
              }

              if((recmode==1)||(recmode==2))
              {
                  rectrackled();
                  activetapeLED();
                  sleep(1);
                   add_send_hex_data("90 24 02");

              }

    togglerec=togglerec+1;
        }
        else
        {



            if(recmode==0)
            {
            //all rec leds off
                  add_send_hex_data("90 18 01");
                  add_send_hex_data("90 19 01");
                  add_send_hex_data("90 1A 01");
                  add_send_hex_data("90 1B 01");
                  add_send_hex_data("90 1C 01");
                  add_send_hex_data("90 1D 01");
                  add_send_hex_data("90 1E 01");
                  add_send_hex_data("90 1F 01");

                 // rec led
                  add_send_hex_data("90 24 01");

                  //tape slot led off
                  add_send_hex_data("B0 1A 07");
                    add_send_hex_data("B0 1B 07");
                      add_send_hex_data("B0 1C 07");
                        add_send_hex_data("B0 1D 07");
                          add_send_hex_data("B0 1E 07");
                            add_send_hex_data("B0 1F 07");
                              add_send_hex_data("B0 20 07");
                                add_send_hex_data("B0 21 07");


                }

            else if((recmode==1)||(recmode==2))
            {
                rectrackled();



                //tape slot led off
                add_send_hex_data("B0 1A 07");
                  add_send_hex_data("B0 1B 07");
                    add_send_hex_data("B0 1C 07");
                      add_send_hex_data("B0 1D 07");
                        add_send_hex_data("B0 1E 07");
                          add_send_hex_data("B0 1F 07");
                            add_send_hex_data("B0 20 07");
                              add_send_hex_data("B0 21 07");
                              sleep(1);
                               add_send_hex_data("90 24 02");

            }


                  togglerec=0;


        }
    //mainrec  = 1;
    //only1 = 0 ;
    //recreadyledinit();
    }


    //activetape

    //enable one channel recordings
    if (aseqsignal2value == 40)
    {
        //rec1counter = rec1counter + 1;
         maincounter = 1;

          qDebug() << "------------------40----------------------rec1counter" <<  maincounter;

          recmode=1;

          restartmodes();



    }

    //enable 2 channel recordings
    if (aseqsignal2value == 41)
    {
        //rec1counter = rec1counter + 1;
         maincounter = 1;

          qDebug() << "------------------41----------------------rec2counter" <<  maincounter;

          recmode=2;

          restartmodes();

    }

    //main button
    if (aseqsignal2value == 48)
    {
        //maincounter = maincounter + 1;
         maincounter =1;


         recmode=0;

          qDebug() << "-------------------48---------------------maincounter" << maincounter;

          restartmodes();
    }



    if (aseqsignal2value == 0)
    {
activetapeNR=1;
        restart1=1;

         qDebug() << "-------------------0 knob----------------restart1=1";

         restartmodes();

//activetape=HomePathT + "/" + "TRM8TT_Tapes" + "/" + "TRM8TT_Tape_1";
    }





    //
    if (aseqsignal2value == 1)
    {
        activetapeNR=2;
               restart1=1;
               restartmodes();
//activetape=HomePathT + "/" + "TRM8TT_Tapes" + "/" + "TRM8TT_Tape_2";
    }

    if (aseqsignal2value == 2)
    {
        activetapeNR=3;
               restart1=1;
               restartmodes();
//activetape=HomePathT + "/" + "TRM8TT_Tapes" + "/" + "TRM8TT_Tape_3";
    }

    if (aseqsignal2value == 3)
    {
        activetapeNR=4;
               restart1=1;
               restartmodes();
//activetape=HomePathT + "/" + "TRM8TT_Tapes" + "/" + "TRM8TT_Tape_4";
    }

    if (aseqsignal2value == 4)
    {
        activetapeNR=5;
               restart1=1;
               restartmodes();
//activetape=HomePathT + "/" + "TRM8TT_Tapes" + "/" + "TRM8TT_Tape_5";
    }

    if (aseqsignal2value == 5)
    {
        activetapeNR=6;
               restart1=1;
               restartmodes();
//activetape=HomePathT + "/" + "TRM8TT_Tapes" + "/" + "TRM8TT_Tape_6";
    }

    if (aseqsignal2value == 6)
    {
        activetapeNR=7;
               restart1=1;
               restartmodes();
//activetape=HomePathT + "/" + "TRM8TT_Tapes" + "/" + "TRM8TT_Tape_7";
    }

    if (aseqsignal2value == 7)
    {
        activetapeNR=8;
               restart1=1;
               restartmodes();
//activetape=HomePathT + "/" + "TRM8TT_Tapes" + "/" + "TRM8TT_Tape_8";
    }
    //
    if (aseqsignal2value == 55)
    {
         //deletetrack();
         qDebug() << "55 received";
//activetape=HomePathT + "/" + "TRM8TT_Tapes" + "/" + "TRM8TT_Tape_8";
    }




}




void Thread1::restartmodes()
{

//restart in playback mode
if ((restart1 == 1)&&(maincounter==1))
{

recmodesfile();
tapesfile();

qDebug() << "mmmmmmmmmmmmmmmmmmmmmmmmmrestart";

//restart LED art
add_send_hex_data("90 18 03");

add_send_hex_data("90 1A 03");

add_send_hex_data("90 1C 03");

add_send_hex_data("90 1E 03");

sleep(2);
add_send_hex_data("90 18 01");

add_send_hex_data("90 1A 01");

add_send_hex_data("90 1C 01");

add_send_hex_data("90 1E 01");

sleep(1);

exitslot();

}

//restart in one track mono recoding mode
if ((restart1==1)&&(rec1counter==1))
{

    recmodesfile();
    tapesfile();


qDebug() << "mmmmmmmmmmmmmmmmmmmmmmmmmrestart ";

//restart LED art
add_send_hex_data("90 18 03");

add_send_hex_data("90 1A 03");

add_send_hex_data("90 1C 03");

add_send_hex_data("90 1E 03");

sleep(2);
add_send_hex_data("90 18 01");

add_send_hex_data("90 1A 01");

add_send_hex_data("90 1C 01");

add_send_hex_data("90 1E 01");

sleep(1);


exitslot();

}

if((deletepre1==1)&&(deletepre2==1)&&(deletepre3==1))
{
    recmodesfile();
    qDebug() << "deleting track... mmmmmmmmmmmmmmmmmmmmmmmmmrestart ";

    add_send_hex_data("B0 23 1C");

    sleep(2);

     add_send_hex_data("B0 23 00");


    exitslot();
}



}


//
void Thread1::recmodesfile()
{

    //main button:  recmode=0
    //rec 1 button:  recmode=1

    QFile chfile("trm8tt_recmode.txt");
                 if (!chfile.open(QIODevice::WriteOnly | QIODevice::Text))
                 {
   qDebug() << "..............restart error can't write file... blink warning here........";
                 }
                      // return;
                 else
                 {
                   QTextStream outh(&chfile);
                   outh << recmode;
                   qDebug() << "writing to file before restarting...recmode.. ." << recmode;
                  }

                   chfile.close();

}

void Thread1::tapesfile()
{
    QFile thfile("trm8tt_tapeslot.txt");
                 if (!thfile.open(QIODevice::WriteOnly | QIODevice::Text))
                 {
   qDebug() << "..............restart error can't write file... blink warning here........";
                 }
                      // return;
                 else
                 {
                   QTextStream outh(&thfile);
                   outh << activetapeNR;
                   qDebug() << "writing to file before restarting..tapeslot... ." << activetapeNR;
                  }

                   thfile.close();



}

void Thread1::activetapeLED()
{
    if(activetapeNR==1)
    {
         //add_send_hex_data("90 00 03");
          add_send_hex_data("B0 1A 1C");
    }
    if(activetapeNR==2)
    {
         add_send_hex_data("B0 1B 1C");
    }
    if(activetapeNR==3)
    {
         add_send_hex_data("B0 1C 1C");
    }
    if(activetapeNR==4)
    {
         add_send_hex_data("B0 1D 1C");
    }
    if(activetapeNR==5)
    {
         add_send_hex_data("B0 1E 1C");
    }
    if(activetapeNR==6)
    {
         add_send_hex_data("B0 1F 1C");
    }
    if(activetapeNR==7)
    {
         add_send_hex_data("B0 20 1C");
    }
    if(activetapeNR==8)
    {
         add_send_hex_data("B0 21 1C");
    }

}

//not used
void Thread1::effectmainlim()
{
    qDebug() << "received main lim...........++++++++++++.............";

    ecas.command("cs-select play_chainsetup");
    ecas.command("c-select chainMaster");
    //-eal:limit-%
    ecas.command("cop-add -eal:98");

     //add_send_hex_data("B0 23 1B");

}


//example for later added effects (not used)
 void Thread1::effecttrack(int effecttrackNR)
 {


//for track 5 triggered from other function with:    effecttrack(4);

     qDebug() << "received rectrack........................" << effecttrackNR;


//



     //


   //jack_transport_stop(client);



   // int trackNR = 5;
 //QString TapeName =  TapesPath + "/TRM8TT_Track_" + QString::number(trackNR) + ".wav";
 //QString TrackName = activetape + "/Track_" + QString::number(trackNR) + ".wav";


 ecas.command("cs-select play_chainsetup");


 //delay test
             QString qcsai_addo = "c-select chain" + QString::number(effecttrackNR);
             QString qcsai_add = qcsai_addo;
             QString strcs = qcsai_add;
             std::string stdstrcs = strcs.toStdString();
             const char * cstrcs = stdstrcs.c_str();
             qDebug() << "effecttrack ........ cstrcs" << qPrintable(cstrcs);
             //ecas.command("c-select chain1");
           ecas.command(cstrcs);


             //ecas.command("c-select chain5");
             //-eal:limit-%
             //ecas.command("cop-add -eal:100");
              //ecas.command("c-select chain5");
              //delay -etm:delay-time-msec,number-of-delays,mix-%
              //ecas.command("cop-add -etm:900,3,500");

   ecas.command(cstrcs);

   //-eca:peak-level-%, release-time-sec, fast-crate, crate
   //-eca:69,0,0.25,0.25 -ea:%1
   //-pd:Supersoft_compressor
   //dyn_compress_hard = -eca:69,0,0.5,1.0 -ea:%1

   ecas.command("cop-add -eca:69,0,0.25,0.25");
   //ecas.command("ctrl-add -km:1,1,99,18,1");
              //ecas.command("cop-list");

              //cerr << ".........................................cop status: " << ecas.last_string() << endl;

             // ecas.command("cs-status");
              //cerr << "Chain operator status: " << ecas.last_string() << endl;



           // ecas.command("-f:24,1,");


//             if((trackNR==1)||(trackNR==3)||(trackNR==5)||(trackNR==7))
//             {
//               ecas.command("ai-add jack,capture_1");
//             }

//             if((trackNR==2)||(trackNR==4)||(trackNR==6)||(trackNR==8))
//             {
//               ecas.command("ai-add jack,capture_2");
//             }

             //QString qai_addo = "ao-add " + TapesPath + "/Dummy_Track_" + QString::number(trackNR) + ".wav";





//             QString qai_addo = "ao-add " + TapeName;
//             QString qai_add = qai_addo;
//             QString str = qai_add;
//             std::string stdstr = str.toStdString();
//             const char * cstr = stdstr.c_str();
//             qDebug() << "REC ............ ao-add" << qPrintable(cstr);

//             ecas.command(cstr);





//             ecas.command("cs-connect");
//             ecas.command("start");
//    play();








 }


 void Thread1::effectoff(int effecttrackNR)
 {

          qDebug() << "received rectrack........................" << effecttrackNR;

       //   -etm:delay-time-msec,number-of-delays,mix-%
              // ecas.command("cop-add -etm:900,3,800");


ecas.command("c-select chain4");
  // ecas.command("cop-select 5");


   //cop-set ’chainop_id,param_id,value’

    ecas.command("cop-set ’5,3,0’");



     //ecas.command("cop-remove");

      toggleeffect4=0;




    }


void Thread1::valueGotStop(int timestopvalue)
{


    //                //turn off all fan lights
                   // add_send_hex_data("B0 28 00");
                   //  add_send_hex_data("B0 29 00");
    qDebug() << "timestopvalue" << timestopvalue;

    //timepointer = timevalue;

    //add_send_hex_data("B0 29 01");





}


void Thread1::play()

{
 emit stopsignal(0);
     //int timepointerplay=timepointer;

     //qDebug() << "timepointerplay" << timepointerplay;


    //tThread->start();
    //QString Tx = "emit from worker test";
//emit t1signal(Tx);
    //QString acommand = "gnome-terminal -x bash -c \"/usr/bin/qjackctl";    
    // process1.start(acommand);

      client_name = jack_get_client_name(client);

       //qDebug() << "client_namePlay";
       //qDebug() << client_name;


          jack_transport_start(client);
           qDebug() << client;
          //ecas.command("engine-launch");



//           ecas.command("cs-get-position");
//              double cspos = ecas.last_float();

//                         qDebug() << "cspos%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
//                          qDebug() << cspos;

rxplayon();

timer->start(1000);




}

void Thread1::meters()

{
   // QString bcommand = "gnome-terminal -x bash -c \"jmeters -t din -c 2 L R";

      // process1.start(bcommand);

     //  jack_port_by_name(client);
      // ecas.command("jack-connect ’ecasound-01:out_1’ ’jmeters:in-1’");
     //  ecas.command("jack-connect ’src-port’ ’dest-port’");

//system:playback_1
//system:playback_2
//ecasound-01:out_1
//ecasound-01:out_2
//ecasound-03:out_1
//ecasound-03:out_2
//jmeters:in-1
//jmeters:in-2

//---------------------------

    //jack_connect

        // to list all clients:
         //jack_lsp

      //   jack_connect "TRM8TT:Track_1_1" "jack_mixer:1 L"


        ports = jack_get_ports (client, NULL, NULL,JackPortIsOutput);

             qDebug() << "eca ports--------------------------";
             qDebug() << ports;

        jack_client_t *mclient;

            const char **mports;
            //const char *mclient_name;

        QString qmclient_name = "jack_mixer";
        std::string qmtclient_name = qmclient_name.toStdString();
        const char * mclient_name = qmtclient_name.c_str();



        mclient = jack_client_open (mclient_name, options, &status, server_name);
           qDebug() << "mclient";
           qDebug() << mclient;
           qDebug() << mclient_name;

            mports = jack_get_ports (mclient, NULL, NULL,JackPortIsInput);

            qDebug() << "jack mixer ports--------------------------";
            qDebug() << mports;

    //*************************************




    //+++++ARRAY+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //for array
    //                                const QByteArray client_port1
    //                                    = QString(node1->nodeName() + ':' + port1->portName()).toUtf8();
    //                                const QByteArray client_port2
    //                                    = QString(node2->nodeName() + ':' + port2->portName()).toUtf8();

    //                                const char *client_port_name1 = client_port1.constData();
    //                                const char *client_port_name2 = client_port2.constData();

    //end for array
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


                                    const char **client_ports1
                                        = ::jack_get_ports(client, NULL, NULL, 0);
                                    if (client_ports1 == NULL)
                                        return;

                                    qDebug() << "client_ports1";

                                     qDebug() << client_ports1;

                                     for (int i = 0; client_ports1[i]; ++i)
                                     {
                                         const char *client_port1 = client_ports1[i];
                                         jack_port_t *jack_port1 = ::jack_port_by_name(client, client_port1);

                                         qDebug() << "client_port1";

                                          qDebug() << client_port1;




                                         if (jack_port1 == NULL)
                                             continue;

      //++++++other port

      const char **client_ports2 = ::jack_port_get_all_connections(client, jack_port1);
    qDebug() << "client_ports2";
    qDebug() << client_ports2;



    //                                     for (int j = 0; client_ports2[j]; ++j)
    //                                     {
    //                                         const char *client_port2 = client_ports2[j];


    //                                         qDebug() << "client_port2";

    //                                         qDebug() << client_port2;

    //                                     }




                                     }



    //"jack_mixer:1 L";


    //"TRM8TT:Track_1_1";

//collect ports in prop down lists... so user can connect them...


QString qclient_port_name1a= "TRM8TT:Track_1_1";
std::string qtclient_port_name1a = qclient_port_name1a.toStdString();
 const char * client_port_name1a = qtclient_port_name1a.c_str();

 QString qclient_port_name1b= "jack_mixer:1 L";
 std::string qtclient_port_name1b = qclient_port_name1b.toStdString();
  const char * client_port_name1b = qtclient_port_name1b.c_str();


 jack_connect(client, client_port_name1a, client_port_name1b);


 //to do: jack_disconnect...

     //multiport end







}

void Thread1::loop_device()

{
    ecas.command("c-add loopdevice_chain");
     ecas.command("c-select loopdevice_chain");

     ecas.command("ai-add loop,1");
     //ecas.command("ao-add jack,system");

     //cop_pmeter();

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//alsaconnect

void Thread1::list_each_subs(snd_seq_t *seq, snd_seq_query_subscribe_t *subs, int type, const char *msg)
{
    int count = 0;
    //snd_seq_query_subscribe_set_type(subs, type);
    snd_seq_query_subscribe_set_index(subs, 0);
    while (snd_seq_query_port_subscribers(seq, subs) >= 0)
    {
        const snd_seq_addr_t *addr;
        if (count++ == 0)
            printf("\t%s: ", msg);


        else
            printf(", ");
        addr = snd_seq_query_subscribe_get_addr(subs);
        printf("%d:%d", addr->client, addr->port);
        if (snd_seq_query_subscribe_get_exclusive(subs))
            printf("[ex]");
        if (snd_seq_query_subscribe_get_time_update(subs))
            printf("[%s:%d]",
                   (snd_seq_query_subscribe_get_time_real(subs) ? "real" : "tick"),
                   snd_seq_query_subscribe_get_queue(subs));
        snd_seq_query_subscribe_set_index(subs, snd_seq_query_subscribe_get_index(subs) + 1);
    }
    if (count > 0)
        printf("\n");


    qDebug() << "msg";
      qDebug() << msg;



}

void Thread1::list_subscribers(snd_seq_t *seq, const snd_seq_addr_t *addr)
{
    snd_seq_query_subscribe_t *subs;
    snd_seq_query_subscribe_alloca(&subs);
    snd_seq_query_subscribe_set_root(subs, addr);
    list_each_subs(seq, subs, SND_SEQ_QUERY_SUBS_READ, ("Connecting To"));
    list_each_subs(seq, subs, SND_SEQ_QUERY_SUBS_WRITE, ("Connected From"));

    qDebug() << "list_each_subs";
    qDebug() << subs;


}




#define LIST_INPUT	1
#define LIST_OUTPUT	2

#define perm_ok(pinfo,bits) ((snd_seq_port_info_get_capability(pinfo) & (bits)) == (bits))

void Thread1::check_permission(snd_seq_port_info_t *pinfo, int perm)
{
    if (perm) {
        if (perm & LIST_INPUT) {
            if (perm_ok(pinfo, SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ))
                goto __ok;
        }
        if (perm & LIST_OUTPUT) {
            if (perm_ok(pinfo, SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE))
                goto __ok;
        }
        return ;
    }
 __ok:
    if (snd_seq_port_info_get_capability(pinfo) & SND_SEQ_PORT_CAP_NO_EXPORT)
        return ;
    return ;
}





void Thread1::alsaconnect()
{




  //  snd_seq_t *seq;

    if (snd_seq_open(&seq, "default", SND_SEQ_OPEN_DUPLEX, 0) < 0)
    {
            fprintf(stderr, ("can't open sequencer\n"));
            return;
    }



    int queue = 0, convert_time = 0, convert_real = 0, exclusive = 0;
//    int command = SUBSCRIBE;

    snd_seq_port_subscribe_t *subs;
snd_seq_addr_t sender, dest;

const char senderv  [16] = "X-TOUCH COMPACT";
const char destv  [16] ="ecasound";

 qDebug() << "senderv!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
 qDebug() << senderv;
  qDebug() << destv;

//do_search_port(seq, list_perm,list_subs ? print_port_and_subs : print_port);


int perm;



    snd_seq_client_info_t *cinfo;
    snd_seq_port_info_t *pinfo;




    snd_seq_client_info_alloca(&cinfo);
    snd_seq_port_info_alloca(&pinfo);
    snd_seq_client_info_set_client(cinfo, -1);
    //--



    qDebug() << "before";



check_permission(pinfo, perm);


/* set client info */
    if (snd_seq_set_client_name(seq, "ALSA Connector") < 0)
    {
        snd_seq_close(seq);
        fprintf(stderr, ("can't set client info\n"));
        return;
}

  /* set subscription */
      if (snd_seq_parse_address(seq, &sender, senderv) < 0)
      {
          snd_seq_close(seq);
          fprintf(stderr, ("invalid sender address %s\n"));
          return;
      }
      if (snd_seq_parse_address(seq, &dest, destv) < 0)
      {
          snd_seq_close(seq);
          fprintf(stderr,("invalid destination address %s\n"));
          return;
      }




    snd_seq_port_subscribe_alloca(&subs);

    snd_seq_port_subscribe_set_sender(subs, &sender);
    snd_seq_port_subscribe_set_dest(subs, &dest);
    snd_seq_port_subscribe_set_queue(subs, queue);
    snd_seq_port_subscribe_set_exclusive(subs, exclusive);
    snd_seq_port_subscribe_set_time_update(subs, convert_time);
    snd_seq_port_subscribe_set_time_real(subs, convert_real);

    if (snd_seq_get_port_subscription(seq, subs) == 0)
            {
                snd_seq_close(seq);
                fprintf(stderr, ("Connection is already subscribed\n"));
                return;
            }
            if (snd_seq_subscribe_port(seq, subs) < 0)
            {
                snd_seq_close(seq);
                fprintf(stderr, ("Connection failed (%s)\n"));
                return;
             }

//for feedback light that alsa is connected
  list_subscribers(seq, snd_seq_port_info_get_addr(pinfo));
//


  outputp = &output;
  inputp = NULL;

 snd_rawmidi_open(inputp, outputp,"virtual" , 0);



          //snd_rawmidi_open(inputp, outputp, "virtual", SND_RAWMIDI_APPEND);

 rxvirtualclient();

 qDebug() << "alsaconnect 1 end";
}
//rx virtual connect


void Thread1::rxvirtualclient()

{

//do_search_port(seq, list_perm,list_subs ? print_port_and_subs : print_port);

     //snd_seq_t *seq;
snd_seq_client_info_t *cinfo;
snd_seq_port_info_t *pinfo;

int count;

 qDebug() << "rxvirtualclient start";

snd_seq_client_info_alloca(&cinfo);

snd_seq_port_info_alloca(&pinfo);
snd_seq_client_info_set_client(cinfo, -1);

 while (snd_seq_query_next_client(seq, cinfo) >= 0)
 {
     /* reset query info */
     snd_seq_port_info_set_client(pinfo, snd_seq_client_info_get_client(cinfo));
     snd_seq_port_info_set_port(pinfo, -1);
     count = 0;
//        while (snd_seq_query_next_port(seq, pinfo) >= 0)
//        {
//            if (check_permission(pinfo, perm)==0)
//            {
//                do_action(seq, cinfo, pinfo, count);
//                count++;
//            }
//        }


 //

     //qDebug() << "client_info_get_client" << snd_seq_client_info_get_client(cinfo);
     qDebug() << "client_info_get_name" <<  snd_seq_client_info_get_name(cinfo);


    const char * cnamerx = snd_seq_client_info_get_name(cinfo);

    std::string cnamerxstd = cnamerx;
    std::string rxcontains = "Client-";



    if (cnamerxstd.find(rxcontains) != string::npos)
    {
     qDebug() << "This is the name to connect rx:" <<  cnamerx;
     rxconnect = cnamerx;
     alsaconnectrx();


    }



     //qDebug() << "client_info_get_type" <<  snd_seq_client_info_get_type(cinfo);
     //qDebug() << "client_info_get_card" <<  snd_seq_client_info_get_card(cinfo);
     //qDebug() << "client_info_get_pid" <<  snd_seq_client_info_get_pid(cinfo);
     //
     //qDebug() << "client_info_get_num_ports" << snd_seq_client_info_get_num_ports(cinfo);

     //qDebug() << "port_info_get_port" <<  snd_seq_port_info_get_port(pinfo);
     //qDebug() << "port_info_get_name" <<  snd_seq_port_info_get_name(pinfo);
     //qDebug() << "port_info_get_addr" <<  snd_seq_port_info_get_addr(pinfo);
     //

     //qDebug() << "port_info_get_client" <<  snd_seq_port_info_get_client(pinfo);
     //qDebug() << "port_info_get_addr" <<  snd_seq_port_info_get_addr(pinfo);
     //qDebug() << "snd_seq_port_info_get_type" <<  snd_seq_port_info_get_type(pinfo);
     //qDebug() << "port_info_get_port_specified" <<  snd_seq_port_info_get_port_specified(pinfo);




}
 qDebug() << "rxvirtualclient end";
}


void Thread1::alsaconnectrx()
{




  //  snd_seq_t *seq;

    if (snd_seq_open(&seq, "default", SND_SEQ_OPEN_DUPLEX, 0) < 0)
    {
            fprintf(stderr, ("can't open sequencer\n"));
            return;
    }



    int queue = 0, convert_time = 0, convert_real = 0, exclusive = 0;
//    int command = SUBSCRIBE;

    snd_seq_port_subscribe_t *subs;
snd_seq_addr_t sender, dest;

//const char senderv  [16] = rxconnect;
const char destv  [16] ="X-TOUCH COMPACT";

 qDebug() << "sendervrx!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
 //qDebug() << senderv;
  qDebug() << destv;

//do_search_port(seq, list_perm,list_subs ? print_port_and_subs : print_port);


int perm;



    snd_seq_client_info_t *cinfo;
    snd_seq_port_info_t *pinfo;




    snd_seq_client_info_alloca(&cinfo);
    snd_seq_port_info_alloca(&pinfo);
    snd_seq_client_info_set_client(cinfo, -1);
    //--



    qDebug() << "before";



check_permission(pinfo, perm);


/* set client info */
    if (snd_seq_set_client_name(seq, "ALSAConnectorRX") < 0)
    {
        snd_seq_close(seq);
        fprintf(stderr, ("can't set client info\n"));
        return;
}

  /* set subscription */

      //if (snd_seq_parse_address(seq, &sender, senderv) < 0)
            if (snd_seq_parse_address(seq, &sender, rxconnect) < 0)
      {
          snd_seq_close(seq);
          fprintf(stderr, ("invalid sender address %s\n"));
          return;
      }
      if (snd_seq_parse_address(seq, &dest, destv) < 0)
      {
          snd_seq_close(seq);
          fprintf(stderr,("invalid destination address %s\n"));
          return;
      }




    snd_seq_port_subscribe_alloca(&subs);

    snd_seq_port_subscribe_set_sender(subs, &sender);
    snd_seq_port_subscribe_set_dest(subs, &dest);
    snd_seq_port_subscribe_set_queue(subs, queue);
    snd_seq_port_subscribe_set_exclusive(subs, exclusive);
    snd_seq_port_subscribe_set_time_update(subs, convert_time);
    snd_seq_port_subscribe_set_time_real(subs, convert_real);

    if (snd_seq_get_port_subscription(seq, subs) == 0)
            {
                snd_seq_close(seq);
                fprintf(stderr, ("Connection is already subscribed\n"));
                return;
            }
            if (snd_seq_subscribe_port(seq, subs) < 0)
            {
                snd_seq_close(seq);
                fprintf(stderr, ("Connection failed (%s)\n"));
                return;
             }

//for feedback light that alsa is connected
  list_subscribers(seq, snd_seq_port_info_get_addr(pinfo));
//

sleep(1);

rxpan1();
rxpan2();
rxpan3();
rxpan4();
rxpan5();
rxpan6();
rxpan7();
rxpan8();

rxfader1();
rxfader2();
rxfader3();
rxfader4();
rxfader5();
rxfader6();
rxfader7();
rxfader8();
//main fader
add_send_hex_data("B0 09 00");


//turn off all fan lights
              add_send_hex_data("B0 28 00");
              add_send_hex_data("B0 29 00");






 qDebug() << "alsaconnectrx  end";
}

//alsaconnect end++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




//void Thread1::readrestarttxt()
//{
//    QFile hfile("trm8tt_restart.txt");
//           if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
//           {
//               recmode=0;

//                qDebug() << ".......................!hfile.open...  recmode=0";
//           }
//           //
//           else
//           {
//           QTextStream in(&hfile);
//                 while (!in.atEnd())
//                   {
//                     QString hostrr = in.readLine();

//                     if(~(hostrr.isEmpty()))
//                          {
//                      qDebug() << hostrr << "+++++++++++++++++string+++++++++++++++++++++++++in.readLine" ;
//                    int forrecmode=hostrr.toInt();
//                     qDebug() << forrecmode << "++++++++++++++recmode int++++++++++++++++++++++++++++in.readLine" ;
//                      recmode=forrecmode;
//                          }
//                    }
//           }
//}


void Thread1::readrecmodetxt()
{
    QFile hfile("trm8tt_recmode.txt");
           if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
           {
               recmode=0;
               //playbackmode

                qDebug() << ".......................!hfile.open...  recmode=0";
           }
           //
           else
           {
           QTextStream in(&hfile);
                 while (!in.atEnd())
                   {
                     QString hostrr = in.readLine();

                     if(~(hostrr.isEmpty()))
                          {
                      qDebug() << hostrr << "+++++++++++++++++string+++++++++++++++++++++++++in.readLine" ;
                    int forrecmode=hostrr.toInt();
                     qDebug() << forrecmode << "++++++++++++++recmode int++++++++++++++++++++++++++++in.readLine" ;
                      recmode=forrecmode;
                          }
                    }
           }
             hfile.close();
}



void Thread1::readtapeslottxt()
{
    QFile rhfile("trm8tt_tapeslot.txt");
           if (!rhfile.open(QIODevice::ReadOnly | QIODevice::Text))
           {
               activetapeNR=1;

                qDebug() << ".......................!hfile.open...  activetapeNR 1";
           }
           //
           else
           {
           QTextStream rin(&rhfile);
                while (!rin.atEnd())
                   {
                     QString rhostrr = rin.readLine();

                     if(~(rhostrr.isEmpty()))
                          {
                      qDebug() << rhostrr << "+++++++++++++++++string+++++++activetapeNR++++++++++++++++++in.readLine" ;
                    int rforrecmode=rhostrr.toInt();
                     qDebug() << rforrecmode << "+++++++++++++activetapeNR int++++++++++++++++++++++++++++in.readLine" ;
                     activetapeNR=rforrecmode;
                          }
                    }
           }
            rhfile.close();
}





void Thread1::run()
{

    //readtapeslottxt();

//read rec mode file
// (0=playback, 1=mono rec...)
//readrestarttxt();
readrecmodetxt();




 qDebug() << activetapeNR << "1934aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaractivetapeNR ";

int res;

qDebug() << "_____________________--worker thread 1" << reinterpret_cast<std::uintptr_t>(thread()->currentThreadId());

qDebug() << "QDir::homePath()" << HomePathT;


qDebug() << "recmode from run###########################" << recmode;



//qDebug() << "TapesPath" << TapesPath;

//QDir dir(TapesPath);
//if (!dir.exists())
//    dir.mkpath(TapesPath);

//8 project folders with 8 8track tape each
//{
//    QString TapeFolder = HomePathT + "/" + "TRM8TT_Tapes" + "/" + "TRM8TT_Tape_" + QString::number(tapeNR);

//    QDir dir(TapeFolder);
//    if (!dir.exists())
//        dir.mkpath(TapeFolder);
//}


activetape = HomePathT + "/" + "TRM8TT_Tapes" + "/" + "Tape_" + QString::number(activetapeNR);


   QDir dir(activetape);
   if (!dir.exists())
       dir.mkpath(activetape);

qDebug() << "activetape#####################################################################" << activetape;

if(recmode>10)
{
 qDebug() << "recmode > 10 ########################" << recmode;

 deletetrack();

}
else
{

//+++++++ecasound++++++++++++

    ecas.command("engine-launch");
    //ecas.command("engine-status");

    ecas.command("cs-add play_chainsetup");

    ecas.command("cs-set-audio-format ’24,2,’");

   ecas.command("cs-set-param -G:jack,system,recv");




//master chain
 ecas.command("c-add chainMaster");
 ecas.command("c-select chainMaster");
 ecas.command("ao-add jack,system");
 ecas.command("ai-add jack,xMaster,xMasterIN");

 //cop 1 (master vol.):
  ecas.command("cop-add -ea:0");

 //cop 2 (master peak signal):
  ecas.command("cop-add -evp");

 //cop 3 master limiter:
   //ecas.command("cop-add -eal:80");

  //master volumne control:
   ecas.command("cop-select 1");
   ecas.command("ctrl-add -km:1,0,100,9,1");




//stereo mix
//CC midi map for X-TOUCH COMPACT
    for(int trackNR=1;trackNR<=8;trackNR++)
    {
        //QString TapeName =  TapesPath + "/TRM8TT_Track_" + QString::number(trackNR) + ".wav";
        QString TrackName = activetape + "/Track_" + QString::number(trackNR) + ".wav";

                //QDir dir(TapesPath);
                 QDir dir(activetape);

                //play ready
                //if (dir.exists(TapeName))
                    if (dir.exists(TrackName))
                {
                    qDebug() << TrackName << "does exist";



                    QString qcai_addo = "c-add chain" + QString::number(trackNR);
                    QString qcai_add = qcai_addo;
                    QString strc = qcai_add;
                    std::string stdstrc = strc.toStdString();
                    const char * cstrc = stdstrc.c_str();
                    qDebug() << "cstrc" << qPrintable(cstrc);
                    //ecas.command("c-add chain1");
                    ecas.command(cstrc);

                    QString qcsai_addo = "c-select chain" + QString::number(trackNR);
                    QString qcsai_add = qcsai_addo;
                    QString strcs = qcsai_add;
                    std::string stdstrcs = strcs.toStdString();
                    const char * cstrcs = stdstrcs.c_str();
                    qDebug() << "cstrcs" << qPrintable(cstrcs);
                    //ecas.command("c-select chain1");
                    ecas.command(cstrcs);

                    //ecas.command("-f:24,1,");
                    //ecas.command("cop-add -chcopy:1,2");

                     //ecas.command("ao-add jack,system");

                      ecas.command("ao-add jack,system-01");



                    //QString qai_addo = "ai-add " + TapeName;
                    QString qai_addo = "ai-add " + TrackName;

                    QString qai_add = qai_addo;
                    QString str = qai_add;
                    std::string stdstr = str.toStdString();
                    const char * cstr = stdstr.c_str();
                    //qDebug() << "ai-add" << qPrintable(cstr);
                    ecas.command(cstr);

                    //chcopy to get mono file ready for epp panning
                    ecas.command(cstrcs);

                    //cop 1 (to pan mono in the middle)
                    ecas.command("cop-add -chcopy:1,2");
                     ecas.command(cstrcs);

                     //cop 2 (pan):
                    ecas.command("cop-add -epp:50");

                    //cop 3: ea to control the volume
                    ecas.command("cop-add -ea:0");

                    //cop 4: evp for signal meter (after ea)
                    ecas.command("cop-add -evp");

                    //cop 5: reverb -ete:room_size,feedback-%,wet-%
                    //ecas.command("cop-add -ete:50,25,0");
                    //-efl:cutoff-freq
                    //ecas.command("-efl:20000");


                    //cop 5: limiter (number not called)
                    //ecas.command("cop-add -eal:98");



                    //epp (pan)
                    int panchan = 9 + trackNR;
                    qDebug() << "panchan" << panchan;
                    QString qpfai_addo = "ctrl-add -km:1,0,100," + QString::number(panchan) + ",1";
                    QString qpfai_add = qpfai_addo;
                    QString pfstr = qpfai_add;
                    std::string pfstdstr = pfstr.toStdString();
                    const char * pfcstr = pfstdstr.c_str();
                    qDebug() << "pfcstr" << qPrintable(pfcstr);
                    ecas.command("cop-select 2");
                    //ecas.command("ctrl-add -km:1,0,100,10,1");
                    ecas.command(pfcstr);

                    //ea (faders)
                    QString qfai_addo = "ctrl-add -km:1,0,180," + QString::number(trackNR) + ",1";
                    QString qfai_add = qfai_addo;
                    QString fstr = qfai_add;
                    std::string fstdstr = fstr.toStdString();
                    const char * fcstr = fstdstr.c_str();
                    qDebug() << "fcstr" << qPrintable(fcstr);
                    ecas.command("cop-select 3");
                    //ecas.command("ctrl-add -km:1,0,180,1,1");
                    ecas.command(fcstr);


                    //

//                    //reverb knobs
//                    //QString rqfai_addo = "ctrl-add -km:3,0,100," + QString::number(trackNR+17) + ",1";
//                    //QString rqfai_addo = "ctrl-add -km:3,0,100," + QString::number(trackNR+36) + ",1";
//                    //low pass filter
//                    //QString rqfai_addo = "ctrl-add -km:1,0,10000," + QString::number(trackNR+36) + ",1";
//                    QString rqfai_add = rqfai_addo;
//                    QString rfstr = rqfai_add;
//                    std::string rfstdstr = rfstr.toStdString();
//                    const char * rfcstr = rfstdstr.c_str();
//                    qDebug() << "fcstr" << qPrintable(rfcstr);
//                    ecas.command("cop-select 5");
//                    //ecas.command("ctrl-add -km:1,0,180,1,1");
//                    //ecas.command(rfcstr);







                   // ecas.command("cop-select 5");
                   // ecas.command("ctrl-add -km:1,0,150,18,1");

                    //-km:fx-param,start-value,end-value,controller,channel
                    //-ete:room_size,feedback-%,wet-%


                }



                //rec ready



              //if ((!dir.exists(TapeName))&&reconly1track<1)
                   if (!dir.exists(TrackName))

                {

                       QString dummytape = HomePathT + "/TRM8TT_Tapes/DummyTape" + QString::number(trackNR)  + ".wav";


oneemptytrack=1;
emptytracks = emptytracks +1;

                       emptytracksar.push_back(trackNR);

track_rec[trackNR-1] = 1;

                      qDebug() << mainrec << "2222222mainrec22222222222222222";




                    qDebug() << TrackName << "does not exist";
                    //QString TapeDummy =  TapesPath + "/dummy.wav";

                    QString qcai_addo = "c-add chain" + QString::number(trackNR);
                    QString qcai_add = qcai_addo;
                    QString strc = qcai_add;
                    std::string stdstrc = strc.toStdString();
                    const char * cstrc = stdstrc.c_str();
                    qDebug() << "cstrc" << qPrintable(cstrc);
                    //ecas.command("c-add chain1");
                    ecas.command(cstrc);

                    QString qcsai_addo = "c-select chain" + QString::number(trackNR);
                    QString qcsai_add = qcsai_addo;
                    QString strcs = qcsai_add;
                    std::string stdstrcs = strcs.toStdString();
                    const char * cstrcs = stdstrcs.c_str();
                    qDebug() << "cstrcs" << qPrintable(cstrcs);
                    //ecas.command("c-select chain1");
                  ecas.command(cstrcs);

                  // ecas.command("-f:24,1,");



                     if(recmode==2)
                     {

                         recmode2counter=recmode2counter+1;
                      //if(trackNR==emptytracksar.at(1))

                     }





                if((recmode2counter==0)||(recmode2counter==1))
                {
                    RecLED1counter=RecLED1counter+1;
                    if(RecLED1counter==1)
                    {
                    trackNRRecLED1 = trackNR;
                      qDebug() << trackNRRecLED1 << "....trackNRRecLED1.............. ..................... ai-add jack,capture_1";
                    }

                    qDebug() << recmode2counter <<  "....t................................. recmode2counter ai-add jack,capture_1";

                    if(recmode==0)
                    {
                 //ecas.command("ai-add null");



                 QString dqai_addo = "ai-add " + dummytape;

                 QString dqai_add = dqai_addo;
                 QString dstr = dqai_add;
                 std::string dstdstr = dstr.toStdString();
                 const char * dcstr = dstdstr.c_str();
                qDebug() << " dummytape ---------------------------------------------------ai-add" << qPrintable(dcstr);
                 ecas.command(dcstr);

                    }

                     if((recmode==1)||(recmode==2))
                     {
                  ecas.command("ai-add jack,capture_1");
                     }

                }


                if(recmode2counter==2)
                {
                    RecLED2counter=RecLED2counter+1;
                    if(RecLED2counter==1)
                    {
                    trackNRRecLED2= trackNR;
                     qDebug() <<  trackNRRecLED2 << ".........trackNRRecLED2... recmode2counter ai-add jack,capture_2";
                    }
                   qDebug() << recmode2counter << ".......................... recmode2counter ai-add jack,capture_2";
                  ecas.command("ai-add jack,capture_2");
                }

                if(recmode2counter>2)
                {
                  ecas.command("ai-add null");
                      //ecas.command("ai-add jack,capture_1");
                }



                   //QString qai_addo = "ao-add " + TapesPath + "/Dummy_Track_" + QString::number(trackNR) + ".wav";
                    QString qai_addo = "ao-add " + TrackName;
                    QString qai_add = qai_addo;
                    QString str = qai_add;
                    std::string stdstr = str.toStdString();
                    const char * cstr = stdstr.c_str();
                    qDebug() << "ao-add" << qPrintable(cstr);
                   //ecas.command(cstr);

//software monitoring
//ecas.command("ao-add jack,system");

//hardware monitoring
ecas.command("ao-add null");


//                    QString qai_addo = "ai-add " + TapeDummy;
//                    QString qai_add = qai_addo;
//                    QString str = qai_add;
//                    std::string stdstr = str.toStdString();
//                    const char * cstr = stdstr.c_str();
                    //qDebug() << "ai-add" << qPrintable(cstr);
                    //ecas.command(cstr);
                    //ecas.command("ai-add jack,system");
                     //ecas.command("cs-set-audio-format ’24,1,44100’");


                    //chcopy to get mono file ready for epp panning
       ecas.command("cop-add -chcopy:1,2");

                //limiter/compresssor dummy cop to keep the cop number constant (for peak meter loop), when removing chcopy to
                    //get real mono files
                //  ecas.command("cop-add -eal:100");
                     // ecas.command("cop-add -eca:69,0,0.25,0.25");


                    ecas.command("cop-add -epp:50");
                    //ea to control the volume
                    ecas.command("cop-add -ea:0");
                    //evp for signal meter (after ea)
                    ecas.command("cop-add -evp");
                    // ecas.command("cop-add -ete:0,50,50");

                    //epp (pan)
                    int panchan = 9 + trackNR;
                    qDebug() << "panchan" << panchan;
                    QString qpfai_addo = "ctrl-add -km:1,0,100," + QString::number(panchan) + ",1";
                    QString qpfai_add = qpfai_addo;
                    QString pfstr = qpfai_add;
                    std::string pfstdstr = pfstr.toStdString();
                    const char * pfcstr = pfstdstr.c_str();
                    qDebug() << "pfcstr" << qPrintable(pfcstr);
                    ecas.command("cop-select 2");
                    //ecas.command("ctrl-add -km:1,0,100,10,1");
                    ecas.command(pfcstr);

                    //ea (faders)
                    QString qfai_addo = "ctrl-add -km:1,0,180," + QString::number(trackNR) + ",1";
                    QString qfai_add = qfai_addo;
                    QString fstr = qfai_add;
                    std::string fstdstr = fstr.toStdString();
                    const char * fcstr = fstdstr.c_str();
                    qDebug() << "fcstr" << qPrintable(fcstr);
                    ecas.command("cop-select 3");
                    //ecas.command("ctrl-add -km:1,0,180,1,1");
                    ecas.command(fcstr);



                   }

    }


    //rec chain


//one channel recording
     if((recmode==1)&&(oneemptytrack>0))

                   {


qDebug() <<  emptytracksar.at(0) << "000000000000000000000000000000000000000000emptytracksar[0]";


//qDebug() <<  emptytracksar.at(1) << "000000000000000000000000000000000000000000emptytracksar[1]";

   //QString RecTapeName =  TapesPath + "/TRM8TT_Track_" + QString::number(emptytracksar.at(0)) + ".wav";
     QString RecTrackName =  activetape + "/Track_" + QString::number(emptytracksar.at(0)) + ".wav";


                    QString rqcai_addo = "c-add recchain" + QString::number(emptytracksar.at(0));
                    QString rqcai_add = rqcai_addo;
                    QString rstrc = rqcai_add;
                    std::string rstdstrc = rstrc.toStdString();
                    const char * rcstrc = rstdstrc.c_str();
                    qDebug() << "rec --c-add recchain-------------------- rcstrc" << qPrintable(rcstrc);

                    ecas.command(rcstrc);

                    //QString rqcsai_addo = "c-select recchain" + QString::number(trackNR);
                    QString rqcsai_addo = "c-select recchain" + QString::number(emptytracksar.at(0));
                    QString rqcsai_add = rqcsai_addo;
                    QString rstrcs = rqcsai_add;
                    std::string rstdstrcs = rstrcs.toStdString();
                    const char * rcstrcs = rstdstrcs.c_str();
                    qDebug() << "c-select recchain----------------------------rcstrcs" << qPrintable(rcstrcs);

                  ecas.command(rcstrcs);

 ecas.command("-f:24,1,");

 ecas.command("ai-add jack,capture_1");

// ecas.command("cop-add -chcopy:1,2");





                   // QString rqai_addo = "ao-add " + TapesPath + "/NewREC_Track_" + QString::number(trackNR) + ".wav";
                      QString rqai_addo = "ao-add " + RecTrackName;
                    QString rqai_add = rqai_addo;
                    QString rstr = rqai_add;
                    std::string rstdstr = rstr.toStdString();
                    const char * rcstr = rstdstr.c_str();
                    qDebug() << "###RecTrackName####################ao-add" << qPrintable(rcstr);
                   ecas.command(rcstr);




    }
//

     //2 channels recording
          if((recmode==2)&&(emptytracks>1))

                        {


     qDebug() <<  emptytracksar.at(0) << "000000000000000000000000000000000000000000emptytracksar[0]";


     qDebug() <<  emptytracksar.at(1) << "000000000000000000000000000000000000000000emptytracksar[1]";


     //rec channel 1

        //QString RecTapeName =  TapesPath + "/TRM8TT_Track_" + QString::number(emptytracksar.at(0)) + ".wav";
          QString RecTrackName =  activetape + "/Track_" + QString::number(emptytracksar.at(0)) + ".wav";


                         QString rqcai_addo = "c-add recchain" + QString::number(emptytracksar.at(0));
                         QString rqcai_add = rqcai_addo;
                         QString rstrc = rqcai_add;
                         std::string rstdstrc = rstrc.toStdString();
                         const char * rcstrc = rstdstrc.c_str();
                         qDebug() << "rec --c-add recchain-------------------- rcstrc" << qPrintable(rcstrc);

                         ecas.command(rcstrc);

                         //QString rqcsai_addo = "c-select recchain" + QString::number(trackNR);
                         QString rqcsai_addo = "c-select recchain" + QString::number(emptytracksar.at(0));
                         QString rqcsai_add = rqcsai_addo;
                         QString rstrcs = rqcsai_add;
                         std::string rstdstrcs = rstrcs.toStdString();
                         const char * rcstrcs = rstdstrcs.c_str();
                         qDebug() << "c-select recchain----------------------------rcstrcs" << qPrintable(rcstrcs);

                       ecas.command(rcstrcs);

      ecas.command("-f:24,1,");

      ecas.command("ai-add jack,capture_1");



                        // QString rqai_addo = "ao-add " + TapesPath + "/NewREC_Track_" + QString::number(trackNR) + ".wav";
                           QString rqai_addo = "ao-add " + RecTrackName;
                         QString rqai_add = rqai_addo;
                         QString rstr = rqai_add;
                         std::string rstdstr = rstr.toStdString();
                         const char * rcstr = rstdstr.c_str();
                         qDebug() << "###RecTrackName####################ao-add 1" << qPrintable(rcstr);
                        ecas.command(rcstr);

                        //

// rec channel 2


                          QString RecTrackName2 =  activetape + "/Track_" + QString::number(emptytracksar.at(1)) + ".wav";


                                         QString rqcai_addo2 = "c-add recchain" + QString::number(emptytracksar.at(1));
                                         QString rqcai_add2 = rqcai_addo2;
                                         QString rstrc2 = rqcai_add2;
                                         std::string rstdstrc2 = rstrc2.toStdString();
                                         const char * rcstrc2 = rstdstrc2.c_str();
                                         qDebug() << "rec --c-add recchain-------------------- rcstrc2" << qPrintable(rcstrc2);

                                         ecas.command(rcstrc2);

                                         //QString rqcsai_addo = "c-select recchain" + QString::number(trackNR);
                                         QString rqcsai_addo2 = "c-select recchain" + QString::number(emptytracksar.at(1));
                                         QString rqcsai_add2 = rqcsai_addo2;
                                         QString rstrcs2 = rqcsai_add2;
                                         std::string rstdstrcs2 = rstrcs2.toStdString();
                                         const char * rcstrcs2 = rstdstrcs2.c_str();
                                         qDebug() << "c-select recchain----------------------------rcstrcs2" << qPrintable(rcstrcs2);

                                       ecas.command(rcstrcs2);

                      ecas.command("-f:24,1,");

                      ecas.command("ai-add jack,capture_2");


                                           QString rqai_addo2 = "ao-add " + RecTrackName2;
                                         QString rqai_add2 = rqai_addo2;
                                         QString rstr2 = rqai_add2;
                                         std::string rstdstr2 = rstr2.toStdString();
                                         const char * rcstr2 = rstdstr2.c_str();
                                         qDebug() << "###RecTrackName####################ao-add 2" << qPrintable(rcstr2);
                                        ecas.command(rcstr2);








         }

          //error messages


          //not tested
          if((recmode==2)&&(emptytracks<2))

                        {
                qDebug() <<  "emptytracks<2, restarting to playback mode";

                recmode=0;



                recmodesfile();


                qDebug() << "error  recmode==2mmmmmmmmmmmmmmmmmmmmmmmmmrestart";

                //restart LED art




                qDebug() << "error  recmode==2 before  QProcess sh11;";
               //
               QProcess sh11;
                sh11.start("sh");

                //
                QString qshpath = HomePathT + "/x_helper_script.sh";
                std::string shpath = qshpath.toStdString();
                const char * pqshpath = shpath.c_str();
                qDebug() << "pqshpath" << qPrintable(pqshpath);


                //


               sh11.write(pqshpath);



                sh11.closeWriteChannel();
                sh11.waitForFinished();


                 qDebug() << "error  recmode==2 after  QProcess sh11";


tThread->quit();

 qDebug() << "error  recmode==2 after  QtThread->quit()";

int putexit =1;
emit exitvalue(putexit);

 qDebug() << "error  recmode==2 after emit exitvalue(putexit)";





                       }


          //testted
          if((recmode==1)&&(oneemptytrack==0))

                        {
                qDebug() <<  "emptytracks<1, restarting to playback mode";

                recmode=0;



                recmodesfile();


                qDebug() << "mmmmmmmmmmmmmmmmmmmmmmmmmrestart";


                //exitslot();

                 qDebug() << "before  QProcess sh11;";
                //
                QProcess sh11;
                 sh11.start("sh");

                 //
                 QString qshpath1 = HomePathT + "/x_helper_script.sh";
                 std::string shpath1 = qshpath1.toStdString();
                 const char * pqshpath1 = shpath1.c_str();
                 qDebug() << "pqshpath1" << qPrintable(pqshpath1);


                 //


                sh11.write(pqshpath1);



                 sh11.closeWriteChannel();
                 sh11.waitForFinished();


                  qDebug() << "after  QProcess sh11";


tThread->quit();

  qDebug() << "after  QtThread->quit()";

int putexit =1;
emit exitvalue(putexit);

  qDebug() << "after emit exitvalue(putexit)";

                       }



//+++++++++++CONNECT TO X-TOUCH COMPACT
             sleep(1);

             ecas.command("cs-option -Md:alsaseq,'X-TOUCH COMPACT'");
             sleep(1);

//++++++++++++++status
                //ecas.command("ctrl-list");
                //ecas.command("ctrl-status");

                //cerr << "Chain ctrl status: " << ecas.last_string() << endl;

                ecas.command("cs-status");

                cerr << "cs status: " << ecas.last_string() << endl;

                //ecas.command("cop-list");
                //ecas.command("cop-status");

                //cerr << "Chain operator status: " << ecas.last_string() << endl;

//+++++++++++++++++++++++++++++++++++
//OUTPUT
//++++++++++++++++++++++++++++++++++++

//for stereo mix:
    //c-select 'cname1,...,cnameN'
    //ecas.command("c-select-all");
    //ecas.command("ao-add jack,system");


    //todo: peak meter (max. only) for stereo master
    // ecas.command("ao-add jack");
    //ecas.command("ao-add loop,1");
    // ecas.command("ao-add jack_multi,playback_1");
    //stereo master track with -ea via loop,1 chain9
    //jack,system
    //jack (excluding jack connections)
    //jack_multi,destport1,...,destportN
    //(number of channels is set with -f:bits,channels,rate
    //https://manpages.debian.org/jessie/ecasound/ecasound.1.en.html

//stereo mix end++++++++++++++++++++++++++



  ecas.command("cs-connect");
  ecas.command("start");
  ecas.command("cs-set-position 0");
  //jack_transport_locate(client,0);
  //jack_transport_stop (client);

// alsaconnect() and aseqdump() for midi controll
     alsaconnect();
     sleep(1);
     tThread->start();

     //startup LED art
     add_send_hex_data("90 18 03");
     add_send_hex_data("90 19 03");
     add_send_hex_data("90 1A 03");
     add_send_hex_data("90 1B 03");
     add_send_hex_data("90 1C 03");
     add_send_hex_data("90 1D 03");
     add_send_hex_data("90 1E 03");
     add_send_hex_data("90 1F 03");
     sleep(2);

       //

     add_send_hex_data("90 18 01");
     add_send_hex_data("90 19 01");
     add_send_hex_data("90 1A 01");
     add_send_hex_data("90 1B 01");
     add_send_hex_data("90 1C 01");
     add_send_hex_data("90 1D 01");
     add_send_hex_data("90 1E 01");
     add_send_hex_data("90 1F 01");

     //turn off 9-14 LED ring
     add_send_hex_data("B0 22 00");
       add_send_hex_data("B0 23 00");
        add_send_hex_data("B0 24 00");
         add_send_hex_data("B0 25 00");
          add_send_hex_data("B0 26 00");
           add_send_hex_data("B0 27 00");






     // sleep(1);
          jack_transport_locate(client,0);
           jack_transport_start(client);
          rxplayon();


//tell timer LEDs are ready to use
timerLEDsOK=1;

     //recreadyledinit();
if((recmode==1)||(recmode==2))
{
    rectrackled();
}
if(recmode==0)
{
    //rec led off
     add_send_hex_data("90 24 01");
}


//+++++++++++++++++++++++++++++++++++++
//signalmeter frequency=200000 microsec
//+++++++++++++++++++++++++++++++++++++

     while(! done )
         {
        usleep(200000);


         res = signalmeter(&ecas);


       if (res < 0)
       {
       }


}


exec();

}
}

void Thread1::rectrackled()
{
 add_send_hex_data("90 24 02");


 if(trackNRRecLED1 == 1)
 {
 add_send_hex_data("90 18 02");


 }
 if((trackNRRecLED1 == 2)||(trackNRRecLED2 == 2))
 {
    add_send_hex_data("90 19 02");


 }
  if((trackNRRecLED1 == 3)||(trackNRRecLED2 == 3))
 {
   add_send_hex_data("90 1A 02");


 }
  if((trackNRRecLED1 == 4)||(trackNRRecLED2 == 4))
 {
     add_send_hex_data("90 1B 02");


 }
  if((trackNRRecLED1 == 5)||(trackNRRecLED2 == 5))
 {
     add_send_hex_data("90 1C 02");


 }
  if((trackNRRecLED1 == 6)||(trackNRRecLED2 == 6))
 {
     add_send_hex_data("90 1D 02");


 }
  if((trackNRRecLED1 == 7)||(trackNRRecLED2 == 7))
 {
     add_send_hex_data("90 1E 02");


 }
  if((trackNRRecLED1 == 8)||(trackNRRecLED2 == 8))
 {
     add_send_hex_data("90 1F 02");

}




}






void Thread1::recreadyledinit()

{


    //marks which tracks are rec tracks
          for(int n = 0; n < ecasv_chcount; n++)
          {

                  int trackNR = n+1;
                  QString TrackName =  activetape+ "/Track_" + QString::number(trackNR) + ".wav";

                          QDir dir(activetape);

                          //if (!dir.exists(TapeName))
                              if(track_rec[n+1] == 1)
                          {
                              if(n==0)
                              {

                                  if(only1<1)
                                  {
                               add_send_hex_data("90 18 02");
                                  }
                                   only1=only1+1;
                               track_rec[0] = 1;

                              }
                              if(n==1)
                              {

                                  if(only1<1)
                                  {
                                add_send_hex_data("90 19 02");
                                  }
                                   only1=only1+1;
                                  track_rec[1] = 1;

                              }
                              if(n==2)
                              {
                                  if(only1<1)
                                  {
                                 add_send_hex_data("90 1A 02");
                                     }
                               only1=only1+1;
                                  track_rec[2] = 1;

                              }
                              if(n==3)
                              {
                                  if(only1<1)
                                  {
                                  add_send_hex_data("90 1B 02");
                                 }
                               only1=only1+1;
                                  track_rec[3] = 1;

                              }
                              if(n==4)
                              {
                                  if(only1<1)
                                  {

                             add_send_hex_data("90 1C 02");

                                     }
                               only1=only1+1;
                                  track_rec[4] = 1;

                              }
                              if(n==5)
                              {

                                  if(only1<1)
                                  {
                                  {add_send_hex_data("90 1D 02");
                                   }
                                    only1=only1+1;
                                  track_rec[5] = 1;

                              }
                              if(n==6)
                              {
                                  if(only1<1)
                                  {
                                      add_send_hex_data("90 1E 02");
                                  }
                                   only1=only1+1;
                                  track_rec[6] = 1;

                              }
                              if(n==7)
                              {
                                  if(only1<1)
                                  {
                                      add_send_hex_data("90 1F 02");
                                  }
                                   only1=only1+1;
                                  track_rec[7] = 1;

                              }

                          }


}

          }
}
//


void Thread1::recreadyled()

{


    //shows which tracks are rec tracks





                              if(track_rec[0] == 1)
                              {
                               add_send_hex_data("90 18 03");


                              }
                              if(track_rec[1] == 1)
                              {
                                  add_send_hex_data("90 19 03");


                              }
                              if(track_rec[2] == 1)
                              {
                                  add_send_hex_data("90 1A 03");


                              }
                              if(track_rec[3] == 1)
                              {
                                  add_send_hex_data("90 1B 03");


                              }
                              if(track_rec[4] == 1)
                              {
                                  add_send_hex_data("90 1C 03");


                              }
                              if(track_rec[5] == 1)
                              {
                                  add_send_hex_data("90 1D 03");


                              }
                              if(track_rec[6] == 1)
                              {
                                  add_send_hex_data("90 1E 03");


                              }
                              if(track_rec[7] == 1)
                              {
                                  add_send_hex_data("90 1F 03");


                              }
sleep(1);
//main rec led on
 add_send_hex_data("90 24 03");


}




//peak meter


int Thread1::signalmeter(ECA_CONTROL_INTERFACE* eci)
{
  int result = 0;

  for(int cn = 1; cn < 3; cn++)

       {


     //master
     eci->command("c-select chainMaster");
     eci->command("cop-select 2");


//     //--
//     QString crqcsai_addo = "copp-select " + QString::number(cn);
//     QString crqcsai_add = crqcsai_addo;
//     QString crstrcs = crqcsai_add;
//     std::string crstdstrcs = crstrcs.toStdString();
//     const char * crcstrcs = crstdstrcs.c_str();
//     //qDebug() << "crcstrcs" << qPrintable(crcstrcs);

//   ecas.command(crcstrcs);


     //--
    // eci->command("copp-select 1");


     eci->command("copp-select " + kvu_numtostr(cn));
     eci->command("copp-get");

     if (eci->error())
     {
       result = -1;
       break;
     }

     double mvalue = eci->last_float();



     if(mvalue>=0.95)
        {
  //qDebug() << "--------------------------------------mvalue "   <<   mvalue   ;
         add_send_hex_data("90 20 02");

        }

     if(mvalue<0.93)
     {
  add_send_hex_data("90 20 01");
        }


}




     //end master



     for(int n = 0; n < ecasv_chcount; n++)

          {

      //chain select n1 - n8, copp id static
     // eci->command("c-select chain1");

     //<<<<<<<<<<<<<<<<<replace with QString::number(trackNR) and remove kvu

      eci->command("c-select chain" + kvu_numtostr(n + 1));
      //before ea: eci->command("cop-select 1");
       eci->command("cop-select 4");



      eci->command("copp-select 1");
    //eci->command("copp-select " + kvu_numtostr(n + 1));
    eci->command("copp-get");

    if (eci->error())
    {
      result = -1;
      break;
    }

    double value = eci->last_float();

  // qDebug() << n << "vu value++++++++++++++++++++++++++" << value;



    //all lights on
    if(value>=0.9)
    {
       if(n==0)
       {
        add_send_hex_data("90 00 02");
        add_send_hex_data("90 08 02");
        add_send_hex_data("90 10 02");
       }
       if(n==1)
       {
        add_send_hex_data("90 01 02");
        add_send_hex_data("90 09 02");
        add_send_hex_data("90 11 02");
       }
       if(n==2)
       {
        add_send_hex_data("90 02 02");
        add_send_hex_data("90 0A 02");
        add_send_hex_data("90 12 02");
       }
       if(n==3)
       {
        add_send_hex_data("90 03 02");
        add_send_hex_data("90 0B 02");
        add_send_hex_data("90 13 02");
       }
       if(n==4)
       {
        add_send_hex_data("90 04 02");
        add_send_hex_data("90 0C 02");
        add_send_hex_data("90 14 02");
       }
       if(n==5)
       {
        add_send_hex_data("90 05 02");
        add_send_hex_data("90 0D 02");
        add_send_hex_data("90 15 02");
       }
       if(n==6)
       {
        add_send_hex_data("90 06 02");
        add_send_hex_data("90 0E 02");
        add_send_hex_data("90 16 02");
       }
       if(n==7)
       {
       add_send_hex_data("90 07 02");
       add_send_hex_data("90 0F 02");
       add_send_hex_data("90 17 02");
       }
    }
    //turn off peak light
    if((value<0.84)&(value>0.60))
    {

       if(n==0)
       {
        add_send_hex_data("90 00 01");
        add_send_hex_data("90 08 02");
        add_send_hex_data("90 10 02");
       }
       if(n==1)
       {
        add_send_hex_data("90 01 01");
        add_send_hex_data("90 09 02");
        add_send_hex_data("90 11 02");
       }
       if(n==2)
       {
        add_send_hex_data("90 02 01");
        add_send_hex_data("90 0A 02");
        add_send_hex_data("90 12 02");
       }
       if(n==3)
       {
        add_send_hex_data("90 03 01");
        add_send_hex_data("90 0B 02");
        add_send_hex_data("90 13 02");
       }
       if(n==4)
       {
        add_send_hex_data("90 04 01");
        add_send_hex_data("90 0C 02");
        add_send_hex_data("90 14 02");
       }
       if(n==5)
       {
        add_send_hex_data("90 05 01");
        add_send_hex_data("90 0D 02");
        add_send_hex_data("90 15 02");
       }
       if(n==6)
       {
        add_send_hex_data("90 06 01");
        add_send_hex_data("90 0E 02");
        add_send_hex_data("90 16 02");
       }
       if(n==7)
       {
       add_send_hex_data("90 07 01");
       add_send_hex_data("90 0F 02");
       add_send_hex_data("90 17 02");
       }
    }
//turn off peak and middle light
    if((value<0.60)&(value>0.10))
    {
       //qDebug() << "vu meter RED";

       if(n==0)
       {
        add_send_hex_data("90 00 01");
        add_send_hex_data("90 08 01");
        add_send_hex_data("90 10 02");
       }
       if(n==1)
       {
        add_send_hex_data("90 01 01");
        add_send_hex_data("90 09 01");
        add_send_hex_data("90 11 02");
       }
       if(n==2)
       {
        add_send_hex_data("90 02 01");
        add_send_hex_data("90 0A 01");
        add_send_hex_data("90 12 02");
       }
       if(n==3)
       {
        add_send_hex_data("90 03 01");
        add_send_hex_data("90 0B 01");
        add_send_hex_data("90 13 02");
       }
       if(n==4)
       {
        add_send_hex_data("90 04 01");
        add_send_hex_data("90 0C 01");
        add_send_hex_data("90 14 02");
       }
       if(n==5)
       {
        add_send_hex_data("90 05 01");
        add_send_hex_data("90 0D 01");
        add_send_hex_data("90 15 02");
       }
       if(n==6)
       {
        add_send_hex_data("90 06 01");
        add_send_hex_data("90 0E 01");
        add_send_hex_data("90 16 02");
       }
       if(n==7)
       {
       add_send_hex_data("90 07 01");
       add_send_hex_data("90 0F 01");
       add_send_hex_data("90 17 02");
       }
    }
//turn off "green" light
    if(value<0.10)
    {
       //qDebug() << "vu meter RED";

       if(n==0)
       {
        add_send_hex_data("90 00 01");
        add_send_hex_data("90 08 01");
        add_send_hex_data("90 10 01");
       }
       if(n==1)
       {
        add_send_hex_data("90 01 01");
        add_send_hex_data("90 09 01");
        add_send_hex_data("90 11 01");
       }
       if(n==2)
       {
        add_send_hex_data("90 02 01");
        add_send_hex_data("90 0A 01");
        add_send_hex_data("90 12 01");
       }
       if(n==3)
       {
        add_send_hex_data("90 03 01");
        add_send_hex_data("90 0B 01");
        add_send_hex_data("90 13 01");
       }
       if(n==4)
       {
        add_send_hex_data("90 04 01");
        add_send_hex_data("90 0C 01");
        add_send_hex_data("90 14 01");
       }
       if(n==5)
       {
        add_send_hex_data("90 05 01");
        add_send_hex_data("90 0D 01");
        add_send_hex_data("90 15 01");
       }
       if(n==6)
       {
        add_send_hex_data("90 06 01");
        add_send_hex_data("90 0E 01");
        add_send_hex_data("90 16 01");
       }
       if(n==7)
       {
       add_send_hex_data("90 07 01");
       add_send_hex_data("90 0F 01");
       add_send_hex_data("90 17 01");
       }
    }



  }

  return result;


}


//end signalmeter



void Thread1::reset()
{
     ecas.command("cs-set-position 0");
     //jack_transport_reposition 	(client,0);
     jack_transport_locate(client,0);


   //turn off all fan lights
                   add_send_hex_data("B0 28 00");
                    add_send_hex_data("B0 29 00");
    ntt=0;

}


void Thread1::pstop()
{
//    rxfader1();
//    rxfader2();
//    rxfader3();
//    rxfader4();
//    rxfader5();
//    rxfader6();
//    rxfader7();
//    rxfader8();

ecas.command("c-select chainMaster");
ecas.command("cop-set ’1,1,0’");
//add_send_hex_data("B0 09 00");

ecas.command("c-select chain1");
ecas.command("cop-set ’3,1,0’");
ecas.command("c-select chain2");
ecas.command("cop-set ’3,1,0’");
ecas.command("c-select chain3");
ecas.command("cop-set ’3,1,0’");
ecas.command("c-select chain4");
ecas.command("cop-set ’3,1,0’");
ecas.command("c-select chain5");
ecas.command("cop-set ’3,1,0’");
ecas.command("c-select chain6");
ecas.command("cop-set ’3,1,0’");
ecas.command("c-select chain7");
ecas.command("cop-set ’3,1,0’");
ecas.command("c-select chain8");
ecas.command("cop-set ’3,1,0’");




    //qDebug() << "terminate";
    emit stopsignal(1);
    maxrectracks=0;

    //tThread->Stop=true;

    timer->stop();

     //ecas.command("engine-halt");
     jack_transport_stop(client);
   //ecas.command("stop");
   // ecas.command("cs-get-position");

     rxplayoff();

     maincounter = 0;

     restart1 = 0;
     restart2 = 0;
     restart3 = 0;

     rec1counter = 0;
     rec2counter = 0;
     rec3counter = 0;

     //turn all vu lights off
sleep(1);

     add_send_hex_data("90 00 01");
     add_send_hex_data("90 08 01");
     add_send_hex_data("90 10 01");

     add_send_hex_data("90 01 01");
     add_send_hex_data("90 09 01");
     add_send_hex_data("90 11 01");

     add_send_hex_data("90 02 01");
     add_send_hex_data("90 0A 01");
     add_send_hex_data("90 12 01");

     add_send_hex_data("90 03 01");
     add_send_hex_data("90 0B 01");
     add_send_hex_data("90 13 01");

     add_send_hex_data("90 04 01");
     add_send_hex_data("90 0C 01");
     add_send_hex_data("90 14 01");

     add_send_hex_data("90 05 01");
     add_send_hex_data("90 0D 01");
     add_send_hex_data("90 15 01");

     add_send_hex_data("90 06 01");
     add_send_hex_data("90 0E 01");
     add_send_hex_data("90 16 01");

    add_send_hex_data("90 07 01");
    add_send_hex_data("90 0F 01");
    add_send_hex_data("90 17 01");

    //all rec leds off
       add_send_hex_data("90 18 01");
       add_send_hex_data("90 19 01");
       add_send_hex_data("90 1A 01");
       add_send_hex_data("90 1B 01");
       add_send_hex_data("90 1C 01");
       add_send_hex_data("90 1D 01");
       add_send_hex_data("90 1E 01");
       add_send_hex_data("90 1F 01");

      // rec led
       add_send_hex_data("90 24 01");

       if((recmode==1)||(recmode==2))
       {
           rectrackled();
               add_send_hex_data("90 24 02");


       }


  // ecas.command("cs-disconnect");


    // requestInterruption();

  //  qApp->quit();
   // QProcess::startDetached(qApp->arguments()[0], qApp->arguments());


    //m_pJackClient != NULL;
    //jack_transport_stop(m_pJackClient);

   // m_pJackClient == NULL;

    // client = jack_client_open("sixad-jack", JackNullOption, 0);


//    const char **ports;
//        const char *client_name = "simple";
//    jack_status_t status;


//jack_port_t *input_port;
//jack_port_t *output_port;
//jack_client_t *client;
//client = jack_client_open (client_name, JackNullOption, &status );



}
//just for debug use, to recycle
//void Thread1::valueChanged1(int searchvalueN)
//{

//    qDebug() << "valueChanged";
//    qDebug() << searchvalueN;
//}

void Thread1::rewind(int searchvalueN)

{

    timer->stop();
    pstop();



    ntt = ntt - searchvalueN;

    //turn off all fan lights
                    add_send_hex_data("B0 28 00");
                     add_send_hex_data("B0 29 00");

    qDebug() << "valueChanged in rewind++++++++";
    qDebug() << searchvalueN;
 if (client)
 {
     jack_position_t tpos;
     jack_transport_query(client, &tpos);
     float rate = float(tpos.frame_rate);
     float tloc = ((float(tpos.frame) / rate) - searchvalueN) * rate;
     if (tloc < 0.0f) tloc = 0.0f;
     jack_transport_locate(client, (jack_nframes_t) tloc);

     if (searchvalueN < 60.0)
         searchvalueN *= 1.1f;
 }
}


void Thread1::forward(int searchvalueN)

{

  timer->stop();
    pstop();


  ntt = ntt + searchvalueN;

  //turn off all fan lights
                  add_send_hex_data("B0 28 00");
                   add_send_hex_data("B0 29 00");

 if (client)
    {
     jack_position_t tpos;
     jack_transport_query(client, &tpos);
     float rate = float(tpos.frame_rate);
     float tloc = ((float(tpos.frame) / rate) + searchvalueN) * rate;
     if (tloc < 0.0f) tloc = 0.0f;
     jack_transport_locate(client, (jack_nframes_t) tloc);

     qDebug() << "searchvalueN"  << searchvalueN;
     qDebug() << "rate" << rate ;
     qDebug() << "tloc"  << tloc;

     if (searchvalueN < 60.0f)
         searchvalueN *= 1.1f;


    }
}


void Thread1::terminateall()
{
    jack_transport_stop(client);
    ecas.command("cs-disconnect");
    ecas.command("engine-halt");

  ecas.command("stop");

}

void Thread1::exitslot()
{

jack_transport_stop(client);
ecas.command("cs-select play_chainsetup");
ecas.command("cs-disconnect");
//file is saving blinking:
add_send_hex_data("90 20 03");
sleep(1);
add_send_hex_data("90 20 01");

//qDebug() << "reconnecting"  ;
//ecas.command("cs-select play_chainsetup");
//ecas.command("cs-connect");

    //----------------------------this worked
//    QProcess processgg;

//    QString acommandg = "gnome-terminal -x bash -c \"" + execpathg;
//    qDebug() <<  acommandg;
//    processgg.start(acommandg);
    //-----------------------------------------
                                         //
                     QProcess sh11;
                      sh11.start("sh");

                      //
                      QString qshpath = HomePathT + "/x_helper_script.sh";
                      std::string shpath = qshpath.toStdString();
                      const char * pqshpath = shpath.c_str();
                      qDebug() << "pqshpath" << qPrintable(pqshpath);



                     sh11.write(pqshpath);

                      sh11.closeWriteChannel();
                      sh11.waitForFinished();

                     // QProcess process33;

//
                                 //process33.waitForFinished(-1);
                      //sleep(2);
                               //  QString stdoute = process33.readAllStandardOutput();
                      //sleep(2);


                                 //qDebug() << "QProcess" << stdoute ;





                                         //



     qDebug() << "exitslot thread"  ;

int putexit =1;

// //emit exitvalue(putexit);

////sleep(2);

//ecas.command("ctrl-status");

//     QProcess sh;
//     sh.start("sh");

//     sh.write("pgrep ecasound");
//     sh.closeWriteChannel();

//     sh.waitForFinished();
//     QByteArray output2 = sh.readAll();

//     QString DataAsString = QString(output2);

//      QString  outp2 = DataAsString.remove("\n");

//      qDebug() << " QByteArray output" << output2 << outp2;

//       int stdoi =  outp2.toInt();

//      if(outp2!=NULL)
//      {
//        qDebug() << "not null";

//       kill (stdoi, SIGINT);
//        //kill (stdoi, SIGTERM);
//            sleep(1);



//      }




//     sh.close();

//if(outp2==NULL)
//{
//ecas.command("ctrl-status");
//     //
//     QProcess process3;
//     QProcess process4;

//           process3.start("pgrep ecasound");
//           process3.waitForFinished(-1);
////sleep(2);
//           QString stdoute = process3.readAllStandardOutput();
////sleep(2);
//          QString stdoute2 = stdoute.remove("\n");

//        int stdo3 =  stdoute2.toInt();

//           qDebug() << "QProcess" << stdoute << stdoute2 << stdo3   ;

//           if(stdoute!=NULL)
//           {
//             qDebug() << "not null";

//            kill (stdo3, SIGINT);
//             //kill (stdo3, SIGTERM);
//                 sleep(1);



//           }
//           else
//           {
//               process4.start("pidof ecasound");
//               process4.waitForFinished(-1);
//    sleep(1);
//               QString stdoute4 = process4.readAllStandardOutput();
//    sleep(1);
//              QString stdoute24 = stdoute4.remove("\n");

//            int stdo34 =  stdoute24.toInt();

//               qDebug() << "QProcess4" << stdoute4 << stdoute24 << stdo34   ;

//               if(stdoute4!=NULL)
//               {
//                 qDebug() << "not null4";

//                kill (stdo34, SIGINT);
//                 //kill (stdo34, SIGTERM);
//                     sleep(1);
//           }
//           }





// qDebug() << "exitslot3"  ;


// process3.kill();
//  process4.kill();



//      qDebug() << "exitslot4 after jack"  ;

//      sleep(1);

//     qApp->quit();
//    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());

tThread->quit();

emit exitvalue(putexit);


  }







void Thread1::csgetpos()
{




//timer->start(1000);


}

//rxsend
void Thread1::rxsend()
{

//    outputp = &output;
//    inputp = NULL;
//    snd_rawmidi_open(inputp, outputp, "virtual", 0);

//list with aconnect to get port to connect to
    //connect to aseq

    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    //str = "90 26 02";
    //str = "0xB0 0x1A 0x07";
    str="B0 1A 07";
    //str = "B0 01 00";
    add_send_hex_data(str);
}

 qDebug() << "rx send str ------------------------------------" << str;


}


void Thread1::rxplayon()
{

//    outputp = &output;
//    inputp = NULL;
//    snd_rawmidi_open(inputp, outputp, "virtual", 0);

//list with aconnect to get port to connect to
    //connect to aseq
sleep(1);
    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "90 26 02";
     //str = "90 00 03";
    add_send_hex_data(str);
}

 //qDebug() << "rxplayon str ------------------------------------" << str;


}

void Thread1::rxplayoff()
{

//    outputp = &output;
//    inputp = NULL;
//    snd_rawmidi_open(inputp, outputp, "virtual", 0);

//list with aconnect to get port to connect to
    //connect to aseq

    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "90 26 01";
    add_send_hex_data(str);
}

 //qDebug() << "rxplayoff str ------------------------------------" << str;

}
//pan 12 o'clock
void Thread1::rxpan1()
{
    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "B0 1A 07";
    add_send_hex_data(str);
}
}
//
void Thread1::rxpan2()
{
    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "B0 1B 07";
    add_send_hex_data(str);
}
}
//
void Thread1::rxpan3()
{
    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "B0 1C 07";
    add_send_hex_data(str);
}
}
//
void Thread1::rxpan4()
{
    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "B0 1D 07";
    add_send_hex_data(str);
}
}
//
void Thread1::rxpan5()
{
    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "B0 1E 07";
    add_send_hex_data(str);
}
}
//
void Thread1::rxpan6()
{
    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "B0 1F 07";
    add_send_hex_data(str);
}
}
//
void Thread1::rxpan7()
{
    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "B0 20 07";
    add_send_hex_data(str);
}
}
//
void Thread1::rxpan8()
{
    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "B0 21 07";
    add_send_hex_data(str);
}
}

//FADERS to 0
void Thread1::rxfader1()
{
    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "B0 01 00";
    add_send_hex_data(str);
}
}
//
void Thread1::rxfader2()
{
    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "B0 02 00";
    add_send_hex_data(str);
}
}
//
void Thread1::rxfader3()
{
    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "B0 03 00";
    add_send_hex_data(str);
}
}
//
void Thread1::rxfader4()
{
    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "B0 04 00";
    add_send_hex_data(str);
}
}
//
void Thread1::rxfader5()
{
    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "B0 05 00";
    add_send_hex_data(str);
}
}
//
void Thread1::rxfader6()
{
    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "B0 06 00";
    add_send_hex_data(str);
}
}
//
void Thread1::rxfader7()
{
    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "B0 07 00";
    add_send_hex_data(str);
}
}
//
void Thread1::rxfader8()
{
    const char *str;
str = NULL;
if(str!=NULL)
{
 //qDebug() << "str error";
}
else
{
    str = "B0 08 00";
    add_send_hex_data(str);
}
}
//

//


//mod of amidi.c line 389...
//send
void Thread1::add_send_hex_data(const char *str)
{
    int length;
    char *s;
send_hex =NULL;
  //qDebug() << "str ----send_hex--------------------------------" << send_hex;
   //  qDebug() << "str --str in--:add_send_hex_data(--------------------------------" << str;

    length = (send_hex ? strlen(send_hex) + 1 : 0) + strlen(str) + 1;


    size_t size;



        void *p = malloc(size);
    //s = static_cast<char*>(my_malloc(length));
    s = static_cast<char*>(malloc(length));

    if (send_hex)
    {
        strcpy(s, send_hex);
        strcat(s, " ");
    } else {
        s[0] = '\0';
    }
    strcat(s, str);
    free(send_hex);
    send_hex = s;

        //qDebug() << "uiiiiiiiiiiiiiiiiiiiiiiiiiiiii_ send_hex = s" << send_hex;
         // qDebug() << "uiiiiiiiiiiiiiiiiiiiiiiiiiiiii_ s" << s;



    //if (send_hex)
    parse_data();
}







//mod of amidi.c line 274...
void Thread1::parse_data(void)
{
    const char *p;
    int i, value;
send_data=NULL;
    send_data = static_cast<char*>(malloc(strlen(send_hex))); /* guesstimate */
    i = 0;
    value = -1; /* value is >= 0 when the first hex digit of a byte has been read */
    for (p = send_hex; *p; ++p) {
        int digit;
        if (isspace((unsigned char)*p)) {
            if (value >= 0) {
                send_data[i++] = value;
                value = -1;
            }
            continue;
        }
        digit = hex_value(*p);
        if (digit < 0) {
            send_data = NULL;
           // return;
        }
        if (value < 0) {
            value = digit;
        } else {
            send_data[i++] = (value << 4) | digit;
            value = -1;
        }
    }
    if (value >= 0)
        send_data[i++] = value;
    send_data_length = i;

//send midi hex
static char *port_namerx;

   // port_namerx = "virtual";
     port_namerx = "X-TOUCH COMPACT";

        outputp = &output;
        inputp = NULL;

       // qDebug() << send_data << ".................................send_data" << send_data_length << "send_data_length";


          snd_rawmidi_write(output, send_data, send_data_length);





//        if(dontspamrawmidi_open==0)
//        {
//       snd_rawmidi_open(inputp, outputp, port_namerx, SND_RAWMIDI_NONBLOCK);
//        }
//       snd_rawmidi_write(output, send_data, send_data_length);

}

//mod of amidi.c line 262...
int Thread1::hex_value(char c)
{
    if ('0' <= c && c <= '9')
        // qDebug() << "0-9";
        return c - '0';
    if ('A' <= c && c <= 'F')
                 //qDebug() << "A-F";
        return c - 'A' + 10;
    if ('a' <= c && c <= 'f')
                 //qDebug() << "a-f";
        return c - 'a' + 10;
    //error("invalid character %c", c);
    return -1;
}


//rxsend end



void Thread1::deletetrack()

{
           qDebug() << activetape << "activetape XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXdeletetrack()";
           qDebug() << recmode-10 << "recmode-10 XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXdeletetrack()";

        QString OldTapeName =  activetape + "/Track_" + QString::number(recmode-10) + ".wav";

         qDebug() << OldTapeName << "OldTapeName XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXdeletetrack()";

        //int randomValue1 = qrand() % 999999;

        QDateTime now = QDateTime::currentDateTime();
        QString timestamp = now.toString(QLatin1String("yyyyMMdd-hhmm"));

          qDebug() << now << timestamp << "timestamp  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXdeletetrack()";


        //QString NewTapeName =  activetape + "/X_OLD_Track_" + QString::number(recmode-10) + "_" + QString::number(randomValue1) + ".wav";
        QString NewTapeName =  activetape + "/X_OLD_Track_" + QString::number(recmode-10) + "_" + timestamp + ".wav";

         qDebug() << NewTapeName << "NewTapeName XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXdeletetrack()";




        QFile file2(OldTapeName);
        file2.rename(NewTapeName);


         qDebug() << "end of renaming.........";

         recmode=0;
         recmodesfile();

         sleep(1);

         qDebug() << recmode << "recmode mmmmmmmmmmmmmmmmmmmmmmmmmrestart";

          QProcess sh11;
                               sh11.start("sh");


                               //
                               QString qshpath = HomePathT + "/x_helper_script.sh";
                               std::string shpath = qshpath.toStdString();
                               const char * pqshpath = shpath.c_str();
                               qDebug() << "pqshpath" << qPrintable(pqshpath);



                              sh11.write(pqshpath);


                               sh11.closeWriteChannel();
                               sh11.waitForFinished();

         int putexit =1;


         tThread->quit();

         emit exitvalue(putexit);







    }


//not used
void Thread1::maincounterfive()
{
if(maincounter==5)
{
    add_send_hex_data("90 18 03");
    add_send_hex_data("90 19 03");
    add_send_hex_data("90 1A 03");
    add_send_hex_data("90 1B 03");
    add_send_hex_data("90 1C 03");
    add_send_hex_data("90 1D 03");
    add_send_hex_data("90 1E 03");
    add_send_hex_data("90 1F 03");


}
}



Thread1::~Thread1()
{

    //ecas.command("engine-halt");
    //jack_client_close(client);
    //sleep(1);
//timer2->stop();
  quit();

#if QT_VERSION >= QT_VERSION_CHECK(5,2,0)
requestInterruption();
#endif

wait();
sleep(1);

//



  //

//  char buf[512];
//  FILE *cmd_pipe = popen("pidof -s ecasound", "r");

//  fgets(buf, 512, cmd_pipe);
//  pid_t pid = strtoul(buf, NULL, 10);

//  pclose( cmd_pipe );

// QString pidrs = QString::number(pid);
//   qDebug() << "pidrs"  ;
//  qDebug() << pidrs  ;

//  //QString comend = "gnome-terminal -x bash -c \"kill -INT " + pidrs + "\"";

//  kill (pid, SIGINT);
//   kill (pid, SIGTERM);


}









//+++NOTES+++++++++++++++++++++++++++++++++++++

//https://manpages.debian.org/jessie/ecasound/ecasound.1.en.html
//http://nosignal.fi/ecasound/Documentation/ecasound-iam_manpage.html

//amidi -l

//amidi -p hw:3,0,0  --dump


//xtouch map

//SEND
//rec enable
//1-8
//90 28 7F
//90 29 7F
//90 2A 7F
//90 2B 7F
//90 2C 7F
//90 2D 7F
//90 2E 7F
//90 2F 7F
// -----------------------
//main
//90 30 7F

//transport
//<<
//90 31 7F

//>>
//90 32 7F

//rec
//90 34 7F

//play
//90 36 7F

//stop
//90 35 7F

//loop
//90 33 7F
//-------------------------

//mute (1-8)
//90 20 7F
//90 21 7F
//90 22 7F
//90 23 7F
//90 24 7F
//90 25 7F
//90 26 7F
//90 27 7F

//solo (1-8)
//90 18 7F
//B0 65 00
//90 1A 7F
//90 1B 7F
//90 1C 7F
//90 1D 7F
//90 1E 7F
//90 1F 7F

//select (1-8)
//90 10 7F
//90 11 7F
//90 12 7F
//90 13 7F
//90 14 7F
//90 15 7F
//90 16 7F
//90 17 7F

//+++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++
//https://www.midi.org/specifications-old/item/table-3-control-change-messages-data-bytes-2

//RX (receive to controll LED)
//set panning to 12 o'clock

//amidi -p hw:3,0,0 -S "B0 1A 07"

//B0 1A 07
//B0 1B 07
//B0 1C 07
//B0 1D 07
//B0 1E 07
//B0 1F 07
//B0 20 07
//B0 21 07

//--------------

//change 9-16 to FAN LED

//amidi -p hw:3,0,0 -S "B0 12 02"

//B0 13 02
//B0 14 02
//B0 15 02
//...

//------------------------

//faders to 0 (0-127)

//amidi -p hw:3,0,0 -S "B0 01 00"


//...
//B0 09 00


//------------------------

//amidi -p hw:3,0,0 -S "90 00 01"

//xx= 90 (note on)
//yy= note
//zz= vel.

//xx yy 01 off
//xx yy 02 on
//xx yy 03 blinking

//1st row:
//90 00
//90 01
//...
//90 07

//2nd row (yy)
//08
//09
//0A
//0B
//0C
//0D
//0E
//0F


//3rd row (yy)
//10
//11
//12
//13
//14
//15
//16
//17


//rec enable (yy)
//18
//19
//1A
//1B
//1C
//1D
//1E
//1F


//master fader (yy)
//20


//transport (yy)

//<<
//21

//>>
//22

//loop
//23

//rec
//24

//stop
//25

//play
//26



//+++++++++++++++++++++++++++++

//if (byte == 0x28)
//            {
//          qDebug() << "byte 0x28vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";
//          if (dontspam28==0)
//          {
//          sendmidinote();
//          dontspam28=dontspam28+1;
//          dontspamrawmidi_open=dontspamrawmidi_open+1;
//          }

//           }

//   if (byte == 0x29)
//            {
//          qDebug() << "byte 0x29vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";
//          //reset 28
//          dontspam28=0;
//           }

//   if (byte == 0x2A)
//            {
//          qDebug() << "byte 0x2Avvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";
//           }







