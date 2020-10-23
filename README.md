# X_GNU_TRM8TT Standalone Multi-track Recorder Operating System Prototype

v0157 

Replaced by GUI_TRM8TT:

https://github.com/AndreasDanielKlumpp/GUI_TRM8TT




What do I need for the prototype?


Linux with ALSA and Jack including dev libs


//required libs
//jack dev libs
//libjack-dev
//or
//libjack-jackd2-dev
//alsa dev libs
//libasound2-dev


Ecasound 


Behringer XTouchCompact


Audio Interface for Linux


Qt

- based on Linux and Alsa, Jack and Ecasound
- NON-GUI version (GUI version available, which is more stable)
- control via midi faders, knobs, buttons and LEDs... 
- prototype used Behringer XTouchCompact
- every track has a 3 elements peak meter 

Is X_GNU_TRM8TT only working with Behringer XTouchCompact?

Yes, but it is possible to change the code so that it would work with similar Midi controllers or with a hardware prototype

playback mode: "Main button" and "tape slot button" (knob button 1-8)

How do I record?
Tape slot button (1-8) and Rec enable button  1 (one track recording) or 2 (for recording with 2 tracks, e.g. stereo). The recording tracks are always the next free 1 or 2 tracks... if all tracks are already used knob ring 10 will blink and X_GNU_TRM8TT will change to playback mode... (change of the code would allow to record up to 8 tracks at the same time, see GUI version).

How do I delete a track?
Knob buttons 9 + 10 and top row buttons (of peak meter) to select the track...
This will not delete the track, but rename it, so that the track is invisible for X_GNU_TRM8TT, but still visible for a computer.

Which function has the 'LOOP' button?
RTZ - return to zero 

When pressing '<<' or '>>' the tape skips only 3 seconds or so... how can I skip 5 min without pressing pressing the buttons 100 times?

Button knob 16 when pressed one time adds 10 seconds, when pressed 2 times 20 sec and so on to the default value for '<<' or '>>'
Button knob 15 resets the skip time back to 3 seconds...

If the main LED (rec enable LED of the main fader) blinks then the master track is almost peaking and it is better to turn faders or input down.

Are there digital limiters?
No, it is recommended to use an analog compressor/limiter.

If I use a2j X_GNU_TRM8TT is crashing...
X_GNU_TRM8TT is an Operating System Prototype WIP (the GUI version is more stable) and should only use the mentioned software for a standalone recorder system.

Without DummyTapes this prototype is not working (fixed for GUI version). DummyTapes are short (empty) wav. files (same bit/KHz as the project), in the following structure:
home/.../TRM8TT_Tapes/DummyTape1.wav
home/.../TRM8TT_Tapes/DummyTape2.wav
home/.../TRM8TT_Tapes/DummyTape3.wav
home/.../TRM8TT_Tapes/DummyTape4.wav
home/.../TRM8TT_Tapes/DummyTape5.wav
home/.../TRM8TT_Tapes/DummyTape6.wav
home/.../TRM8TT_Tapes/DummyTape7.wav
home/.../TRM8TT_Tapes/DummyTape8.wav


sh files:
path to files has to be edited manually...


//alsa midi input/output system contains modifications of
//aseqdump.c and amidi.c (original files by Clemens Ladisch published under the GNU General Public License 2 or later, see originalfiles folder)
//modifications by A.D.Klumpp published under the GNU General Public License 2 or later
//see mod comments inside of thread1.cpp

for unmodified files please refer to the copyright note inside of the file

//list jack ports: jack_lsp -c

//delete a track
//1) enter tape with track, which should be removed
//2) press the buttons of knobs 9 and 10
//3) select the track to delete via the top button row (below pan knobs)

//restartmodes()
//press main button + balance knob 1-8 to set the active tape for restart
//pressing the knobs 1-8 will set restart1 to 1, which will restart the progam:
//1) when pressing main into playback mode by setting maincounter to 1
//2) when pressing rec 1 into mono recording mode by setting rec1counter to 1
//3) stereo rec mode when pressing rec 2

//button of knob 11 can reset all faders, when fader controll crashed/frozen

//known bugs
//fader cops can crash, if used when transport is stopped (button of knob 11 can reset all faders) - fixed in the GUI version






