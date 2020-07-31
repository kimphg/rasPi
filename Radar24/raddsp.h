#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <complex>
#include <iostream>
#include <valarray>
#include <QThread>
#define BUF_SIZE 1024
typedef std::complex<double> Complex;
class RadDSP : public QObject
{
    Q_OBJECT
public:

    RadDSP(QObject* thingy, QObject* parent = 0);
    static void StopRead();
    static void StartRead();
//    static unsigned char *getData();
    static QString getDataString();
    static Complex *getData();
private:
    QObject* mythingy;
    bool setupGPIO();
signals:
    void deleteObject(QObject* thingy);
public slots:
    void doWork();
};

#endif // WORKER_H
