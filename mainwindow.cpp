#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "mythread.h"
#include <QDebug>
//#include <eca-control-interface.h>

#include <QFileDialog>

#include <QLineEdit>
#include <QFile>

#include <QApplication>
#include <QProcess>

#include <QMessageBox>

#include <QCloseEvent>

#include <signal.h>

int disconandexit = 0;


//#include <QMutex>
int quitvalue;

// ui->label->setText();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


      mThread = new Thread1(this);


//      QFile hfile(".eca_hfile.txt");
//      if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
//          return;
//      QTextStream in(&hfile);
//      while (!in.atEnd()) {
//          QString hostr = in.readLine();
//          //qDebug() << hostr;
//          if(~(hostr.isEmpty())){
//          ui->label_2->setText(hostr);}
//                  }


 mThread->start();

 qDebug() << "_____________________--mainwindow thread" << reinterpret_cast<std::uintptr_t>(thread()->currentThreadId());




//connect(mThread,SIGNAL(possignal(int)), this, SLOT(valueGot(int)));



// connect(this,SIGNAL(signalValueUpdated(int)),mThread, SLOT(valueChanged1(int)));
// connect(this,SIGNAL(signalValueUpdated(int)),mThread, SLOT(rewind(int searchvalue)));
//  connect(this,SIGNAL(signalValueUpdated(int)),mThread, SLOT(forward(int searchvalue)));

  //





//connect(mThread,SIGNAL(t1signal(QString)), ui->label_t1, SLOT(setText(QString)));
//connect(mThread,SIGNAL(t2signal(QString)), ui->label_t2, SLOT(setText(QString)));
//connect(mThread,SIGNAL(t3signal(QString)), ui->label_t3, SLOT(setText(QString)));
//connect(mThread,SIGNAL(t4signal(QString)), ui->label_t4, SLOT(setText(QString)));
//connect(mThread,SIGNAL(t5signal(QString)), ui->label_t5, SLOT(setText(QString)));
//connect(mThread,SIGNAL(t6signal(QString)), ui->label_t6, SLOT(setText(QString)));
//connect(mThread,SIGNAL(t7signal(QString)), ui->label_t7, SLOT(setText(QString)));
//connect(mThread,SIGNAL(t8signal(QString)), ui->label_t8, SLOT(setText(QString)));


//connect(mThread,SIGNAL(possignalmin(QString)), ui->label_posmin, SLOT(setText(QString)));
//connect(mThread,SIGNAL(possignalsec(QString)), ui->label_possec, SLOT(setText(QString)));

//connect(mThread,SIGNAL(lensignalmin(QString)), ui->label_alenmin, SLOT(setText(QString)));
//connect(mThread,SIGNAL(lensignalsec(QString)), ui->plainTextEdit, SLOT(setText(QString)));

//connect(mThread,SIGNAL(textoutput(QString)), ui->plainTextEdit, SLOT(insertPlainText(QString)));


connect(mThread,SIGNAL(exitvalue(int)), this, SLOT(exitslot0(int)));

//ui->spinBox->setValue(5);




}

void MainWindow::closeEvent(QCloseEvent *event)
{


event->ignore();
//    if (QMessageBox::Yes == QMessageBox::question(this, "GNU_TRM8TT", "Disconnect and Exit?", QMessageBox::Yes | QMessageBox::No))
//    {
//         mThread->exitslot();
//        event->accept();

//    }


    if (disconandexit==1)
    {
    {
             qDebug() << "closeevvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvent" ;
         //mThread->exitslot();
        event->accept();
    }

    }







}

void MainWindow::valueGot(int timevalue)
{

    qDebug() << "timevalue" << timevalue;
}


//void MainWindow::resetslot()
//{

////    QString nfile( ui->lineEdit->toPlainText())   ;
//   // qDebug() << nfile;

// mThread->reset();

//        //ui->StartButton->setVisible(false);
//}


//void MainWindow::stopslot()
//{

//    //qDebug() << "na";

//  // mThread->Stop = true;

//   mThread->pstop();

//}

//if (m_ui.BackwardToolButton->isDown() && m_fSkipAccel < 60.0)
//m_fSkipAccel *= 1.1f;



//void MainWindow::rewindslot()
//{

//  int searchvalue = ui->spinBox->value();
//qDebug() << "searchvalueRR:::::::::::::::::::::::::::";
// qDebug() << searchvalue;


//emit signalValueUpdated(searchvalue);


//mThread->valueChanged1(searchvalue);
//mThread->rewind(searchvalue);


//}

//void MainWindow::forwardslot()
//{

//  int searchvalue = ui->spinBox->value();
//  qDebug() << "searchvalueFF:::::::::::::::::::::::::::";
//   qDebug() << searchvalue;

//  emit signalValueUpdated(searchvalue);

//mThread->forward(searchvalue);
//}

