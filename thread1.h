#ifndef THREAD1_H
#define THREAD1_H

//#include <jack/jack.h>
//#include <jack/transport.h>
//#include <jack/metadata.h>
//#include <jack/control.h>

#include "eca-control-interface.h"

#include <vector>

#include <cassert>
#include <cmath>
#include <cstdio>

#include "asoundlib.h"


#include <QThread>

#include "thread2.h"


class Thread1 : public QThread
{


    Q_OBJECT
public:
    explicit Thread1(QObject *parent = 0, bool b = false);
     ~Thread1();
    Thread2 *tThread;

    void run();
    void pstop();
    void reset();
    void rewind(int searchvalueN);
    void forward(int searchvalueN);
    void meters();
    void play();
    //void valueChanged1(int searchvalueN);
    void terminateall();
    void exitslot();
    int signalmeter(ECA_CONTROL_INTERFACE* ecas);



    void loop_device();

    void csgetpos();

  typedef void (*action_func_t)(snd_seq_t *seq, snd_seq_client_info_t *cinfo, snd_seq_port_info_t *pinfo, int count);
   void alsaconnect();
   void list_subscribers(snd_seq_t *seq, const snd_seq_addr_t *addr);
   void list_each_subs(snd_seq_t *seq, snd_seq_query_subscribe_t *subs, int type, const char *msg);

   void check_permission(snd_seq_port_info_t *pinfo, int perm);

   //x-touch sends midi notes
//   void dump_event(const snd_seq_event_t *ev);
//   void aseqdump();
//   void check_snd(const char *operation, int err);

   //x-touch receives midi notes (RX lights, fader movement)
   void rxsend();
   void rxplayon();
   void rxplayoff();
   void add_send_hex_data(const char *str);
   void parse_data(void);
   int hex_value(char c);
   void rxvirtualclient();
   void alsaconnectrx();
   void rxpan1();
   void rxpan2();
   void rxpan3();
   void rxpan4();
   void rxpan5();
   void rxpan6();
   void rxpan7();
   void rxpan8();
   void rxfader1();
   void rxfader2();
   void rxfader3();
   void rxfader4();
   void rxfader5();
   void rxfader6();
   void rxfader7();
   void rxfader8();

   void recreadyledinit();
    void recreadyled();
    void effecttrack(int effecttrackNR);
     void effectoff(int effecttrackNR);
     void effectmainlim();

    //void readrestarttxt();
    void readrecmodetxt();
    void restartmodes();
    void rectrackled();

    void recmodesfile();
    void tapesfile();
    void activetapeLED();
    void readtapeslottxt();
    void deletetrack();
    void maincounterfive();




    // if Stop = true, the thread will break
    // out of the loop, and will be disposed
    bool Stop;


private:
       //jack_client_t *client;


signals:

    //void T1(QString);
    void t1signal(QString T1);
    void t2signal(QString T2);
    void t3signal(QString T3);
    void t4signal(QString T4);
    void t5signal(QString T5);
    void t6signal(QString T6);
    void t7signal(QString T7);
    void t8signal(QString T8);
    void possignalmin(QString possmin);
     void possignalsec(QString posssec);
     void lensignalmin(QString possmin);
     void lensignalsec(QString possec);     
     void stopsignal(int stoploop);
     void textoutput(QString);
     void exitvalue(int putexit);



    void buttonOkClickedSignal(QString var);

public slots:

private slots:
    void valueGotStart(int timestartvalue);
    void valueGotStop(int timestopvalue);
    void valueGotAseq(int aseqsignal2value);








};

#endif // THREAD1_H
