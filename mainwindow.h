#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "thread1.h"
#include "thread2.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Thread1 *mThread;
    //Thread2 *tThread;

signals:
//        void buttonOkClickedSignal(QString var);
//        void signalValueUpdated(int);
        void esignal(QString fileName);
//          void signalcstimer(int);



private:
    Ui::MainWindow *ui;

public slots:
    void closeEvent(QCloseEvent *event);


private slots:
//    void resetslot();
//    void stopslot();
    void fileslot();
//    void rewindslot();
//    void forwardslot();
//    void metersslot();
//    void playslot();
   void valueGot(int timevalue);
    void exitslot0(int onevalue);

};

#endif // MAINWINDOW_H









