#include "raddsp.h"
#ifndef Q_OS_WIN
#include "wiringPi.h"
#include "wiringSerial.h"


#endif
int bitCount = 0;
int byteCount = 0;

#define DATA_PIN 4
#define CLOCK_PIN 5
#define EN_PIN 3
const double PI = 3.141592653589793238460;

Complex mdata[BUF_SIZE];
Complex mFFTdata[BUF_SIZE];
// Cooley-Tukey FFT (in-place, breadth-first, decimation-in-frequency)
// Better optimized but less intuitive
// !!! Warning : in some cases this code make result different from not optimased version above (need to fix bug)
// The bug is now fixed @2017/05/30
void fft()
{
    // DFT
    memcpy(mFFTdata,mdata,BUF_SIZE*sizeof(Complex));
    unsigned int N = BUF_SIZE, k = N, n;
    double thetaT = 3.14159265358979323846264338328L / N;
    Complex phiT = Complex(cos(thetaT), -sin(thetaT)), T;
    while (k > 1)
    {
        n = k;
        k >>= 1;
        phiT = phiT * phiT;
        T = 1.0L;
        for (unsigned int l = 0; l < k; l++)
        {
            for (unsigned int a = l; a < N; a += n)
            {
                unsigned int b = a + k;
                Complex t = mFFTdata[a] - mFFTdata[b];
                mFFTdata[a] += mFFTdata[b];
                mFFTdata[b] = t * T;
            }
            T *= phiT;
        }
    }
    // Decimate
    unsigned int m = (unsigned int)log2(N);
    for (unsigned int a = 0; a < N; a++)
    {
        unsigned int b = a;
        // Reverse bits
        b = (((b & 0xaaaaaaaa) >> 1) | ((b & 0x55555555) << 1));
        b = (((b & 0xcccccccc) >> 2) | ((b & 0x33333333) << 2));
        b = (((b & 0xf0f0f0f0) >> 4) | ((b & 0x0f0f0f0f) << 4));
        b = (((b & 0xff00ff00) >> 8) | ((b & 0x00ff00ff) << 8));
        b = ((b >> 16) | (b << 16)) >> (32 - m);
        if (b > a)
        {
            Complex t = mFFTdata[a];
            mFFTdata[a] = mFFTdata[b];
            mFFTdata[b] = t;
        }
    }
    //// Normalize (This section make it not working correctly)
    Complex f = 1.0 / sqrt(N);
    for (unsigned int i = 0; i < N; i++)
    {
        mFFTdata[i] *= f;
//        if(mFFTdata[i].real()>600)
//            mFFTdata[i]=0;
    }
    //return x;
}


unsigned short  data1,data2,data3;
#ifndef Q_OS_WIN

void clkRisingInterrupt(void)
{
//    digitalRead(23);
    if(bitCount==0)
    {
        data1=(digitalRead(DATA_PIN)<<3);
        bitCount=1;
    }
    else if(bitCount==1)
    {
        data2=(digitalRead(DATA_PIN)<<2);
        bitCount=2;
    }
    else if(bitCount==2)
    {
        data3=(digitalRead(DATA_PIN)<<1);
        bitCount=3;
    }
    else
    {
        mdata[byteCount]=(data1+data2+data3+(digitalRead(DATA_PIN)));
//        printf("\n");
//        for(int i=0;i<data[byteCount];i++)printf("0");
        byteCount++;
        if(byteCount>=BUF_SIZE)byteCount=0;
        bitCount=0;
    }
}


#endif
QString RadDSP::getDataString()
{
    //CArray fftData = fft();
    QString output="";
//    for(int i = 0;i<BUF_SIZE;i++)
//    {
//        output.append("!\t");
//        output.append(QString::number(i)+"\t"+QString::number(fftData[i].real()));
//        output.append("#");
//    }
    return output;
}
Complex* RadDSP::getData()
{
    fft();
    return mFFTdata;
}
RadDSP::RadDSP(QObject* thingy, QObject* parent)
    : QObject(0)    //no real parent, so we can move to a different thread
{
    mythingy = thingy;

    //move myself to a new thread and start it
    QThread* thread = new QThread(parent);
    connect(thread, SIGNAL(started()), this, SLOT(doWork()));
    this->moveToThread(thread);
    thread->start();
    //set up connnection
#ifndef Q_OS_WIN
    if (wiringPiSetup () == -1)
    {
        printf ( "Unable to start wiringPi\n") ;
        return ;
    }
    setupGPIO();
#endif
}
void RadDSP::doWork()
{
    int a = 0;
    printf("\nStart reading data");
    while (1)
    {
        a++;
        QThread::msleep(5);
    }
    return;
}
void RadDSP::StartRead()
{
#ifndef Q_OS_WIN
    digitalWrite (EN_PIN, HIGH) ;
    printf("\nEn on");
#endif

}
void RadDSP::StopRead()
{
#ifndef Q_OS_WIN
    digitalWrite (EN_PIN, LOW) ;
    printf("\nEn off");
#endif

}
bool RadDSP::setupGPIO()
{

#ifndef Q_OS_WIN
    pinMode (EN_PIN, OUTPUT) ;//enable
    pinMode (DATA_PIN, INPUT) ;//data
    pinMode (CLOCK_PIN, INPUT) ;//clock

    // set Pin 17/0 generate an interrupt on high-to-low transitions
      // and attach myInterrupt() to the interrupt
      if ( wiringPiISR (CLOCK_PIN, INT_EDGE_RISING, &clkRisingInterrupt) < 0 ) {
          fprintf (stderr, "Unable to setup ISR: %s\n", strerror (errno));
          return false;
      }
#endif

      return true;
}
