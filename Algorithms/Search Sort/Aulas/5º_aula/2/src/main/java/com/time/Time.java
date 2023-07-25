package com.time;

public class Time {
  private double time;

  public void setTime(long initialTime, long finalTime) {
    this.time = ((finalTime - initialTime) / 1000d);
  }

  public double getTime() {
    return this.time;
  }
}
