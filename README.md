# 32-channel I2C output module.
## General information about the module.

This module is based on two TCA6416A chips.  
* Supply voltage: 24VDC.
* Output voltage: 0V to 24V.
* It has galvanic isolation for I2C signals by ISO1540.
* Each channel has LED indication.
* One TCA6416 module has address 20 and the other has address 21.
* The outputs are based on P-type MOSFETs SP3401LT2C.
* Output current of each output 0.5A

![32-channel I2C output module](img/32ch_out_100.png)
<a href="https://tranzystorek.pl/" target="_blank">tranzystorek.pl</a>


The bus I2C can be connected via connectors J101 or J102.

![](img/I2C_Connector_pcb.png)
![](img/I2C_Connector_sch.png)

