# Arduino-ULN2003 Drives Stepper Motors


Samples driving stepper motor using [ULN2003](https://github.com/Tarsier-Marianz/ULN2003_Motors/blob/master/References/uln2003_DS.pdf) integrated circuit in [Arduino](https://www.arduino.cc/).

* `ULN2003_MotorControl4Wire` - basic example on how to drive **4-wired** stepper motor (ex: [28BYJ48](http://robocraft.ru/files/datasheet/28BYJ-48.pdf)) using *ULN2003* IC, without using any libraries for driving motors just a simple `HIGH/LOW` pre-defined sequence of configured **I/O** pins.
* `ULN2003_MotorControl6Wire` - driving **6-wired** stepper motor (ex: [28BYJ48](http://robocraft.ru/files/datasheet/28BYJ-48.pdf)) using *ULN2003* IC, just triggering `HIGH/LOW` pre-defined  sequence of configured **I/O** pins like first example.
* `ULN2003_MotorControl4Wire_AcccelStepper` - simple demonstration on driving **4-wired** stepper motor (ex: [28BYJ48](http://robocraft.ru/files/datasheet/28BYJ-48.pdf)) using *ULN2003* with the used of [AccelStepper](https://www.arduinolibraries.info/libraries/accel-stepper) a 3rd-party library.
* `ULN2003_MotorControl6Wire_AcccelStepper` - just like the third example above but the difference is, it used **6-wired** stepper motor. [Click here](https://github.com/Tarsier-Marianz/ULN2003_Motors/blob/master/ULN2003_MotorControl6Wire_AcccelStepper/ULN2003_MotorControl6Wire_diagram.png) to see the connection diagram.
