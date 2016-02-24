#!/usr/bin/env bash

while true
do
  curWindow=$(xdotool getwindowname `xdotool getactivewindow`)
  printf '%s\n' $curWindow 
  sleep 0.2
done
