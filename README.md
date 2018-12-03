# cmput-274-arduino-melodies
**By Imtisal Ahmad and Ryan Sandoval**
Name : Imtisal Ahmad and Ryan Sandolva 
ID #: 1495401 and 
CMPUT 274 Fa18
Project:

Included Files:
   * main.cpp
   * config.h
   * input.cpp
   * input.h
   * songs.h
   * test.cpp
   * test.h
   * tone.cpp
   * tone.h
   * utilities.cpp
   * utilities.h
   * README
   * Makefile

Project Description:
We have created a manual/ automatic music player for our project with an arduino and two buzzers.The music player program has two usages: it can be used a 
keyboard piano player or as a musical track player both with 3 choices. They user can choose three sets of notes to play on the piano keyboard or three tracks from our provided list to play on the track player option.

Running Instuctions:
   * Set up the arduinos: buzzers should be connected to pins 12 ,11 
   * Now connect your arduinos to your computer using a usb cabels.
   * Download the project.tar.gz file from eclass
   * Extract all the contents from the project.tar.gz file to another folder such as your documents or desktop 
   * Open the now extracted project folder, then open the terminal for the following directory, type in make hit enter, then type make upload. 
   * Then on the terminal window the track player will appear, answer the prompt to either play the piano or listen to track. 
   * For the piano part you can choose three different sets of notes to play, as prompted by the terminal.Make sure that you use the 
   following keys: d,f,g,h,j,k,l,;,r,t,u,i,o inorder for the keyboard to play like a piano.
   * For the track player just pick a prompted track out of the 3 provided ,and the 2 buzzers will play it for you.
   

Notes and Assumptions:

   * The file project.cpp contains a file called main.cpp which calls on the input.cpp and config.h files inorder to prompt and take in user input for the keyboard piano and track player. The config.h file is our set up file for the project, with all our arduino settings.The input.cpp file mainly deals with the manual (keyboard piano) aspect of our project, while the utilites.cpp, utilites.h  and song.h files are related to the automatic (track player) option of the project. The tone file contain code for the 2 buzzers running at the same time, which is used in both the manual and automatic part of the songs.


