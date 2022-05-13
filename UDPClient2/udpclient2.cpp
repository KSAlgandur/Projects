#include "udpclient2.h"
#include "ui_udpclient2.h"

UDPClient2::UDPClient2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UDPClient2)
{
    ui->setupUi(this);
    Timers.Timer(ui->lineEdit_3,1000); // обновление времени через 1 сек
    updSocket = new QUdpSocket(this);
    updSocket->bind(QHostAddress::LocalHost,8081);
    connect(updSocket,SIGNAL(readyRead()),this,SLOT(ReadingData()));

}

UDPClient2::~UDPClient2()
{
    delete ui;
}

void UDPClient2::ReadingData()// чтение данных
{
    QHostAddress sender;// adres
    quint16 senderPort;//порт отправления

    while(updSocket -> hasPendingDatagrams())
    {


        QTime qtime = QTime::currentTime();
        QString stime = qtime.toString(Qt::LocalDate);

        QByteArray datagram;
        datagram.resize(updSocket->pendingDatagramSize());
        updSocket->readDatagram(datagram.data(),datagram.size(),&sender,&senderPort);
        ui->textEdit->append(stime+" "+"<font color = red>" + QString(datagram) + "</font>");
        qDebug() << datagram.data() <<"IP: " + sender.toString() <<"Port: " + QString("%1").arg(senderPort);
        ui->lineEdit_2->setText("Port: " + QString("%1").arg(senderPort));

    }
}

void UDPClient2::on_pushButton_clicked()
{
    QTime qtime = QTime::currentTime();
    QString stime = qtime.toString(Qt::LocalDate);

    updSocket->writeDatagram(ui->lineEdit->text().toUtf8(),QHostAddress::LocalHost,8080);
    ui->textEdit->append(stime+" "+"Вы: <font color=green>" + ui->lineEdit->text()+"</font>");
    ui->lineEdit->clear();
}

