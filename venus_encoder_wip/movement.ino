struct Movement {
  float left_wheel_revs;
  float right_wheel_revs;
}

float move_forward_and_measure(int ms) 
{
  servo_attach();

  unsigned long start_ms = millis();
  
  servoLeft.writeMicroseconds(1680);
  servoRight.writeMicroseconds(1300);

  int passed_spokes_l = 0;
  int passed_spokes_r = 0;

  while (millis() <= start_ms + ms) {
    spoke_stat_l_prev = spoke_stat_l;
    spoke_stat_r_prev = spoke_stat_r;

    spoke_stat_l = digitalRead(8);
    spoke_stat_r = digitalRead(7);

    if (spoke_stat_l != spoke_stat_l_prev) {
      passed_spokes_l++;
//      Serial.println((float) passed_spokes_l);
    }

    if (spoke_stat_r != spoke_stat_r_prev) {
      passed_spokes_r++;
    }
  }

//  Serial.print("Revolutions: ");
  Serial.print("Left: ");
  Serial.print((float) passed_spokes_l / NUM_OF_SPOKES);

  Serial.print("    ");
  
  Serial.print("Right: ");
  Serial.println((float) passed_spokes_r / NUM_OF_SPOKES);

  servo_detach();

  return (float) (passed_spokes_l + passed_spokes_r) / 2 / NUM_OF_SPOKES * 3.14 * WHEEL_DIAMETER / 2;     // cm
}
