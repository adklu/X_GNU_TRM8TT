# X_GNU_TRM8TT
Standalone Multi-track Recorder Operating System Prototype

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
- no screen, control via midi faders, knobs, buttons and LEDs... 
- prototype dev used Behringer XTouchCompact, even 8 peak meters and a timer, which shows the position of the tape head (even if the Behringer XTouchCompact does not have a LCD screen, there are 2 LED rings as pointer for minutes and 5 sec steps, the maximum time is 14 minutes, because the ring has only 13 LEDs...

So the peak meter is not on the Computer screen, but on the Behringer XTouchCompact, even if the Behringer XTouchCompact does not have a peak meter?
Yes, every track on the Behringer XTouchCompact has three buttons with LEDs, the LEDs are now the peak meter... every track has a 3 elements peak meter ("there is sound", "the volumne is ok", "it is almost clipping, turn it down"). 

Which effects does it include?
No effects, it is suggested to use 24bit/94KHz to not include digital artifacts, when capturing analog effects like tape recorder's tape compression and tape hiss/flutter or analog compressors/EQs/tape delay/analog reverb. 

Is X_GNU_TRM8TT only working with Behringer XTouchCompact?
Yes, but it is possible to change the code so that it would work with similar Midi controllers or with a hardware prototype, for example combined with a real recording tape track, which is rendered in real time to the digital track... 

Aren't there already enough multi-track recorders for overdubbing on the market, should I buy a Behringer XTouchCompact, if I need a standalone digital hardware multi-track recorder for overdubbing?
There are cheaper solutions (e.g. by companies like Tascam or Zoom), also this is a prototype (it hasn't been longtime tested...)

How do I change the (digital) tapes?
One project contains 8 8-track tapes, so it is possible to record 8 8-track songs (for now the 'timer' limit is 14 min.).
After recording on all 8 tapes a computer is necessary to free space for another set of 8 tapes...

How do I put a tape into the recorder?
Main button and tape slot button (knob button 1-8)... this is the playback mode...

If if change from playback to recording mode or vice versa, the timer is not working...
RTZ activates the timer, changing modes starts into play to pre listen the song and to avoid moving the faders during transport stop... 

How do I record?
Tape slot button(1-8) and Rec enable button  1 (or one track recording) or 2 (for recording with 2 tracks, e.g. stereo). It can't be selected which tracks the recording tracks are, which are always the next free 1 or 2 tracks... if all tracks are already used knob ring 10 will blink and X_GNU_TRM8TT will change to playback mode... (change of the code would allow to record up to 8 tracks at the same time, but this is not implemented yet, since the focus and testing was on overdubbing track by track with a simple 2-channel input audio interface... also already recorded tracks can be imported into the 'Tape' folders...).

How do I delete a track?
Knob buttons 9 + 10 and top row button from top (of peak meter) to select the track...
This will not delete the track, but rename it, so that the track is invisible for X_GNU_TRM8TT, but still visible for a computer.

Are there mute or solo buttons?
No, there are 8 faders and it is possible to move them all with 8 fingers or so...

Which function has the 'LOOP' button?
RTZ - return to zero 

When pressing '<<' or '>>' the tape skips only 3 seconds or so... how can I skip 5 min without pressing pressing the buttons 100 times?
Button knob 16 when pressed one time adds 10 seconds, when pressed 2 times 20 sec and so on... to the default value on '<<' or '>>'
Button knob 15 resets the skip time back to 3 seconds...

Ok, so every track has its 3 part peak meter, but where is the peak meter of the master track?
It is true that there is a stereo master mix output (including panning of knobs 1-8) and if the main LED (rec enable LED of the main fader) blinks then the master track is almost peaking and it is better to turn faders or input down.

Are there digital limiters?
No, it is recommended to use an analog compressor/limiter.

If I stop the track and move the faders, I can't change the volume anymore...
If the transport is stopped and the faders are moved it can happen that the midi control of the faders freezes (prototype wip)... so better to move the faders only when the transport is running... button knob 11 can reset the faders... when changing the record mode from playback to recording or vice versa, the transport will run to avoid fader crashes... this is the preview mode of the tape, in order to start the recoding it is recommended to RTZ (which will also activate the timer).

If I use a2j X_GNU_TRM8TT is crashing...
X_GNU_TRM8TT is an Operating System Prototype wip and should only use the mentioned software for a standalone recorder system.

Without DummyTapes the prototype is not working. DummyTapes are short (empty) wav. files (same bit/KHz as the project), in the following structure:
home/.../TRM8TT_Tapes/DummyTape1.wav
home/.../TRM8TT_Tapes/DummyTape2.wav
home/.../TRM8TT_Tapes/DummyTape3.wav
home/.../TRM8TT_Tapes/DummyTape4.wav
home/.../TRM8TT_Tapes/DummyTape5.wav
home/.../TRM8TT_Tapes/DummyTape6.wav
home/.../TRM8TT_Tapes/DummyTape7.wav
home/.../TRM8TT_Tapes/DummyTape8.wav


//alsa midi input/output system contains modifications of
//aseqdump.c and amidi.c (original files by Clemens Ladisch published under the GNU General Public License 2 or later, see originalfiles folder)
//modifications by A.D.Klumpp published under the GNU General Public License 2 or later
//see mod comments inside of thread1.cpp

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
//fader cops can crash, if used when transport is stopped (button of knob 11 can reset all faders)






