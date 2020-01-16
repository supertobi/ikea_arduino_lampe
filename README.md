# IKEA Arduino Lampe

<p align="center">
  <img src="Lamp_light.jpg" width="350" title="Lamp">
  <img src="Lamp_dark.jpg" width="350" alt="Lamp dark">
</p>

The pimped lamp:
https://www.ikea.com/de/de/p/lampan-tischleuchte-weiss-20046988/

## G'MIC
You can get the latest version of G'MIC here:
https://gmic.eu/

The g'mic simmulation looks like this:
![G'MIC](gmic_lamp.jpeg)

Ues this command to simulate the lamp with G'MIC:
```bash
gmic Lampshade.png -command lamp.gmic -lamp3d
```

