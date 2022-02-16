//Idea behind pure pursuit
double vectorRAngle(double endX, double endY)
{
  double gAngle = vectorGAngle(endX, endY);
  //Finds angle from 0 - 2pi of the bot angle from the vector angle
  double relativeAngle = angleWrap(gAngle - odom.getAngle(RADIANS), RADIANS);

  return relativeAngle;
}

double vectorGAngle(double endX, double endY)
{
  //Finds X and Y difference from start to target
  double vectorX = endX-odom.getX();
  double vectorY = endY-odom.getY();

  //Finds angle from 0 - 2pi of the vector from 0 (right on the x-axis)
  double vectorGlobalAngle = angleWrap(atan2(vectorY, vectorX), RADIANS);

  return vectorGlobalAngle;
}


double vectorLength(double endX, double endY)
{
  //Finds X and Y difference from start to target
  double vectorX = endX-odom.getX();
  double vectorY = endY-odom.getY();
  
  //Finds length of the vector
  double vectorL = hypot(vectorX, vectorY);

  return vectorL;
}

double coordFinderX(double distance, double angle){
  return odometry.getX() + (distance * cos(angle)); 
}

double coordFinderY(double distance, double angle){
  return odometry.getY() + (distance * sin(angle)); 
}
