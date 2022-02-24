screen_middle_x = 316 / 2
linedup = False
dt.set_velocity(5, vex.VelocityUnits.PCT)
while not linedup:
  eyes.take_snapshot(YELLOW_GOAL)
  if eyes.object_count > 0:
    if eyes.largest_object.centerX < screen_middle_x - 5:
      dt.turn(vex.TurnType.LEFT)
    elif eyes.largest_object.centerX > screen_middle_x + 5:
      dt.turn(vex.TurnType.RIGHT)
    else:
      linedup = True
      dt.stop(vex.BrakeType.COAST)
  else:
    dt.stop(vex.BrakeType.COAST)
  #Initial idea, changed to pros and started using pids to smoothen out the process.