void MainWindow::fileslot()
{
//     mThread->terminateall();
//     mThread->exitslot();
//todo: let user select default folder in settings
//    QString fileName;
//    fileName = QFileDialog::getOpenFileName(this,
//         tr("Open WAV File"), "/home/debian9/Desktop/ecasound", tr("WAV Files (*.wav)"));
//    ui->lineEdit->setText(fileName);

//    QFile hfile(".eca_hfile.txt");
//         if (!hfile.open(QIODevice::WriteOnly | QIODevice::Text))
//             return;

//         QTextStream outh(&hfile);
//         outh << fileName;
//           qApp->quit();
//           QProcess::startDetached(qApp->arguments()[0], qApp->arguments());

//the following was OK to get the new file with signals/slots (toggle all//):
    connect(this,SIGNAL(esignal(QString TapeFolder)),mThread,SLOT(cs_remove()));

   // mThread->terminateall();
  //  mThread->exitslot();
//todo: let user select default folder in settings

   QString TapeFolder = QFileDialog::getExistingDirectory(0, ("Select Tape Folder"), QDir::currentPath());


// QString fileName;
// fileName = QFileDialog::getOpenFileName(this,
//      tr("Open WAV File"), "/home/debian9/Desktop/ecasound", tr("WAV Files (*.wav)"));

            emit esignal(TapeFolder);

 ui->label_2->setText(TapeFolder);

 QFile hfile(".eca_hfile.txt");
      if (!hfile.open(QIODevice::WriteOnly | QIODevice::Text))
          return;

      QTextStream outh(&hfile);
      outh << TapeFolder;


////sleep(1);
//mThread->cs_remove(TapeFolder);



}



//void MainWindow::playslot()
//{
//    mThread->play();

//   //-- int cstimestart =1;

//    //--emit signalcstimer(cstimestart);

//    mThread->csgetpos();


//   // tThread->timerChanged1(cstimestart);


//}

//void MainWindow::metersslot()
//{
//    // mThread->aseqdump();
//     mThread->rxsend();
//}


//exitslot0
void MainWindow::exitslot0(int onevalue)
{


       mThread->quit();



     qDebug() << "onevalue";
      qDebug() << onevalue;



//     qDebug() << "exitslot main"  ;

//      qDebug() << "_____________________--mainwindow exit thread" << reinterpret_cast<std::uintptr_t>(thread()->currentThreadId());



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

//       sleep(1);

//      if(outp2!=NULL)
//      {
//        qDebug() << "not null";

//       kill (stdoi, SIGINT);
//        //kill (stdoi, SIGTERM);
//            sleep(1);

//            qApp->quit();
//            QProcess::startDetached(qApp->arguments()[0], qApp->arguments());

//          system("reboot");

//      }




//     sh.close();

//while(outp2==NULL)
//{


//     //
//     QProcess process3;
//     QProcess process4;


//     int n = 0;
//     if(n==0)
//     {

//           process3.start("pgrep ecasound");
//           process3.waitForFinished(-1);
////sleep(2);
//           QString stdoute = process3.readAllStandardOutput();
////sleep(2);
//          QString stdoute2 = stdoute.remove("\n");

//        int stdo3 =  stdoute2.toInt();

//           qDebug() << "QProcess" << stdoute << stdoute2 << stdo3   ;

//           sleep(1);

//           n=n+1;

//           if(stdoute!=NULL)
//           {
//             qDebug() << "not null";

//            kill (stdo3, SIGINT);
//             //kill (stdo3, SIGTERM);
//                 sleep(1);
//                 qApp->quit();
//                 QProcess::startDetached(qApp->arguments()[0], qApp->arguments());


//           }

//     }
//           else
//           {
//               process4.start("pidof ecasound");
//               process4.waitForFinished(-1);
//    sleep(1);
//               QString stdoute4 = process4.readAllStandardOutput();

//              QString stdoute24 = stdoute4.remove("\n");

//            int stdo34 =  stdoute24.toInt();

//               qDebug() << "QProcess4" << stdoute4 << stdoute24 << stdo34   ;

//               if(stdoute4!=NULL)
//               {
//                 qDebug() << "not null4";

//                kill (stdo34, SIGINT);
//                 //kill (stdo34, SIGTERM);
//                     sleep(1);

//                     qApp->quit();
//                     QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
//           }
//           }




// qDebug() << "exitslot3"  ;


// process3.kill();
//  process4.kill();

  //}

//      qDebug() << "exitslot4 after jack"  ;

//    qApp->quit();
//    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());


//QApplication::exit(-1);

//disconandexit=1;



sleep(1);

//     QProcess sh;
//     sh.start("sh");

//     sh.write("pgrep GNU_TRM8TT");
//     sh.closeWriteChannel();

//     sh.waitForFinished();
//     QByteArray output2 = sh.readAll();

//     QString DataAsString = QString(output2);

//      QString  outp2 = DataAsString.remove("\n");

//      qDebug() << " QByteArray output GNU_TRM8TT" << output2 << outp2;

//       int stdoi =  outp2.toInt();

//       sleep(1);

//      if(outp2!=NULL)
//      {
//        qDebug() << "not null";

//       kill (stdoi, SIGINT);
//        //kill (stdoi, SIGTERM);
//            sleep(1);





      //



}





//exit0 end

MainWindow::~MainWindow()
{
    delete ui;
}



