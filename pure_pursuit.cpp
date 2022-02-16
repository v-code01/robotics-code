//Idea behind pure pursuit
double vectorRAngle(double endX, double endY)
{
  double gAngle = vectorGAngle(endX, endY);
  double relativeAngle = angleWrap(gAngle - odom.getAngle(RADIANS), RADIANS);

  return relativeAngle;
}

double vectorGAngle(double endX, double endY)
{
  double vectorX = endX-odom.getX();
  double vectorY = endY-odom.getY();
  double vectorGlobalAngle = angleWrap(atan2(vectorY, vectorX), RADIANS);

  return vectorGlobalAngle;
}
double vectorLength(double endX, double endY)
{
  double vectorX = endX-odom.getX();
  double vectorY = endY-odom.getY();
  double vectorL = hypot(vectorX, vectorY);

  return vectorL;
}
double coordFinderX(double distance, double angle){
  return odometry.getX() + (distance * cos(angle)); 
}
double coordFinderY(double distance, double angle){
  return odometry.getY() + (distance * sin(angle)); 
}
