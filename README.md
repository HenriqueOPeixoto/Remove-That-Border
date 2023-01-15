# Remove-That-Border
Application to remove window borders in Windows, written in C++ and using wxWidgets.

It's still really early in development, but already offers some basic functionality. I intend on improving this app in the near future, to fix some edge cases.

## Why would I need this?

Some games, especially older ones, don't offer bordeless fullscreen by default. This app tries to allow these games to run in borderless fullscreen. Exclusive fullscreen worked in the past but nowadays they can just introduce more bugs and lead to an overall frustating experience, especially when you have multiple apps open and like to switch often.

Some games I've tested:

* Fallout: New Vegas works and allows alt tabbing without crashing.
* Fixes Metal Gear Rising extremely low framerate on HDMI TVs upon using Exclusive Fullscreen.
* Sonic Adventure 2 works fine as well.

## How to use?

Just open the game in windowed mode and choose the screen native resolution. Then open the app and choose the game's window name on the list. After selecting click on Remove Borders and you're set.

## Known issues (will be fixed in future updates):

* A mostly negligible part of the game gets cropped in the bottom and right sides of the screen;
* Games that don't have a window name are not supported yet;

## Disclaimer

All work product by Developer is provided “AS IS”. Other than as provided in this agreement, Developer makes no other warranties, express or implied, and hereby disclaims all implied warranties, including any warranty of merchantability and warranty of fitness for a particular purpose.
