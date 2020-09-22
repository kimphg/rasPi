
#define BUF_SIZE 128
#define FFT_DEGREE 7
//int mdata[BUF_SIZE];
float mFFTdata_r[BUF_SIZE];
float mFFTdata_im[BUF_SIZE];
int bytecount;
void setup()
{
    bytecount=0;
    Serial.begin(9600);
//    Serial.print("start");
}


void loop()
{
//  Serial.print("loop");
    int a = 0;
//    if(bytecount%2==0)a=20;
//    else a=-20;

    mFFTdata_r[bytecount]=float(analogRead(2))+a;
    mFFTdata_im[bytecount] = 0;
    
    bytecount++;
    if(bytecount>=BUF_SIZE)
    {
//      Serial.println("--------------data:");
//      for (int i =0;i<BUF_SIZE;i++)
//        {
//            Serial.println(mFFTdata_r[i]);
//        }
        bytecount=0;
//        FFT(mdata,mFFTdata_r,mFFTdata_im,BUF_SIZE);
        Serial.println('!');  
        Serial.println(0);  
        for (int i =1;i<BUF_SIZE;i++)
        {
            Serial.println(mFFTdata_r[i]);
        }
        Serial.flush();
        FFT2(1,FFT_DEGREE,mFFTdata_r,mFFTdata_im);
        Serial.println('!');  
        Serial.println(1);  
        for (int i =1;i<BUF_SIZE;i++)
        {
            Serial.println(0.1+sqrt(mFFTdata_r[i]*mFFTdata_r[i]+mFFTdata_im[i]*mFFTdata_im[i]));
        }
    }
    else
    {
      delay(50);
      }
    
}
void FFT2(short int dir,int m,float *x,float *y)
{
    int n,i,i1,j,k,i2,l,l1,l2;
    float c1,c2,tx,ty,t1,t2,u1,u2,z;

    /* Calculate the number of points */
    n = 1;
    for (i=0;i<m;i++)
        n *= 2;

    /* Do the bit reversal */
    i2 = n >> 1;
    j = 0;
    for (i=0;i<n-1;i++) {
        if (i < j) {
            tx = x[i];
            ty = y[i];
            x[i] = x[j];
            y[i] = y[j];
            x[j] = tx;
            y[j] = ty;
        }
        k = i2;
        while (k <= j) {
            j -= k;
            k >>= 1;
        }
        j += k;
    }

    /* Compute the FFT */
    c1 = -1.0;
    c2 = 0.0;
    l2 = 1;
    for (l=0;l<m;l++) {
        l1 = l2;
        l2 <<= 1;
        u1 = 1.0;
        u2 = 0.0;
        for (j=0;j<l1;j++) {
            for (i=j;i<n;i+=l2) {
                i1 = i + l1;
                t1 = u1 * x[i1] - u2 * y[i1];
                t2 = u1 * y[i1] + u2 * x[i1];
                x[i1] = x[i] - t1;
                y[i1] = y[i] - t2;
                x[i] += t1;
                y[i] += t2;
            }
            z =  u1 * c1 - u2 * c2;
            u2 = u1 * c2 + u2 * c1;
            u1 = z;
        }
        c2 = sqrt((1.0 - c1) / 2.0);
        if (dir == 1)
            c2 = -c2;
        c1 = sqrt((1.0 + c1) / 2.0);
    }

    /* Scaling for forward transform */
    if (dir == 1) {
        for (i=0;i<n;i++) {
            x[i] /= n;
            y[i] /= n;
        }
    }
}
