(1) how to setup and run your program
1. main.cpp

I/O:
用PA_4作為AnalogOut，PB_1作為AnalogIn，PA_7作為調高頻率的button，PA_6作為調低頻率的button，PA_2作為確認調整頻率的button，USER_BUTTON作為傳送DACdata回PC端的button。
button 都使用DigitalIn的PullNone mode。利用當前的button狀態與先前儲存的button狀態比較，不同的話代表button被按過，執行功能。

Display:
使用三個頻率，60Hz，120Hz，240Hz(cut-off frquency)，
用0,1,2分別代表60Hz，120Hz，240Hz。
用freq_s和freq分別代表將要選用的頻率和現在正在輸出的頻率。
每當freq_s或freq變更時，call f_change()。
f_change()會先清空螢幕，再重新顯示新的頻率在uLCD上。

Generate waveform:
