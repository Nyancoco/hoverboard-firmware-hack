\ The following compile to flash, only need to include once

\ include uart2.fs
\ include hoverboard.fs

\ ramp: target speed, steer in time

0 variable speed_step
0 variable steer_step
500 variable step_delay

: set_ramp ( speed steer -- )
	steer @ - steer_step !
	speed @ - speed_step !
;


: ramp ( speed steer -- ) 
  set_ramp
  17 0 do 
  steer_step @ i 16 */ steer @ + steer !
  speed_step @ i 16 */ speed @ + speed !
  send step_delay @ ms
  loop
;
  
  
  
