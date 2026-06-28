# b2w

## Purpose
b2w is a simple command-line program written in C using basic functions only \[1\]. The goal is to track the number of kilometres for the "Bike to Work" campagn \[2\] traveled throughout the day in order to calculate the daily total. This rounded integer value has to be entered in the appropriate field on the "Bike to Work" website.

## Background
*Bike to Work is a campaign to promote health within companies. You can participate in Bike to Work as soon as your company is registered. To do this you create a personal profile, assign it to your company and then record your bike days regularly on the calendar.* (https://www.biketowork.ch/en/faq)

## System requirements
The program can be built and run on various systems, such as Linux, Windows and Android.

## Installation
Download the repository into your desired directory.

```
cd <directory>
git clone https://github.com/ABoehlen/b2w
```

### Linux and other POSIX conformant systems
Use the enclosed shellscript which builds the binary using the gcc compiler.

```
cd b2w
./build_gcc
```

### Windows
On Windows (10 / 11) the following compilers have been tested successfully:

* In Code::Blocks, create a new project, add the \*.c and \*.h files and then build the binary using the 'Build' function. You should then find it in the subdirectory bin\\Debug.
* TCC (Tiny C Compiler) is a very small compiler (as the name suggests), but it is useful in many situations. Before using it, copy the "b2w.h" into the source directory. Do the same with the "build_tcc.cmd" batch file. Ensure, that the PATH variable includes the folder containing tcc.exe. Then build the binary by double clicking on "build_tcc.cmd".
* Cygwin can also be used. The procedure is the same as on Linux systems. Please note that the resulting "b2w.exe" can only be run within Cygwin. It's not a stand alone Windows executable file.

### Android
In the Cxxdroid app, create a new project, copy the \*.c and \*.h files into the appropriate directories and then build the binary using the automatically generated CMakeLists.txt file.

## Usage
The data will be saved in a comma-separated text file with the extension \*.csv. This file can be created when you use the program for the first time, or you create it manually using a text editor.

The program is launched from the command line using the command "b2w". The csv files contained in the current directory are listed, after which the correct file must be specified:
![no command-line arguments](https://github.com/ABoehlen/b2w/blob/main/no_command-line_argument.jpg)

If you already knew the name of the table you can use it as command-line argument:
![table name as command-line argument](https://github.com/ABoehlen/b2w/blob/main/command-line_argument_table.jpg)

After that the main menu appears, which currently contains only two functions:

### Collect data
This function is used to collect the data for each day. You must provide the following information:
- Date in the format YYYYMMDD (e.g. 20260501)
- The number of kilometres traveled by bicycle in the morning, at midday, and in the evening. The value can be entered as a whole number or with one decimal place. If you didn't ride, enter 0 or just press the Enter key.
Once the data for the current day is complete, you can either enter the data for another day right away or return to the main menu.

### List table content
A clear table appears, showing the total number of kilometres traveled each day, rounded to the nearest whole number. You should enter this number into your personal calendar at https://www.biketowork.ch. The total number of kilometres is also calculated and appears at the bottom of the table.
![table name as command-line argument](https://github.com/ABoehlen/b2w/blob/main/list_table_cxxdroid.jpg)

For futher calculations the csv file can easily be imported into a spreadsheet oder database application. You may need to change the extension to \*.txt to do this.

## License
This project is licensed under the MIT License - see the LICENSE file for details

## Literature
\[1\] Kernighan & Ritchie: The C Programming Language, 1978

\[2\] https://www.biketowork.ch/en/challenge
