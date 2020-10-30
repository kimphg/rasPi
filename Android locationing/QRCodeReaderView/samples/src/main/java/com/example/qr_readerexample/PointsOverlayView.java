package com.example.qr_readerexample;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.PointF;
import android.util.AttributeSet;
import android.view.View;

public class PointsOverlayView extends View {

  PointF[] points;
  private Paint paint;
  private PointF qr_ct;

  public PointsOverlayView(Context context) {
    super(context);
    init();
  }

  public PointsOverlayView(Context context, AttributeSet attrs) {
    super(context, attrs);
    init();
  }

  public PointsOverlayView(Context context, AttributeSet attrs, int defStyleAttr) {
    super(context, attrs, defStyleAttr);
    init();
  }

  private void init() {
    paint = new Paint();
    paint.setColor(Color.YELLOW);
    paint.setStyle(Paint.Style.FILL);
  }

  public void setPoints(PointF[] points,PointF ct) {
    this.points = points;
    this.qr_ct = ct;
    invalidate();
  }

  @Override public void draw(Canvas canvas) {
    super.draw(canvas);
    if (points != null) {
      for (PointF pointF : points) {
        canvas.drawCircle(pointF.x, pointF.y, 10, paint);
        canvas.drawCircle(qr_ct.x,qr_ct.y,20,paint);
      }
    }
  }
}
