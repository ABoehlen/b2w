# b2w

## Purpose
b2w is used to collect the kilometres for the "Bike To Work" campaign in a comma-separated table.
The fields are: Date, Morning, Midday, Evening and Sum.
The value in "Sum" has to be entered in the appropriate field on the website https://www.biketowork.ch/

## Background
Bike to Work is a campaign to promote health within companies. You can participate in Bike to Work as soon as your company is registered. To do this you create a personal profile, assign it to your company and then record your bike days regularly on the calendar. (https://www.biketowork.ch/en/faq)

## System requirements
The program can be used on all UNIX-like systems and also runs on Android (using the Cxxdroid app). Currently, it does not run on Windows.

## Installation
Download the repository into your desired directory and build the binary:

```
cd <directory>
git clone https://github.com/ABoehlen/b2w
cd b2w
./build
```

## Usage
The data is saved in a comma-separated text file with the extension \*.txt. This file can be generated directly by the program the first time it is used, or created manually using a text editor.
The program is launched from the command line using the command "b2w". The txt files contained in the corresponding directory are listed, after which the correct file must be specified.
You are then taken to the main menu, which contains the following functions:

### Collect data
The following information must be provided:
- Date in the format YYYYMMDD (e.g. 20260501)
- The number of kilometres traveled by bicycle in the morning, at midday, and in the evening. The value can be entered as a whole number or with one decimal place. If you didn't ride, just enter 0 or press the Enter key.
After this day is entered, you can either enter the data for the next day right away or return to the main menu.

### List table content
A clear table appears, showing the total number of kilometers traveled each day, rounded to the nearest whole number. You should enter this number into your personal calendar at https://www.biketowork.ch. The total number of kilometers is also calculated.

## License
This project is licensed under the MIT License - see the LICENSE file for details