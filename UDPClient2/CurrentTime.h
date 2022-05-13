#ifndef CURRENTTIME_H
#define CURRENTTIME_H
#include <QTime>
#include <QTimer>
#include <QLineEdit>

class CurrentTime : public QObject
{
    Q_OBJECT
public:
    CurrentTime(){}
    virtual ~CurrentTime() {}
    void Timer(QLineEdit* line, int step);



public slots:
    void Update();

private:

    QLineEdit* new_line;
    QTimer* timer;

};






#endif // CURRENTTIME_H
