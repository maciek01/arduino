# arduino


YMFC is an auto pilot project by Joop Brokking.

In this repo i have made couple of small improvement to keep my copte flying accourding to what i am used to from my experience with cleanflight and beta flight.

DONE:

- wire switch (port 3) for auto level / acro (no level) modes
- LED indicator of acro mode when not arme
- RC rates for YAW, PITCH and ROLE (independent)
- wait 1 second before disarming - to prevent accidental disarms while flying
- control MIN BATTERY WARNING LEVEL via a constant
- remove ESC proding when idle - with BLHELIs this maked props move and is not necessary
- disable auto level function on min throttle to prevent flips while min thorttle on the ground 


TODO:

- ACRO mode switch via RC channel
- ARM/DISARM via RC channel
- figure out how to prevent acc drift during AL flight
- ADD battery low beeper (port 2)
- ADD Bluetooth on rx/tx to transmit FC state - investigate crashes :)

