# YMFC-AL - MNK


YMFC/YMFC-AL is an auto pilot project by Joop Brokking (http://www.brokking.net/ymfc-al_main.html).

In this repo i have made couple of small improvement to keep my copter flying according to what i am used to from my experience with cleanflight and betaflight.

DONE:

- wire switch (port 3) for auto level / acro (no level) modes
- LED indicator of acro mode when not armed
- RC rates for YAW, PITCH and ROLL (independent)
- wait 1 second before disarming - to prevent accidental disarms while flying
- control MIN BATTERY WARNING LEVEL via a constant
- remove ESC proding when idle - not necessary with BLHELI ESCs
- disable auto level function and PID loop on min throttle to prevent flips on the ground 
- beeper support via timer interrupt
- ADD battery low beeper (port 13)
- ADD beeps when behind on the mainloop


TODO:

- support for SBUS (via inverter http://www.dx.com/p/signal-inverter-for-naze32-flight-control-sbus-receiver-black-429018#.WCJNt8wrKV4)
- ACRO mode switch via RC channel
- ARM/DISARM via RC channel
- figure out how to prevent XY acc drift during AL flight
- ADD Bluetooth on rx/tx to transmit FC state - crashes investigation
- Parameter (PID) tuning using RC channels

