//Odometry using motor encoders, if shaft encoders or rotation encoders are used uncomment the respective line
while (true){
double L = degToIn(((LFM.position(degrees) + LBM.position(degrees))/2) - prevL, 4.125);
  double R = degToIn(((RFM.position(degrees) + RBM.position(degrees))/2) - prevR, 4.125);
  //double L = degToIn(LeftEncoder.position(degrees) - prevL, 2.75);
  //double L = degToIn(RightEncoder.position(degrees) - prevR, 2.75);
  prevL = EncoderL.position(deg);
  prevR = EncoderR.position(deg);
  double theta = (L-R)/(Wl+Wr);
  double dChord;
  if (theta != 0)
  {
    dChord = 2 * sin(theta/2) * (R/theta + Wr);    
  }
  else 
  {
    dChord = (L+R)/2;
  }
  double dlocalX = dChord * sin(botRot + theta/2);
  double dlocalY = dChord * cos(botRot + theta/2);
  globalX += dlocalX;
  globalY += dlocalY;
  botRot += theta;
}
//for the angle to be accurate the distance from center has to extremely precise, therefore, alternatively you can use an imu for angle.
