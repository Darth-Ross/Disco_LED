# Quick description 

This is a design for a IR RGB LEDstrip driver which uses a 24 key RGB remote. It can display 16 predetermined static colours, change brightness, turn off and on again while remembering the last colour and display special functions like for example smooth colour change or colour flashing. 

The repo includes both hardware and software design which you can either use directly or include in your own projects.

# Licenses

The software is licensed under the GNU General Public License V3.0 and the hardware is licensed under the CERN Open Hardware License V1.2. See the license files in each folder for more information.

# Libraries 

These are all the libraries I have used that were made by other users.
- https://github.com/electrobs/AVR-LIBRARY-IR_REMOTE_RECV


# Hardware changelog
#### V1.0
- Added electrical schematic
- Added PCB design
- Added licensing
#### V1.0.1
- Added gerber files 
- Added 3D renders 
#### V1.1
- Fixed connection error for ICSP port

# Software changelog
#### V1.0
- Basic feature implementation
- Added 24 key RGB remote support
- Added ATmega328p support
- Added licensing
#### V1.1
- Added first implementation of CMD_REPEAT functionality
- Reworked the brightness system to use percentage instead of RGB values. 

#### Known bugs
- CMD_REPEAT remembers the command BPLUS OR BMIN even after pressing other commands. This will cause the BPLUS or BMIN command to be executed if other commands are repeated.

