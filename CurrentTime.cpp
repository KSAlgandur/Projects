#include"CurrentTime.h"

void CurrentTime::Timer(QLineEdit *line, int step)
{
   timer = new QTimer(this);
   new_line = line;
   connect(timer,SIGNAL(timeout()),this,SLOT(Update()));
   //QTimer::singleShot(step, this, &CurrentTime::Update);
   timer->start(step);

}

void CurrentTime::Update()
{
    QTime qtime = QTime::currentTime();
    QString stime = qtime.toString("H:m:s a");
    new_line->setText(stime);
}
