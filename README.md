# Bursting Bubbles FourSquare Switch

Greet your guests with wonderful soap bubbles after they checked in at your venue with foursqaure. Or just enjoy them yourself, it's both very beautiful.

![soap bubbles time!!](http://distilleryimage0.ak.instagram.com/0c02eb9e01e011e3bd1922000ae800b1_7.jpg)

It's built with [this soap bubbles machine](http://www.kosmos.de/produktdetail-909-909/seifenblasen_roboter-325/) but I guess it will work with any bursting bubbles machine that uses a toy motor up to 12V depending on the MOS-FET you use.

## Variant A: Arduino & Xbee WiFly

Uses a ruby server to connect with Foursquare and a XBee WiFly to connect to your wireless.

* Push the whole repo to e.g. Heroku to let the ruby middleware run
* Find the Arduino code in `arduino/bursting_bubbles_switch/`
* Use the Fritzing sketch located in `fritzing/bursting_bubbles.fzz` or the corresponding PDF to see how to wire things

## Variant Y: Arduino Yun

Uses a Yun to connect with Foursquare and to your wireless - quite exciting device!

* The only code you'll need is in `arduino/bursting_bubbles_yun` (did I mention that I find this very exciting?)
* Make sure your Yun has access to your network & the internet
* Use the Fritzing sketch located in `fritzing/bursting_bubbles_yun.fzz` or the corresponding PDF to see how to wire things
