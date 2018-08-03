# Arduino-ULN2003 Drives Stepper Motors


Samples driving stepper motor using [ULN2003](https://github.com/Tarsier-Marianz/ULN2003_Motors/blob/master/References/uln2003_DS.pdf) integrated circuit in [Arduino](https://www.arduino.cc/).

* `ULN2003_MotorControl4Wire` - basic example on how to drive **4-wired** stepper motor (ex: [28BYJ48](http://robocraft.ru/files/datasheet/28BYJ-48.pdf)) using *ULN2003* IC, without using any libraries for driving motors just a simple `HIGH/LOW` sequnces of configured **I/O** pins.
* `ULN2003_MotorControl6Wire` - driving **6-wired** stepper motor (ex: [28BYJ48](http://robocraft.ru/files/datasheet/28BYJ-48.pdf)) using *ULN2003* IC, just triggering `HIGH/LOW` sequences of configured **I/O** pins like first example.
